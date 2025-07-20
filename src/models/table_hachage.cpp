#include "table_hachage.h"
#include <QDebug>
#include <cmath>



int f1_hash(const QString &cle, int taille) {
    unsigned int hash = 0;
    for (QChar c : cle) {
        hash += c.unicode();
    }
    return hash % taille;
}


int f2_hash(const QString &cle, int taille) {
    unsigned long long hash = 0;
    const int p = 31;
    for (QChar c : cle) {
        hash = (hash * p + c.unicode());
    }
    return hash % taille;
}


int f3_hash(const QString &cle, int taille) {
    unsigned long hash = 5381;
    for (QChar c : cle) {
        hash = ((hash << 5) + hash) + c.unicode();
    }
    return hash % taille;
}

TableHachage::TableHachage(int taille)
    : m_taille(prochainPremier(taille))
    , m_nombreElements(0)
    , m_nombreCollisions(0)
    , m_fonctionHachage(F1)
{
    m_table = new NoeudMaison*[m_taille];
    for (int i = 0; i < m_taille; ++i) {
        m_table[i] = nullptr;
    }
}

TableHachage::~TableHachage()
{
    vider();
    delete[] m_table;
}

void TableHachage::inserer(const QString &cle, Maison* maison)
{
    if (m_fonctionHachage == SANS_HACHAGE) {

        int index = 0;
        while (index < m_taille && m_table[index] != nullptr) {
            index++;
        }
        if (index < m_taille) {
            m_table[index] = new NoeudMaison(maison);
            m_nombreElements++;
        }
        return;
    }

    int index = calculerHash(cle);
    NoeudMaison* courant = m_table[index];
    

    while (courant != nullptr) {
        if (courant->maison->getId() == cle) {
            delete courant->maison;
            courant->maison = maison;
            return;
        }
        courant = courant->suivant;
    }


    NoeudMaison* nouveau = new NoeudMaison(maison, m_table[index]);
    m_table[index] = nouveau;
    m_nombreElements++;
    

    if (m_table[index]->suivant != nullptr) {
        m_nombreCollisions++;
    }
}

Maison* TableHachage::get(const QString &cle) const
{
    if (m_fonctionHachage == SANS_HACHAGE) {

        for (int i = 0; i < m_taille; ++i) {
            if (m_table[i] != nullptr && m_table[i]->maison->getId() == cle) {
                return m_table[i]->maison;
            }
        }
        return nullptr;
    }

    int index = calculerHash(cle);
    NoeudMaison* courant = m_table[index];
    
    while (courant != nullptr) {
        if (courant->maison->getId() == cle) {
            return courant->maison;
        }
        courant = courant->suivant;
    }
    
    return nullptr;
}

void TableHachage::supprimer(const QString &cle)
{
    if (m_fonctionHachage == SANS_HACHAGE) {

        for (int i = 0; i < m_taille; ++i) {
            if (m_table[i] != nullptr && m_table[i]->maison->getId() == cle) {
                delete m_table[i]->maison;
                delete m_table[i];
                m_table[i] = nullptr;
                m_nombreElements--;
                return;
            }
        }
        return;
    }

    int index = calculerHash(cle);
    NoeudMaison* courant = m_table[index];
    NoeudMaison* precedent = nullptr;
    
    while (courant != nullptr) {
        if (courant->maison->getId() == cle) {
            if (precedent == nullptr) {
                m_table[index] = courant->suivant;
            } else {
                precedent->suivant = courant->suivant;
            }
            delete courant->maison;
            delete courant;
            m_nombreElements--;
            return;
        }
        precedent = courant;
        courant = courant->suivant;
    }
}

bool TableHachage::contient(const QString &cle) const
{
    return get(cle) != nullptr;
}

