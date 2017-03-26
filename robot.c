
#include <stdio.h>
#include <stdlib.h>

#include "robot.h"

// fonction de débug
void show_cord(Coordonnee coord) {

    printf("col : %d      |        lin : %d\n", coord.num_col, coord.num_ligne);

}


// comparer deux coordonnées
// @return : 0 si elles sont égales
bool Compare(Coordonnee c1, Coordonnee c2) {

    if(c1.num_col == c2.num_col &&
        c1.num_ligne == c2.num_ligne) {
            return true;
        }

        return false;
    }

    /**
    * Vérifie si une étape est déjà présente dans une liste d'étape passée en argument
    * @return : true l'étape est présente, false sinon
    */
    bool Verif_Etape_Appartient_liste(Liste_dynamique_generique * li, Etape etape_courante) {

        // on commence par récupérer la tête de la liste et on initialise le premier élement
        Element_liste_dynamique_generique *tmp;
        tmp = li->psTete;

        // utile pour comparer les coordonnées de l'étape courante avec celles de la liste
        Coordonnee coord_courante = etape_courante.coord;

        // coordonnées temporaire d'une des coordonnées passées dans le chemin
        Coordonnee coord_tmp;

        // nombre d'élèment de la liste
        int max_size  = li->iTaille;

        // on itére dans toute la liste pour essayer de trouver etape_courante
        while(tmp->ElementSuivant != NULL) {

            // on récupére les coordonnées de l'étape temporaire
            coord_tmp = ((Etape *)tmp->tdDonnee)->coord;

            // on compare les deux étapes avec leurs coordonnées
            if(Compare(coord_courante, coord_tmp)) {
                return true;
            }

            tmp = tmp->ElementSuivant;
        }

        return false;

    }

    /**
    * Permet de déterminer si la case est visitable "physiquement", si elle l'est alors :
    * - La case n'est pas hors de la map
    * - La case est bien un caractère espace
    * @return true si elle est visitable, false sinon
    */
    bool evaluation(Coordonnee case_courante,Problem *problem) {

        // coordonnées de la case (<=> étape) courante
        int cur_col = case_courante.num_col;
        int cur_lin = case_courante.num_ligne;



        if(cur_col < 0 || cur_col > problem->nb_colonne // si la case dépasse des bords
            || cur_lin < 0 || cur_lin > problem->nb_ligne // de la carte .... ou
            || problem->carte[cur_lin][cur_col] != ' ' // si la case est un mur
        ) {
            return false;
        }

        return true;

    }

    /**
    * Récupére la liste des toutes les cases voisines visitables
    */
    int etat_suivants(Etape etape_courante, Liste_dynamique_generique *frontiere, Problem *probleme) {



        // on ajoute l'étape courante au chemin de l'étape courante pour la réutilisation après
        Ajouter_elem_fin_liste_dynamique_generique(etape_courante.chemin, &etape_courante, sizeof(Etape));

        Liste_dynamique_generique * nouveau_chemin = malloc(52222);

        // coordonnées de la case (<=> étape) courante
        int cur_col = etape_courante.coord.num_col;

        int cur_lin = etape_courante.coord.num_ligne;



        // coordonnées temporaire des cases adjacentes (<=> voisines)
        Etape *haut = malloc(sizeof(Etape));
        Etape *bas = malloc(sizeof(Etape));
        Etape *gauche = malloc(sizeof(Etape));
        Etape *droite = malloc(sizeof(Etape));

        // case du dessus
        haut->coord.num_ligne = cur_lin - 1;
        haut->coord.num_col = cur_col;

        // case du dessous
        bas->coord.num_ligne = cur_lin + 1;
        bas->coord.num_col = cur_col;

        // case à gauche
        gauche->coord.num_ligne = cur_lin;
        gauche->coord.num_col = cur_col - 1;

        // case à droite
        droite->coord.num_ligne = cur_lin;
        droite->coord.num_col = cur_col + 1;


        // si la case du haut est valide on l'ajoute
        if(evaluation(haut->coord,probleme) && !Verif_Etape_Appartient_liste(etape_courante.chemin, *haut)) // si on n'est pas déjà passé par cette case
        {
            printf("HAUT : \n");
            show_cord(haut->coord);

            memcpy(nouveau_chemin, etape_courante.chemin, sizeof(etape_courante.chemin));

            Ajouter_elem_fin_liste_dynamique_generique(nouveau_chemin, haut, sizeof(Etape));

            haut->chemin = nouveau_chemin; // grave vérif

            Ajouter_elem_fin_liste_dynamique_generique(frontiere, &haut, sizeof(Etape));

        }

        // si la case du bas est valide on l'ajoute
        if(evaluation(bas->coord,probleme) && !Verif_Etape_Appartient_liste(etape_courante.chemin, *bas)) // si on n'est pas déjà passé par cette case
        {
            printf("BAS : \n");
            show_cord(bas->coord);

            memcpy(nouveau_chemin, etape_courante.chemin, sizeof(etape_courante.chemin));

            Ajouter_elem_fin_liste_dynamique_generique(nouveau_chemin, bas, sizeof(Etape));

            bas->chemin = nouveau_chemin; // grave vérif

            Ajouter_elem_fin_liste_dynamique_generique(frontiere, &bas, sizeof(Etape));

        }

        // si la case de gauche est valide on l'ajoute
        if(evaluation(gauche->coord,probleme) && !Verif_Etape_Appartient_liste(etape_courante.chemin, *gauche)) // si on n'est pas déjà passé par cette case
        {
            printf("GAUHCE : \n");
            show_cord(gauche->coord);

            memcpy(nouveau_chemin, etape_courante.chemin, sizeof(etape_courante.chemin));

            Ajouter_elem_fin_liste_dynamique_generique(nouveau_chemin, gauche, sizeof(Etape));

            gauche->chemin = nouveau_chemin; // grave vérif

            Ajouter_elem_fin_liste_dynamique_generique(frontiere, &gauche, sizeof(Etape));

        }

        // si la case de droite est valide on l'ajoute
        if(evaluation(droite->coord,probleme) && !Verif_Etape_Appartient_liste(etape_courante.chemin, *droite)) // si on n'est pas déjà passé par cette case
        {
            printf("DROITE : \n");
            show_cord(droite->coord);

            memcpy(nouveau_chemin, etape_courante.chemin, sizeof(etape_courante.chemin));

            Ajouter_elem_fin_liste_dynamique_generique(nouveau_chemin, droite, sizeof(Etape));

            droite->chemin = nouveau_chemin; // grave vérif

            Ajouter_elem_fin_liste_dynamique_generique(frontiere, &droite, sizeof(Etape));

        }


    }


    void Parcours_Larg(Coordonnee coord_arrivee, Problem *problem, Liste_dynamique_generique *frontiere)
    {

        Etape *premiere_etape = malloc(sizeof(Etape));

        // on récupére la première étape
        Enlever_elem_tete_liste_dynamique_generique(frontiere, &premiere_etape, sizeof(Etape));


        // l'étape courante n'est pas l'arrivé alors on continue le parcours

        while(!(premiere_etape->coord.num_col == coord_arrivee.num_col
            && premiere_etape->coord.num_ligne == coord_arrivee.num_ligne))
            {
                // debug coordonées étape courante printf("%d %d\n",premiere_etape->coord.num_col, premiere_etape->coord.num_ligne);
                etat_suivants(*premiere_etape, frontiere, problem);

                // on récupére la première étape
                Enlever_elem_tete_liste_dynamique_generique(frontiere, &premiere_etape, sizeof(Etape));
            }


        }


        void lire_fichier(FILE *f, Problem *p) {
            char c;
            fscanf(f,"%s\n",p->nom);
            lire_coordonnee(f,&p->depart);
            lire_coordonnee(f,&p->arrive);
            fscanf(f,"%i\n",&p->nb_ligne);
            fscanf(f,"%i\n",&p->nb_colonne);
            p->carte = (char **) malloc(sizeof(char *)*p->nb_ligne);
            if(p->carte==NULL) {
                printf("\nallocation impossible, pas assez de mémoire\n");
                exit (1);
            } else {
                for (int i = 0; i < p->nb_ligne; i++) {
                    p->carte[i] = (char*)malloc(sizeof(char)*p->nb_colonne);
                    if (p->carte[i]==NULL) {
                        printf("\nallocation impossible, pas assez de m�moire\n");
                        exit (1);
                    }
                }
            }
            for (int i = 0; i < p->nb_ligne; i++) {
                for(int j=0; j< p->nb_colonne; j++) {
                    fscanf(f,"%c",&p->carte[i][j]);
                }
                fscanf(f,"%c",&c);  // enl�ve le \n
            }
        }
        void Affiche_matrice(Problem *p) {
            printf("nom du labyrinthe : %s\n", p->nom);
            printf("position de depart : %i;%i\n",p->depart.num_ligne,p->depart.num_col);
            printf("position de arrivee : %i;%i\n",p->arrive.num_ligne,p->arrive.num_col);
            printf("nb_ligne : %i; nb_colonne : %i\n", p->nb_ligne, p->nb_colonne);
            for (int i = 0; i < p->nb_ligne; i++) {
                printf("|");
                for (int j = 0; j < p->nb_colonne; j++) {
                    if( p->arrive.num_ligne==i&&p->arrive.num_col==j){
                        putchar('A');
                    }else if( p->depart.num_ligne==i&&p->depart.num_col==j){
                        putchar('D');
                    }else{
                        printf("%c",p->carte[i][j]);
                    }
                }
                printf("|\n");
            }
        }

        void lire_coordonnee(FILE *f, Coordonnee *c) {
            fscanf(f,"%i\t%i\n",&c->num_ligne,&c->num_col);
        }

        void libere_matrice(Problem *p){
            for (int i = 0; i < p->nb_ligne; i++) {
                free(p->carte[i]);
            }
            free(p->carte);
        }
