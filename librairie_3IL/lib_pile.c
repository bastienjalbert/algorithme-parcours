# include <stdio.h>
# include <stdlib.h>

#include "lib_pile.h"

/*****************************************************************/
/*****      DECLARARIONS DES PRIMITVES DU TDA PILE STATIQUE  *****/
/*****************************************************************/

/**
 * \fn int Vider_pile_statique (Pile_statique * psPile)
 * \brief fonction pour vider une pile statique
 * \param psPile Pointeur vers une structure pile a vider
 * \return un entier correspondant a 1 si il y a probleme (pointeur null) et 0 sinon
 */

int Vider_pile_statique (Pile_statique * psPile) {
    if (psPile == NULL) {
        printf("erreur adresse pile NULL");
        return 1;
    }
    // on laisse les elements dans le tableau, on modifie juste l'indice de tête pour le reinitialiser
    psPile->iSommet = -1;
    return 0;
}

/**
 * \fn int Creer_pile_statique (Pile_statique * psPile)
 * \brief fonction pour initialiser une pile statique
 * \param psPile Pointeur vers une structure pile a initialiser
 * \return un entier correspondant a 1 si il y a probleme (pointeur null) et 0 sinon
 */
int Creer_pile_statique (Pile_statique * psPile) {
    if (psPile == NULL) {
        printf("erreur adresse pile NULL");
        return 1;
    }
    psPile->iSommet=-1;
    return 0 ;
}

/**
 * \fn int Ajouter_elem_pile_statique(Pile_statique * psPile, TypeDonneePile *pContenu_elem)
 * \brief fonction pour ajouter un element donne a une pile statique
 * \param psPile Pointeur vers une structure pile dans laquelle on va ajouter l'element
 * \param pContenu_elem Pointeur vers le contenu de l'element a ajouter
 * \return un entier correspondant a 1 si il y a probleme de pointeurs (pointeur null), 2 si la pile est pleine et 0 sinon
 */

int Ajouter_elem_pile_statique(Pile_statique * psPile, TypeDonneePile *pContenu_elem) {
    if (psPile == NULL || pContenu_elem == NULL) {
        printf("Erreur adresse pile ou element NULL");
        return 1;
    } else {
        // on verifie la taille
        if(psPile->iSommet>=LGPIL-1) {
            printf("\nErreur pile pleine");
            return 2;
        }
        // si taille et pointeurs ok, on ajoute en tête
        else {
            psPile->iSommet++;
            psPile->TsPile[psPile->iSommet].tdDonnee=*pContenu_elem;
            return 0;
        }
    }
}

/**
 * \fn int Enlever_elem_pile_statique(Pile_statique * psPile, TypeDonneePile *pContenu_elem)
 * \brief fonction pour enlever un element en tête d'une pile statique
 * \param psPile Pointeur vers une structure pile dans laquelle on va enlever un element
 * \param psElem Pointeur vers le contenu de l'element retire
 * \return un entier correspondant a 1 si il y a probleme de pointeurs (pointeur null), 2 si la pile est vide et 0 sinon
 */
int Enlever_elem_pile_statique(Pile_statique * psPile, TypeDonneePile *pContenu_elem){
    if (psPile == NULL || pContenu_elem == NULL) {
        printf("Erreur adresse pile ou element NULL");
        return 1;
    } else {
        // verification de la taille
        if (psPile->iSommet <= -1) {
            printf("\nErreur pile vide");
            return 2;
        } else {
            *pContenu_elem = psPile->TsPile[psPile->iSommet].tdDonnee;
            psPile->iSommet--;
            return 0;
        }
    }
}

/**
 * \fn int sommet_pile_statique(Pile_statique * psPile, TypeDonneePile *pContenu_elem)
 * \brief fonction pour recuperer l'element en tête d'une pile statique sans l'enlever
 * \param psPile Pointeur vers une structure pile dans laquelle on va enlever un element
 * \param psElem Pointeur vers le contenu de l'element recupere en tête
 * \return un entier correspondant a 1 si il y a probleme de pointeurs (pointeur null), 2 si la pile est vide et 0 sinon
 */
