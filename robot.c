
#include <stdio.h>
#include <stdlib.h>

#include "robot.h"

// fonction de débug
void show_cord(Coordonnee coord) {

    printf("col : %d | lin : %d & ", coord.num_col, coord.num_ligne);

}
//********* FONCTIONS DE TESTS *******************//

void test_Verif_Etape_Appartient_liste()
{
    Liste_dynamique_generique cases_marquees;
    Creer_liste_dynamique_generique(&cases_marquees);

    Etape *et1 = malloc(sizeof(Etape));
    Etape *et2 = malloc(sizeof(Etape));
    Etape *et3 = malloc(sizeof(Etape));
    Etape *et4 = malloc(sizeof(Etape));
    Coordonnee *t1 = malloc(sizeof(Coordonnee));
    Coordonnee *t2 = malloc(sizeof(Coordonnee));
    Coordonnee *t3 = malloc(sizeof(Coordonnee));
    Coordonnee *t4 = malloc(sizeof(Coordonnee));
    t1->num_col = 0;
    t1->num_ligne = 1;
    et1->coord = *t1;

    t2->num_col = 1;
    t2->num_ligne = 0;
    et2->coord = *t2;

    t3->num_col = 2;
    t3->num_ligne = 0;
    et3->coord = *t3;

    t4->num_col = 4;
    t4->num_ligne = 0;
    et4->coord = *t4;


    Ajouter_elem_fin_liste_dynamique_generique(&cases_marquees, et1, sizeof(Etape));
    Ajouter_elem_fin_liste_dynamique_generique(&cases_marquees, et3, sizeof(Etape));
    Ajouter_elem_fin_liste_dynamique_generique(&cases_marquees, et4, sizeof(Etape));


    printf("\n\nShould be true : \n");
    if(Verif_Etape_Appartient_liste(&cases_marquees, *et4)) {
        printf("true\n");
    } else {
        printf("false\n");
    }

    printf("\n\nShould be false : \n");
    if(Verif_Etape_Appartient_liste(&cases_marquees, *et2)) {
        printf("true\n");
    } else {
        printf("false\n");
    }

    printf("\n\nShould be true : \n");
    if(Verif_Etape_Appartient_liste(&cases_marquees, *et3)) {
        printf("true\n");
    } else {
        printf("false\n");
    }


}
/*
int main(void) {

test_Verif_Etape_Appartient_liste();


return 0;
}*/

//********* FIN FONCTIONS DE TESTS *******************//

