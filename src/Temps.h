#ifndef TEMPS_H
#define TEMPS_H

#include <chrono>
#include <iostream>

/**
 * @file Temps.h
 * @brief Définition de la classe Temps pour mesurer le temps écoulé.
 */

/**
 * @brief Classe pour gérer le Temps
 */
class Temps {
private:
    std::chrono::time_point<std::chrono::steady_clock> tempsDebut; ///< Moment du début de la mesure
    std::chrono::time_point<std::chrono::steady_clock> tempsCourant; ///< Moment actuel de la mesure

public:
    /**
     * @brief Constructeur de la classe Temps.
     * 
     * Initialise les points de temps de début et actuel.
     */
    Temps();

    /**
     * @brief Réinitialise le temps du programme.
     * 
     * Réinitialise le point de temps de début à l'instant actuel.
     */
    void reinitialiser();

    /**
     * @brief Met à jour le temps écoulé depuis la dernière mise à jour.
     * 
     * Met à jour le point de temps actuel pour calculer le temps écoulé.
     */
    void mettreAJour();

    /**
     * @brief Obtient le temps écoulé en secondes.
     * 
     * Calcule et renvoie le temps écoulé depuis le point de temps de début en secondes.
     * 
     * @return Le temps écoulé en secondes.
     */
    double obtenirTempsEcoule() const;

    /**
     * @brief Convertit le temps total en une chaîne de caractères formatée.
     * 
     * Convertit le temps total en une chaîne de caractères formatée pour affichage.
     * 
     * @param tempsTotal Le temps total à convertir.
     * @return Le temps total converti en une chaîne de caractères formatée.
     */
    std::string convertirTemps(double tempsTotal) const;

    /**
     * @brief Test de régression pour s'assurer du bon fonctionnement de la classe Temps.
     */
    static void testRegression();
};

#endif // TEMPS_H
