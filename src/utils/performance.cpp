#include "performance.h"
#include <QFile>
#include <QTextStream>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <cmath>

Performance& Performance::getInstance()
{
    static Performance instance;
    return instance;
}

MesurePerformance Performance::mesurerOperation(TableHachage& table, const QString& cle, Maison* maison)
{
    MesurePerformance mesure;
    
    // Mesure insertion
    m_timer.start();
    table.inserer(cle, maison);
    mesure.tempsInsertion = m_timer.elapsed();
    
    // Mesure recherche
    m_timer.start();
    table.get(cle);
    mesure.tempsRecherche = m_timer.elapsed();
    
    // Mesure suppression
    m_timer.start();
    table.supprimer(cle);
    mesure.tempsSuppression = m_timer.elapsed();
    
    // Statistiques
    mesure.nombreCollisions = table.getNombreCollisions();
    mesure.tauxOccupation = table.getTauxOccupation();
    
    return mesure;
}

QMap<TableHachage::FonctionHachageType, QVector<MesurePerformance>> 
Performance::mesurerOperations(const QVector<QString>& cles, const QVector<Maison*>& maisons)
{
    QMap<TableHachage::FonctionHachageType, QVector<MesurePerformance>> resultats;
    QVector<TableHachage::FonctionHachageType> types = {
        TableHachage::F1,
        TableHachage::F2,
        TableHachage::F3,
        TableHachage::SANS_HACHAGE
    };
    
    for (TableHachage::FonctionHachageType type : types) {
        TableHachage table(1000); // Taille initiale
        table.setFonctionHachage(type);
        QVector<MesurePerformance> mesures;
        
        for (int i = 0; i < cles.size() && i < maisons.size(); ++i) {
            mesures.append(mesurerOperation(table, cles[i], maisons[i]));
        }
        
        resultats[type] = mesures;
    }
    
    return resultats;
}

bool Performance::exporterCSV(const QString& chemin,
                            const QMap<TableHachage::FonctionHachageType, QVector<MesurePerformance>>& mesures)
{
    QFile file(chemin);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        return false;
    }
    
    QTextStream out(&file);
    out << "Fonction,Taille,Insertion,Recherche,Suppression,Collisions,Occupation\n";
    
    for (auto it = mesures.begin(); it != mesures.end(); ++it) {
        QString fonction = fonctionHachageToString(it.key());
        const QVector<MesurePerformance>& valeurs = it.value();
        
        for (int i = 0; i < valeurs.size(); ++i) {
            const MesurePerformance& m = valeurs[i];
            out << fonction << ","
                << i + 1 << ","
                << m.tempsInsertion << ","
                << m.tempsRecherche << ","
                << m.tempsSuppression << ","
                << m.nombreCollisions << ","
                << m.tauxOccupation << "\n";
        }
    }
    
    return true;
}

bool Performance::exporterJSON(const QString& chemin,
                             const QMap<TableHachage::FonctionHachageType, QVector<MesurePerformance>>& mesures)
{
    QJsonObject root;
    
    for (auto it = mesures.begin(); it != mesures.end(); ++it) {
        QString fonction = fonctionHachageToString(it.key());
        QJsonArray mesuresArray;
        
        for (const MesurePerformance& m : it.value()) {
            QJsonObject mesureObj;
            mesureObj["insertion"] = static_cast<int>(m.tempsInsertion);
            mesureObj["recherche"] = static_cast<int>(m.tempsRecherche);
            mesureObj["suppression"] = static_cast<int>(m.tempsSuppression);
            mesureObj["collisions"] = m.nombreCollisions;
            mesureObj["occupation"] = m.tauxOccupation;
            mesuresArray.append(mesureObj);
        }
        
        root[fonction] = mesuresArray;
    }
    
    QJsonDocument doc(root);
    QFile file(chemin);
    if (!file.open(QIODevice::WriteOnly)) {
        return false;
    }
    
    file.write(doc.toJson());
    return true;
}

QVector<double> Performance::calculerMoyennes(const QVector<MesurePerformance>& mesures)
{
    QVector<double> moyennes(5, 0.0); // [insertion, recherche, suppression, collisions, occupation]
    
    if (mesures.isEmpty()) return moyennes;
    
    for (const MesurePerformance& m : mesures) {
        moyennes[0] += m.tempsInsertion;
        moyennes[1] += m.tempsRecherche;
        moyennes[2] += m.tempsSuppression;
        moyennes[3] += m.nombreCollisions;
        moyennes[4] += m.tauxOccupation;
    }
    
    double n = static_cast<double>(mesures.size());
    for (double& moyenne : moyennes) {
        moyenne /= n;
    }
    
    return moyennes;
}

QVector<double> Performance::calculerEcartTypes(const QVector<MesurePerformance>& mesures)
{
    QVector<double> moyennes = calculerMoyennes(mesures);
    QVector<double> ecartTypes(5, 0.0);
    
    if (mesures.size() <= 1) return ecartTypes;
    
    // Calcul des carrés des écarts
    for (const MesurePerformance& m : mesures) {
        ecartTypes[0] += std::pow(m.tempsInsertion - moyennes[0], 2);
        ecartTypes[1] += std::pow(m.tempsRecherche - moyennes[1], 2);
        ecartTypes[2] += std::pow(m.tempsSuppression - moyennes[2], 2);
        ecartTypes[3] += std::pow(m.nombreCollisions - moyennes[3], 2);
        ecartTypes[4] += std::pow(m.tauxOccupation - moyennes[4], 2);
    }
    
    // Division par n-1 et racine carrée
    double n = static_cast<double>(mesures.size() - 1);
    for (double& ecartType : ecartTypes) {
        ecartType = std::sqrt(ecartType / n);
    }
    
    return ecartTypes;
}

QString Performance::fonctionHachageToString(TableHachage::FonctionHachageType type) const
{
    switch (type) {
        case TableHachage::F1:
            return "F1";
        case TableHachage::F2:
            return "F2";
        case TableHachage::F3:
            return "F3";
        case TableHachage::SANS_HACHAGE:
            return "SansHachage";
        default:
            return "Inconnu";
    }
} 