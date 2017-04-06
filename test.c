#include <stdio.h>
#include <stdlib.h>

#include "robot.h"

/**
 * Fichier regroupant les tests effectués sur l'application et ses fonctions
 *
 */


 //********* FONCTIONS DE TESTS *******************//

 // void test_Verif_Etape_Appartient_liste()
 // {
 //     Liste_dynamique_generique cases_marquees;
 //     Creer_liste_dynamique_generique(&cases_marquees);
 //
 //     Etape *et1 = malloc(sizeof(Etape));
 //     Etape *et2 = malloc(sizeof(Etape));
 //     Etape *et3 = malloc(sizeof(Etape));
 //     Etape *et4 = malloc(sizeof(Etape));
 //     Etape *tmp = malloc(sizeof(Etape));
 //     Coordonnee *t1 = malloc(sizeof(Coordonnee));
 //     Coordonnee *t2 = malloc(sizeof(Coordonnee));
 //     Coordonnee *t3 = malloc(sizeof(Coordonnee));
 //     Coordonnee *t4 = malloc(sizeof(Coordonnee));
 //     t1->num_col = 0;
 //     t1->num_ligne = 1;
 //     et1->coord = *t1;
 //
 //     t2->num_col = 1;
 //     t2->num_ligne = 0;
 //     et2->coord = *t2;
 //
 //     t3->num_col = 2;
 //     t3->num_ligne = 0;
 //     et3->coord = *t3;
 //
 //     t4->num_col = 4;
 //     t4->num_ligne = 0;
 //     et4->coord = *t4;
 //
 //
 //     Ajouter_elem_fin_liste_dynamique_generique(&cases_marquees, et1, sizeof(Etape));
 //     Ajouter_elem_fin_liste_dynamique_generique(&cases_marquees, et3, sizeof(Etape));
 //     Ajouter_elem_fin_liste_dynamique_generique(&cases_marquees, et4, sizeof(Etape));
 //
 //     printf("\n\nTest coordonnées : \n");
 //     printf("%d : %d", et3->coord.num_col, et3->coord.num_ligne);
 //     Recuperer_elem_ieme_liste_dynamique_generique(&cases_marquees, tmp, 2, sizeof(Etape));
 //     printf("%d : %d", tmp->coord.num_col, tmp->coord.num_ligne);
 //
 //
 //     printf("\n\nShould be true : \n");
 //     if(Verif_Etape_Appartient_liste(&cases_marquees, et4->coord)) {
 //         printf("true\n");
 //     } else {
 //         printf("false\n");
 //     }
 //
 //     printf("\n\nShould be false : \n");
 //     if(Verif_Etape_Appartient_liste(&cases_marquees, et2->coord)) {
 //         printf("true\n");
 //     } else {
 //         printf("false\n");
 //     }
 //
 //     printf("\n\nShould be true : \n");
 //     if(Verif_Etape_Appartient_liste(&cases_marquees, et3->coord)) {
 //         printf("true\n");
 //     } else {
 //         printf("false\n");
 //     }


 /** @author : Mickaël PERIES
 * \fn void test_tri()
 * \brief Test si le tri marche
 * false sinon
 */
 void test_tri()
 {
   Liste_dynamique_generique a_trier;
   Creer_liste_dynamique_generique(&a_trier);

   Etape etape1;
   etape1.heuristique = 5;
   Etape etape2;
   etape2.heuristique = 2;
   Etape etape3;
   etape3.heuristique = 9;
   Etape etape4;
   etape4.heuristique = 7;

   Ajouter_elem_fin_liste_dynamique_generique(&a_trier, &etape1, sizeof(Etape));
   Ajouter_elem_fin_liste_dynamique_generique(&a_trier, &etape2, sizeof(Etape));
   Ajouter_elem_fin_liste_dynamique_generique(&a_trier, &etape3, sizeof(Etape));
   Ajouter_elem_fin_liste_dynamique_generique(&a_trier, &etape4, sizeof(Etape));

   printf("Liste avant tri: ");
   for (int i = 1; i < Taille_liste_dynamique_generique(&a_trier); i++) {
     Etape temp;
     Recuperer_elem_ieme_liste_dynamique_generique(&a_trier, &temp, i, sizeof(Etape));
     printf("%d ", temp.heuristique);
   }
   printf("\n");
   tri_liste_generique(&a_trier);
   printf("Liste après tri: ");
   for (int i = 1; i < Taille_liste_dynamique_generique(&a_trier); i++) {
     Etape temp;
     Recuperer_elem_ieme_liste_dynamique_generique(&a_trier, &temp, i, sizeof(Etape));
     printf("%d ", temp.heuristique);
   }


 }

 /** @author : benjamin mazoyer
 * \fn void test_compare()
 * \brief Test si la fonction de comparaison fonctionne, qui renvoie true si les coordonnées sont identiques
 * false sinon
 */
 void test_compare() {
    // On créé deux coordonnées qui nous servirons à tester la fonction
    Coordonnee c1, c2;
    // Résultat de la fonction que l'on test
    bool resultat;

    // Cas nominal, le fonction doit nous revoiyé une valeur autre que 0
    c1.num_col = 1;
    c1.num_ligne = 3;
    c2.num_col = 1;
    c2.num_ligne = 3;

    resultat = Compare(c1, c2);
    printf("Test de la fonction compare\n");
    printf("Cas nominal\n");
    // Résultat différent de 0 => true donc le test est réussi
    if (resultat) {
        printf("Test de la fonction compare reussi\n");
    } else {
        printf("Test de la fonction compare fail\n");
    }

    // Numéro de colonne différent, numéro de ligne identique
    c1.num_col = 2;

    resultat = Compare(c1, c2);
    printf("\nNumero de colonne different\n");
    // Résultat égal de 0 => false donc le test est réussi
    if (!resultat) {
        printf("Test de la fonction compare reussi\n");
    } else {
        printf("Test de la fonction compare fail\n");
    }

    // Numéro de colonne identique, numéro de colonne différent
    c1.num_col = 1;
    c1.num_ligne = 2;

    resultat = Compare(c1, c2);
    printf("\nNumero de ligne different\n");
    // Résultat égal de 0 => false donc le test est réussi
    if (!resultat) {
        printf("Test de la fonction compare reussi\n");
    } else {
        printf("Test de la fonction compare fail\n");
    }
 }

 /** @author : benjamin mazoyer
 * \fn void test_case_marquee()
 * \brief Test si la fonction de test de case marquée fonctionne, true si la case est deja présente
 * false sinon
 */
 /*
 void test_case_marquee() {

    // On créé une case et une liste pour tester la fonction
    Case case1;
    Liste_dynamique_generique liste_test;
    bool resultat;

    // Cas nominal, la case est présente dans la liste
    case1.coord.num_col = 1;
    case1.coord.num_ligne = 1;

    // On créé la liste et on y ajoute la case
    Creer_liste_dynamique_generique(&liste_test);
    Ajouter_elem_tete_liste_dynamique_generique(&liste_test, &case1, sizeof(Case));

    printf("\n\nTest de la fonction case_marquee\n");
    resultat = case_marquee(&case1, liste_test);
    printf("Test du cas nominal\n");
    if(resultat) {
        printf("Test de la fonction case_marquee reussi\n");
    } else {
        printf("Test de la fonction case_marquee fail\n");
    }

    // On enlève la case pour tester que la foncion ne retoruve pas la case dans la liste
    Enlever_elem_tete_liste_dynamique_generique(&liste_test, &case1, sizeof(Case));

    resultat = case_marquee(&case1, liste_test);
    printf("Test du cas ou la case n\'est pas presente dans la liste\n");
    if(!resultat) {
        printf("Test de la fonction case_marquee reussi\n");
    } else {
        printf("Test de la fonction case_marquee fail\n");
    }
 }
*/
/** @author : benjamin mazoyer
 * \fn void test_evaluation()
 * \brief Test pour la fonction qui permet de savoir si une case est visitable, true si oui
 * false sinon
 */
 void test_evaluation() {
    // On créé un probleme et des cases
    Problem prob;
    Case case_courante;
    bool resultat;

    // On fait une carte de dimension 3X3
    prob.nb_colonne = 3;
    prob.nb_ligne = 3;

    // CAS NOMINAL
    // On met des coordonnées à la case
    case_courante.coord.num_col = 1;
    case_courante.coord.num_ligne = 1;

    resultat = evaluation(&case_courante,&prob);

    printf("\nTest de la fonction d\'evaluation\n\n");
    printf("Test du cas nominal\n");
    if(resultat) {
        printf("Test de la fonction evaluation reussi\n");
    } else {
        printf("Test de la fonction evaluation fail\n");
    }

    // Cas où la case n'est pas dans le problème
    case_courante.coord.num_col = 4;
    case_courante.coord.num_ligne = 4;

    resultat = evaluation(&case_courante,&prob);

    printf("Test du cas ou la case n'est pas dans le probleme\n");
    if(!resultat) {
        printf("Test de la fonction evaluation reussi\n");
    } else {
        printf("Test de la fonction evaluation fail\n");
    }

    // Cas ou les coordonnées de la case sont inférieures à 0
    case_courante.coord.num_col = -1;
    case_courante.coord.num_ligne = -1;

    resultat = evaluation(&case_courante,&prob);

    printf("Test du cas ou les coordonnes sont < 0\n");
    if(!resultat) {
        printf("Test de la fonction evaluation reussi\n");
    } else {
        printf("Test de la fonction evaluation fail\n");
    }
 }


 int main(void) {
   //test_compare();
   //test_case_marquee();
   //test_evaluation();
	test_tri();
 return 0;
 }

 //********* FIN FONCTIONS DE TESTS *******************//

 /** comparer deux coordonnées
 * @return : 0 si elles sont égales
 */
void test_Verif_Etape_Appartient_liste() {

}