int sommet_pile_statique(Pile_statique * psPile, TypeDonneePile *pContenu_elem) {
    if (psPile == NULL || pContenu_elem == NULL) {
        printf("Erreur adresse pile ou element NULL");
        return 1;
    } else {
        if (psPile->iSommet <= -1) {
            printf("\nErreur pile vide");
            return 2;
        } else {
            *pContenu_elem = psPile->TsPile[psPile->iSommet].tdDonnee;
            return 0;
        }
    }
}

/**
 * \fn int test_pile_statique_vide(Pile_statique * psPile)
 * \brief fonction pour tester si une pile statique est vide
 * \param psPile Pointeur vers une structure pile a tester
 * \return un entier correspondant 1 si la pile est vide, 0 si elle l'est et 2 si le pointeur est null
 */
int test_pile_statique_vide(Pile_statique * psPile) {
    if (psPile == NULL) {
        printf("Erreur adresse pile NULL");
        return 2;
    } else {
        if (psPile->iSommet <= -1) {
            return 1;
        } else {
            return 0;
        }
    }
}

/**
 * \fn int Taille_pile_statique(Pile_statique * psPile)
 * \brief fonction qui retourne la taille effective de la pile (nb d elements stocke)
 * \param psPile Pointeur vers une structure pile dont on veut connaitre la taille
 * \return un entier correspondant au nombre d'éléments et -1 si le pointeur est null
 */
int Taille_pile_statique(Pile_statique * psPile){
    if (psPile == NULL){
        printf("Erreur adresse pile NULL");
        return -1;
    } else {
        return psPile->iSommet+1;
    }
}

/*******************Dyna-statique****************************************************/

/**
 * \fn int Vider_pile_dyna_statique (Pile_dyna_statique * psPile)
 * \brief fonction pour vider une pile dyna-statique
 * \param psPile Pointeur vers une structure pile a vider
 * \return un entier correspondant a 1 si il y a probleme (pointeur null) et 0 sinon
 */

int Vider_pile_dyna_statique (Pile_dyna_statique * psPile){
    if (psPile == NULL) {
        printf("erreur adresse pile NULL");
        return 1;
    }
    // on laisse les elements dans le tableau, on modifie juste l'indice de tête pour le reinitialiser
    psPile->iSommet = -1;
    return 0;
}

/**
 * \fn int Creer_pile_dyna_statique (Pile_dyna_statique * psPile, int iNb_max)
 * \brief fonction pour initialiser une pile dyna-statique
 * \param psPile Pointeur vers une structure pile a initialiser
 * \param iNb_max  entier correspondant a la taille initiale
 * \return un entier correspondant a 1 si il y a probleme de pointeur (pointeur null),
 *                                   2 si la taille demandee est inferieure a 1
 *                                   3 si il  n'a pas pu reserver la memoire (retour malloc NULL)
 *                                   et 0 sinon
 */

int Creer_pile_dyna_statique (Pile_dyna_statique * psPile, int iNb_max){
    if (psPile == NULL) {
        printf("erreur adresse pile NULL");
        return 1;
    }
    if (iNb_max < 1){
        printf("erreur taille demandee inferieure a 1");
        return 2;
    }
    psPile->TsPile = (Element_dyna_statique *) malloc( iNb_max *sizeof( Element_dyna_statique ));
    if (psPile->TsPile == NULL){
        printf("\n erreur impossible de reserver de la memoire");
        return 3;
    }
    psPile->taille_affectee_TsPile = iNb_max;
    psPile->iSommet=-1;
    return 0 ;
}

