#ifndef FONCTION_HACHAGE_H
#define FONCTION_HACHAGE_H

#include <QString>
#include <QVector>

class FonctionHachage
{
public:

    static int f1(const QString &cle, int taille);


    static int f2(const QString &cle, int taille);


    static int f3(const QString &cle, int taille);


    static QVector<int> calculerCollisions(const QString &cle, int taille);

private:

    static const int PRIME = 31;
    static const int MULTIPLIER = 33;
};

#endif // FONCTION_HACHAGE_H 
