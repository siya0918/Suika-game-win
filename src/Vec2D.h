#ifndef _VEC2D_H
#define _VEC2D_H

#include <iostream>

/**
 * @class Vec2D
 * @file Vec2D.h
 * @brief Représente un vecteur à deux dimension
 */

/**
 * @brief Classe pour Vecteur 2D
 */
class Vec2D
{
    public:
        
        float x,y; ///< Coordonée d'un vecteur en deux dimensions.

        /**
         * @brief Constructeur par défaut de Vec2D.
         * 
         * Initialise les coordonées (x,y) à (0,0).
        */
        Vec2D() : x(0), y(0) {};

        /**
         * @brief Constructeur avec paramètres de Vec2D
         * 
         * @param x Coordonnée en x | float
         * @param y Coordonnée en y | float
         * 
         * Initialise un Vec2D avec les coordonées précisé
        */
        Vec2D(float x1, float y1);


        const Vec2D operator+ (const Vec2D& vecdroite) const;

        const Vec2D operator- (const Vec2D& vecdroite) const;

        const Vec2D operator* (float u) const;

        bool operator== (const Vec2D& vecdroite) const;

        friend std::ostream& operator<< (std::ostream& flux, const Vec2D& v);

        /**
         * @return La norme euclidienne d'un Vec2D
        */
        float norm() const;

        /**
         * @param vecdroite Deuxième vecteur | Vec2D&
         * 
         * @return Le produit scalaire entre le vecteur de la
         * classe et le vecteur en paramètre
        */
        float dotProduct(const Vec2D& vecdroite) const;
        
        static void testRegression();
        



        
};




#endif