/**
 * \fn int Detruire_pile_dyna_statique (Pile_dyna_statique * psPile)
 * \brief fonction pour detruire une pile dyna-statique
 * \param psPile Pointeur vers une structure pile a detruire
 * \return un entier correspondant a 1 si il y a probleme (pointeur null) et 0 sinon
 */
int Detruire_pile_dyna_statique (Pile_dyna_statique * psPile){
    if (psPile == NULL) {
        printf("erreur adresse pile NULL");
        return 1;
    }
    free(psPile->TsPile);
    return 0 ;
}


/**
 * \fn int Ajouter_elem_pile_dyna_statique(Pile_dyna_statique * psPile, TypeDonneePile *pContenu_elem)
 * \brief fonction pour ajouter un element donne a une pile dyna-statique
 * \param psPile Pointeur vers une structure pile dans laquelle on va ajouter l'element
 * \param psElem Pointeur vers le contenu de l'element a ajouter
 * \return un entier correspondant a 1 si il y a probleme de pointeur (pointeur null),
 *                                   2 si il  n'a pas pu reserver la memoire (retour malloc NULL
 *                                   et 0 sinon
 */
int Ajouter_elem_pile_dyna_statique(Pile_dyna_statique * psPile,TypeDonneePile *pContenu_elem){
    if (psPile == NULL || pContenu_elem == NULL) {
        printf("Erreur adresse pile ou element NULL");
        return 1;
    } else {
        // on verifie la taille
        if(psPile->iSommet>=psPile->taille_affectee_TsPile-1) {
            // augmentation de la zone memoire allouee, on multiple par 2 la taille
            Element_dyna_statique * nouvelle_adress = (Element_dyna_statique *) realloc(psPile->TsPile,psPile->taille_affectee_TsPile*2*sizeof(Element_dyna_statique));
            if (nouvelle_adress == NULL)
            {
                printf("\nerreur reallocation impossible");
                return 2;
            }
            // si l'allocation a fonctionne on met a jour les champs
            psPile->taille_affectee_TsPile*=2;
            psPile->TsPile = nouvelle_adress;
        }
        psPile->iSommet++;
        psPile->TsPile[psPile->iSommet].tdDonnee=*pContenu_elem;
        return 0;
    }
}

/**
 * \fn int Enlever_elem_pile_dyna_statique(Pile_dyna_statique * psPile, TypeDonneePile *pContenu_elem)
 * \brief fonction pour enlever un element en tête d'une pile dyna-statique
 * \param psPile Pointeur vers une structure pile dans laquelle on va enlever un element
 * \param pContenu_elem Pointeur vers le contenu de l'element retire
 * \return un entier correspondant a 1 si il y a probleme de pointeurs (pointeur null), 2 si la pile est vide et 0 sinon
 */
int Enlever_elem_pile_dyna_statique(Pile_dyna_statique * psPile, TypeDonneePile *pContenu_elem){
    if (psPile == NULL || pContenu_elem == NULL) {
        printf("Erreur adresse pile ou element NULL");
        return 1;
    } else {
        // verification de la taille
        if (psPile->iSommet <= -1) {
            printf("\nErreur pile vide");
            return 2;
        } else {
            *pContenu_elem = psPile->TsPile[psPile->iSommet].tdDonnee;
            psPile->iSommet--;
            return 0;
        }
    }
}
/**
 * \fn int sommet_pile_dyna_statique(Pile_dyna_statique * psPile, TypeDonneePile *pContenu_elem)
 * \brief fonction pour recuperer l'element en tête d'une pile dyna-statique sans l'enlever
 * \param psPile Pointeur vers une structure pile dans laquelle on va enlever un element
 * \param pContenu_elem Pointeur vers le contenu de l'element recupere en tête
 * \return un entier correspondant a 1 si il y a probleme de pointeurs (pointeur null), 2 si la pile est vide et 0 sinon
 */
