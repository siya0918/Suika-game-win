#include <cassert>
#include <time.h>
#include <stdlib.h>
#include <iostream>
#include <filesystem>
#include <string>
#include <time.h>
#include <string>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

#include "gestionSDL.h"


using namespace std;

const int DIMX = 1250;
const int DIMY = 825;

/*--------------Initsalitaion de SDL--------------*/

gestionSDL::gestionSDL(): m_surface(nullptr), m_texture(nullptr), m_renderer(nullptr), m_window(nullptr){
  gestionmodeSDL();
  // Initialisation de la SDL
  //std:://cout << "SDL: init" << endl;
  if (SDL_Init(SDL_INIT_VIDEO) != 0) {
    cerr << "Erreur lors de l'initialisation de la SDL : " << SDL_GetError() << endl;
    exit(1);
  }

  int imgFlags = IMG_INIT_PNG | IMG_INIT_JPG;
  //std:://cout << "SDL_image: init" << endl;
  if (!(IMG_Init(imgFlags) & imgFlags)) {
    //std:://cout << "SDL_m_image could not initialize! SDL_m_image Error: " << IMG_GetError() << endl;
    SDL_Quit();
    exit(1);
  }

  // Initialisation de SDL_ttf
  //std:://cout << "SDL_ttf: init" << endl;
  if (TTF_Init() != 0) {
    cerr << "Erreur lors de l'initialisation de SDL_ttf : " << TTF_GetError() << endl;
    SDL_Quit();
    exit(1);
  }

  // Création de la fenêtre
  m_window = SDL_CreateWindow("Suika Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, DIMX, DIMY, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
  //std:://cout << "SDL: fenetre cree" << endl;
  if (m_window == nullptr) {
    cerr << "Erreur lors de la création de la fenêtre : " << SDL_GetError() << endl;
    SDL_Quit();
    exit(1);
  }
  // Charger l'icône
  icon = SDL_LoadBMP("data/Sukialogo.bmp"); // Remplacez "icone.bmp" par le chemin vers votre fichier ICO
  if (!icon) {
      cout << "Erreur lors de la icon" << endl;
      // Gestion de l'erreur de chargement de l'icône
      SDL_DestroyWindow(m_window);
      SDL_Quit();
      exit(1);
  }
  // Définir l'icône de la fenêtre
  SDL_SetWindowIcon(m_window, icon);


  // Création du renderer
  m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_ACCELERATED);
  //std:://cout << "SDL_CreateRenderer" << endl;
  if (m_renderer == nullptr) {
    cerr << "Erreur lors de la création du renderer : " << SDL_GetError() << endl;
    SDL_DestroyWindow(m_window);
    SDL_Quit();
    exit(1);
  }






  init();

}

/*--------------Destrecture SDL--------------*/
gestionSDL::~gestionSDL() {
    // Libération de la surface, de la texture et du rendu
    if (m_surface != nullptr) {
      m_surface = nullptr;
        SDL_FreeSurface(m_surface);
        
    }
    if (m_texture != nullptr) {
       m_texture = nullptr;
        SDL_DestroyTexture(m_texture);
    }
    if (m_renderer != nullptr) {
       m_renderer = nullptr;
        SDL_DestroyRenderer(m_renderer);
    }

    // Destruction de la fenêtre
    if (m_window != nullptr) {
      m_window = nullptr;
        SDL_DestroyWindow(m_window);
    }
    if (icon != nullptr) {
        icon = nullptr;
        SDL_FreeSurface(icon);
    }

    // Libération des bibliothèques SDL_Image et SDL_ttf
    IMG_Quit();
    TTF_Quit();
    

    // Nettoyage de SDL
    SDL_Quit();
}


void gestionSDL::getImage(string name, Image & im) {
    std::string cheminImage = "data/" + name + ".jpg";
    //std:://cout << "Chargement de l'image : " << cheminImage << endl;
    im.loadFromFile(cheminImage.c_str(), m_renderer);
    im.loadFromCurrentSurface(m_renderer);
}


