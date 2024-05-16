#include "Map.h"

#include <cassert>

#include <iostream>


Map::Map()
{
    posx = 0;
    posy = 0;
    longueur = 700;
    largeur = 600;
}

Map::Map(unsigned int x, unsigned int y)
{
    posx = 0;
    posy = 0;
    longueur = x;
    largeur = y;
}

Map::Map(unsigned int posix, unsigned int posiy,unsigned int x, unsigned int y)
{
    posx = posix;
    posy = posiy;
    longueur = x;
    largeur = y;
}
unsigned int Map::getPosx() const
{
    return posx;
}

unsigned int Map::getPosy() const
{
    return posy;
}

unsigned int Map::getLargeur() const
{
    return largeur;
}

unsigned int Map::getLongueur() const
{
    return longueur;
}

void Map::testRegression() {
    Map defaultMap;
    assert(defaultMap.getPosx() == 0);
    assert(defaultMap.getPosy() == 0);
    assert(defaultMap.getLargeur() == 600);
    assert(defaultMap.getLongueur() == 700);

    Map customMap(100, 200);
    assert(customMap.getPosx() == 0);
    assert(customMap.getPosy() == 0);
    assert(customMap.getLargeur() == 200);
    assert(customMap.getLongueur() == 100);

    Map customMap2(5, 10, 100, 200);
    assert(customMap2.getPosx() == 5);
    assert(customMap2.getPosy() == 10);
    assert(customMap2.getLargeur() == 200);
    assert(customMap2.getLongueur() == 100);

    //std:://cout<<"Tests passés avec succès"<<std::endl;

}