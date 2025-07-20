#ifndef MAISON_H
#define MAISON_H

#include <QString>

class Maison
{

public:
    Maison(); // Constructeur par défaut
    Maison(const QString& id, const QString& type, const QString& standing,
           int chambres, int toilettes, const QString& description,
           const QString& photo1, const QString& photo2, const QString& photo3, const QString& photo4);

    // Getters
    QString getId() const { return m_id; }
    QString getType() const { return m_type; }
    QString getStanding() const { return m_standing; }
    int getChambres() const { return m_chambres; }
    int getToilettes() const { return m_toilettes; }
    QString getDescription() const { return m_description; }
    QString getPhoto1() const { return m_photo1; }
    QString getPhoto2() const { return m_photo2; }
    QString getPhoto3() const { return m_photo3; }
    QString getPhoto4() const { return m_photo4; }

    // Setters
    void setId(const QString &id) { m_id = id; }
    void setType(const QString &type) { m_type = type; }
    void setStanding(const QString &standing) { m_standing = standing; }
    void setChambres(int chambres) { m_chambres = chambres; }
    void setToilettes(int toilettes) { m_toilettes = toilettes; }
    void setDescription(const QString &description) { m_description = description; }
    void setPhoto1(const QString &chemin) { m_photo1 = chemin; }
    void setPhoto2(const QString &chemin) { m_photo2 = chemin; }
    void setPhoto3(const QString &chemin) { m_photo3 = chemin; }
    void setPhoto4(const QString &chemin) { m_photo4 = chemin; }

    // Opérateurs
    bool operator==(const Maison &other) const { return m_id == other.m_id; }
    bool operator!=(const Maison &other) const { return !(*this == other); }

private:
    QString m_id;          // Clé primaire
    QString m_type;        // Type de maison (appartement, villa, etc.)
    QString m_standing;    // Standing (luxe, moyen, etc.)
    int m_chambres;        // Nombre de chambres
    int m_toilettes;       // Nombre de toilettes
    QString m_description; // Description détaillée
    QString m_photo1;      // Photo intérieure 1
    QString m_photo2;      // Photo intérieure 2
    QString m_photo3;      // Photo extérieure 1
    QString m_photo4;      // Photo extérieure 2
};

#endif // MAISON_H 