/**
 * Fichier regroupant les tests effectués sur l'application et ses fonctions
 *
 */


 //********* FONCTIONS DE TESTS *******************//

 void test_Verif_Etape_Appartient_liste()
 {
     Liste_dynamique_generique cases_marquees;
     Creer_liste_dynamique_generique(&cases_marquees);

     Etape *et1 = malloc(sizeof(Etape));
     Etape *et2 = malloc(sizeof(Etape));
     Etape *et3 = malloc(sizeof(Etape));
     Etape *et4 = malloc(sizeof(Etape));
     Etape *tmp = malloc(sizeof(Etape));
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

     printf("\n\nTest coordonnées : \n");
     printf("%d : %d", et3->coord.num_col, et3->coord.num_ligne);
     Recuperer_elem_ieme_liste_dynamique_generique(&cases_marquees, tmp, 2, sizeof(Etape));
     printf("%d : %d", tmp->coord.num_col, tmp->coord.num_ligne);


     printf("\n\nShould be true : \n");
     if(Verif_Etape_Appartient_liste(&cases_marquees, et4->coord)) {
         printf("true\n");
     } else {
         printf("false\n");
     }

     printf("\n\nShould be false : \n");
     if(Verif_Etape_Appartient_liste(&cases_marquees, et2->coord)) {
         printf("true\n");
     } else {
         printf("false\n");
     }

     printf("\n\nShould be true : \n");
     if(Verif_Etape_Appartient_liste(&cases_marquees, et3->coord)) {
         printf("true\n");
     } else {
         printf("false\n");
     }


 }
 /*
 int main(void) {


 return 0;
 }*/

 //********* FIN FONCTIONS DE TESTS *******************//

 /** comparer deux coordonnées
 * @return : 0 si elles sont égales
 */
void test_Verif_Etape_Appartient_liste() {

}
