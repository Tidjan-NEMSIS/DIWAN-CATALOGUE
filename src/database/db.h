#ifndef DATABASE_H
#define DATABASE_H

#include <QObject>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QString>
#include <QDebug>
#include <QDir>
#include <QStandardPaths>
#include "../models/maison.h"
#include "../models/table_hachage.h"

class Database : public QObject
{
    Q_OBJECT

public:
    static Database& getInstance();
    
    bool initialiser();
    bool estConnecte() const { return m_estConnecte; }
    QString getErreur() const { return m_erreur; }
    
    bool chargerDansTable(TableHachage& table);
    bool insererMaison(const Maison& maison);
    bool supprimerMaison(const QString& id);
    Maison* rechercherMaison(const QString& id);
    QList<Maison*> getAllMaisons();
    
    bool exporterCSV(const QString& chemin);
    bool exporterJSON(const QString& chemin);

    bool sauvegarderTable(const TableHachage& table);

private:
    Database();
    ~Database();
    Database(const Database&) = delete;
    Database& operator=(const Database&) = delete;
    
    void setErreur(const QString& erreur);
    bool creerTables();
    bool insererDonneesTest();
    QString trouverCheminDB();
    
    QSqlDatabase m_db;
    bool m_estConnecte;
    QString m_erreur;
};

#endif // DATABASE_H 