int sommet_pile_dyna_statique(Pile_dyna_statique * psPile, TypeDonneePile *pContenu_elem){
    if (psPile == NULL || pContenu_elem == NULL) {
        printf("Erreur adresse pile ou element NULL");
        return 1;
    } else {
        if (psPile->iSommet <= -1) {
            printf("\nErreur pile vide");
            return 2;
        } else {
            *pContenu_elem = psPile->TsPile[psPile->iSommet].tdDonnee;
            return 0;
        }
    }
}

/**
 * \fn int test_pile_vide_dyna_statique(Pile_dyna_statique * psPile)
 * \brief fonction pour tester si une pile dyna-statique est vide
 * \param psPile Pointeur vers une structure pile a tester
 * \return un entier correspondant 1 si la pile est vide, 0 si elle l'est et 2 si le pointeur est null
 */
int test_pile_vide_dyna_statique(Pile_dyna_statique * psPile){
    if (psPile == NULL) {
        printf("Erreur adresse pile NULL");
        return 2;
    } else {
        if (psPile->iSommet <= -1) {
            return 1;
        } else {
            return 0;
        }
    }
}
/**
 * \fn int Taille_pile_dyna_statique(Pile_dyna_statique * psPile)
 * \brief fonction qui retourne la taille effective de la pile (nb d elements stocke)
 * \param psPile Pointeur vers une structure pile dont on veut connaitre la taille
 * \return un entier correspondant au nombre d'éléments et -1 si le pointeur est null
 */
int Taille_pile_dyna_statique(Pile_dyna_statique * psPile){
    if (psPile == NULL){
        printf("Erreur adresse pile NULL");
        return -1;
    } else {
        return psPile->iSommet+1;
    }
}



/*******************Dynamique non generique : utilisation d'une file dynamique**********************/

/**
 * \fn int Vider_pile_dynamique (Pile_dynamique * psPile)
 * \brief fonction pour vider une pile dynamique
 * \param psPile Pointeur vers une structure pile a vider
 * \return un entier correspondant a 1 si il y a probleme (pointeur null) et 0 sinon
 */

int Vider_pile_dynamique (Pile_dynamique * psPile){
    if (psPile == NULL) {
        printf("erreur adresse pile NULL");
        return 1;
    }
    Vider_liste_dynamique(psPile);
    return 0;
}

/**
 * \fn int Creer_pile_dynamique (Pile_dynamique * psPile)
 * \brief fonction pour initialiser une pile dynamique
 * \param psPile Pointeur vers une structure pile a initialiser
 * \return un entier correspondant a 1 si il y a probleme de pointeur (pointeur null),
 *                                   2 si il  n'a pas pu reserver la memoire (retour malloc NULL)
 *                                   et 0 sinon
 */
int Creer_pile_dynamique (Pile_dynamique * psPile){
    if (psPile == NULL) {
        printf("erreur adresse pile NULL");
        return 1;
    }
    return Creer_liste_dynamique(psPile);
}

/**
 * \fn int Ajouter_elem_pile_dynamique(Pile_dynamique * psPile, TypeDonneePile * pContenu_elem)
 * \brief fonction pour ajouter un element donne a une pile dynamique
 * \param psPile Pointeur vers une structure pile dans laquelle on va ajouter l'element
 * \param pContenu_elem Pointeur vers le contenu a ajouter
 * \return un entier correspondant a 1 si il y a probleme de pointeur (pointeur null),
 *                                   2 si il  n'a pas pu reserver la memoire (retour malloc NULL
 *                                   et 0 sinon
 */
int Ajouter_elem_pile_dynamique(Pile_dynamique * psPile, TypeDonneePile* pContenu_elem){
    if (psPile == NULL || pContenu_elem == NULL) {
        printf("Erreur adresse pile ou element NULL");
        return 1;
    } else {
        return Ajouter_elem_tete_liste_dynamique(psPile,pContenu_elem);
    }
}

