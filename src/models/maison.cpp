#include "maison.h"

Maison::Maison()
    : m_chambres(0)
    , m_toilettes(0)
{
}

Maison::Maison(const QString &id, const QString &type, const QString &standing,
               int chambres, int toilettes, const QString &description,
               const QString &photo1, const QString &photo2,
               const QString &photo3, const QString &photo4)
    : m_id(id)
    , m_type(type)
    , m_standing(standing)
    , m_chambres(chambres)
    , m_toilettes(toilettes)
    , m_description(description)
    , m_photo1(photo1)
    , m_photo2(photo2)
    , m_photo3(photo3)
    , m_photo4(photo4)
{
} 