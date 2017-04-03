
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

bool case_marquee(Etape *a_verifier, Liste_dynamique_generique *marquees)
{
  Etape etape_a_tester;
  for (int i = 1; i <= Taille_liste_dynamique_generique(marquees); i++) {

      Recuperer_elem_ieme_liste_dynamique_generique(marquees, &etape_a_tester, i, sizeof (Etape));
      if (etape_a_tester.coord.num_ligne == a_verifier->coord.num_ligne
        && etape_a_tester.coord.num_col == a_verifier->coord.num_col) {
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
bool evaluation(Etape *case_courante,Problem *problem) {

  // coordonnées de la case (<=> étape) courante
  int cur_col = case_courante->coord.num_col;
  int cur_lin = case_courante->coord.num_ligne;

  if(cur_col < 0 || cur_col > problem->nb_colonne // si la case dépasse des bords
    || cur_lin < 0 || cur_lin > problem->nb_ligne // de la carte .... ou
    || problem->carte[cur_lin][cur_col] != ' ' // si la case est un mur
  ) {
    return false;
  }

  return true;

}

/** @author : bastien enjalbert
* \fn Etape creer_etape(Case * caseGrille, Etape * precedente)
* \brief Créer une nouvelle étape à partir d'une case de la grille et d'une autre étape précédente
* \param caseGrille pointeur vers la case de la grille
* \param precedente l'étape précédente a lier
* \param cases_a_traiter la liste des cases utilisée pour le traitement de l'algo
* \return l'étape tout fraichement créée
*/
Etape creer_etape(int num_ligne, int num_col, Etape * precedente) {

    Etape etape;
    etape.coord.num_ligne = num_ligne;
    etape.coord.num_col = num_col;
    etape.precedente = precedente;
    return etape;

}

/** @author: bastien enjalbert, Mickaël PERIES
* \fn void etat_suivants(Etape * etape_a_traiter, Liste_dynamique_generique *traitement, Liste_dynamique_generique *marquees , Problem *probleme)
* \brief Trouve les cases utiles au traitemenet et les ajoutes à la liste des étapes à traiter
* \param etape_a_traiter l'étape courante surlaquelle on travaille
* \param traitement la liste des étapes à traiter
* \param marquees les cases sur lesquelles nous sommes déjà passé
* \param probleme le problème (qui contient la grille de toutes les cases et touticuinti)
*/
void etat_suivants(Etape * etape_a_traiter, Liste_dynamique_generique *traitement,
   Liste_dynamique_generique *marquees, Problem *probleme) {
     // coordonnées de la case (<=> étape) courante
     int cur_col = etape_a_traiter->coord.num_col;
     int cur_lin = etape_a_traiter->coord.num_ligne;

     // Nouvelles étapes à tester
     Etape haut = creer_etape(cur_lin - 1, cur_col, etape_a_traiter);
     Etape bas = creer_etape(cur_lin + 1, cur_col, etape_a_traiter);
     Etape gauche = creer_etape(cur_lin, cur_col - 1, etape_a_traiter);
     Etape droite = creer_etape(cur_lin, cur_col + 1, etape_a_traiter);

    // Liste des cases autours
    Liste_dynamique_generique etapes_possibles;
    Creer_liste_dynamique_generique(&etapes_possibles);
    Ajouter_elem_tete_liste_dynamique_generique(&etapes_possibles, &haut, sizeof(Etape));
    Ajouter_elem_tete_liste_dynamique_generique(&etapes_possibles, &bas, sizeof(Etape));
    Ajouter_elem_tete_liste_dynamique_generique(&etapes_possibles, &gauche, sizeof(Etape));
    Ajouter_elem_tete_liste_dynamique_generique(&etapes_possibles, &droite, sizeof(Etape));

    while(Taille_liste_dynamique_generique(&etapes_possibles) > 0)
    {
      Etape prochaine_etape;
      Enlever_elem_fin_liste_dynamique_generique(&etapes_possibles, &prochaine_etape, sizeof(Etape));;

      if(evaluation(&prochaine_etape,probleme) && !case_marquee(&prochaine_etape, marquees)) // si on n'est pas déjà passé par cette case
      {
         // On ajoute l'étape aux étapes marquées
         Ajouter_elem_fin_liste_dynamique_generique(marquees, &prochaine_etape, sizeof (Coordonnee));

         Ajouter_elem_fin_liste_dynamique_generique(traitement, &prochaine_etape, sizeof(Etape));
      }
    }

}

/** @author : bastien enjalbert, Mickaël PERIES
* \fn Etape Parcours_Larg(Coordonnee coord_arrivee, Problem *problem, Liste_dynamique_generique *traitement, Liste_dynamique_generique * marquees)
* \brief trouve le chemin le plus cours pour arriver à l'arrivé
* \param coord_arrivee Coordonnées de l'arrivé
* \param problem pointeur vers le problème (labyrinthe, départ, arrivé, ...)
* \param cases_a_traiter la liste des cases utilisée pour le traitement de l'algo
* \param marquees les cases sur lesquelles nous sommes déjà passé
* \return l'étape finale qui est composée des coordonnées de l'arrivé et du chemin pour y arriver depuis le départ
*/
Etape * Parcours_Larg(Coordonnee coord_arrivee, Problem *problem, Etape * etape_a_traiter,
                      Liste_dynamique_generique * traitement, Liste_dynamique_generique * marquees)
{
    // on initialise l'étape de départ
    Etape etapeDepart = creer_etape(problem->depart.num_ligne, problem->depart.num_col, NULL);
    Ajouter_elem_tete_liste_dynamique_generique(marquees, &etapeDepart, sizeof(Etape));
    etape_a_traiter = &etapeDepart;
    int i = 1;


    // l'étape courante n'est pas l'arrivé alors on continue le parcours
    while (!(etape_a_traiter->coord.num_col == coord_arrivee.num_col &&
            etape_a_traiter->coord.num_ligne == coord_arrivee.num_ligne)) {

        // on utilise l'étape à traiter pour ensuite
        // traiter les cases voisines pour continuer l'algo
        etat_suivants(etape_a_traiter, traitement, marquees, problem);


        // on récupére l'etape à traiter (première de la liste (LIFO))
        // on enlève pas les autres étapes car on en aura besoin pour reconstituer
        // le chemin à la fin
        Recuperer_pointeur_elem_ieme_liste_dynamique_generique(traitement, &etape_a_traiter, i);

        // DEBUG
        printf("Etape suivante : ligne --> %d colonne --> %d\n", etape_a_traiter->coord.num_col, etape_a_traiter->coord.num_ligne);

        // attention la taille de traimtent varie en fonction du nombre de case voisines visitables !
        if (i < Taille_liste_dynamique_generique(traitement))
            i++;

    }

    printf("Vous êtes bien arrivé !");

    return etape_a_traiter;

}

/** @author : bastien enjalbert
* \fn bool etape_est_le_depart(Case cas, Problem * problem)
* \brief Détermine si la case passée en param est l'arrivé ou pas
* \param problem pointeur vers le problème (labyrinthe, départ, arrivé, ...)
* \param cas la case à tester
* \return true si c'est l'arrivé, false sinon
*/
// bool etape_est_le_depart(Case cas, Problem * problem) {
//
//     if (cas.coord.num_ligne == problem->depart.num_ligne
//             && cas.coord.num_col == problem->depart.num_col) {
//         return true;
//     } else {
//         return false;
//     }
//
// }



/**
 * Permet d'afficher le chemin à la fin
 *TODO PETIT PROBLEME le départ n'est pas dans la liste à corriger
 */
 void afficher_chemin_etape(Etape *etape_finale, Problem * pb) {
//
//
//     // pointeur vers les étapes (et on commence par l'arrivé car on remontera le
//     // chemin en utilisant les étapes précédentes)
//     Etape temp = *etape_finale;
//     // case associé à l'étape
//     Case cas = *temp.caseGrille;
//
//     // on a besoin des coordonées dans l'ordre inverse car on commence par l'arrivé...
//     Liste_dynamique_generique * case_dans_le_bon_ordre = malloc(sizeof(Liste_dynamique_generique));
//     Creer_liste_dynamique_generique(case_dans_le_bon_ordre);
//
//     // tant qu'on est pas arrivé au départ
//     while (true) {
//         Coordonnee coord;
//         coord.num_col = cas.coord.num_col;
//         coord.num_ligne = cas.coord.num_ligne;
//
//
//         // on prend l'étape précédente
//         temp = *temp.precedente;
//         // et sa case associée
//         cas = *temp.caseGrille;
//
//         Ajouter_elem_tete_liste_dynamique_generique(case_dans_le_bon_ordre, &coord, sizeof(Coordonnee));
//
//         // TODO bidouillage ici pour simuler que le départ est présente, à corriger ...
//         if(&temp == temp.precedente) {
//             Coordonnee coord;
//             coord.num_col = cas.coord.num_col;
//             coord.num_ligne = cas.coord.num_ligne;
//
//
//             // on prend l'étape précédente
//             temp = *temp.precedente;
//             // et sa case associée
//             cas = *temp.caseGrille;
//
//             Ajouter_elem_tete_liste_dynamique_generique(case_dans_le_bon_ordre, &coord, sizeof(Coordonnee));
//             Ajouter_elem_tete_liste_dynamique_generique(case_dans_le_bon_ordre, &pb->depart, sizeof(Coordonnee));
//             break;
//         }
//
//     }
//
//     printf("Voici les coordonnées de chaque case a emprunter pour arrivé : %d\n\n", Taille_liste_dynamique_generique(case_dans_le_bon_ordre));
//     while(Taille_liste_dynamique_generique(case_dans_le_bon_ordre) > 0) {
//         Coordonnee coord;
//
//         Enlever_elem_tete_liste_dynamique_generique(case_dans_le_bon_ordre, &coord, sizeof(Coordonnee));
//
//         printf("Coordonnées| LIGNE : %d ::: COLONNE : %d\n", coord.num_ligne, coord.num_col);
//     }
//
//     free(case_dans_le_bon_ordre);
//
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

void lire_coordonnee(FILE *f, Coordonnee *c) {
    fscanf(f, "%i\t%i\n", &c->num_ligne, &c->num_col);
}

void libere_matrice(Problem *p){
    for (int i = 0; i < p->nb_ligne; i++) {
       free(p->carte[i]);
        }
    free(p->carte);
}
