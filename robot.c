
#include <stdio.h>
#include <stdlib.h>

#include "robot.h"

// fonction de débug

void show_cord(Coordonnee coord) {

    printf("col : %d | lin : %d & ", coord.num_col, coord.num_ligne);

}

/** @author : bastien enjalbert
 * \fn bool Compare(Coordonnee c1, Coordonnee c2)
 * \brief Compare deux coordonnées pour savoir si elles sont égales
 * \param c la première coordonnée
 * \param c la deuxième coordonnée
 * \return true si les coordonnées sont égales, false sinon
 */
bool Compare(Coordonnee c1, Coordonnee c2) {

    if (c1.num_col == c2.num_col &&
            c1.num_ligne == c2.num_ligne) {
        return true;
    }

    return false;
}

/**
 * Permet de déterminer si la case est visitable "physiquement", si elle l'est alors :
 * - La case n'est pas hors de la grille
 * - La case est bien un caractère espace
 * - On marque la case dans la grille
 * @return true si elle est visitable, false sinon
 */
bool evaluation(Case * case_courante, Problem *problem) {


    if (case_courante == NULL) {
        return false;
    }

    // coordonnées de la case (<=> étape) courante
    int cur_col = case_courante->coord.num_col;
    int cur_lin = case_courante->coord.num_ligne;



    if (cur_col < 0 || cur_col > problem->nb_colonne // si la case dépasse des bords
            || cur_lin < 0 || cur_lin > problem->nb_ligne // de la carte .... ou
            || problem->grille[cur_lin][cur_col].carac != ' ' // si la case est un mur
            || problem->grille[cur_lin][cur_col].marque == true // si la case a été marquée
            ) {
        return false;
    }
    // else : on marque la case car on va y passer dessus
    problem->grille[cur_lin][cur_col].marque = true;
    return true;

}

/** @author: bastien enjalbert
* \fn Case * recuperer_case(Problem *pb, int ligne, int colonne)
* \brief Retourne la case de la grille du problème aux coordonnées données
* \param pb le problème (qui contient la grille de toutes les cases)
* \param ligne, colonne, les coordonnées de la case qu'on veut récupérer
*/
Case * recuperer_case(Problem *pb, int ligne, int colonne) {
    // vérification de la validité des coordonées
    if (colonne < 0 || colonne > pb->nb_colonne // si la case dépasse des bords
            || ligne < 0 || ligne > pb->nb_ligne) {
        return NULL;
    }
    return &pb->grille[ligne][colonne];

}

/** @author : bastien enjalbert
* \fn Etape creer_etape(Case * caseGrille, Etape * precedente)
* \brief Créer une nouvelle étape à partir d'une case de la grille et d'une autre étape précédente
* \param caseGrille pointeur vers la case de la grille
* \param precedente l'étape précédente a lier
* \param cases_a_traiter la liste des cases utilisée pour le traitement de l'algo
* \return l'étape tout fraichement créée
*/
Etape creer_etape(Case * caseGrille, Etape * precedente) {

    Etape etape;

    etape.caseGrille = caseGrille;
    etape.precedente = precedente;

    return etape;

}

/** @author: bastien enjalbert
* \fn void Ajouter_case_voisines(Liste_dynamique_generique * li, Etape * etape_courante, Problem * pb)
* \brief Créé une liste des cases voisines visitables
* \param pb le problème (qui contient la grille de toutes les cases)
* \param li la liste qui sera retournée
* \param etape_courante l'étape courante
*/
void Ajouter_case_voisines(Liste_dynamique_generique * li, Etape * etape_courante, Problem * pb) {

    // coordonnées de la case (<=> étape) courante
    int cur_col = etape_courante->caseGrille->coord.num_col;

    int cur_lin = etape_courante->caseGrille->coord.num_ligne;

    // coordonnées temporaire des cases adjacentes (<=> voisines)
    // on marque si son passage est possible pour l'ajout en fin de liste
    Etape haut;
    bool haut_possible = false;
    Etape bas;
    bool bas_possible = false;
    Etape gauche;
    bool gauche_possible = false;
    Etape droite;
    bool droite_possible = false;


    // case initialiser avec les coordonées haut, bas, gauche, droite
    Case * une_case_voisine;

    // on initialise la case avec celle du dessus
    une_case_voisine = recuperer_case(pb, cur_lin - 1, cur_col);

    // si on peut aller dans la case du dessus ... :
    if (evaluation(une_case_voisine, pb)) {
        // on associe les pointeurs qu'il faut à l'étape qui sera à traiter
        // cf creer_etape
        haut = creer_etape(recuperer_case(pb, cur_lin - 1, cur_col), etape_courante);
        // on dit qu'on pourra ajouter cette étape au étape à traiter (liste)
        haut_possible = true;
    }

    // on fait pareil pour toutes les cases adjacentes (haut, bas, gauche, droite)
    une_case_voisine = recuperer_case(pb, cur_lin + 1, cur_col);

    if (evaluation(une_case_voisine, pb)) {
        bas = creer_etape(recuperer_case(pb, cur_lin + 1, cur_col), etape_courante);
        bas_possible = true;
    }

    une_case_voisine = recuperer_case(pb, cur_lin, cur_col - 1);

    if (evaluation(une_case_voisine, pb)) {
        gauche = creer_etape(recuperer_case(pb, cur_lin, cur_col - 1), etape_courante);
        gauche_possible = true;
    }

    une_case_voisine = recuperer_case(pb, cur_lin, cur_col + 1);

    if (evaluation(une_case_voisine, pb)) {
        droite = creer_etape(recuperer_case(pb, cur_lin, cur_col + 1), etape_courante);
        droite_possible = true;
    }


    // ajout des cases visitables dans la liste qu'on "retourne"
    if (haut_possible) {
        Ajouter_elem_tete_liste_dynamique_generique(li, &haut, sizeof (Etape));
    }
    if (bas_possible) {
        Ajouter_elem_fin_liste_dynamique_generique(li, &bas, sizeof (Etape));
    }
    if (gauche_possible) {
        Ajouter_elem_fin_liste_dynamique_generique(li, &gauche, sizeof (Etape));
    }
    if (droite_possible) {
        Ajouter_elem_fin_liste_dynamique_generique(li, &droite, sizeof (Etape));
    }

}

