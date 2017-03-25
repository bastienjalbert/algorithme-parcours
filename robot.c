
#include <stdio.h>
#include <stdlib.h>

#include "robot.h"


// comparer deux coordonnées
// @return : 0 si elles sont égales
int Compare(Coordonnee c1, Coordonnee c2) {

    if(c1.num_col == c2.num_col &&
       c1.num_ligne == c2.num_ligne) {
        return 0;
    }

    return 1;
}

/**
 * Vérifie si une étape est déjà présente dans une liste d'étape passée en argument
 * @return : true l'étape est présente, false sinon
 */
bool Verif_Etape_Appartient_liste(Liste_dynamique_generique * li, Etape etape_courante) {

  // on commence par récupérer la tête de la liste et on initialise le premier élement
  Element_liste_dynamique_generique *tmp;
  tmp = li->psTete;

  // L'étape temporaire dans la liste
  Etape *step_tmp;

  // utile pour comparer les coordonnées de l'étape courante avec celles de la liste
  Coordonnee coord_courante = etape_courante.coord;;
  Coordonnee coord_tmp;


  // on itére dans toute la liste pour essayer de trouver etape_courante
  for(int i = 0 ; i < li->iTaille ; i++) {

    // on récupére les données de l'étape (une structure étape)
    step_tmp = tmp->tdDonnee;

    // on récupére les coordonnées de l'étape temporaire
    coord_tmp = step_tmp->coord;

    // on compare les deux étapes avec leurs coordonnées
    // TODO vérifier si il faut pas faire plus de vérif que avec seulement les coordonnées
    if(Compare(coord_courante, coord_tmp )) {
        return true;
    }
    // on assigne l'élèment d'après à tmp puis on réitére
    //  tmp = tmp.suivant;
    tmp = (li->psTete->ElementSuivant);
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
int etat_suivants(Etape etape_courante, Liste_dynamique_generique etapes_suivantes) {

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

  // Liste des cases autours
  Etape etapes[5] = {*haut, *bas, *gauche, *droite};

  for (int i = 0; i < sizeof(etapes); i++)
  {
    if(!Verif_Etape_Appartient_liste(etape_courante.chemin, etapes[i])) // si on n'est pas déjà passé par cette case
      {

       // on ajoute au chemin l'étape actuelle pour l'enregistre dans la prochaine Etape
       Ajouter_elem_fin_liste_dynamique_generique(etape_courante.chemin, &etape_courante, sizeof(Etape));
       etapes[i].chemin = etape_courante.chemin; // grave vérif
       etapes[i].suivant = NULL; // bouchon

       Ajouter_elem_fin_liste_dynamique_generique(&etapes_suivantes, &etapes[i], sizeof(Etape));

     }
  }

}


// TODO savoir pk un pointeur et comment marche cette méthode
void Parcours_Larg(Etape etape_courante, Coordonnee coord_arrivee,
                     bool evaluation(Coordonnee case_courante,Problem *problem), Problem *problem)
{

  if (etape_courante.coord.num_col == coord_arrivee.num_col
   && etape_courante.coord.num_ligne == coord_arrivee.num_ligne) {
     printf("Vous êtes à l'arrivée");
   } else {

     // On récupère une liste avec tous les prochaines étapes
     Liste_dynamique_generique etapes_suivantes;
     Creer_liste_dynamique_generique(&etapes_suivantes);
     etat_suivants(etape_courante, etapes_suivantes);

     while(Taille_liste_dynamique(&etapes_suivantes) > 0)
     {
       Etape prochaine_etape;
       Enlever_elem_fin_liste_dynamique_generique(&etapes_suivantes, &prochaine_etape, sizeof(Etape));
       Parcours_Larg(prochaine_etape, coord_arrivee, evaluation(prochaine_etape.coord,problem), problem);
     }
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
        printf("\nallocation impossible, pas assez de m�moire\n");
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
