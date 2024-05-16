#include "Vec2D.h"
#include <math.h>
#include <assert.h>

Vec2D::Vec2D(float x1, float y1)
{
    x = x1; y = y1;
}


const Vec2D Vec2D::operator+(const Vec2D& vecdroite) const
{
    return Vec2D(x + vecdroite.x, y + vecdroite.y);
}

const Vec2D Vec2D::operator-(const Vec2D& vecdroite) const
{
    return Vec2D(x - vecdroite.x, y - vecdroite.y);
}

const Vec2D Vec2D::operator*(float u) const
{
    return Vec2D(u*x, u*y);
}

bool Vec2D::operator== (const Vec2D& vecdroite) const
{
    return (x == vecdroite.x && y == vecdroite.y);
}

std::ostream& operator<< (std::ostream& flux, const Vec2D& v)
{
    flux << "(" << v.x << ";" << v.y << ")";
    return flux;
}


float Vec2D::norm() const
{
    return sqrt(x*x + y*y);
}

float Vec2D::dotProduct(const Vec2D& vecdroite) const
{
    return x*vecdroite.x + y*vecdroite.y;
}

void Vec2D::testRegression()
{
    Vec2D v1;
    assert(v1.x == 0 && v1.y == 0); //test constructeur par defaut

    Vec2D v2(3,4);
    assert(v2.x == 3 && v2.y == 4); //test constructeur avec parametre

    Vec2D v3(1,1);
    Vec2D v4 = v2 + v3;
    assert(v4.x == 4 && v4.y == 5); //test operateur +

    Vec2D v5 = v2 - v3;
    assert(v5.x == 2 && v5.y == 3); //test operateur -

    Vec2D v6 = v3 * 6.;
    assert(v6.x == 6 && v6.y == 6); //test operateur *

    Vec2D v3second(1,1);
    assert(v3 == v3second); //test operateur ==

    float normev2 = v2.norm();
    assert(normev2 == 5); //test fonction norm

    //std:://cout << "affichage du vecteur v2 : " << v2 << std::endl;

    //std:://cout << "Tests passés avec succès." << std::endl;

}