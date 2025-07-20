#ifndef PERFORMANCE_H
#define PERFORMANCE_H

#include <QElapsedTimer>
#include <QVector>
#include <QString>
#include <QMap>
#include "../models/table_hachage.h"

struct MesurePerformance {
    qint64 tempsInsertion;
    qint64 tempsRecherche;
    qint64 tempsSuppression;
    int nombreCollisions;
    double tauxOccupation;
};

class Performance
{
public:
    static Performance& getInstance();
    
    // Mesures
    MesurePerformance mesurerOperation(TableHachage& table, const QString& cle, Maison* maison);
    QMap<TableHachage::FonctionHachageType, QVector<MesurePerformance>> mesurerOperations(
        const QVector<QString>& cles, const QVector<Maison*>& maisons);
    
    // Export
    bool exporterCSV(const QString& chemin, 
                    const QMap<TableHachage::FonctionHachageType, QVector<MesurePerformance>>& mesures);
    bool exporterJSON(const QString& chemin,
                     const QMap<TableHachage::FonctionHachageType, QVector<MesurePerformance>>& mesures);
    
    // Statistiques
    QVector<double> calculerMoyennes(const QVector<MesurePerformance>& mesures);
    QVector<double> calculerEcartTypes(const QVector<MesurePerformance>& mesures);
    
private:
    Performance() = default;
    ~Performance() = default;
    Performance(const Performance&) = delete;
    Performance& operator=(const Performance&) = delete;
    
    QElapsedTimer m_timer;
    
    QString fonctionHachageToString(TableHachage::FonctionHachageType type) const;
};

#endif // PERFORMANCE_H 