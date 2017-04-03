
#include <stdio.h>
#include <stdlib.h>

#include "robot.h"

// fonction de débug
void show_cord(Coordonnee coord) {

    printf("col : %d | lin : %d & ", coord.num_col, coord.num_ligne);

}




    bool Compare(Coordonnee c1, Coordonnee c2) {

    if(c1.num_col == c2.num_col &&
        c1.num_ligne == c2.num_ligne) {
            return true;
        }

        return false;
    }

    bool Verif_Etape_Appartient_liste(Liste_dynamique_generique * li, Coordonnee coord_courante) {

        Coordonnee a_tester;

        for(int i = 1; i <= Taille_liste_dynamique_generique(li) ; i++) {

            Recuperer_elem_ieme_liste_dynamique_generique(li, &a_tester, i, sizeof(Coordonnee));

            if(Compare(a_tester, coord_courante)) {
                return true;
            }

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
    * Fonction qui retourne la liste des cases à proximité (du moins leurs coordonnées)
    * par rapport à l'étape passée en paramètre
    */
    void Ajouter_case_voisines(Liste_dynamique_generique * li, Etape etape_courante) {

        // coordonnées de la case (<=> étape) courante
        int cur_col = etape_courante.coord.num_col;

        int cur_lin = etape_courante.coord.num_ligne;

        // coordonnées temporaire des cases adjacentes (<=> voisines)
        Etape haut;
        Etape bas;
        Etape gauche;
        Etape droite;

        // case du dessus
        haut.coord.num_ligne = cur_lin - 1;
        haut.coord.num_col = cur_col;

        // case du dessous
        bas.coord.num_ligne = cur_lin + 1;
        bas.coord.num_col = cur_col;

        // case à gauche
        gauche.coord.num_ligne = cur_lin;
        gauche.coord.num_col = cur_col - 1;

        // case à droite
        droite.coord.num_ligne = cur_lin;
        droite.coord.num_col = cur_col + 1;

        Ajouter_elem_tete_liste_dynamique_generique(li, &haut, sizeof(Etape));
        Ajouter_elem_fin_liste_dynamique_generique(li, &bas, sizeof(Etape));
        Ajouter_elem_fin_liste_dynamique_generique(li, &gauche, sizeof(Etape));
        Ajouter_elem_fin_liste_dynamique_generique(li, &droite, sizeof(Etape));
    }


    void etat_suivants(Etape etape_courante, Liste_dynamique_generique *cases_a_traiter, Problem *probleme) {

        // C'est le chemin des cases précédentes l'étape en cours
        Liste_dynamique_generique * nouveau_chemin;

        // chemin de l'étape courante
        Liste_dynamique_generique * chemin_etp_courante = &etape_courante.chemin;

        // liste des cases voisines à la case courante que l'on va tester
        Liste_dynamique_generique cases_voisines;
        Creer_liste_dynamique_generique(&cases_voisines);
        Ajouter_case_voisines(&cases_voisines, etape_courante);


        for(int it = 1 ; it <= 4 ; it++) {

            // on itére dans les cases voisines (haut, bas, gauche, droite)
            Etape etape_a_tester;
            Recuperer_elem_ieme_liste_dynamique_generique(&cases_voisines, &etape_a_tester, it, sizeof(Etape));

            // cooordonnées des étapes voisines
            Coordonnee coord_a_ajouter ;
            coord_a_ajouter.num_col = etape_a_tester.coord.num_col;
            coord_a_ajouter.num_ligne = etape_a_tester.coord.num_ligne;

            // si la case à tester est valide on l'ajoute & si on n'est pas déjà passé par cette case
            if(evaluation(etape_a_tester.coord, probleme) && !Verif_Etape_Appartient_liste(chemin_etp_courante, etape_a_tester.coord))
            {

                // on affecte une nouvelle zone mémoire pour le nouveau chemin des étapes
                nouveau_chemin = (Liste_dynamique_generique *)  malloc(sizeof(Liste_dynamique_generique));
                // on duplique la liste pour l'ajouter à l'étape intermédiaire
                Dupliquer_liste_dynamique_generique(chemin_etp_courante, nouveau_chemin, sizeof(Coordonnee));

                // on ajoute en fin de liste les coordonées de l'étape qu'on a tester pour les prochains tests
                Ajouter_elem_fin_liste_dynamique_generique(nouveau_chemin, &coord_a_ajouter, sizeof(Coordonnee));

                // on affecte le nouveau chemin à l'étape testée
                etape_a_tester.chemin = *nouveau_chemin;

                // on ajoute à la frontière l'étape pour les futurs traitements
                Ajouter_elem_fin_liste_dynamique_generique(cases_a_traiter, &etape_a_tester , sizeof(Etape));

            }

        }

    }


    Etape Parcours_Larg(Coordonnee coord_arrivee, Problem *problem, Liste_dynamique_generique cases_a_traiter)
    {

        // on récupére à chaque fois la première étape de la liste des cases_a_traiter
        Etape etape_a_traiter;

        // on récupére la première étape
        Enlever_elem_tete_liste_dynamique_generique(&cases_a_traiter, &etape_a_traiter, sizeof(Etape));


        // l'étape courante n'est pas l'arrivé alors on continue le parcours
        while(!(etape_a_traiter.coord.num_col == coord_arrivee.num_col
            && etape_a_traiter.coord.num_ligne == coord_arrivee.num_ligne))
            {
                // on utilise l'étape à traiter pour ensuite
                // traiter les cases voisines pour continuer le traitement
                etat_suivants(etape_a_traiter, &cases_a_traiter, problem);

                // on récupére l'etape à traiter (première de la liste (LIFO))
                Enlever_elem_tete_liste_dynamique_generique(&cases_a_traiter, &etape_a_traiter, sizeof(Etape));
            }
            return etape_a_traiter;

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

        void afficher_chemin_coordonnee(Liste_dynamique_generique *liste) {

            Coordonnee coord;
            printf("\nTaille liste : %d\n",Taille_liste_dynamique_generique(liste));
            for(int k = 1; k <= Taille_liste_dynamique_generique(liste); k++) {

                Recuperer_elem_ieme_liste_dynamique_generique(liste, &coord, k, sizeof(Coordonnee));
                printf("\n%d : Pointe vers :\n",k);
                show_cord(coord);


            }
        }


        void afficher_chemin_etape(Liste_dynamique_generique *liste) {

            Etape * etape = malloc(sizeof(Etape));
            printf("\nTaille liste : %d\n",Taille_liste_dynamique_generique(liste));
            for(int k = 1; k <= Taille_liste_dynamique_generique(liste); k++) {

                Recuperer_elem_ieme_liste_dynamique_generique(liste, etape, k, sizeof(Etape));
                printf("\n%d : Pointe vers : %p\n",k, etape);
                show_cord(etape->coord);


            }
        }

        void Affiche_matrice_avec_chemin(Problem *p, Liste_dynamique_generique *liste) {
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

                    for(int k = 1; k < liste->iTaille; k++) {

                        Etape * etape = malloc(sizeof(Etape));
                        Recuperer_elem_ieme_liste_dynamique_generique(liste, &etape, k, sizeof(Etape));
                        //
                        if(etape->coord.num_col == j && etape->coord.num_ligne == i) {
                            putchar('O');
                        }

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
