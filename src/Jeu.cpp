#include <cassert>
#include <iostream>
#include "Jeu.h"

using namespace std;

const int DIMX = 1250;
const int DIMY = 825;

Jeu::Jeu(): mapr(600, 125, map.getLargeur(), map.getLongueur()), fruitActuel(Myrtille, true, Vec2D((mapr.getPosx() + mapr.getLargeur() / 2)-50, mapr.getPosy()), Vec2D(0, 0), Vec2D(0, 0)), ph(1000, 1. / 60.) {
  movefruit = 0;
  keyd = false;
  keyo = false;
  keyspace = false;
  keyq = false;
  GameOver=false;
  tgameovedepassement.reinitialiser();
  play.loadRecord();
  nbfruitfuisonSTAT=0;
  nbfruittotalSTAT=0;
  dernierfruitSTAT="Myrtille";
  typefruithautsSTAT=1;
  peutlancer=true;
  multiplicateurmodechoas=0;
  txt[2]="vous avez quitté !";
  win=false;
}

Jeu::~Jeu() {}

void Jeu::gestionFruit() {

  assert(fruitActuel.getType() >= 0 && fruitActuel.getType() <= 10 && "Erreur : Le type de fruit actuel est invalide.");
  assert(fruitnext.getType() >= 0 && fruitnext.getType() <= 10 && "Erreur : Le type de fruit suivant est invalide.");

  if(modejeu==2)
    keyspace=true;
  
  if (peutlancer && keyspace) {
    Fruit frrandom;
    fruitnext.pos = fruitActuel.pos;
    fruitActuel.pos.x = fruitActuel.pos.x + movefruit;
    fruits.push_back(fruitActuel);
    fruitActuel = fruitnext;
    fruitnext = frrandom;
    movefruit = 0;
    nbfruittotalSTAT++;
    peutlancer=false;
  }
  fruitActuel.pos.x = fruitActuel.pos.x + movefruit;

  if (!(fruitActuel.pos.x <= mapr.getPosx()+mapr.getLongueur()-fruitActuel.getRayon())) {//partie droite
    fruitActuel.pos.x -= 5;
  } else if (!(fruitActuel.pos.x >= mapr.getPosx()+fruitActuel.getRayon())){//partie gauche
    fruitActuel.pos.x += 5;
  }

  if(peutlancer==false) {
    tlache.mettreAJour();
    if(tlache.obtenirTempsEcoule() > 1.5 - multiplicateurmodechoas) {
      tlache.reinitialiser();
      peutlancer=true;
      //cout<<"Joueur peut lancer"<<endl;
    }
  } else {
    tlache.reinitialiser();
  } 
}

void Jeu::gestionText() {
  txt[0] = "Le but du Suika Game est de faire tomber des fruits dans un récipient afin de les combiner, ce qui les transforme en fruits plus gros, jusqu'à l'obtention d'une pastèque.";
  txt[1] = "Commandes: \n Q : pour déplacer le fruit à gauche, \n D : pour déplacer à droite, \n O : pour quitter le jeu, \n Space : pour lâcher le fruit";
  peutlancer ? txt[4]="OK" : txt[4]="WAIT";
}

void Jeu::gestionphysique(vector<Fruit>& tabfruit, const Map& m) {
    for (auto it = tabfruit.begin(); it != tabfruit.end(); ) {
        bool erased = false;
        auto next_it = std::next(it); 
        for (auto it2 = next_it; it2 != tabfruit.end(); ++it2) {
            if (ph.checkColisionFruit(*it, *it2)) {
                if (it->getType() == it2->getType() && it->getType() < 11 && it2->getType() < 11) {
                    int typeint = it2->getType() + 1;
                    typeFruit type1 = static_cast<typeFruit>(typeint);
                    Fruit fruit(type1, false, it2->pos, it2->vitesse, it2->acceleration);
                    *it = fruit;
                    play.score = play.score + it2->getType() * 2;
                    if (play.score > play.getrecord()) { play.saveRecord(play.score); }
                    nbfruitfuisonSTAT++;
                    tabfruit.erase(it2);
                    erased = true;
                    break;
                }
                else {
                    ph.upadateColisionFruit(*it, *it2);
                }
            }
        }
        if (!erased) {
            ++it; 
        }
    }
    for (auto& fruit : tabfruit) {
        ph.updateVitesse(fruit);
        ph.updatePosition(fruit);
        ph.updateColisionMapX(m, fruit);
        ph.updateColisionMapY(m, fruit);
    }
}