/** @author: bastien enjalbert
* \fn void etat_suivants(Etape * etape_a_traiter, Liste_dynamique_generique *traitement, Problem *probleme)
* \brief Trouve les cases utiles au traitemenet et les ajoutes à la liste des étapes à traiter
* \param etape_a_traiter l'étape courante surlaquelle on travaille
* \param traitement la liste des étapes à traiter
* \param etape_courante l'étape courante
* \param probleme le problème (qui contient la grille de toutes les cases et touticuinti)
*/
void etat_suivants(Etape * etape_a_traiter, Liste_dynamique_generique *traitement, Problem *probleme) {


    // liste des cases voisines à la case courante que l'on va tester
    Liste_dynamique_generique cases_voisines;
    Creer_liste_dynamique_generique(&cases_voisines);


    Ajouter_case_voisines(&cases_voisines, etape_a_traiter, probleme);


    for (int it = 1; it <= Taille_liste_dynamique_generique(&cases_voisines); it++) {

        // on itére dans les cases voisines (haut, bas, gauche, droite)
        Etape etape_a_tester;

        Recuperer_elem_ieme_liste_dynamique_generique(&cases_voisines, &etape_a_tester, it, sizeof (Etape));


        Ajouter_elem_fin_liste_dynamique_generique(traitement, &etape_a_tester, sizeof (Etape));


    }
}

/** @author : bastien enjalbert
* \fn Etape Parcours_Larg(Coordonnee coord_arrivee, Problem *problem, Liste_dynamique_generique frontiere)
* \brief trouve le chemin le plus cours pour arriver à l'arrivé
* \param coord_arrivee Coordonnées de l'arrivé
* \param problem pointeur vers le problème (labyrinthe, départ, arrivé, ...)
* \param cases_a_traiter la liste des cases utilisée pour le traitement de l'algo
* \return l'étape finale qui est composée des coordonnées de l'arrivé et du chemin pour y arriver depuis le départ
*/
Etape * Parcours_Larg(Coordonnee coord_arrivee, Problem *problem, Etape * etape_a_traiter, Liste_dynamique_generique * traitement) {

    Case * caseDepart = recuperer_case(problem, problem->depart.num_ligne, problem->depart.num_col);
    // on initialise l'étape de départ
    Etape etapeDepart;
    etapeDepart.precedente = NULL;
    etapeDepart.caseGrille = caseDepart;

    //
    etape_a_traiter = &etapeDepart;
    int i = 1;


    // l'étape courante n'est pas l'arrivé alors on continue le parcours
    while (!(etape_a_traiter->caseGrille->coord.num_col == coord_arrivee.num_col &&
            etape_a_traiter->caseGrille->coord.num_ligne == coord_arrivee.num_ligne)) {

        // on utilise l'étape à traiter pour ensuite
        // traiter les cases voisines pour continuer l'algo
        etat_suivants(etape_a_traiter, traitement, problem);


        // on récupére l'etape à traiter (première de la liste (LIFO))
        // on enlève pas les autres étapes car on en aura besoin pour reconstituer
        // le chemin à la fin
        Recuperer_pointeur_elem_ieme_liste_dynamique_generique(traitement, &etape_a_traiter, i);

        // attention la taille de traimtent varie en fonction du nombre de case voisines visitables !
        if (i < Taille_liste_dynamique_generique(traitement))
            i++;

    }

    return etape_a_traiter;

}

/** @author : bastien enjalbert
* \fn bool etape_est_le_depart(Case cas, Problem * problem)
* \brief Détermine si la case passée en param est l'arrivé ou pas
* \param problem pointeur vers le problème (labyrinthe, départ, arrivé, ...)
* \param cas la case à tester
* \return true si c'est l'arrivé, false sinon
*/
bool etape_est_le_depart(Case cas, Problem * problem) {

    if (cas.coord.num_ligne == problem->depart.num_ligne
            && cas.coord.num_col == problem->depart.num_col) {
        return true;
    } else {
        return false;
    }

}