/*--------------Gestion des texte statique--------------*/
void gestionSDL::gestionTextStat() {

  jeu.gestionText();

  SDL_Color m_font_color = {
    255,
    250,
    250
  };

  int size=16;
  winorlose.loadFont(32);
  nomfruitactuel.loadFont(size);
  nomfruitnext.loadFont(size);
  tdepass.loadFont(128);
  for(int i=0; i<12;i++)
  {
    t_texte[i].loadFont(size);
    t_nomfruit[i].loadFont(size);
    t_pointfruit[i].loadFont(size);
    Statistique[i].loadFont(size);
  }

  //gestion texte regle
  t_texte[0].renderText(m_renderer,jeu.txt[0].c_str(),m_font_color,400);
  //std:://cout << "Texte loaded : Regle de jeu " << endl;
  //gestion texte commande
  t_texte[1].renderText(m_renderer,jeu.txt[1].c_str(),m_font_color,400);
  //std:://cout << "Texte loaded : commande " << endl;

  //gestion texte commande
  t_texte[5].renderText(m_renderer,jeu.txt[2].c_str(),m_font_color,300);
  //std:://cout << "Texte loaded : vous avez perdu " << endl;

  ///Recuperation des fruits
  Vec2D position(100, 20); // Position arbitraire
  Vec2D vit(0, 0); // Vitesse arbitraire
  Vec2D accel(0, 0); // Accélération arbitraire

  for (int i = 1; i <= 11; ++i) {
    Fruit f(static_cast < typeFruit > (i), false, position, vit, accel);
    fruitsSDL.push_back(f);
    t_nomfruit[i].renderText(m_renderer,f.getName().c_str(),m_font_color,300);
    t_pointfruit[i].renderText(m_renderer,to_string(f.getType()*2).c_str(),m_font_color,300);
  }
}

/*--------------Gestion Image Statique--------------*/
void gestionSDL::gestionImageStat() {
  //charge image de recipiant
  fond.loadFromFile("data/fondrecipiant.png", m_renderer);
  fond.loadFromCurrentSurface(m_renderer);
 
  //charge les 11 image des fruits gauche de l'écran
  for (size_t i = 0; i < fruitsSDL.size(); ++i) {
    getImage(fruitsSDL[i].getName(), m_imagefruit[i]);
  }
}

/*--------------Gestion de text général--------------*/
void gestionSDL::gestionText() {
  //color blanc
  SDL_Color m_font_color = {
    255,
    250,
    250
  };


  //Affichage nom de fruit actuelle
  string nom = "Fruit Actuel : " + jeu.fruitActuel.getName();
  nomfruitactuel.renderText(m_renderer,nom.c_str(),m_font_color,300);
  nomfruitactuel.draw(m_renderer,600,45);

  //Affichage nom de fruit prochain
  nom = "Fruit Next : " + jeu.fruitnext.getName();
  nomfruitnext.renderText(m_renderer,nom.c_str(),m_font_color,300);
  

  //affichage nom fruit next
  nomfruitnext.draw(m_renderer,915,45);  

  //Afficher txt régle
  t_texte[0].draw(m_renderer, 10, DIMY - 450);

  //Afficher txt commande
  t_texte[1].draw(m_renderer, 10, DIMY - 350);

  //affichage txt mode de jeu
  t_texte[6].renderText(m_renderer,jeu.txt[3].c_str(),m_font_color,300);
  t_texte[6].draw(m_renderer, 10, DIMY - 225);
  

  //affichage temps
  string timer = "Temps  : " + jeu.t.convertirTemps(jeu.t.obtenirTempsEcoule()) + " ";
  t_texte[2].renderText(m_renderer,timer.c_str(),m_font_color,300);
  t_texte[2].draw(m_renderer, jeu.map.getLargeur() - 130, 75);

//affichage record
  string bestScore = "Record : " + to_string(jeu.play.getrecord());
  t_texte[3].renderText(m_renderer,bestScore.c_str(),m_font_color,300);
  t_texte[3].draw(m_renderer, jeu.map.getLargeur() - 130, 100);

//affichage score
string score = "Score : " + to_string(jeu.play.score);
t_texte[4].renderText(m_renderer,score.c_str(),m_font_color,300);
t_texte[4].draw(m_renderer, jeu.map.getLargeur() - 130, 125);

//affichage OK,wait
SDL_Color colorstatus;
jeu.txt[4]=="OK" ? colorstatus= {0,255,0,0} : colorstatus= {255,0,0,0};
t_texte[5].renderText(m_renderer,jeu.txt[4].c_str(),colorstatus,300);
t_texte[5].draw(m_renderer, 850, 45);
    
  //Afficher les noms fruits et leurs points
  for (size_t i = 1; i <= fruitsSDL.size(); ++i) {
    t_nomfruit[i].draw(m_renderer,100,20+i*25);
    t_pointfruit[i].draw(m_renderer,200,20+i*25);
  }

if (jeu.depassementFruit(jeu.fruits,jeu.mapr)) {//boucle de dépassement
  int tempsInt = static_cast < int > (jeu.tgameovedepassement.obtenirTempsEcoule());
  string tempsStr = to_string(tempsInt);
  if(tempsInt>=1)
  {
  tdepass.renderText(m_renderer,tempsStr.c_str(),m_font_color,500);
  tdepass.draw(m_renderer, jeu.map.getLargeur()/2+200, jeu.map.getLongueur()/2);
  }
  }



}

