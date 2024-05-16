#ifndef _MAP_H
#define _MAP_H

/**
 * @class Map
 * @file Map.h
 * @brief Représente le cadre du conteneur des fruits
*/

/**
 * @brief Classe pour gérer la cadre de jeu
*/
class Map
{
    public:

        /**
         * @brief Constructeur par défaut de Map
         * 
         * Initialise un cadre de taille 600x700
        */
        Map();

        /**
         * @brief Constructeur avec parametre de Map
         * 
         * @param x longueur du cadre | unsigned int
         * @param y largeur du cadre | unsigned int
         * 
         * Initialise un cadre de taille choisi
        */
        Map(unsigned int x, unsigned int y);

        /**
         * @brief Constructeur avec parametre de Map
         * 
         * @param posix position x du cadre | unsigned int
         * @param posiy position y du cadre | unsigned int
         * @param x longueur du cadre | unsigned int
         * @param y largeur du cadre | unsigned int
        */
        Map(unsigned int posix, unsigned int posiy, unsigned int x, unsigned int y);

        /**
         * @return la position x | unsigned int
        */
        unsigned int getPosx() const;

        /**
         * @return la position y | unsigned int
        */
        unsigned int getPosy() const;

        /**
         * @return longueur du cadre | unsigned int
        */
        unsigned int getLongueur() const;

        /**
         * @return largeur du cadre | unsigned int
        */
        unsigned int getLargeur() const;


        /**
         * @brief Test de régression pour s'assurer du bon fonctionnement de la classe Map
         * 
         * 
        */
        static void testRegression();

    private:
    
        unsigned int longueur, largeur, posx, posy; ///< Taille et position du cadre
};

#endif