/** comparer deux coordonnées
* @return : 0 si elles sont égales
*/
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

        Etape * etape_tmp;


        // on itére dans toute la liste pour essayer de trouver etape_courante
        for(int i = 0; i < li->iTaille; i++) {

            // on récupére l'étape temporaire de la liste
            etape_tmp = (Etape *) tmp->tdDonnee;



            // on récupére les coordonnées de l'étape temporaire
            coord_tmp = etape_tmp->coord;




            // on compare les deux étapes avec leurs coordonnées
            if(Compare(coord_courante, coord_tmp)) {
                return true;
            }

            // on prend l'élément suivant pour la vérification afin de réitérer
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
    * TODO Problème de parcours ici : à corriger
    */
    void etat_suivants(Etape etape_courante, Liste_dynamique_generique *frontiere, Problem *probleme) {

        // C'est le chemin des cases précédentes l'étape en cours
        Liste_dynamique_generique * nouveau_chemin = (Liste_dynamique_generique *) malloc(sizeof(Liste_dynamique_generique));

        // coordonnées de la case (<=> étape) courante
        int cur_col = etape_courante.coord.num_col;

        int cur_lin = etape_courante.coord.num_ligne;



        // chemin de l'étape courante
        Liste_dynamique_generique * chemin_etp_courante = etape_courante.chemin;

        // initilisation de la liste des chemins si on commence le parcours (avec elle même) TODO : savoir si c'est nécessaire
        if(cur_col == probleme->depart.num_col && cur_lin == probleme->depart.num_ligne) {
            Etape * e = (Etape *) malloc(sizeof(Etape));

            e->coord.num_col = probleme->depart.num_col;
            e->coord.num_ligne = probleme->depart.num_ligne;

            Ajouter_elem_tete_liste_dynamique_generique(chemin_etp_courante, e, sizeof(Etape));


        }



        // coordonnées temporaire des cases adjacentes (<=> voisines)
        Etape *haut = (Etape *) malloc(sizeof(Etape));
        Etape *bas = (Etape *) malloc(sizeof(Etape));
        Etape *gauche = (Etape *) malloc(sizeof(Etape));
        Etape *droite = (Etape *) malloc(sizeof(Etape));

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

        Liste_dynamique_generique * liste_etape_possible = malloc(sizeof(Liste_dynamique_generique));
        Creer_liste_dynamique_generique(liste_etape_possible);

        Ajouter_elem_tete_liste_dynamique_generique(liste_etape_possible, haut, sizeof(Etape));
        Ajouter_elem_fin_liste_dynamique_generique(liste_etape_possible, bas, sizeof(Etape));
        Ajouter_elem_fin_liste_dynamique_generique(liste_etape_possible, gauche, sizeof(Etape));
        Ajouter_elem_fin_liste_dynamique_generique(liste_etape_possible, droite, sizeof(Etape));
        Ajouter_elem_fin_liste_dynamique_generique(liste_etape_possible, droite, sizeof(Etape));


        printf("-------------------\n");
        printf("Etape courante, lin : %d et col : %d\n", cur_lin, cur_col);

        for(int it = 1 ; it <= 4 ; it++) {

            // on itére dans les cases voisines (haut, bas, gauche, droite)
            Etape * etape_a_tester = (Etape *) malloc(sizeof(Etape));
            Recuperer_elem_ieme_liste_dynamique_generique(liste_etape_possible, etape_a_tester, it, sizeof(Etape));



            // si la case du haut est valide on l'ajoute
            if(evaluation(etape_a_tester->coord,probleme) && !Verif_Etape_Appartient_liste(chemin_etp_courante, *etape_a_tester)) // si on n'est pas déjà passé par cette case
            {

                // on affecte une nouvelle zone mémoire pour le nouveau chemin des étapes
                nouveau_chemin = malloc(sizeof(Liste_dynamique_generique));
                Creer_liste_dynamique_generique(nouveau_chemin);

                // on duplique la liste pour l'ajouter à l'étape intermédiaire
                Dupliquer_liste_dynamique_generique(etape_courante.chemin, nouveau_chemin, sizeof(Etape));

                // debug echo
                printf("avant ajou1t\n");
                afficher_chemin(nouveau_chemin);

                // TODO déterminer le comportement relativement aléatoire d'ajouter
                // on ajoute l'étape actuelle au chemin de celle-ci pour la marqué
                Ajouter_elem_tete_liste_dynamique_generique(nouveau_chemin, etape_a_tester, sizeof(Etape));

                // debug echo
                printf("\n");
                printf("après ajou1t\n");
                afficher_chemin(nouveau_chemin);

                // on affecte le nouveau chemin à l'étape testée
                etape_a_tester->chemin = nouveau_chemin;

                // on ajoute à la frontière l'étape pour les futurs traitements
                Ajouter_elem_fin_liste_dynamique_generique(frontiere, etape_a_tester , sizeof(Etape));
                printf("\n");
                printf("LA FRONTIERE : \n");
                afficher_chemin(frontiere);
                printf("\n");

                printf("\n\n\n");

            }

        }

        printf("-------------------\n");





    }


    /**
    * Fonctionne en file donc premier entré dernier traité (LIFO) -> cf boucle et
    * comment on ajouter les valeurs à la frontière pour comprendre
    * (ici on traite la tête et avec etat_suivants on remplit la liste par le bas)
    *
    */
    void Parcours_Larg(Coordonnee coord_arrivee, Problem *problem, Liste_dynamique_generique *frontiere)
    {

        Etape *etape_a_traiter = malloc(sizeof(Etape));

        // on récupére la première étape
        Enlever_elem_tete_liste_dynamique_generique(frontiere, &etape_a_traiter, sizeof(Etape));


        // l'étape courante n'est pas l'arrivé alors on continue le parcours
        while(!(etape_a_traiter->coord.num_col == coord_arrivee.num_col
            && etape_a_traiter->coord.num_ligne == coord_arrivee.num_ligne))
            {
                /* debug coordonées étape courante printf("%d %d\n",etape_a_traiter->coord.num_col, etape_a_traiter->coord.num_ligne); */
                etat_suivants(*etape_a_traiter, frontiere, problem);



                // debug :
                // system("clear");
                // Affiche_matrice_avec_chemin(problem, frontiere);

                // on récupére l'etape à traiter
                Enlever_elem_tete_liste_dynamique_generique(frontiere, etape_a_traiter, sizeof(Etape));


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


        void afficher_chemin(Liste_dynamique_generique *liste) {

            Etape * etape = malloc(sizeof(Etape));

            for(int k = 1; k <= liste->iTaille; k++) {


                Recuperer_elem_ieme_liste_dynamique_generique(liste, etape, k, sizeof(Etape));

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
