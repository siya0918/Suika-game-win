#include "Texte.h"
#include <iostream>
#include <filesystem>
#include <cassert>
#include <stdlib.h>
using namespace std;
Texte::Texte() : m_font(nullptr), m_surface(nullptr), m_texture(nullptr), m_hasChanged(false) 
{
   
}

Texte::~Texte() {
    if (m_font != nullptr) {
        m_font = nullptr;
        TTF_CloseFont(m_font);
        TTF_Quit();
    }

    if (m_surface != nullptr) {
        SDL_FreeSurface(m_surface);
        m_surface = nullptr;
    }
    
    if (m_texture != nullptr) {
        SDL_DestroyTexture(m_texture);
        m_texture = nullptr;
    }
    m_hasChanged =false;
}


void Texte::loadFont(int size) {
    m_font = TTF_OpenFont("data/Roboto-Regular.ttf", size);
    assert(m_font != nullptr && "Erreur: Impossible de charger la police");
    //std:://cout << "Police chargée" << std::endl;
}

bool Texte::updateText(const char* Nouvelletexte) {
    if(strcmp(m_text.c_str(), Nouvelletexte) != 0) {
        m_text = Nouvelletexte;
        m_hasChanged = true;
        return true;
    } else {
        return false;
    }
}



// Méthode pour rendre du texte
void Texte::renderText(SDL_Renderer* renderer, const char* text, SDL_Color color,int l) {
    if (updateText(text)) {
        assert(m_font != nullptr && "Erreur: La police n'est pas chargée !");
        
        if (m_surface != nullptr) {
            SDL_FreeSurface(m_surface);
            m_surface = nullptr;
        }
        
        m_surface = TTF_RenderUTF8_Blended_Wrapped(m_font, text, color, l);
        assert(m_surface != nullptr && "Erreur: Impossible de rendre la surface du texte");
        //std:://cout << "Texte : " << text << " rendu avec succès" << std::endl;

        if (m_texture != nullptr) {
            SDL_DestroyTexture(m_texture);
            m_texture = nullptr;
        }

        m_texture = SDL_CreateTextureFromSurface(renderer, m_surface);
        assert(m_texture != nullptr && "Erreur: Impossible de créer la texture à partir du texte rendu");
    }
}


void Texte::draw(SDL_Renderer* renderer, int x, int y){
    if (m_hasChanged) {
        SDL_UpdateTexture(m_texture, nullptr, m_surface->pixels, m_surface->pitch);
        m_hasChanged = false;
    }
    SDL_Rect dstRect = { x, y, m_surface->w, m_surface->h };
    SDL_RenderCopy(renderer, m_texture, nullptr, &dstRect);
}

    SDL_Texture * Texte::getTexture() const {return m_texture;}
    void Texte::setSurface(SDL_Surface * surf) {m_surface = surf;}

