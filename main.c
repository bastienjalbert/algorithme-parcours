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
        Liste_dynamique_generique cases_marquees;
        Creer_liste_dynamique_generique(&cases_marquees);



        Liste_dynamique_generique frontiere;
        Creer_liste_dynamique_generique(&frontiere);


        Etape *depart = malloc(sizeof(Etape));

        lire_fichier(file,&probleme);
        Affiche_matrice(&probleme);

        depart->coord = probleme.depart;

        depart->chemin = &cases_marquees;

        Ajouter_elem_tete_liste_dynamique_generique(&frontiere, &depart, sizeof(Etape));

        Parcours_Larg(probleme.arrive, &probleme, &frontiere);
        libere_matrice(&probleme);
        }
    return 0;
    }
