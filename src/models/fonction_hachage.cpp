#include "fonction_hachage.h"

int FonctionHachage::f1(const QString &cle, int taille)
{
    int hash = 0;
    for (const QChar &c : cle) {
        hash += c.unicode();
    }
    return hash % taille;
}

int FonctionHachage::f2(const QString &cle, int taille)
{
    int hash = 0;
    for (const QChar &c : cle) {
        hash = (hash * MULTIPLIER + c.unicode()) % taille;
    }
    return hash;
}

int FonctionHachage::f3(const QString &cle, int taille)
{
    int hash = 0;
    int power = 1;
    
    for (const QChar &c : cle) {
        hash = (hash + c.unicode() * power) % taille;
        power = (power * PRIME) % taille;
    }
    
    return hash;
}

QVector<int> FonctionHachage::calculerCollisions(const QString &cle, int taille)
{
    QVector<int> collisions(3);
    collisions[0] = f1(cle, taille);
    collisions[1] = f2(cle, taille);
    collisions[2] = f3(cle, taille);
    return collisions;
}