/*--------------Gestion des images--------------*/
void gestionSDL::gestionImage() {

    // Afficher fond de récipient
    int x, y, w, h;
    x = jeu.mapr.getPosx();
    y = jeu.mapr.getPosy();
    w = jeu.map.getLargeur();
    h = jeu.map.getLongueur();
    fond.draw(m_renderer, x, y, w, h);
    // Affichage du fruit actuel
   // SDL_SetRenderDrawColor(m_renderer, 255, 0, 0, 255);
  //  SDL_RenderDrawLine(m_renderer, coordx+jeu.fruitActuel.getRayon(), coordy+jeu.fruitActuel.getRayon(), coordx+jeu.fruitActuel.getRayon(), coordy+jeu.mapr.getLongueur()+jeu.fruitActuel.getRayon());
    m_imagefruit[jeu.fruitActuel.getType()-1].draw(m_renderer, jeu.fruitActuel.pos.x -jeu.fruitActuel.getRayon() , jeu.fruitActuel.pos.y , 2*jeu.fruitActuel.getRayon(), 2*jeu.fruitActuel.getRayon());

    // Affichage du fruit suivant
    m_imagefruit[jeu.fruitnext.getType()-1].draw(m_renderer, 1075, 40, 25, 25);

    // Afficher les noms de fruits statiques
    for (size_t i = 0; i < fruitsSDL.size(); ++i) {
        m_imagefruit[i].draw(m_renderer, 50, 45 + i * 25, 25, 25);
    }

    jeu.ph.setClock();//reset l'horloge

    jeu.gestionphysique(jeu.fruits,jeu.mapr);//on applique la physique

        if (jeu.depassementFruit(jeu.fruits,jeu.mapr)) {//boucle de dépassement
            SDL_SetRenderDrawColor(m_renderer, 255, 0, 0, 255);
            SDL_RenderDrawLine(m_renderer, jeu.mapr.getPosx(), jeu.mapr.getPosy() * 2, jeu.mapr.getPosx() + jeu.mapr.getLongueur(), jeu.mapr.getPosy() * 2);
            
        }
        
    // Affichage des fruits dans le récipient
    for (size_t i = 0; i < jeu.fruits.size(); ++i) {//boucle d'affichage des fruits
        m_imagefruit[jeu.fruits[i].getType()-1].draw(m_renderer, jeu.fruits[i].pos.x - jeu.fruits[i].getRayon(), jeu.fruits[i].pos.y - jeu.fruits[i].getRayon(), 2*jeu.fruits[i].getRayon(), 2*jeu.fruits[i].getRayon());
    }

    jeu.ph.waitDeltatime();
}


/*--------------Gestion des touches--------------*/
void gestionSDL::gestionTouches() {
  if (clavier.isDroitePressed()) {
    jeu.keyd = true;
  } else if (clavier.isGauchePressed()) {
    jeu.keyq = true;
  } else if (clavier.isLacherPressed()) {
    jeu.keyspace = true;
  } else if (clavier.isOPressed()) {
    jeu.keyo = true;
  } else {
    jeu.keyspace = jeu.keyd = jeu.keyq = false;
  }
  jeu.gestionTouches();
  clavier.gestionEntree(); 
}

