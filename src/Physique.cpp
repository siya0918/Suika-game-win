#include "Physique.h"
#include "Fruit.h"
#include "Map.h"
#include <chrono>
#include <thread>
#include <vector>
#include <cassert>
#include <iostream>

Physique::Physique(float g, float delta)
{
    gravity = g; dt = delta;
}

/*--------------Horloge--------------*/

void Physique::setClock()
{
    t0 = time(NULL);
}

void Physique::waitDeltatime()
{
    double elapsedtime = difftime(time(NULL), t0);
    if ((double)dt > elapsedtime)
    {
        std::chrono::microseconds sleep_duration(static_cast<long long>((dt - elapsedtime) * 1000000.));
        std::this_thread::sleep_for(sleep_duration);
    }
}

/*--------------Collision Fruit/Cadre--------------*/

bool Physique::checkColisionMapGauche(const Map& map, Fruit& fruit) const
{
    return (float)map.getPosx() + fruit.getRayon() > fruit.pos.x;
}

bool Physique::checkColisionMapDroit(const Map& map, Fruit& fruit) const
{
    return (float)map.getPosx() + map.getLongueur() - fruit.pos.x < fruit.getRayon();
}

void Physique::updateColisionMapX(const Map& map, Fruit& fruit)
{
    if (checkColisionMapGauche(map, fruit))
    {
        //   //cout<<"touché à gauche par le fruit "<<fruit.getName()<<"à la pos ( "<<fruit.pos.x<<','<<fruit.pos.y<<" )" <<endl;
        fruit.vitesse.x = 0.;
        fruit.pos.x = (float)map.getPosx() + fruit.getRayon();
    }
    if (checkColisionMapDroit(map, fruit))
    {
        ////cout<<"touché droit par le fruit "<<fruit.getName()<<"à la pos ( "<<fruit.pos.x<<','<<fruit.pos.y<<" )" <<endl;
        fruit.vitesse.x = 0.;
        fruit.pos.x = (float)map.getPosx() + map.getLongueur() - fruit.getRayon();
    }
}

bool Physique::checkColisionMapY(const Map& map, Fruit& fruit) const
{
    return map.getPosy() + (float)map.getLargeur() - fruit.pos.y < fruit.getRayon();
}

void Physique::updateColisionMapY(const Map& map, Fruit& fruit)
{
    if (checkColisionMapY(map, fruit))
    {
        fruit.vitesse.y = 0.;
        fruit.pos.y = map.getPosy() + map.getLargeur() - fruit.getRayon();
    }

}

/*--------------Collision Fruit/Fruit--------------*/

bool Physique::checkColisionFruit(const Fruit& fruit_1, const Fruit& fruit_2) const
{
    Vec2D dist = fruit_1.pos - fruit_2.pos;
    return dist.norm() < fruit_1.getRayon() + fruit_2.getRayon();
}


void Physique::upadateColisionFruit(Fruit& fruit_1, Fruit& fruit_2)
{
    Vec2D v1 = fruit_1.vitesse;
    Vec2D v2 = fruit_2.vitesse;

    float m1 = fruit_1.getMasse();
    float m2 = fruit_2.getMasse();
    float r1 = fruit_1.getRayon();
    float r2 = fruit_2.getRayon();

    float dist = (fruit_1.pos - fruit_2.pos).norm();

    // Calcul de la base Orthonormée (n,t)
    // n est normal au plan de collision, t est tangent
    Vec2D n = (fruit_2.pos - fruit_1.pos) * (1 / dist);
    Vec2D t(-n.y, n.x);

    // Calcul des vitesse dans cette base
    float v1n = v1.dotProduct(n);
    float v1t = v1.dotProduct(t);
    float v2n = v2.dotProduct(n);
    float v2t = v2.dotProduct(t);

    // Calcul des nouvelles vitesses après la collision (collision élastique)
    float v1nNew = ((m1 - m2) * v1n + 2 * m2 * v2n) / (m1 + m2);
    float v2nNew = ((m2 - m1) * v2n + 2 * m1 * v1n) / (m1 + m2);

    // Mise à jour des vitesses
    fruit_1.vitesse = t * v1t + n * v1nNew * 0.8;
    fruit_2.vitesse = t * v2t + n * v2nNew * 0.8;


    // On place ensuite les fruits de sorte qu'ils sont plus l'un dans l'autre
    while (dist < r1 + r2)
    {
        fruit_1.pos = fruit_1.pos - n * 0.01;
        fruit_2.pos = fruit_2.pos + n * 0.01;
        dist = (fruit_1.pos - fruit_2.pos).norm();
    }


}

/*--------------Mise à Jour Vitesse/Position--------------*/

void Physique::updateVitesse(Fruit& fruit)
{
    fruit.vitesse = Vec2D(0, gravity * dt) + fruit.vitesse;
}

void Physique::updatePosition(Fruit& fruit)
{
    fruit.pos = fruit.vitesse * dt + fruit.pos;
}



void Physique::testRegression() {
    const float DT = 1. / 60.;
    Fruit b(Mandarine, false, Vec2D(300, 0), Vec2D(0, 100), Vec2D(0, 0));
    vector<Fruit> tabFruit;
    tabFruit.push_back(b);
    Map map;
    Physique physique(1000., DT);
    double temps_actu = 0.;

    while (temps_actu < 2.)
    {
        physique.setClock();

        physique.updateVitesse(tabFruit[0]);
        physique.updatePosition(tabFruit[0]);

        physique.updateColisionMapX(map, tabFruit[0]);
        physique.updateColisionMapY(map, tabFruit[0]);

        //std:://cout << "b est en : " << tabFruit[0].pos;
        physique.waitDeltatime();
        temps_actu += DT;
        //std:://cout << " en t = " << temps_actu << std::endl;
    }

    Fruit c(Poire, false, Vec2D(299, 0), Vec2D(0, 100), Vec2D(0, 0));
    tabFruit.push_back(c);

    while (temps_actu < 5.)
    {
        physique.setClock();

        for (size_t i = 0; i < tabFruit.size(); ++i)
        {
            for (size_t j = 0; j < tabFruit.size(); ++j)
            {
                if (i == j) { continue; }
                else
                {
                    if (physique.checkColisionFruit(tabFruit[i], tabFruit[j]))
                    {
                        physique.upadateColisionFruit(tabFruit[i], tabFruit[j]);
                    }
                }
            }

            physique.updateVitesse(tabFruit[i]);
            physique.updatePosition(tabFruit[i]);

            physique.updateColisionMapX(map, tabFruit[i]);
            physique.updateColisionMapY(map, tabFruit[i]);

            //std:://cout << "Fruit[" << i << "] est en : " << tabFruit[i].pos << std::endl;
        }

        physique.waitDeltatime();
        temps_actu += DT;
        //std:://cout << "Temps actuel : " << temps_actu << std::endl;
    }
    assert(tabFruit[0].pos.x - 358.391 < 1 && tabFruit[0].pos.x - 543 < 1);
    assert(tabFruit[1].pos.x - 117 < 1 && tabFruit[1].pos.x - 483 < 1);
    //std:://cout << "Tests passés avec succès" << std::endl;
}