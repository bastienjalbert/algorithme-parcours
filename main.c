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
        // cases traitées
        Liste_dynamique_generique *cases_traitement = malloc(1024);
        // cases marquées
        Liste_dynamique_generique *cases_marquees = malloc(1024);

        Etape *depart = malloc(sizeof(Etape));
        Etape *arrivee = malloc(sizeof(Etape));

        int nb_elem = 5;

        lire_fichier(file,&probleme);
        Affiche_matrice(&probleme);

        // On ajoute la case de départ dans nos deux listes
        Ajouter_elem_tete_liste_dynamique_generique(cases_traitement, &probleme.depart, sizeof(probleme.depart));
        Ajouter_elem_tete_liste_dynamique_generique(cases_marquees, &probleme.depart, sizeof(probleme.depart));

        depart->coord = probleme.depart;
        depart->chemin = NULL;
        arrivee->coord = probleme.arrive;
        arrivee->chemin = NULL;

        Parcours_Larg(*depart,
                             *arrivee,
                             etat_suivants(*depart, *cases_traitement, nb_elem),
                             evaluation(probleme.depart,&probleme)
                             );
        libere_matrice(&probleme);
        }
    return 0;
    }
