#ifndef _PHYSIQUE_H
#define _PHYSIQUE_H

#include <time.h>
#include "Fruit.h"
#include "Map.h"

/**
 * @class Physique
 * @file Physique.h
 * @brief Permet de faire d'appliquer sur les fruits tous les calculs des
 * divers événements physique
*/

/**
 * @brief Classe pour gérer la physique
*/
class Physique
{
    public:

        /**
         * @brief Constructeur avec paramètre de physique
         * 
         * @param g Accélération de la pensenteur (en px/s²) | float
         * @param delta Intervalle entre chaque update de la physique (en s)
        */
        Physique(float g, float delta);


        /**
         * @brief Met à jour t0 à l'instant où la boucle commence une itération
        */
        void setClock();

        /**
         * @brief Met en pause l'éxécution du programme
         * tant que le temps d'éxécution de l'itération
         * est inférieur à dt 
        */
        void waitDeltatime();


        /**
         * @brief Vérifie si un fruit est en colision
         * avec le coté gauche du cadre
         * 
         * @param map Cadre du jeu | Map&
         * @param fruit fruit sur lequel on veut vérif la collision | Fruit&
         * 
         * @return true si il y a une collision, false sinon | bool
        */
        bool checkColisionMapGauche(const Map& map, Fruit& fruit) const;

        /**
         * @brief Vérifie si un fruit est en colision
         * avec le coté droit du cadre
         * 
         * @param map Cadre du jeu | Map&
         * @param fruit fruit sur lequel on veut vérif la collision | Fruit&
         * 
         * @return true si il y a une collision, false sinon | bool
        */
        bool checkColisionMapDroit(const Map& map, Fruit& fruit) const;

        /**
         * @brief Met à jour la vitesse/position d'un fruit après une collision
         * avec les cotés de la map
         * 
         * @param map Cadre du jeu | Map&
         * @param fruit fruit sur lequel on veut vérif la collision | Fruit&
         * 
         * @return true si il y a une collision, false sinon | bool
        */
        void updateColisionMapX(const Map& map, Fruit& fruit);

        /**
         * @brief Vérifie si un fruit est en colision avec
         * le bas du cadre 
         * 
         * @param map Cadre du jeu | Map&
         * @param fruit fruit sur lequel on veut vérif la collision | Fruit&
         * 
         * @return true si il y a une collision, false sinon | bool
        */
        bool checkColisionMapY(const Map& map, Fruit& fruit) const ;

        /**
         * @brief Met à jour la vitesse/position d'un fruit après une collision
         * avec le bas de la map
         * 
         * @param map Cadre du jeu | Map&
         * @param fruit fruit que l'on veut mettre à jour | Fruit&
        */
        void updateColisionMapY(const Map& map, Fruit& fruit);


        /**
         * @brief Vérifie si un fruit est en colision avec
         * un autre
         * 
         * @param fruit_1 1er fruit | Fruit&
         * @param fruit_2 2eme fruit | Fruit&
         * 
         * @return true si il a une collision, false sinon | bool
        */
        bool checkColisionFruit(const Fruit& fruit_1,const Fruit& fruit_2) const;

        /**
         * @brief Met à jour la vitesse/position de deux fruits après une collision
         * 
         * @param fruit_1 1er fruit | Fruit&
         * @param fruit_2 2eme fruit | Fruit&
        */
        void upadateColisionFruit(Fruit& fruit_1, Fruit& fruit_2);


        /**
         * @brief Calcul la vitesse d'un fruit à l'instant t+dt
         * 
         * @param fruit Fruit sur lequel on souhaite mettre à
         * jour sa vitesse | Fruit&
        */
        void updateVitesse(Fruit& fruit);

        /**
         * @brief Calcul la position d'un fruit à l'instant t+dt 
         * 
         * @param Fruit Fruit sur lequel on souhaite mettre à
         * jour sa position | Fruit&
        */
       void updatePosition(Fruit& Fruit);

        /**
         * @brief Test de régression pour s'assurer du bon fonctionnement de la classe Physique
         * 
         * 
        */
        static void testRegression();

    private:

        float gravity; ///< Accélération de la pensenteur (en px/s²)
        float dt; ///< intervalle de temps entre chaque update de la physique (en s)
        time_t t0; ///< Temps du début de la boucle d'éxécution (en s)

};


#endif