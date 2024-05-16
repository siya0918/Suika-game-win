#ifndef GESTIONSDL_H
#define GESTIONSDL_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <vector>
#include <iostream>
#include "Image.h"
#include "Texte.h"
#include "entreeClavier.h"
#include "../Jeu.h"

/**
 * @file gestionSDL.h
 * @brief La classe gérant le jeu avec un affichage SDL.
 */

/**
 * @class gestionSDL
 * @brief La classe gérant le jeu avec un affichage SDL.
 */
class gestionSDL {
private:
    SDL_Window* m_window; ///< Fenêtre SDL
    SDL_Renderer* m_renderer; ///< Renderer SDL
    SDL_Surface* m_surface; ///< Surface SDL
    SDL_Texture* m_texture; ///< Texture SDL
    SDL_Surface* icon; ///< Icon SDL
    std::vector<Fruit> fruitsSDL; ///< Stocke les inforamtions des 12 fruits(img ou txt)

    Image m_imagefruit[12]; ///< Images des fruits 
    
    Image fond; ///< Image de fond

    Texte winorlose; ///< Objet Texte pour gérer l'affichage du texte lors de gain ou la perte
    Texte tdepass; ///< Objet Texte pour gérer l'affichage du timer de dépassement de fruit(celle qui est centre en grand)
    Texte t_texte[12]; ///< Tableau d'objets Texte pour gérer l'affichage de divers textes
    Texte t_nomfruit[12]; ///< Tableau d'objets Texte pour gérer l'affichage des noms de fruits
    Texte t_pointfruit[12]; ///< Tableau d'objets Texte pour gérer l'affichage des points des fruits
    Texte nomfruitactuel; ///< Objet Texte pour gérer l'affichage du nom du fruit actuel
    Texte nomfruitnext; ///< Objet Texte pour gérer l'affichage du nom du prochain fruit
    Texte Statistique[12]; ///< Tableau d'objets Texte pour gérer l'affichage des statistiques

    entreeClavier clavier; ///< Gestionnaire des touches

    Jeu jeu; ///< Instance du jeu
    SDL_Event e; ///< Événement SDL

public:
    /**
     * @brief Constructeur de la classe gestionSDL.
     * 
     * Initialise tout SDL2 et crée la fenêtre et le renderer.
     */
    gestionSDL();

    /**
     * @brief Destructeur de la classe gestionSDL.
     * 
     * Détruit et ferme SDL2.
     */
    ~gestionSDL();

    /**
     * @brief Charge une image depuis un fichier et l'assigne à un objet Image.
     * 
     * @param name Nom du fichier de l'image
     * @param im Référence vers l'objet Image
     */
    void getImage(std::string name,Image& im);

    /**
     * @brief Charge les images à afficher dans le jeu.
     */
    void gestionImage();

    /**
     * @brief Charge les images statiques à afficher dans le jeu.
     */
    void gestionImageStat();

    /**
     * @brief Génère le texte à afficher dans le jeu.
     */
    void gestionText();

    /**
     * @brief Génère le texte statique à afficher dans le jeu.
     */
    void gestionTextStat();

    /**
     * @brief Gère les entrées clavier pour contrôler le jeu.
     */
    void gestionTouches();

     /**
     * @brief Gère les entrées clavier pour contrôler le jeu.
     */
    void gestionmodeSDL();



    /**
     * @brief Initialise les paramètres du jeu, y compris l'affichage initial.
     */
    void init();

    /**
     * @brief Affiche les éléments du jeu dans la fenêtre.
     */
    void afficher();

    /**
     * @brief Affiche l'écran de fin de jeu lorsque le joueur termine.
     */
    void affichergameover();

    /**
     * @brief Actualise les éléments affichés en fonction des actions du joueur.
     */
    void update();

};

#endif  // GESTIONSDL_H
