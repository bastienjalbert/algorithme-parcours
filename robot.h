#ifndef ROBOT_H_INCLUDED
#define ROBOT_H_INCLUDED

#include "librairie_3IL/lib_liste.h"
#include <stdbool.h>
#include <string.h>

/**
 * structure de coordonnées
 *      num_ligne: le numéro de la ligne
 *      num_col: le numéro de la colonne
 */

typedef struct coordonnee {
    unsigned int num_ligne,num_col;
    } Coordonnee;

/**
 * permet de représenter une carte
 *      nom: le nom de la carte
 *      arrive: le point d'arrive de la carte
 *      depart: le point de depart de la carte
 *      nb_ligne: le nombre de ligne de la carte
 *      nb_colonne: le nombre de colonne de la carte
 *      carte: la representation de la carte
 */
typedef struct problem {
    char nom[20];                   // nom du labyrinthe
    Coordonnee arrive, depart;      // coordonnee de depart et d arrivee
    int nb_ligne,nb_colonne;        // nb de ligne et de colonne du labyrinthe correspondant
    char **carte;                   // carte du labyrinthe
    } Problem;

/**
 * permet de définir une etape de la recherche
 *      coord: La position de l etape
 *      chemin: la liste des positions precedentes
 */
typedef struct etape {
    Coordonnee coord;
    Liste_dynamique_generique chemin;
}Etape;


/**
 * Affiche des coordonées afin de pouvoir débugguer les données
 */
void show_cord(Coordonnee coord);


/**
 * \fn void lire_fichier(FILE *f, Problem *p)
 * \brief permet de lire un fichier de carte
 * \param f flux du fichier de la carte
 * \param p structure de donn�e pour stocker les �l�ments du probl�me
 */
void lire_fichier(FILE *f, Problem *p);

/**
 * \fn void Affiche_matrice(Problem *p)
 * \brief permet d afficher la carte
 * \param p structure de donn�e pour stocker les �l�ments du probl�me
 */
void Affiche_matrice(Problem *p);

// Ajouté par le groupe pour le projet

/**
 * \fn void Affiche_matrice(Problem *p, Liste_dynamique_generique *liste)
 * \brief permet d afficher la carte ainsi que les Étapes passé en paramètre
 * \param p structure de donn�e pour stocker les �l�ments du probl�me
 */
void Affiche_matrice_avec_chemin(Problem *p, Liste_dynamique_generique *liste);


// affiche les coordonées d'une liste d'étape
void afficher_chemin(Liste_dynamique_generique *liste);

//


/**
 * \fn void libere_matrice(Problem *p)
 * \brief permet de liberer la memoire allouee pour la carte
 * \param p structure de donn�e pour stocker les �l�ments du probl�me
 */
void libere_matrice(Problem *p);

/**
 * \fn void lire_coordonnee(FILE *f, Coordonnee *c)
 * \brief permet de lire dans un fichier une coordonnee de la carte
 * \param f flux vers le fichier contenant la carte
 * \param c pointeur vers la coordonnee saisie
 */
void lire_coordonnee(FILE *f, Coordonnee *c);

/**
*
*  Prototype des fonctions pour la recherche
*
*/

/** @author : bastien enjalbert
* \fn Etape Parcours_Larg(Coordonnee coord_arrivee, Problem *problem, Liste_dynamique_generique frontiere)
* \brief trouve le chemin le plus cours pour arriver à l'arrivé
* \param coord_arrivee Coordonnées de l'arrivé
* \param problem pointeur vers le problème (labyrinthe, départ, arrivé, ...)
* \param cases_a_traiter la liste des cases utilisée pour le traitement de l'algo
* \return l'étape finale qui est composée des coordonnées de l'arrivé et du chemin pour y arriver depuis le départ
 */
Etape Parcours_Larg(Coordonnee coord_arrivee, Problem *problem, Liste_dynamique_generique cases_a_traiter);
/** @author : bastien enjalbert
* \fn bool Verif_Etape_Appartient_liste(Liste_dynamique_generique * li, Coordonnee etape_courante)
* \brief teste si la liste passé en paramètre est composé d'une coordonée ou pas
* \param li Liste de coordonées
* \param coord_courante les coordonnées de l'étape que l'on veut chercher
* \return true si les coordonnées courantes sont dans la liste, false sinon
 */
bool Verif_Etape_Appartient_liste(Liste_dynamique_generique * li, Coordonnee coord_courante);

/** @author : bastien enjalbert
* \fn void afficher_chemin_coordonnee(Liste_dynamique_generique *liste)
* \brief Affiche une liste de coordonnées
* \param liste Liste de coordonées
 */
void afficher_chemin_coordonnee(Liste_dynamique_generique *liste);

/** @author : bastien enjalbert
* \fn void afficher_chemin_etape(Liste_dynamique_generique *liste)
* \brief Affiche les coordonnées d'une liste d'étape
* \param liste Liste d'étape
 */
void afficher_chemin_etape(Liste_dynamique_generique *liste);

/** @author : bastien enjalbert
* \fn void show_cord(Coordonnee coord)
* \brief Affiche une coordonée unique sur la sortie std
* \param coord les coordonnées à afficher
 */
void show_cord(Coordonnee coord);

/** @author : bastien enjalbert
* \fn bool Compare(Coordonnee c1, Coordonnee c2)
* \brief Compare deux coordonnées pour savoir si elles sont égales
* \param c la première coordonnée
* \param c la deuxième coordonnée
* \return true si les coordonnées sont égales, false sinon
 */
bool Compare(Coordonnee c1, Coordonnee c2);


#endif // ROBOT_H_INCLUDED
