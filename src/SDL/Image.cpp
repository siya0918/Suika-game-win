
#include <iostream>
#include <filesystem>
#include <cassert>
#include <stdlib.h>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

#include "Image.h"

using namespace std;

Image::Image () : m_surface(nullptr), m_texture(nullptr), m_hasChanged(false) {
}


Image::~Image()
{
    if (m_surface)
    SDL_FreeSurface(m_surface);
    SDL_DestroyTexture(m_texture);

    m_surface = nullptr;
    m_texture = nullptr;
    m_hasChanged = false;
}



void Image::loadFromFile (const char* filename, SDL_Renderer * m_renderer) {
    m_surface = IMG_Load(filename);
    if (m_surface == nullptr) {
        string nfn = string(filename);
        int n=0;
        while( (m_surface == nullptr) && (n<3))
        {
            nfn = string("../") + nfn;
            m_surface = IMG_Load(nfn.c_str());
        }
    }
    if (m_surface == nullptr) {
        std::filesystem::path currentPath = std::filesystem::current_path();
        //std:://cout << "Répertoire courant : " << currentPath << std::endl;
        //cout<<"Error: cannot load "<< filename <<endl;
        exit(1);
    }

    SDL_Surface * surfaceCorrectPixelFormat = SDL_ConvertSurfaceFormat(m_surface,SDL_PIXELFORMAT_ARGB8888,0);
    SDL_FreeSurface(m_surface);
    m_surface = surfaceCorrectPixelFormat;

    m_texture = SDL_CreateTextureFromSurface(m_renderer,surfaceCorrectPixelFormat);
    if (m_texture == nullptr) {
        //cout << "Error: problem to create the texture of "<< filename<< endl;
        exit(1);
    }
}

void Image::loadFromCurrentSurface (SDL_Renderer * m_renderer) {
    m_texture = SDL_CreateTextureFromSurface(m_renderer,m_surface);
    if (m_texture == nullptr) {
        //cout << "Error: problem to create the texture from surface " << endl;
        exit(1);
    }

    
}

void Image::draw (SDL_Renderer * m_renderer, int x, int y, int w, int h) {
    int ok;
    SDL_Rect r;
    r.x = x;
    r.y = y;
    r.w = (w<0)?m_surface->w:w;
    r.h = (h<0)?m_surface->h:h;

    if (m_hasChanged) {
        ok = SDL_UpdateTexture(m_texture,nullptr,m_surface->pixels,m_surface->pitch);
        assert(ok == 0);
        m_hasChanged = false;
    }

    ok = SDL_RenderCopy(m_renderer,m_texture,nullptr,&r);
    assert(ok == 0);
    

}

    SDL_Texture * Image::getTexture() const {return m_texture;}
    void Image::setSurface(SDL_Surface * surf) {m_surface = surf;}

    