void Jeu::gestionmode() {
  if(modejeu==0) {
    txt[3] = "Mode normal sans limite. C'est le mode officiel de Sukia Game où vous ne gagnez pas et l'objectif est de battre votre propre record";
  } else if(modejeu==1) {
    txt[3] = "Mode normal. Vous gagnez dès l'obtention d'une pastèque.";
    gameoverwin(fruits);
  } else if(modejeu==2) {
    multiplicateurmodechoas=.75;
    txt[3] = "Mode chaos sans limite. Similaire au mode normal, mais les fruits tombent automatiquement et plus rapidement. \n Vous devez simplement vous déplacer à droite et à gauche pour jouer. ";
  } else if(modejeu==3) {
    gameoverwin(fruits);
    Fruit fruit(Melon, false, fruitActuel.pos, fruitActuel.vitesse, fruitActuel.acceleration);
    fruitActuel=fruit;
    fruitnext=fruit;
    txt[3] = "Mode Melon. Les fruits ne commencent pas par la myrtille mais par le melon, \n ce qui vous permet d'obtenir facilement des pastèques et de gagner rapidement.";
  }
}

void Jeu::gestionTouches() {
  movefruit=0;
  if (keyd) {
    movefruit += 5;
  }
  else if (keyq) {
    movefruit -= 5;
  }

  if(keyq==0 && keyd==0)
  {
      movefruit=0;
  }

  if (keyo) {
    GameOver = true;
  }
}

bool Jeu::depassementFruit(const vector < Fruit >& tabfruit,const Map& m) const {
  for (size_t j = 0; j < tabfruit.size(); ++j) {
    if (tabfruit[j].pos.y + tabfruit[j].getRayon() <= m.getPosy() * 2) {
      return true;
    }
  }
  return false;
}

void Jeu::gameoverdepassement(){
  if (depassementFruit(fruits,mapr)) {
    int tempsInt = static_cast < int > (tgameovedepassement.obtenirTempsEcoule());
    tgameovedepassement.mettreAJour();
    if(tempsInt >= 3) {
      win=false;
      txt[2] = "Dommage! Vous avez perdu";
      GameOver=true;
    }
  } else {
    tgameovedepassement.reinitialiser();
  }
}

void Jeu::gameoverwin(const vector < Fruit >& tabfruit){
  for(size_t i=0; i<fruits.size();i++) {
    if(fruits[i].getType()==11) {
      txt[2] = "Bravo! Vous avez gagner" ;
      win=true;
      GameOver=true;
    }
  }
}

void Jeu::getStat(const vector<Fruit>& tabfruit,unsigned int& nbfrttotal,unsigned int& nbffuison,string& lastf) {
  for (size_t j = 0; j < tabfruit.size(); ++j) {
    if(tabfruit[j].getType()>typefruithautsSTAT) {
      typefruithautsSTAT=tabfruit[j].getType();
      dernierfruitSTAT=tabfruit[j].getName();
    }
    nbfrttotal=nbfruittotalSTAT;
    nbffuison=nbfruitfuisonSTAT;
    lastf=dernierfruitSTAT; 
  }
}

bool Jeu::getwin()const {
  return win;
}

