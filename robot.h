#ifndef ROBOT_H_INCLUDED
#define ROBOT_H_INCLUDED

#include "librairie_3IL/lib_liste.h"
#include <stdbool.h>
#include <string.h>
#include <unistd.h>

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
*      caseGrille: La case de la grille sur laquelle on est à l'étape x
*      precedente: étape précédente utile pour refaire le chemin
*/
typedef struct etape {
    Coordonnee coord;
    struct etape * precedente; // case précédente associée à celle-ci
}Etape;


/** @author: bastien enjalbert
* \fn void Ajouter_case_voisines(Liste_dynamique_generique * li, Etape * etape_courante, Problem * pb)
* \brief Créé une liste des cases voisines visitables
* \param pb le problème (qui contient la grille de toutes les cases)
* \param li la liste qui sera retournée
* \param etape_courante l'étape courante
*/
void Ajouter_case_voisines(Liste_dynamique_generique * li, Etape * etape_courante, Problem * pb);

/** @author: bastien enjalbert
* \fn void etat_suivants(Etape * etape_a_traiter, Liste_dynamique_generique *traitement, Problem *probleme)
* \brief Trouve les cases utiles au traitemenet et les ajoutes à la liste des étapes à traiter
* \param etape_a_traiter l'étape courante surlaquelle on travaille
* \param traitement la liste des étapes à traiter
* \param etape_courante l'étape courante
* \param probleme le problème (qui contient la grille de toutes les cases et touticuinti)
*/
void etat_suivants(Etape * etape_a_traiter, Liste_dynamique_generique *traitement, Liste_dynamique_generique *marquees,Problem *probleme);

/**
* Affiche des coordonées afin de pouvoir débugguer les données
*/
void show_cord(Coordonnee coord);

/** @author: bastien enjalbert
* Permet de déterminer si la case est visitable "physiquement", si elle l'est alors :
* - La case n'est pas hors de la grille
* - La case est bien un caractère espace
* - On marque la case dans la grille
* @return true si elle est visitable, false sinon
*/
bool evaluation(Etape * case_courante,Problem *problem);


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
* \fn Etape creer_etape(Case * caseGrille, Etape * precedente)
* \brief Créer une nouvelle étape à partir d'une case de la grille et d'une autre étape précédente
* \param caseGrille pointeur vers la case de la grille
* \param precedente l'étape précédente a lier
* \param cases_a_traiter la liste des cases utilisée pour le traitement de l'algo
* \return l'étape tout fraichement créée
*/
Etape creer_etape(int num_ligne, int num_col, Etape * precedente);

/** @author : bastien enjalbert
* \fn Etape Parcours_Larg(Coordonnee coord_arrivee, Problem *problem, Liste_dynamique_generique frontiere)
* \brief trouve le chemin le plus cours pour arriver à l'arrivé
* \param coord_arrivee Coordonnées de l'arrivé
* \param problem pointeur vers le problème (labyrinthe, départ, arrivé, ...)
* \param cases_a_traiter la liste des cases utilisée pour le traitement de l'algo
* \return l'étape finale avec laquelle on pourra remonter aux étapes précédentes pour former le chemin
*/
Etape * Parcours_Larg(Coordonnee coord_arrivee, Problem *problem, Etape * etape_a_traiter, Liste_dynamique_generique * traitement, Liste_dynamique_generique * marquees);


/** @author : bastien enjalbert
* \fn bool etape_est_le_depart(Case cas, Problem * problem)
* \brief Détermine si la case passée en param est l'arrivé ou pas
* \param problem pointeur vers le problème (labyrinthe, départ, arrivé, ...)
* \param cas la case à tester
* \return true si c'est l'arrivé, false sinon
*/
//bool etape_est_le_depart(Case cas, Problem * problem);

/** @author : bastien enjalbert
* \fn void afficher_chemin_etape(Etape *etape)
* \brief Affiche le chemin pour arriver à l'étape
* \param liste Liste d'étape
*/
void afficher_chemin_etape(Etape *etape, Problem * pb);

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

Liste_dynamique_generique lire_toutes_coordonnees(Problem *p) ;


#endif // ROBOT_H_INCLUDED