/**
 * \fn int Enlever_elem_pile_dynamique(Pile_dynamique * psPile, TypeDonneePile * pContenu_elem )
 * \brief fonction pour enlever un element en tête d'une pile dynamique
 * \param psPile Pointeur vers une structure pile dans laquelle on va enlever un element
 * \param pContenu_elem Pointeur vers le contenu retire
 * \return un entier correspondant a 1 si il y a probleme de pointeurs (pointeur null), 2 si la pile est vide et 0 sinon
 */
int Enlever_elem_pile_dynamique(Pile_dynamique * psPile, TypeDonneePile * pContenu_elem ){
    if (psPile == NULL || pContenu_elem == NULL) {
        printf("Erreur adresse pile ou element NULL");
        return 1;
    } else {
        return Enlever_elem_tete_liste_dynamique(psPile, pContenu_elem);
    }
}
/**
 * \fn int sommet_pile_dynamique(Pile_dynamique * psPile, TypeDonneePile * pContenu_elem )
 * \brief fonction pour recuperer l'element en tête d'une pile dynamique sans l'enlever
 * \param psPile Pointeur vers une structure pile dans laquelle on va enlever un element
 * \param pContenu_elem Pointeur vers le contenu recupere en tête
 * \return un entier correspondant a 1 si il y a probleme de pointeurs (pointeur null), 2 si la pile est vide et 0 sinon
 */
int sommet_pile_dynamique(Pile_dynamique * psPile, TypeDonneePile * pContenu_elem ){
    if (psPile == NULL || pContenu_elem == NULL) {
        printf("Erreur adresse pile ou element NULL");
        return 1;
    } else {
            return tete_liste_dynamique(psPile,pContenu_elem);
    }
}

/**
 * \fn int test_pile_dynamique_vide(Pile_dynamique * psPile)
 * \brief fonction pour tester si une pile dynamique est vide
 * \param psPile Pointeur vers une structure pile a tester
 * \return un entier correspondant 1 si la pile est vide, 0 si elle l'est et 2 si le pointeur est null
 */
int test_pile_dynamique_vide(Pile_dynamique * psPile){
    if (psPile == NULL) {
        printf("Erreur adresse pile NULL");
        return 2;
    } else {
        return test_liste_dynamique_vide(psPile);
    }
}
/**
 * \fn int Taille_pile_dynamique(Pile_dynamique * psPile)
 * \brief fonction qui retourne la taille effective de la pile (nb d elements stocke)
 * \param psPile Pointeur vers une structure pile dont on veut connaitre la taille
 * \return un entier correspondant au nombre d'elements et -1 si le pointeur est null
 */
int Taille_pile_dynamique(Pile_dynamique * psPile){
    if (psPile == NULL){
        printf("Erreur adresse pile NULL");
        return -1;
    } else {
        return Taille_liste_dynamique(psPile);
    }
}

/**
 * \fn void Afficher_pile_dynamique(Pile_dynamique * psPile)
 * \brief fonction qui affiche la pile dynamique
 * \param psPile Pointeur vers une structure pile a afficher
 */
void Afficher_pile_dynamique(Pile_dynamique * psPile){
   if (psPile == NULL){
        printf("Erreur adresse pile NULL");
    } else {
        Afficher_liste_dynamique(psPile);
    }
}

/**********************************version 5 : pile dynamique generique *********************************************/

/**
 * \fn int Vider_pile_dynamique_generique (Pile_dynamique_generique * psPile,size_t taille_donnee)
 * \brief fonction pour vider une pile dynamique
 * \param psPile Pointeur vers une structure pile a vider
 * \return un entier correspondant a 1 si il y a probleme (pointeur null) et 0 sinon
 */

int Vider_pile_dynamique_generique (Pile_dynamique_generique * psPile,size_t taille_donnee){
    if (psPile == NULL) {
        printf("erreur adresse pile NULL");
        return 1;
    }
    Vider_liste_dynamique_generique(psPile,taille_donnee);
    return 0;
}