void Jeu::testRegression() {
    // Création d'une instance de Jeu
    Jeu jeu;

    // Test de la gestion des fruits
    Fruit testfr = jeu.fruitnext;
    jeu.keyspace = true;
    //cout<<"type fruit actuel : "<<jeu.fruitActuel.getName()<<endl; 
    //cout<<"type fruit test(next) : "<<testfr.getName()<<endl; 
    jeu.gestionFruit();
    assert(testfr.getType() == jeu.fruitActuel.getType() && "Erreur : le changement de fruit a été signalé incorrectement.");
    //cout<<"type fruit actuel aprés gestionfruit ; "<< jeu.fruitActuel.getName()<<endl;
    jeu.keyspace = false;
    //cout << "Test de la gestion des fruits OK!" << endl;

    // Test de la gestion des touches
   
    int posinitx=jeu.fruitActuel.pos.x;
    ////cout<<"pos fruit initi : "<<posinitx<<endl;
    jeu.keyd = true;
    jeu.gestionTouches();
    jeu.gestionFruit();
    //cout<<"pos fruit aprés appuyer sur d : "<<jeu.fruitActuel.pos.x<<endl;
    assert(posinitx+jeu.movefruit == jeu.fruitActuel.pos.x && "Erreur : le déplacement à droite n'a pas été effectué correctement.");
    //cout << "Test de la gestion des touches 'droit' OK!" << endl;


    jeu.keyd = false;
    jeu.keyq = true;
    jeu.gestionTouches();
    jeu.gestionFruit();
    assert(posinitx == jeu.fruitActuel.pos.x && "Erreur : le déplacement à gauche n'a pas été effectué correctement.");
    //cout<<"testfr." << jeu.fruitActuel.pos.x<<endl;

    // Test de la gestion physique
    Map maptest(0, 0, 50, 50);
    jeu.fruits.clear();
    Fruit fruit1(Myrtille, true, Vec2D(maptest.getPosx()+10, maptest.getPosy()+10/2), Vec2D(0, 0), Vec2D(0, 0));
    Fruit fruit2(Myrtille, true, Vec2D(maptest.getPosx()+10, maptest.getPosy()+10/2), Vec2D(0, 0), Vec2D(0, 0));
    jeu.fruits.push_back(fruit1);
    jeu.fruits.push_back(fruit2);
    //cout << "passe" << endl;
    jeu.gestionphysique(jeu.fruits,maptest);
    assert(jeu.fruits[0].getType() == Cerise && "Erreur : la fusion des fruits n'a pas été effectuée correctement.");
    assert(jeu.fruits.size() == 1 && "Erreur : Les fruits ne sont pas été supprimé correctement");
    //cout << "Test de la gestion physique OK!" << endl;

    // Test de la détection de dépassement des fruits
    jeu.fruits.clear();
    Fruit fruit3(Myrtille, true, Vec2D(0, -20), Vec2D(0, 0), Vec2D(0, 0));
    jeu.fruits.push_back(fruit3);
    assert(jeu.depassementFruit(jeu.fruits, maptest) && "Erreur : la détection de dépassement des fruits n'a pas été effectuée correctement.");
    //cout << "Test de la détection de dépassement des fruits OK!" << endl;

    // Test de la gestion des collisions entre deux fruits differents
    jeu.fruits.clear();
    Fruit fruit4(Fraise, true, Vec2D(maptest.getPosx()+2, maptest.getPosy()), Vec2D(0, 0), Vec2D(0, 0));
    Fruit fruit5(Melon, true, Vec2D(maptest.getPosx()+2, maptest.getPosy()), Vec2D(0, 0), Vec2D(0, 0));
    jeu.fruits.push_back(fruit4);
    jeu.fruits.push_back(fruit5);
    jeu.gestionphysique(jeu.fruits, maptest);
    assert(jeu.fruits[0].getType() == Fraise && "Erreur : la collision entre les fruits n'a pas été gérée correctement.");
    assert(jeu.fruits[1].getType() == Melon && "Erreur : la collision entre les fruits n'a pas été gérée correctement.");
    //cout << "Test de la gestion des collisions OK!" << endl;

    //cout << "Tous les tests ont réussi !" << endl;
}
