#ifndef _TEXTE_H
#define _TEXTE_H

#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

/**
 * @file Texte.h
 * @brief Définition de la classe Texte pour gérer du texte avec SDL2 et SDL_ttf.
 */

/**
 * @class Texte
 * @brief Classe pour gérer du texte avec SDL2 et SDL_ttf.
 */
class Texte {
private:
    TTF_Font* m_font;       ///< Police de caractères
    SDL_Surface* m_surface; ///< Surface du texte
    SDL_Texture* m_texture; ///< Texture du texte
    bool m_hasChanged;      ///< Indique si le texte a été modifié depuis sa dernière utilisation
    std::string m_text;     ///< Texte à afficher

public:
    /**
     * @brief Constructeur par défaut de la classe Texte.
     */
    Texte();

    /**
     * @brief Destructeur de la classe Texte.
     */
    ~Texte();

    /**
     * @brief Charge une police de caractères à partir d'un fichier.
     * @param size La taille de la police.
     */
    void loadFont(int size);

    /**
     * @brief Met à jour le texte à afficher.
     * @param Nouvelletexte Le nouveau texte à afficher.
     * @return true si le texte a été mis à jour avec succès, sinon false.
     */
    bool updateText(const char* Nouvelletexte);

    /**
     * @brief Rend du texte sur une surface.
     * @param renderer Le renderer SDL sur lequel dessiner.
     * @param text Le texte à rendre.
     * @param color La couleur du texte.
     * @param l La longueur du texte.
     */
    void renderText(SDL_Renderer* renderer, const char* text, SDL_Color color, int l);

    /**
     * @brief Dessine le texte sur le renderer à une position donnée.
     * @param renderer Le renderer SDL sur lequel dessiner.
     * @param x La position horizontale du texte.
     * @param y La position verticale du texte.
     */
    void draw(SDL_Renderer* renderer, int x, int y);

    /**
     * @brief Obtient la texture du texte.
     * @return La texture du texte.
     */
    SDL_Texture* getTexture() const;

    /**
     * @brief Définit la surface du texte.
     * @param surf La surface à définir.
     */
    void setSurface(SDL_Surface* surf);

};

#endif // _TEXTE_H