/**
 * \fn int Creer_pile_dynamique_generique (Pile_dynamique_generique * psPile)
 * \brief fonction pour initialiser une pile dynamique
 * \param psPile Pointeur vers une structure pile a initialiser
 * \return un entier correspondant a 1 si il y a probleme (pointeur null) et 0 sinon
 */
int Creer_pile_dynamique_generique (Pile_dynamique_generique * psPile){
    if (psPile == NULL) {
        printf("erreur adresse pile NULL");
        return 1;
    }
    return Creer_liste_dynamique_generique(psPile);
}

/**
 * \fn int Ajouter_elem_pile_dynamique_generique(Pile_dynamique_generique * psPile, TypeDonneePileGenerique pContenu_elem,size_t taille_donnee)
 * \brief fonction pour ajouter un element donne a une pile dynamique
 * \param psPile Pointeur vers une structure pile dans laquelle on va ajouter l'element
 * \param pContenu_elem Pointeur vers le contenu de l'element a ajouter
 * \return un entier correspondant a 1 si il y a probleme de pointeurs (pointeur null), 2 si la pile est pleine et 0 sinon
 */

int Ajouter_elem_pile_dynamique_generique(Pile_dynamique_generique * psPile, TypeDonneePileGenerique pContenu_elem,size_t taille_donnee){
    if (psPile == NULL || pContenu_elem == NULL) {
        printf("Erreur adresse pile ou element NULL");
        return 1;
    } else {
        return Ajouter_elem_tete_liste_dynamique_generique(psPile,pContenu_elem,taille_donnee);
    }
}

/**
 * \fn int Enlever_elem_pile_dynamique_generique(Pile_dynamique_generique * psPile, TypeDonneePileGenerique pContenu_elem,size_t taille_donnee )
 * \brief fonction pour enlever un element en tête d'une pile dynamique
 * \param psPile Pointeur vers une structure pile dans laquelle on va enlever un element
 * \param pContenu_elem Pointeur vers le contenu de l'element retire
 * \return un entier correspondant a 1 si il y a probleme de pointeurs (pointeur null), 2 si la pile est vide et 0 sinon
 */
int Enlever_elem_pile_dynamique_generique(Pile_dynamique_generique * psPile, TypeDonneePile *pContenu_elem ,size_t taille_donnee){
    if (psPile == NULL || pContenu_elem == NULL) {
        printf("Erreur adresse pile ou element NULL");
        return 1;
    } else {
        return Enlever_elem_tete_liste_dynamique_generique(psPile, pContenu_elem,taille_donnee);
    }
}
/**
 * \fn int sommet_pile(Pile_dynamique_generique * psPile, TypeDonneePileGenerique pContenu_elem ,size_t taille_donnee )
 * \brief fonction pour recuperer l'element en tête d'une pile dynamique sans l'enlever
 * \param psPile Pointeur vers une structure pile dans laquelle on va enlever un element
 * \param pContenu_elem Pointeur vers le contenu de l'element recupere en tête
 * \return un entier correspondant a 1 si il y a probleme de pointeurs (pointeur null), 2 si la pile est vide et 0 sinon
 */
int sommet_pile_dynamique_generique(Pile_dynamique_generique * psPile, TypeDonneePileGenerique pContenu_elem,size_t taille_donnee){
    if (psPile == NULL || pContenu_elem == NULL) {
        printf("Erreur adresse pile ou element NULL");
        return 1;
    } else {
            return tete_liste_dynamique_generique(psPile,pContenu_elem,taille_donnee);
    }
}

/**
 * \fn int test_pile_dynamique_generique_vide(Pile_dynamique_generique * psPile)
 * \brief fonction pour tester si une pile dynamique est vide
 * \param psPile Pointeur vers une structure pile a tester
 * \return un entier correspondant 1 si la pile est vide, 0 si elle l'est et 2 si le pointeur est null
 */
