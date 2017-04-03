#include <stdio.h>
#include <stdlib.h>

#include "robot.h"



int main() {
    //augmentation de la taille de la console
    //system("mode con cols=120 lines=80");
    FILE* file;
    file = fopen("maps/map.txt", "r" );
    if(file == NULL) {
        printf("\n Erreur ouverture fichier\n");
        }
    else {
        Problem probleme;
        // chemin de base (vide) à initialiser pour la case de départ
        Liste_dynamique_generique chemin_etape_depart;
        Creer_liste_dynamique_generique(&chemin_etape_depart);

        // lecture et affichage du problème
        lire_fichier(file,&probleme);
        Affiche_matrice(&probleme);

        // on initialise le chemin du départ avec lui - même (on est passé par le départ pour arriver au départ)
        Coordonnee e;
        e.num_col = probleme.depart.num_col;
        e.num_ligne = probleme.depart.num_ligne;
        Ajouter_elem_tete_liste_dynamique_generique(&chemin_etape_depart, &e, sizeof(Coordonnee));

        // TODO : changer le nom en cases_a_traiter
        Liste_dynamique_generique frontiere;
        Creer_liste_dynamique_generique(&frontiere);

        // initialisation de l'étape de départ à traiter
        Etape depart;
 
        depart.coord = probleme.depart;
        depart.chemin = chemin_etape_depart;
        // on ajouter au case à traiter le départ (test initial)
        Ajouter_elem_tete_liste_dynamique_generique(&frontiere, &depart, sizeof(Etape));
        // on lance notre algorithme de parcours en largeur
        Etape etapeFinale;
        etapeFinale = Parcours_Larg(probleme.arrive, &probleme, frontiere);
        afficher_chemin_coordonnee(&etapeFinale.chemin);
        libere_matrice(&probleme);
        }
    return 0;
    }
