#include "db.h"
#include <QDebug>
#include <QDir>
#include <QCoreApplication>
#include <QFile>
#include <QTextStream>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>

Database& Database::getInstance()
{
    static Database instance;
    return instance;
}

Database::Database()
    : m_estConnecte(false)
{
    // Constructeur vide, l'initialisation se fait dans initialiser()
}

Database::~Database()
{
    if (m_estConnecte) {
        m_db.close();
    }
}

QString Database::trouverCheminDB()
{
    QDir dir(QCoreApplication::applicationDirPath());
    
    // Remonter jusqu'à 5 niveaux pour trouver le dossier 'data/dataset'
    for (int i = 0; i < 5; ++i) {
        if (dir.exists("data/dataset/maison.db")) {
            return dir.filePath("data/dataset/maison.db");
        }
        if (!dir.cdUp()) {
            break; // On est à la racine, on ne peut plus remonter
        }
    }

    // Si non trouvé, retourner un chemin par défaut dans le build dir
    qWarning() << "Base de données non trouvée dans les répertoires parents. Utilisation du chemin par défaut.";
    QDir buildDir(QCoreApplication::applicationDirPath());
    buildDir.mkpath("data/dataset");
    return buildDir.filePath("data/dataset/maison.db");
}

bool Database::initialiser()
{
    if (m_estConnecte) return true;

    m_db = QSqlDatabase::addDatabase("QSQLITE");
    QString dbPath = trouverCheminDB();
    m_db.setDatabaseName(dbPath);

    qInfo() << "Tentative de connexion à la base de données :" << dbPath;

    if (!m_db.open()) {
        setErreur("Impossible d'ouvrir la base de données: " + m_db.lastError().text());
        return false;
    }
    
    m_estConnecte = true;
    return creerTables();
}

void Database::setErreur(const QString& erreur)
{
    m_erreur = erreur;
    qCritical() << "Erreur Database:" << erreur;
}

bool Database::creerTables()
{
    QSqlQuery query;
    QString requete =
        "CREATE TABLE IF NOT EXISTS maison ("
        "id TEXT PRIMARY KEY,"
        "type TEXT NOT NULL,"
        "standing TEXT NOT NULL,"
        "chambres INTEGER NOT NULL,"
        "toilettes INTEGER NOT NULL,"
        "description TEXT,"
        "photo1 TEXT,"
        "photo2 TEXT,"
        "photo3 TEXT,"
        "photo4 TEXT"
        ")";
    if (!query.exec(requete)) {
        setErreur("Erreur lors de la création de la table: " + query.lastError().text());
        return false;
    }
    return true;
}

bool Database::insererMaison(const Maison& maison)
{
    if (!m_estConnecte) return false;
    QSqlQuery query;
    // Utilisation de INSERT pour éviter l'écrasement. La gestion des doublons se fera au niveau applicatif.
    QString requete =
        "INSERT INTO maison "
        "(id, type, standing, chambres, toilettes, description, photo1, photo2, photo3, photo4) "
        "VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?)";
    query.prepare(requete);
    query.addBindValue(maison.getId());
    query.addBindValue(maison.getType());
    query.addBindValue(maison.getStanding());
    query.addBindValue(maison.getChambres());
    query.addBindValue(maison.getToilettes());
    query.addBindValue(maison.getDescription());
    query.addBindValue(maison.getPhoto1());
    query.addBindValue(maison.getPhoto2());
    query.addBindValue(maison.getPhoto3());
    query.addBindValue(maison.getPhoto4());
    if (!query.exec()) {
        setErreur("Erreur lors de l'insertion: " + query.lastError().text());
        return false;
    }
    return true;
}

bool Database::supprimerMaison(const QString& id)
{
    if (!m_estConnecte) return false;
    QSqlQuery query;
    QString requete = "DELETE FROM maison WHERE id = ?";
    query.prepare(requete);
    query.addBindValue(id);
    if (!query.exec()) {
        setErreur("Erreur lors de la suppression: " + query.lastError().text());
        return false;
    }
    return true;
}

bool Database::chargerDansTable(TableHachage& table)
{
    if (!m_estConnecte) {
        setErreur("Chargement impossible : non connecté à la base de données.");
        return false;
    }
    
    table.vider(); // Vider la table avant de la remplir
    
    QSqlQuery query("SELECT * FROM maison");
    if (!query.exec()) {
        setErreur("Erreur lors du chargement des données: " + query.lastError().text());
        return false;
    }
    
    while (query.next()) {
        Maison* maison = new Maison(
            query.value(0).toString(),
            query.value(1).toString(),
            query.value(2).toString(),
            query.value(3).toInt(),
            query.value(4).toInt(),
            query.value(5).toString(),
            query.value(6).toString(),
            query.value(7).toString(),
            query.value(8).toString(),
            query.value(9).toString()
        );
        table.inserer(maison->getId(), maison);
    }
    return true;
}

bool Database::sauvegarderTable(const TableHachage& table)
{
    if (!m_estConnecte) return false;

    // Début d'une transaction pour assurer l'intégrité
    if (!m_db.transaction()) {
        setErreur("Impossible de démarrer la transaction: " + m_db.lastError().text());
        return false;
    }

    QSqlQuery query;
    if (!query.exec("DELETE FROM maison")) {
        setErreur("Erreur lors de la suppression des anciennes données: " + query.lastError().text());
        m_db.rollback();
        return false;
    }

    for (const auto& id : table.getCles()) {
        Maison* maison = table.get(id);
        if (maison && !insererMaison(*maison)) {
            // L'erreur est déjà définie dans insererMaison
            m_db.rollback();
            return false;
        }
    }

    if (!m_db.commit()) {
        setErreur("Impossible de valider la transaction: " + m_db.lastError().text());
        return false;
    }
    
    return true;
}