void TableHachage::setFonctionHachage(FonctionHachageType type)
{
    if (type != m_fonctionHachage) {
        m_fonctionHachage = type;

        // Sauvegarder les pointeurs de maison
        QVector<Maison*> maisons;
        for (int i = 0; i < m_taille; ++i) {
            NoeudMaison* courant = m_table[i];
            while (courant != nullptr) {
                maisons.append(courant->maison);
                courant = courant->suivant;
            }
        }

        // Vider la structure de la table sans supprimer les maisons
        clearStructure();

        // Réinsérer les maisons avec la nouvelle fonction de hachage
        for (Maison* maison : maisons) {
            inserer(maison->getId(), maison);
        }
    }
}

double TableHachage::getTauxOccupation() const
{
    return static_cast<double>(m_nombreElements) / m_taille;
}

QVector<int> TableHachage::getDistributionCollisions() const
{
    QVector<int> distribution(m_taille, 0);
    for (int i = 0; i < m_taille; ++i) {
        int longueur = 0;
        NoeudMaison* courant = m_table[i];
        while (courant != nullptr) {
            longueur++;
            courant = courant->suivant;
        }
        if (longueur > 0) {
            distribution[longueur - 1]++;
        }
    }
    return distribution;
}

void TableHachage::vider()
{
    for (int i = 0; i < m_taille; ++i) {
        libererListe(m_table[i]);
        m_table[i] = nullptr;
    }
    m_nombreElements = 0;
    m_nombreCollisions = 0;
}

void TableHachage::redimensionner(int nouvelleTaille)
{
    nouvelleTaille = prochainPremier(nouvelleTaille);
    if (nouvelleTaille == m_taille) return;

    // Sauvegarder les maisons existantes
    QVector<Maison*> maisons;
    for (int i = 0; i < m_taille; ++i) {
        NoeudMaison* courant = m_table[i];
        while (courant != nullptr) {
            maisons.append(courant->maison);
            courant = courant->suivant;
        }
    }

    // Réinitialiser la table
    vider();
    delete[] m_table;

    // Créer la nouvelle table
    m_taille = nouvelleTaille;
    m_table = new NoeudMaison*[m_taille];
    for (int i = 0; i < m_taille; ++i) {
        m_table[i] = nullptr;
    }

    // Réinsérer les maisons
    for (Maison* maison : maisons) {
        inserer(maison->getId(), maison);
    }
}

int TableHachage::calculerHash(const QString &cle) const
{
    switch (m_fonctionHachage) {
        case F1: return f1_hash(cle, m_taille);
        case F2: return f2_hash(cle, m_taille);
        case F3: return f3_hash(cle, m_taille);
        case SANS_HACHAGE:
        default:
            return 0; // L'index n'est pas utilisé de la même manière pour SANS_HACHAGE
    }
}

QVector<QString> TableHachage::getCles() const
{
    QVector<QString> cles;
    for (int i = 0; i < m_taille; ++i) {
        NoeudMaison* courant = m_table[i];
        while (courant != nullptr) {
            cles.append(courant->maison->getId());
            courant = courant->suivant;
        }
    }
    return cles;
}

void TableHachage::libererListe(NoeudMaison* liste)
{
    while (liste != nullptr) {
        NoeudMaison* suivant = liste->suivant;
        delete liste->maison; // La table est propriétaire des maisons
        delete liste;
        liste = suivant;
    }
}

void TableHachage::clearStructure()
{
    for (int i = 0; i < m_taille; ++i) {
        NoeudMaison* courant = m_table[i];
        while (courant != nullptr) {
            NoeudMaison* suivant = courant->suivant;
            delete courant; // Supprime seulement le noeud, pas la maison
            courant = suivant;
        }
        m_table[i] = nullptr;
    }
    m_nombreElements = 0;
    m_nombreCollisions = 0;
}

bool TableHachage::estPremier(int n) const
{
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;

    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) return false;
    }
    return true;
}

int TableHachage::prochainPremier(int n) const
{
    if (n <= 1) return 2;
    int premier = n;
    bool trouve = false;
    while (!trouve) {
        premier++;
        if (estPremier(premier)) trouve = true;
    }
    return premier;
}

 
