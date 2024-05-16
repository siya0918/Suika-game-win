#include <iostream>
#include <cassert>
#include <string>
#include <fstream>
#include <sstream>
#include <string>

#include "Player.h"

using namespace std;

Player::Player() {
    score=0;
    recordFile = "data/.record.txt";
    record=0;
}

Player::~Player() {
}

void Player::afficherConsole() const {
    //cout << "Score  : " << score << endl;
    //cout << "Record du joueur : " << record << endl;
}

void Player::saveRecord(unsigned int rec){
    if(record < rec){
        record = rec;
        std::ofstream fichier(recordFile);

        if (fichier.is_open()) {
            fichier << record << std::endl;

            fichier.close();
            //std:://cout << "Record enregistré avec succès dans " << recordFile << std::endl;
        } else {
            //std:://cout << "Erreur : Impossible d'ouvrir le fichier " << recordFile << std::endl;
        }
    } else {
        //std:://cout << "Le score saisi n'est pas un nouveau record" << std::endl;
    }
}

void Player::loadRecord(){
    std::ifstream fichier(recordFile);
    
    if (fichier.is_open()) {
        std::string lecture;
        if (std::getline(fichier, lecture)) {
            record = stoi(lecture);
      //  //std:://cout << "Record chargé avec succès depuis " << recordFile << std::endl;
        }
        fichier.close();
    } else {
        //std:://cout << "Erreur : Impossible d'ouvrir le fichier "<< recordFile << std::endl;
    }
}

unsigned int Player::getrecord()
{
    return record;
}

void Player::testRegression() {
    Player p;

    assert(p.score == 0);

    p.saveRecord(100);
    p.loadRecord();

    assert(p.getrecord() == 100);

    p.afficherConsole();

    //std:://cout<<"Tests passés avec succès"<<std::endl;

}