int test_pile_dynamique_generique_vide(Pile_dynamique_generique * psPile){
    if (psPile == NULL) {
        printf("Erreur adresse pile NULL");
        return 2;
    } else {
        return test_liste_dynamique_generique_vide(psPile);
    }
}

/**
 * \fn int Taille_pile_dynamique_generique(Pile_dynamique_generique * psPile)
 * \brief fonction qui retourne la taille effective de la pile dynamique (nb d elements stocke)
 * \param psPile Pointeur vers une structure pile dont on veut connaitre la taille
 * \return un entier correspondant au nombre d'éléments et -1 si le pointeur est null
 */
int Taille_pile_dynamique_generique(Pile_dynamique_generique * psPile){
    if (psPile == NULL){
        printf("Erreur adresse pile NULL");
        return -1;
    } else {
        return Taille_liste_dynamique_generique(psPile);
    }
}


/**
 * \fn void Afficher_pile_dynamique_generique(Pile_dynamique_generique * psPile, void (*pfAfficher_Contenu_element_pile_dynamique_generique)(TypeDonneePileGenerique psDonnee))
 * \brief fonction qui affiche la pile dynamique
 * \param psPile Pointeur vers une structure pile a afficher
 */
void Afficher_pile_dynamique_generique(Pile_dynamique_generique * psPile, void (*pfAfficher_Contenu_element_pile_dynamique_generique)(TypeDonneePileGenerique psDonnee)){
   if (psPile == NULL){
        printf("Erreur adresse pile NULL");
    } else {
        Afficher_liste_dynamique_generique(psPile,pfAfficher_Contenu_element_pile_dynamique_generique);
    }
}

/**************************Pile dyna statique generique ***********************/

/**
 * \fn int Vider_pile_statique_generique (Pile_statique_generique * psPile,size_t taille_donnee)
 * \brief fonction pour vider une pile statique
 * \param psPile Pointeur vers une structure pile a vider
 * \return un entier correspondant a 1 si il y a probleme (pointeur null) et 0 sinon
 */

int Vider_pile_statique_generique (Pile_statique_generique * psPile,size_t taille_donnee){
    if (psPile == NULL) {
        printf("erreur adresse pile NULL");
        return 1;
    }
    Vider_liste_statique_generique(psPile,taille_donnee);
    return 0;
}

/**
 * \fn int Creer_pile_statique_generique (Pile_statique_generique * psPile, int iNbMax)
 * \brief fonction pour initialiser une pile statique
 * \param psPile Pointeur vers une structure pile a initialiser
 * \return un entier correspondant a 1 si il y a probleme (pointeur null) et 0 sinon
 */
int Creer_pile_statique_generique (Pile_statique_generique * psPile, int iNbMax){
    if (psPile == NULL) {
        printf("erreur adresse pile NULL");
        return 1;
    }
    return Creer_liste_statique_generique(psPile, iNbMax);
}

/**
 * \fn int Ajouter_elem_pile_statique_generique(Pile_statique_generique * psPile, TypeDonneePileGenerique pContenu_elem,size_t taille_donnee)
 * \brief fonction pour ajouter un element donne a une pile statique
 * \param psPile Pointeur vers une structure pile dans laquelle on va ajouter l'element
 * \param pContenu_elem Pointeur vers le contenu de l'element a ajouter
 * \return un entier correspondant a 1 si il y a probleme de pointeurs (pointeur null), 2 si la pile est pleine et 0 sinon
 */

int Ajouter_elem_pile_statique_generique(Pile_statique_generique * psPile, TypeDonneePileGenerique pContenu_elem,size_t taille_donnee){
    if (psPile == NULL || pContenu_elem == NULL) {
        printf("Erreur adresse pile ou element NULL");
        return 1;
    } else {
        return Ajouter_elem_fin_liste_statique_generique(psPile,pContenu_elem,taille_donnee);
    }
}

