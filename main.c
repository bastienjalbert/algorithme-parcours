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
        // cases marquées
        Liste_dynamique_generique *cases_marquees;
        Creer_liste_dynamique_generique(cases_marquees);

        Etape *depart = malloc(sizeof(Etape));

        lire_fichier(file,&probleme);
        Affiche_matrice(&probleme);

        depart->coord = probleme.depart;
        depart->chemin = cases_marquees;

        Parcours_Larg(*depart,probleme.arrive, &probleme);
        libere_matrice(&probleme);
        }
    return 0;
    }
