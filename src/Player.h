#ifndef _PLAYER_H
#define _PLAYER_H

#include <string>


using namespace std;
/**
 * @file Player.h
 * @brief Définition de la classe joueur pour sauvegarde/charge le record
 */

/**
 * @brief Classe pour gérer le joueur
 */
#include <iostream>
#include <string>

class Player {
    private :
    unsigned int record; ///< Record du joueur en entier non signé
    string recordFile; ///< fichier dans on sauvgarde/recup le record
public:
    
    unsigned int score;///< Score du joueur en entier non signé
    

    /**
     * @brief Constructeur sans paramètre.
     * 
     * Initialise le record à 0 et nomme le joueur.
    */
    Player();

    /**
     * @brief Destructeur.
     * 
     * Libère les ressources allouées.
    */
    ~Player();

    /**
     * @brief Recupere le record
     * 
     * 
    */
    unsigned int getrecord();

    /**
     * @brief Affiche les informations du joueur dans la console.
    */
    void afficherConsole() const;


    /**
     * @brief Sauvegarde le record dans un fichier
    */
    void saveRecord(unsigned int rec);

    /**
     * @brief Sauvegarde le record dans un fichier
    */
    void loadRecord();

    /**
     * @brief Effectue une série de tests vérifiant que toutes les fonctions fonctionnent correctement.
    */
    static void testRegression();
};




#endif