/**
 * \fn int Enlever_elem_pile_statique_generique(Pile_statique_generique * psPile, TypeDonneePileGenerique pContenu_elem,size_t taille_donnee )
 * \brief fonction pour enlever un element en tête d'une pile statique
 * \param psPile Pointeur vers une structure pile dans laquelle on va enlever un element
 * \param pContenu_elem Pointeur vers le contenu de l'element retire
 * \return un entier correspondant a 1 si il y a probleme de pointeurs (pointeur null), 2 si la pile est vide et 0 sinon
 */
int Enlever_elem_pile_statique_generique(Pile_statique_generique * psPile, TypeDonneePile *pContenu_elem ,size_t taille_donnee){
    if (psPile == NULL || pContenu_elem == NULL) {
        printf("Erreur adresse pile ou element NULL");
        return 1;
    } else {
        return Enlever_elem_fin_liste_statique_generique(psPile, pContenu_elem,taille_donnee);
    }
}
/**
 * \fn int sommet_pile(Pile_statique_generique * psPile, TypeDonneePileGenerique pContenu_elem ,size_t taille_donnee )
 * \brief fonction pour recuperer l'element en tête d'une pile statique sans l'enlever
 * \param psPile Pointeur vers une structure pile dans laquelle on va enlever un element
 * \param pContenu_elem Pointeur vers le contenu de l'element recupere en tête
 * \return un entier correspondant a 1 si il y a probleme de pointeurs (pointeur null), 2 si la pile est vide et 0 sinon
 */
int sommet_pile_statique_generique(Pile_statique_generique * psPile, TypeDonneePileGenerique pContenu_elem,size_t taille_donnee){
    if (psPile == NULL || pContenu_elem == NULL) {
        printf("Erreur adresse pile ou element NULL");
        return 1;
    } else {
            return fin_liste_statique_generique(psPile,pContenu_elem,taille_donnee);
    }
}

/**
 * \fn int test_pile_statique_generique_vide(Pile_statique_generique * psPile)
 * \brief fonction pour tester si une pile statique est vide
 * \param psPile Pointeur vers une structure pile a tester
 * \return un entier correspondant 1 si la pile est vide, 0 si elle l'est et 2 si le pointeur est null
 */
int test_pile_statique_generique_vide(Pile_statique_generique * psPile){
    if (psPile == NULL) {
        printf("Erreur adresse pile NULL");
        return 2;
    } else {
        return test_liste_statique_generique_vide(psPile);
    }
}

/**
 * \fn int Taille_pile_statique_generique(Pile_statique_generique * psPile)
 * \brief fonction qui retourne la taille effective de la pile statique (nb d elements stocke)
 * \param psPile Pointeur vers une structure pile dont on veut connaitre la taille
 * \return un entier correspondant au nombre d'éléments et -1 si le pointeur est null
 */
int Taille_pile_statique_generique(Pile_statique_generique * psPile){
    if (psPile == NULL){
        printf("Erreur adresse pile NULL");
        return -1;
    } else {
        return Taille_liste_statique_generique(psPile);
    }
}


/**
 * \fn void Afficher_pile_statique_generique(Pile_statique_generique * psPile, void (*pfAfficher_Contenu_element_pile_statique_generique)(TypeDonneePileGenerique psDonnee))
 * \brief fonction qui affiche la pile statique
 * \param psPile Pointeur vers une structure pile a afficher
 */
void Afficher_pile_statique_generique(Pile_statique_generique * psPile, void (*pfAfficher_Contenu_element_pile_statique_generique)(TypeDonneePileGenerique psDonnee)){
   if (psPile == NULL){
        printf("Erreur adresse pile NULL");
    } else {
        Afficher_liste_statique_generique(psPile,pfAfficher_Contenu_element_pile_statique_generique);
    }
}