/**
 * Permet d'afficher le chemin à la fin
 *TODO PETIT PROBLEME le départ n'est pas dans la liste à corriger
 */
void afficher_chemin_etape(Etape *etape_finale, Problem * pb) {


    // pointeur vers les étapes (et on commence par l'arrivé car on remontera le
    // chemin en utilisant les étapes précédentes)
    Etape temp = *etape_finale;
    // case associé à l'étape
    Case cas = *temp.caseGrille;

    // on a besoin des coordonées dans l'ordre inverse car on commence par l'arrivé...
    Liste_dynamique_generique * case_dans_le_bon_ordre = malloc(sizeof(Liste_dynamique_generique));
    Creer_liste_dynamique_generique(case_dans_le_bon_ordre);

    // tant qu'on est pas arrivé au départ
    while (true) {
        Coordonnee coord;
        coord.num_col = cas.coord.num_col;
        coord.num_ligne = cas.coord.num_ligne;


        // on prend l'étape précédente
        temp = *temp.precedente;
        // et sa case associée
        cas = *temp.caseGrille;

        Ajouter_elem_tete_liste_dynamique_generique(case_dans_le_bon_ordre, &coord, sizeof(Coordonnee));

        // TODO bidouillage ici pour simuler que le départ est présente, à corriger ...
        if(&temp == temp.precedente) {
            Coordonnee coord;
            coord.num_col = cas.coord.num_col;
            coord.num_ligne = cas.coord.num_ligne;


            // on prend l'étape précédente
            temp = *temp.precedente;
            // et sa case associée
            cas = *temp.caseGrille;

            Ajouter_elem_tete_liste_dynamique_generique(case_dans_le_bon_ordre, &coord, sizeof(Coordonnee));
            Ajouter_elem_tete_liste_dynamique_generique(case_dans_le_bon_ordre, &pb->depart, sizeof(Coordonnee));
            break;
        }

    }

    printf("Voici les coordonnées de chaque case a emprunter pour arrivé : %d\n\n", Taille_liste_dynamique_generique(case_dans_le_bon_ordre));
    while(Taille_liste_dynamique_generique(case_dans_le_bon_ordre) > 0) {
        Coordonnee coord;

        Enlever_elem_tete_liste_dynamique_generique(case_dans_le_bon_ordre, &coord, sizeof(Coordonnee));

        printf("Coordonnées| LIGNE : %d ::: COLONNE : %d\n", coord.num_ligne, coord.num_col);
    }

    free(case_dans_le_bon_ordre);

}

void Affiche_matrice(Problem *p) {
    printf("nom du labyrinthe : %s\n", p->nom);
    printf("position de depart : %i;%i\n", p->depart.num_ligne, p->depart.num_col);
    printf("position de arrivee : %i;%i\n", p->arrive.num_ligne, p->arrive.num_col);
    printf("nb_ligne : %i; nb_colonne : %i\n", p->nb_ligne, p->nb_colonne);
    for (int i = 0; i < p->nb_ligne; i++) {
        printf("|");
        for (int j = 0; j < p->nb_colonne; j++) {
            if (p->arrive.num_ligne == i && p->arrive.num_col == j) {
                putchar('A');
            } else if (p->depart.num_ligne == i && p->depart.num_col == j) {
                putchar('D');
            } else {
                printf("%c", p->grille[i][j].carac);
            }
        }
        printf("|\n");
    }
}

void lire_fichier(FILE *f, Problem *p) {
    char c;
    fscanf(f, "%s\n", p->nom);
    lire_coordonnee(f, &p->depart);
    lire_coordonnee(f, &p->arrive);
    fscanf(f, "%i\n", &p->nb_ligne);
    fscanf(f, "%i\n", &p->nb_colonne);
    p->grille = (Case **) malloc(sizeof (Case *) * p->nb_ligne);
    if (p->grille == NULL) {
        printf("\nallocation impossible, pas assez de mémoire\n");
        exit(1);
    } else {
        for (int i = 0; i < p->nb_ligne; i++) {
            p->grille[i] = (Case *) malloc(sizeof (Case) * p->nb_colonne);
            if (p->grille[i] == NULL) {
                printf("\nallocation impossible, pas assez de m�moire\n");
                exit(1);
            }
        }
    }

    for (int i = 0; i < p->nb_ligne; i++) {
        for (int j = 0; j < p->nb_colonne; j++) {
            fscanf(f, "%c", &p->grille[i][j].carac);
            p->grille[i][j].coord.num_ligne = i;
            p->grille[i][j].coord.num_col = j;
            p->grille[i][j].marque = false;
            p->grille[i][j].longueur = 0; // TODO

        }
        fscanf(f, "%c", &c); // enl�ve le \n
    }
}

void lire_coordonnee(FILE *f, Coordonnee *c) {
    fscanf(f, "%i\t%i\n", &c->num_ligne, &c->num_col);
}

void libere_matrice(Problem *p) {
    for (int i = 0; i < p->nb_ligne; i++) {
        free(p->grille[i]);
    }
    free(p->grille);
}
