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

        // lecture et affichage du problème
        lire_fichier(file,&probleme);

        Affiche_matrice(&probleme);

        Etape * initialisation = malloc(sizeof(Etape));

        // on initialise la liste des traitements (étapes) on pourrait faire ça dans ParcoursLarg
        Liste_dynamique_generique * traitement = malloc(sizeof(Liste_dynamique_generique));
        Creer_liste_dynamique_generique(traitement);

        // on initialise la liste des cases sur lesquelles nous sommes déjà passé
        Liste_dynamique_generique * marquees = malloc(sizeof(Liste_dynamique_generique));
        Creer_liste_dynamique_generique(marquees);

        // on lance notre algorithme de parcours en largeur
        Etape * etapeFinale;
        etapeFinale = Parcours_Larg(probleme.arrive, &probleme, initialisation, traitement, marquees);
        afficher_chemin_etape(etapeFinale, &probleme);
        libere_matrice(&probleme);
        }
    return 0;
    }