void gestionSDL::affichergameover() {
  // Couleur de fond pour le renderer
  SDL_RenderClear(m_renderer);
  Temps tgo;
  tgo=jeu.t;
  if(jeu.getwin())
  {
    SDL_SetRenderDrawColor(m_renderer, 34, 121, 34, 255);//vert
  }
  else{ SDL_SetRenderDrawColor(m_renderer, 121, 34, 34, 255); // Rouge
  }
  unsigned int  nbfruitfuison=0;
  unsigned int nbfruittotal=0;
  string lastfruit="Myrtille";

  jeu.getStat(jeu.fruits,nbfruitfuison,nbfruittotal,lastfruit);
  SDL_Color m_font_color = {255,255,255};

  string textes= "Nombre Fruit total : " + to_string(nbfruitfuison) + " ";
  Statistique[0].renderText(m_renderer,textes.c_str(),m_font_color,300);

  textes= "Nombre Fruit fin jeu : " + to_string(jeu.fruits.size()) + " ";
  Statistique[1].renderText(m_renderer,textes.c_str(),m_font_color,300);

  textes= "Nombre Fruit fuisonné : " + to_string(nbfruittotal) + " ";
  Statistique[2].renderText(m_renderer,textes.c_str(),m_font_color,300);

  textes= "Fruit le plus haut obtenue : " + lastfruit + " ";
  Statistique[3].renderText(m_renderer,textes.c_str(),m_font_color,400);

  
  textes= "Temps : " + tgo.convertirTemps(tgo.obtenirTempsEcoule()) + " ";
  Statistique[4].renderText(m_renderer,textes.c_str(),m_font_color,400);

  textes= "Score : " + to_string(jeu.play.score);
  Statistique[5].renderText(m_renderer,textes.c_str(),m_font_color,400);

  textes= "Record : " + to_string(jeu.play.getrecord());
  Statistique[6].renderText(m_renderer,textes.c_str(),m_font_color,400);

  winorlose.renderText(m_renderer,jeu.txt[2].c_str(),m_font_color,400);
  winorlose.draw(m_renderer,jeu.map.getLargeur()/2+200, jeu.map.getLongueur()/2-200);

  for(int i=0;i<7;i++)
  {
    Statistique[i].draw(m_renderer,jeu.map.getLargeur()/2,jeu.map.getLongueur()/2-100+50*i+1);
  }
    SDL_RenderPresent(m_renderer);
}

void gestionSDL::gestionmodeSDL()
{

    do {
        cout << "MODE DE JEU : " << endl;
        cout << "0 : Mode normal sans limite" << endl;
        cout << "1 : Mode normal" << endl;
        cout << "2 : Mode chaos sans limite" << endl;
        cout << "3 : Mode Melon" << endl;

        cout << "Selectionnez un mode de jeu : ";
        cin >> jeu.modejeu;
        assert(jeu.modejeu >= 0 && jeu.modejeu <= 3); 
        if(jeu.modejeu < 0 || jeu.modejeu > 3) {
            cout << "**** Chiffre non valide ****" << endl;
        }
    } while (jeu.modejeu < 0 || jeu.modejeu > 3);

    cout << "Mode de jeu sélectionné : " << jeu.modejeu << endl;
}


/*--------------Initsalitaion de jeu avec SDL--------------*/
void gestionSDL::init() {
  jeu.t.reinitialiser();
  gestionTextStat();
  gestionImageStat();
  // Arrière-plan couleur r,g,b,a
  SDL_SetRenderDrawColor(m_renderer, 51, 181, 255, 50);
  /// //cout << "SDL: SDL_SetRenderDrawColor" << endl;
  //std:://cout << "Chargement en cours..." << endl;
  SDL_Delay(1000);
  //std:://cout << "Chargement Terminer" << endl;
}

void gestionSDL::afficher() {
  SDL_SetRenderDrawColor(m_renderer, 74, 120, 160, 255);
  gestionText();
  gestionImage();
  // Réinitialiser la couleur de fond
  SDL_SetRenderDrawColor(m_renderer, 56, 171, 236, 50);
}

void gestionSDL::update() {
  bool running = true;
  while (running) {
      while (SDL_PollEvent(&e)) {
          if (e.type == SDL_QUIT) {
              running = false;
              //std:://cout << "Fin d'exécution" << std::endl;
          }
      }
      if(jeu.GameOver==false)
        {
        SDL_RenderClear(m_renderer);
        jeu.gestionmode();
        jeu.gestionText();
        afficher();
        jeu.gameoverdepassement();
        gestionTouches();
        jeu.gestionFruit();
        SDL_RenderPresent(m_renderer);
        jeu.t.mettreAJour();
        }
      else
      {
        affichergameover();
      }
  }
}
