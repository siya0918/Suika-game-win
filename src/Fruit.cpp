#include "Fruit.h"
#include "Vec2D.h"
#include <assert.h>
#include <math.h>
#include <string>
#include <iostream>
#include <random>
using namespace std;

Fruit::Fruit() : control(true){
    setRandomFruit();
}

Fruit::Fruit(typeFruit Fruit, bool controlable, const Vec2D& position, const Vec2D& vit, const Vec2D& accel){
    type = Fruit;
    control = controlable;
    pos = position; 
    vitesse = vit;
    acceleration = accel;


    switch (type) {
        case 1:
            r = 12;
            masse = .314 * r * r;
            break;
        case 2:
            r = 20;
            masse = .314 * r * r;
            break;
        case 3:
            r = 45;
            masse = .314 * r * r;
            break;
        case 4:
            r = 57;
            masse = .314 * r * r;
            break;
        case 5:
            r = 77;
            masse = .314 * r * r;
            break;
        case 6:
            r = 85;
            masse = .314 * r * r;
            break;
        case 7:
            r = 110;
            masse = .314 * r * r;
            break;
        case 8:
            r = 117;
            masse = .314 * r * r;
            break;
        case 9:
            r = 142;
            masse = .314 * r * r;
            break;
        case 10:
            r = 150;
            masse = .314 * r * r;
            break;
        case 11:
            r = 175;
            masse = .314 * r * r;
            break;
        default:
            r = 25;
            masse = .314 * r * r;
            break;
    }
}

Fruit::~Fruit(){
}

float Fruit::getRayon() const {
    return r;
}

float Fruit::getMasse() const {
    return masse;
}

 bool Fruit::getControl()const{
    return control;
}

 typeFruit Fruit::getType()const{
    return type;
}

  string Fruit::getName()const{
    string nomFruit;
    int typeDuFruit = getType();
    switch (typeDuFruit) {
        case 1:
            return nomFruit = "Myrtille";
            break;
        case 2:
            return nomFruit = "Cerise";
            break;
        case 3:
            return nomFruit = "Fraise";
            break;
        case 4:
            return nomFruit = "Mandarine";
            break;
        case 5:
           return nomFruit = "Orange";
            break;
        case 6:
            return nomFruit = "Pomme";
            break;
        case 7:
          return nomFruit = "Peche";
            break;
        case 8:
            return nomFruit = "Poire";
            break;
        case 9:
            return nomFruit = "Melon";
            break;
        case 10:
            return nomFruit = "Ananas";
            break;
        case 11:
            return nomFruit = "Pasteque";
            break;
        default:
            return nomFruit = "Inconnu";
            break;
    }


}

void Fruit::setRandomFruit(){
    int randomNb = randomNumber(4);
    switch (randomNb) {
        case 1:
            type = Myrtille;
            r = 12;
            masse = 25;
            break;
        case 2:
            type = Cerise;
            r = 20;
            masse = 40;
            break;
        case 3:
            type = Fraise;
            r = 45;
            masse = 90;
            break;
        case 4:
            type = Mandarine;
            r = 57;
            masse = 105;
            break;
        default:
            type = Myrtille;
            break;
    }
}

int Fruit::randomNumber(int max){
    // Créer un générateur de nombres aléatoires
    std::random_device rd;
    std::mt19937 gen(rd());
    
    // Définir la distribution
    std::uniform_int_distribution<> dis(1, max);

    // Générer et renvoyer le nombre aléatoire
    return dis(gen);
}


void Fruit::testRegression(){
    // Test default constructeur
    Fruit defaultFruit;
    assert(defaultFruit.getType() == defaultFruit.getType());
    assert(defaultFruit.getControl() == true);
    assert((defaultFruit.getRayon() - defaultFruit.getRayon()) < 0.001);
    assert((defaultFruit.getMasse() - defaultFruit.getMasse()) < 0.001);
    assert(defaultFruit.pos == Vec2D (0, 0));
    assert(defaultFruit.vitesse == Vec2D (0, 0));
    assert(defaultFruit.acceleration == Vec2D (0, 0));
    //cout << "defaultFruit = \nType : " << defaultFruit.getName() << "\nControle : " << defaultFruit.getControl() << "\nRayon : " << defaultFruit.getRayon() << endl;
    //cout << "Masse : " << defaultFruit.getMasse() << endl;
    //cout << "Position : [" << defaultFruit.pos.x << ";" << defaultFruit.pos.y << "]" << endl;
    //cout << "Vitesse : [" << defaultFruit.vitesse.x << ";" << defaultFruit.vitesse.y << "]" << endl;
    //cout << "Acceleration : [" << defaultFruit.acceleration.x << ";" << defaultFruit.acceleration.y << "]" << endl;


    // Test constructeur 
    Vec2D position(10, 20);
    Vec2D vit(1, 1);
    Vec2D accel(2, 2);
    Fruit customFruit(Mandarine, false, position, vit, accel);
    assert(customFruit.getType() == 4);
    assert(customFruit.getControl() == false);
    assert((customFruit.getRayon() - 57) < 0.001);
    assert((defaultFruit.getMasse() - 105) < 0.001);
    assert(customFruit.pos == position);
    assert(customFruit.vitesse == vit);
    assert(customFruit.acceleration == accel);

    //cout << "\ncustomFruit = "<< endl;
    //cout << "Type : " << customFruit.getName() << endl;
    //cout << "Controle : " << customFruit.getControl() << endl;
    //cout << "Rayon : " << customFruit.getRayon() << endl;
    //cout << "Masse : " << customFruit.getMasse() << endl;
    //cout << "Position : [" << customFruit.pos.x << ";" << customFruit.pos.y << "]" << endl;
    //cout << "Vitesse : [" << customFruit.vitesse.x << ";" << customFruit.vitesse.y << "]" << endl;
    //cout << "Acceleration : [" << customFruit.acceleration.x << ";" << customFruit.acceleration.y << "]" << endl;


    // Test randomFruit 
    Fruit randomFruit;
    randomFruit.setRandomFruit();

    assert(randomFruit.getType() == randomFruit.getType());
    assert(randomFruit.getControl() == true);
    assert((randomFruit.getRayon() - randomFruit.getRayon()) < 0.001);
    assert((randomFruit.getMasse() - randomFruit.getMasse()) < 0.001);
    assert(randomFruit.pos == Vec2D (0, 0));
    assert(randomFruit.vitesse == Vec2D (0, 0));
    assert(randomFruit.acceleration == Vec2D (0, 0));

    //cout << "\nrandomFruit = "<< endl;
    //cout << "Type : " << randomFruit.getName() << endl;
    //cout << "Controle : " << randomFruit.getControl() << endl;
    //cout << "Rayon : " << randomFruit.getRayon() << endl;
    //cout << "Masse : " << randomFruit.getMasse() << endl;
    //cout << "Position : [" << randomFruit.pos.x << ";" << randomFruit.pos.y << "]" << endl;
    //cout << "Vitesse : [" << randomFruit.vitesse.x << ";" << randomFruit.vitesse.y << "]" << endl;
    //cout << "Acceleration : [" << randomFruit.acceleration.x << ";" << customFruit.acceleration.y << "]" << endl;

}