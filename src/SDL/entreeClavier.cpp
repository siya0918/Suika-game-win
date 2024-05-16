    
#include "../../lib/dev/vcpkg/packages/sdl2_x64-windows/include/SDL2/SDL.h"

#include <iostream>
#include "entreeClavier.h"

#include <cassert>

using namespace std;

entreeClavier::entreeClavier() {
    running = true;
    memset(keys, false, sizeof(keys)); // Initialisation du tableau keys à false
}
entreeClavier::entreeClavier(SDL_Window* window_, SDL_Renderer* renderer_) : renderer(nullptr), window(nullptr){
    SDL_Init(SDL_INIT_VIDEO);
    window = window_;
    renderer = renderer_;
}

entreeClavier::~entreeClavier() {
    if (renderer != nullptr) {
        renderer = nullptr;
        SDL_DestroyRenderer(renderer);
        
    }

    if (window != nullptr) {
         window = nullptr;
        SDL_DestroyWindow(window);
    }

        SDL_Quit();
}



void entreeClavier::gestionEntree() {
    SDL_Event event;
    memset(keys, false, sizeof(keys)); // Initialisation du tableau keys à false 
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) {
            running = false;
        }
        else if (event.type == SDL_KEYDOWN || event.type == SDL_KEYUP) {
            SDL_Keycode key = event.key.keysym.sym;
            if (key == SDLK_q || key == SDLK_d || key == SDLK_o || key == SDLK_SPACE) {
                if (event.type == SDL_KEYDOWN) {
                    gestionKeyDown(key);
                }
                else if (event.type == SDL_KEYUP) {
                    gestionKeyUp(key);
                }
            }
        }
    }
}


bool entreeClavier::isKeyPressed(SDL_Keycode key) {
    return keys[key];
}

bool entreeClavier::isGauchePressed(){
    return isKeyPressed(SDLK_q);
}

bool entreeClavier::isDroitePressed(){
    return isKeyPressed(SDLK_d);
}

bool entreeClavier::isLacherPressed(){
    return isKeyPressed(SDLK_SPACE);
}

bool entreeClavier::isOPressed(){
    return isKeyPressed(SDLK_o);
}

bool entreeClavier::isRunning() {
    return running;
}

void entreeClavier::gestionKeyDown(SDL_Keycode key) {
    
    keys[key] = true;
    string droite = SDL_GetKeyName(SDLK_d);
    string gauche = SDL_GetKeyName(SDLK_q);
    string lacher = SDL_GetKeyName(SDLK_SPACE);
    string O = SDL_GetKeyName(SDLK_o);

    if(SDL_GetKeyName(key) == droite){
        ////cout << "Droite enfoncée" << endl;

    }

    else if(SDL_GetKeyName(key) == gauche){
        ////cout << "Gauche enfoncée" << endl;
    }

    else if(SDL_GetKeyName(key) == lacher){
        ////cout << "Lacher enfoncée" << endl;
    }
     else if(SDL_GetKeyName(key) == O){
        ///cout << "o enfoncée" << endl;
    }
}

void entreeClavier::gestionKeyUp(SDL_Keycode key) {
    keys[key] = false;
}

void entreeClavier::testRegression() {
    SDL_Window* window;
    SDL_Renderer* renderer;   
    
    window = SDL_CreateWindow("SDL Keyboard Input", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480, 0);
    renderer = SDL_CreateRenderer(window, -1, 0);

    bool droiteFonctionne;
    bool gaucheFonctionne;
    bool lacherFonctionne;
    bool oFonctionne;


    entreeClavier clavier(window, renderer);

    while (clavier.isRunning()) {
        clavier.gestionEntree();
        if (clavier.isDroitePressed()) {
            cout << "La fonction isDroitePressed fonctionne" << endl;
            droiteFonctionne = true;
            assert(droiteFonctionne);
        }

        if (clavier.isGauchePressed()) {
            cout << "La fonction isGauchePressed fonctionne" << endl;
            gaucheFonctionne = true;
            assert(gaucheFonctionne);
        }

        if (clavier.isLacherPressed()) {
            cout << "La fonction isLacherPressed fonctionne" << endl;
            lacherFonctionne = true;
            assert(lacherFonctionne);
        }

        if (clavier.isOPressed()) {
            cout << "La fonction isOPressed fonctionne" << endl;
            oFonctionne = true;
            assert(oFonctionne);
        }

    }
}