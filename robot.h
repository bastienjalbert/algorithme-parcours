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
    Liste_dynamique_generique * chemin;
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
void Parcours_Larg(Coordonnee coord_arrivee, Problem *problem, Liste_dynamique_generique *frontiere);
bool Verif_Etape_Appartient_liste(Liste_dynamique_generique * li, Etape etape_courante);
// TODO argument probleme rajouter par rapport version de base
// car besoin pour la vérification de la cases (validité de passage)
// donc savoir si on doit utiliser ici evaluation (et donc passé problem en args)
/*
int etat_suivants(Etape etape_courante, Liste_dynamique_generique etapes_suivantes, Problem *problem);

bool evaluation(Coordonnee case_courante,Problem *problem);

int Compare(Coordonnee c1, Coordonnee c2);

void afficher_coordonnee(Coordonnee case_courante);

void afficher_etape(Etape etape_courante);

;

void Parcours_Larg(Etape etape_courante, Coordonnee coord_arrivee, Problem *problem);*/

#endif // ROBOT_H_INCLUDED
