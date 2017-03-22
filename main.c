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
        lire_fichier(file,&probleme);
        Affiche_matrice(&probleme);
        //parcours_largeur(&probleme);
        libere_matrice(&probleme);
        }
    return 0;
    }
