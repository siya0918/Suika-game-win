#ifndef JEU_H
#define JEU_H

#include <vector>
#include <iostream>
#include "Fruit.h"
#include "Map.h"
#include "Temps.h"
#include "Player.h"
#include "Physique.h"

/**
 * @file Jeu.h
 * @brief La classe gérant le déroulement d'une partie.
 */

/**
 * @brief La classe gérant le déroulement d'une partie.
 */
class Jeu {
private:
    unsigned int nbfruittotalSTAT; ///< Nombre total de fruits pour le statsique de jeu
    unsigned int nbfruitfuisonSTAT; ///< Nombre de fruits fusionnés pour le statsique de jeu
    string dernierfruitSTAT; ///< Dernier fruit fusionné pour le statsique de jeu
    int typefruithautsSTAT; ///< Type du fruit en haut de la pile
    bool peutlancer; ///< Indique si le joueur peut lancer un nouveau fruit
    unsigned int multiplicateurmodechoas; ///< Multiplicateur pour le mode chaos
    bool win; ///<si oui, le jeu peut terminer et le joueur gagne.
    float movefruit; ///< Vitesse de déplacement des objets en x

public:
    Player play; ///< Instance de la classe Joueur
    Map map; ///< Récipient de jeu avec ses dimensions
    Map mapr; ///< Map avec les rapports d'écran actuels et le récipient
    Fruit fruitActuel; ///< Fruit actuel
    Fruit fruitnext; ///< Prochain fruit
    std::vector<Fruit> fruits; ///< Tableau des fruits présents dans le récipient
    std::string txt[5]; ///< tableau des Texte à afficher
    Temps t; ///< Temps
    Temps tgameovedepassement; ///< Temps de qui se déclanche dés la dépassement de ligne
    Temps tlache; ///< Temps nécessaire pour le lancer le fruit actuel
   
    bool keyd; ///< Si la touche "d" est activée
    bool keyq; ///< Si la touche "q" est activée
    bool keyspace; ///< Si la touche "SPACE" est activée
    bool keyo; ///< Si la touche "o" est activée
    Physique ph; ///< Gestionnaire de physique
    bool GameOver; ///< Si le jeu est terminé
    unsigned int modejeu; ///< Mode de jeu (normal, chaos, etc.)

    /**
     * @brief Constructeur de la classe Jeu.
     * 
     * Initialise les éléments nécessaires pour le jeu.
     */
    Jeu();

    /**
     * @brief Destructeur de la classe Jeu.
     * 
     * Nettoie les ressources utilisées par le jeu.
     */
    ~Jeu();

    /**
     * @brief ajoute une fruit dans le recipiant,gerer le temps de lancement et bloqué le fruit actuel dans le récipiant.
     * 
     * 
     */
    void gestionFruit();

    /**
     * @brief Initialise le mode de jeu.
     * 
     * 
     */
    void gestionmode();

    /**
     * @brief Génère le texte à afficher dans le jeu.
     * 
     * 
     */
    void gestionText();
    

    /**
     * @brief Gère les aspects physiques du jeu.
     * 
     * 
     */
    void gestionphysique(std::vector<Fruit>& tabfruit,const Map& m);

    /**
     * @brief Gère les entrées clavier pour contrôler le jeu.
     * 
     * 
     */
    void gestionTouches();

    /**
     * @brief Vérifie si un des fruits a dépassé la limite.
     * 
     * 
     */
    bool depassementFruit(const vector<Fruit>& tabfruit,const Map& m) const ;

    /**
     * @brief la fin de jeu est due au dépassement de la limite et le gestion de timer de gameoverd.
     * 
     * 
     */
    void gameoverdepassement();

    /**
     * @brief Vérifie si un de fruit est la pastéque.
     * 
     * 
     */
    void gameoverwin(const vector<Fruit>& tabfruit);

    /**
     * @brief Récupère les statistiques du jeu.
     * 
     * 
     */
    void getStat (const vector < Fruit >& tabfruit,unsigned int& nbfruittotal, unsigned int& nbfruitfuison, string& lastfruit);
    /**
     * @brief Récupère win
     * 
     * 
     */
    bool getwin() const;

    /**
     * @brief Test de régression pour s'assurer du bon fonctionnement de la classe Jeu.
     * 
     * 
     */
    static void testRegression();
};

#endif  // JEU_H
