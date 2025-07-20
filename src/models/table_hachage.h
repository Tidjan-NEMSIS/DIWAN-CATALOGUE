#ifndef TABLE_HACHAGE_H
#define TABLE_HACHAGE_H

#include <QVector>
#include <QString>
#include "maison.h"
#include "fonction_hachage.h"


struct NoeudMaison {
    Maison* maison;
    NoeudMaison* suivant;
    
    NoeudMaison(Maison* m = nullptr, NoeudMaison* s = nullptr)
        : maison(m), suivant(s) {}
};

class TableHachage
{
public:
    explicit TableHachage(int taille = 1000);
    ~TableHachage();


    void inserer(const QString &cle, Maison* maison);
    Maison* get(const QString &cle) const;
    void supprimer(const QString &cle);
    bool contient(const QString &cle) const;
    int size() const { return m_nombreElements; }
    bool estVide() const { return m_nombreElements == 0; }


    enum FonctionHachageType { F1, F2, F3, SANS_HACHAGE };
    void setFonctionHachage(FonctionHachageType type);
    FonctionHachageType getFonctionHachage() const { return m_fonctionHachage; }


    int getNombreCollisions() const { return m_nombreCollisions; }
    double getTauxOccupation() const;
    QVector<int> getDistributionCollisions() const;

    void vider();
    void redimensionner(int nouvelleTaille);

    QVector<QString> getCles() const;

private:
    NoeudMaison** m_table;
    int m_taille;
    int m_nombreElements;
    int m_nombreCollisions;
    FonctionHachageType m_fonctionHachage;


    int calculerHash(const QString &cle) const;
    void libererListe(NoeudMaison* liste);
    void clearStructure();
    bool estPremier(int n) const;
    int prochainPremier(int n) const;
};

#endif // TABLE_HACHAGE_H
