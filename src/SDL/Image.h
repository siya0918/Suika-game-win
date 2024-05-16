#ifndef _IMAGE_H
#define _IMAGE_H

#include <iostream>

#include <SDL2/SDL.h>


/**
 * @file Image.h
 * @brief Définition de la classe Image
 */

/**
 * @brief Classe pour gérer une image avec SDL2
 */
class Image {

private:
    SDL_Surface * m_surface; ///< Surface de l'image
    SDL_Texture * m_texture; ///< Texture de l'image


    bool m_hasChanged; //!< Indique si l'image a été modifiée depuis sa dernière utilisation

public:
    /**
     * @brief Constructeur par défaut de la classe Image
     */
    Image();

    /**
     * @brief Destructeur de la classe Image
     */
    ~Image();

    /**
     * @brief Charge une image à partir d'un fichier
     * @param filename Le chemin du fichier image
     * @param m_renderer Le renderer SDL sur lequel dessiner
     */
    void loadFromFile(const char* filename, SDL_Renderer * m_renderer);

    /**
     * @brief Charge une image à partir de la surface actuelle
     * @param m_renderer Le renderer SDL sur lequel dessiner
     */
    void loadFromCurrentSurface(SDL_Renderer * m_renderer);

    /**
     * @brief Dessine l'image sur le renderer
     * @param m_renderer Le renderer SDL sur lequel dessiner
     * @param x La position horizontale de l'image
     * @param y La position verticale de l'image
     * @param w La largeur de l'image (par défaut, -1 pour conserver la taille d'origine)
     * @param h La hauteur de l'image (par défaut, -1 pour conserver la taille d'origine)
     */
    void draw(SDL_Renderer * m_renderer, int x, int y, int w=-1, int h=-1);

    /**
     * @brief Récupère la texture de l'image
     * @return La texture de l'image
     */
    SDL_Texture * getTexture() const;

    /**
     * @brief Définit la surface de l'image
     * @param surf La surface à définir
     */
    void setSurface(SDL_Surface * surf);


    
};

#endif // _IMAGE_H
