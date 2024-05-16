#ifndef _FRUIT_H
#define _FRUIT_H
#include <iostream>
#include <string>
#include "Vec2D.h"

using namespace std;


/**
 * @file Fruit.h
 * @brief Énumration de types de fruit
 */

/**
 * @brief Les fruits ont des valeurs définies (Myrtille, Cersie, Citron...)
 */
enum typeFruit {
    Myrtille = 1,
    Cerise = 2,
    Fraise = 3,
    Mandarine = 4,
    Orange = 5,
    Pomme = 6,
    Peche = 7,
    Poire = 8,
    Melon = 9,
    Ananas = 10,
    Pasteque = 11
};

/**
* @brief Classe Fruit
* 
* Initialise un fruit avec un rayon (r), une position (pos), une vitesse (vitesse) et un booléen pour savoir si le fruit en question est actif ou non (control).
*/
class Fruit {
private:
    typeFruit type; ///< Type du fruit en constante
    float r; ///< Rayon du fruit
    float masse; ///< Masse du fruit

public:
    Vec2D pos; ///< Vecteur de position du fruit dans le bac à fruits
    Vec2D vitesse; ///< Vecteur de vitesse du fruit en mouvement
    Vec2D acceleration; ///< Vecteur d'accélération du fruit en mouvement
    bool control; ///< Controle pour savoir si le fruit en question est controllable ou s'il est dans le bac à fruits

    /**
     * @brief Constructeur
     * 
     * 
    */
    Fruit();

    /**
     * @brief Constructeur avec parametre
     * @param Fruit Type du fruit
     * @param controlable Controle pour savoir si le fruit en question est controllable ou s'il est dans le bac à fruits
     * @param position Vecteur de position du fruit dans le bac à fruits
     * @param vit Vecteur de vitesse du fruit en mouvement
     * @param accel Vecteur d'accélération du fruit en mouvement
     * 
    */
    Fruit(typeFruit Fruit, bool controlable, const Vec2D& position, const Vec2D& vit, const Vec2D& accel);

    /**
     * @brief Destructeur
     * 
     * 
    */
    ~Fruit();

    /**
     * @brief Fonction d'obtention du rayon du fruit
     * 
     * 
    */
    float getRayon() const;

    /**
     * @brief Fonction d'obtention de la masse du fruit
     * 
     * 
    */
    float getMasse() const;

    /**
     * @brief Fonction d'obtention du controle. Le fruit est-il controlable ? True/False
     * 
     * 
    */
     bool getControl() const;
    
    /**
     * @brief Fonction d'obtention du type du fruit (MMyrtille, Cersie, Citron...)
     * 
     * 
    */
     typeFruit getType()const;

    /**
     * @brief Fonction d'obtention nom (Myrtille, Cersie, Citron...)
     * 
     * 
    */
     string getName() const;


    /**
     * @brief Fonction pour choisir aléatoirement un fruit
     * 
     * 
    */
    void setRandomFruit();


    /**
     * @brief Fonction pour choisir un nombre aléatoire entre 1 et le paramètre
     * 
     * @param max Valeur maximale
    */
    int randomNumber(int max);

    /**
     * @brief Test de régression pour s'assurer du bon fonctionnement de la classe Fruit
     * 
     * 
    */
    static void testRegression();


};
#endif