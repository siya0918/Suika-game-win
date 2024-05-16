#include "Temps.h"

#include <cassert>
#include <iomanip>
#include <iostream>
#include <sstream>

Temps::Temps() {
    reinitialiser();
}

void Temps::reinitialiser() {
    tempsDebut = std::chrono::steady_clock::now();
    tempsCourant = tempsDebut;
}

void Temps::mettreAJour() {
    tempsCourant = std::chrono::steady_clock::now();
}

double Temps::obtenirTempsEcoule() const {
    std::chrono::duration<double> duree = tempsCourant - tempsDebut;
    return duree.count();
}

std::string Temps::convertirTemps(double tempsTotal) const {
    int heures = static_cast<int>(tempsTotal / 3600);
    int minutes = static_cast<int>((tempsTotal - heures * 3600) / 60);
    int secondes = static_cast<int>(tempsTotal - heures * 3600 - minutes * 60);

    // Formater le temps en hh:mm:ss
    std::ostringstream tempsFormate;
    tempsFormate << std::setfill('0') << std::setw(2) << heures << "."
        << std::setfill('0') << std::setw(2) << minutes << "."
        << std::setfill('0') << std::setw(2) << secondes;

    return tempsFormate.str();
}


void Temps::testRegression() {
    Temps t;
    assert(t.obtenirTempsEcoule() == t.obtenirTempsEcoule());
    //std:://cout << "Tests passés avec succès" << std::endl;
}

