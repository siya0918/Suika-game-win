#include "../../lib/dev/vcpkg/packages/sdl2_x64-windows/include/SDL2/SDL.h"

#include <iostream>
using namespace std;

/**
 * @file entreeClavier.h
 * @brief Classe pour gérer les entrées au clavier, notamment les mouvements à gauche (q), à droite (d) et lâcher le fruit (Space)
 */

/**
* @brief Classe pour gérer les entrées au clavier, notamment les mouvements à gauche (q), à droite (d) et lâcher le fruit (Space)
 */
class entreeClavier {

private:
    SDL_Window* window; ///< Pointeur vers la fenêtre SDL
    SDL_Renderer* renderer; ///< Pointeur vers le renderer SDL
    bool running = true; ///< Indique si le programme est en cours d'exécution
    bool keys[SDL_NUM_SCANCODES] = {false}; ///< Tableau de booléens pour stocker l'état de chaque touche

public:
    /**
     * @brief Constructeur par défaut de la classe entreeClavier.
     * 
     * Initialise la classe avec une fenêtre et un renderer.
     * @param window_ Fenêtre associée
     * @param renderer_ Renderer associé
     */
    entreeClavier();

    /**
     * @brief Constructeur de la classe entreeClavier avec paramètres.
     * 
     * Initialise la classe avec une fenêtre et un renderer spécifiés.
     * @param window_ Fenêtre associée
     * @param renderer_ Renderer associé
     */
    entreeClavier(SDL_Window* window_, SDL_Renderer* renderer_);

    /**
     * @brief Destructeur de la classe entreeClavier.
     * 
     * Nettoie les ressources utilisées par la classe.
     */
    ~entreeClavier();

    /**
     * @brief Fonction pour scanner les entrées au clavier en cas de touche enfoncée ou relâchée.
     */
    void gestionEntree();

    /**
     * @brief Vérifie si une touche donnée a été pressée. Renvoie true le cas échéant.
     * 
     * @param key Touche à vérifier
     * @return true si la touche est enfoncée, sinon false
     */
    bool isKeyPressed(SDL_Keycode key);

    /**
     * @brief Utilise isKeyPressed() pour savoir si la touche Gauche (q) a été enfoncée.
     * @return true si la touche Gauche est enfoncée, sinon false
     */
    bool isGauchePressed();

    /**
     * @brief Utilise isKeyPressed() pour savoir si la touche Droite (d) a été enfoncée.
     * @return true si la touche Droite est enfoncée, sinon false
     */
    bool isDroitePressed();

    /**
     * @brief Utilise isKeyPressed() pour savoir si la touche Lâcher (Space) a été enfoncée.
     * @return true si la touche Lâcher est enfoncée, sinon false
     */
    bool isLacherPressed();

    /**
     * @brief Utilise isKeyPressed() pour savoir si la touche O a été enfoncée.
     * @return true si la touche O est enfoncée, sinon false
     */
    bool isOPressed();

    /**
     * @brief Vérifie que la fenêtre est toujours active.
     * @return true si la fenêtre est toujours active, sinon false
     */
    bool isRunning();

    /**
     * @brief Fonction de test de régression pour la classe entreeClavier.
     */
    static void testRegression();

    /**
     * @brief Gère les touches enfoncées et les affiche dans le terminal.
     * 
     * @param key Touche enfoncée
     */
    void gestionKeyDown(SDL_Keycode key);

    /**
     * @brief Gère les touches relâchées.
     * 
     * @param key Touche relâchée
     */
    void gestionKeyUp(SDL_Keycode key);
};

