# include <stdio.h>
# include <stdlib.h>
#include <string.h>
#include "lib_liste.h"
/************************** Liste dynamique non generique ************************/
/**
 * \fn int Vider_liste_dynamique (Liste_dynamique * psListe)
 * \brief fonction pour vider une liste dynamique
 * \param psListe Pointeur vers la liste a vider
 * \return un entier correspondant a 1 si il y a probleme (pointeur null) et 0 sinon
 */

int Vider_liste_dynamique (Liste_dynamique * psListe) {
    if (psListe == NULL) {
        printf("erreur adresse liste NULL");
        return 1;
    }
    while(psListe->iTaille!=0) {
        TypeDonneeListe valeur;
        Enlever_elem_fin_liste_dynamique(psListe,&valeur);
    }
    return 0;
}

/**
 * \fn int Creer_liste_dynamique (Liste_dynamique * psListe)
 * \brief fonction pour initialiser une liste dynamique
 * \param psListe Pointeur vers la liste  a initialiser
 * \return un entier correspondant a 1 si il y a probleme (pointeur null) et 0 sinon
 */
int Creer_liste_dynamique (Liste_dynamique * psListe) {
    if (psListe == NULL) {
        printf("erreur adresse liste NULL");
        return 1;
    }
    psListe->iTaille =0;
    psListe->psFin = NULL;
    psListe->psTete = NULL;
    return 0;
}

/**
 * \fn int Ajouter_elem_tete_liste_dynamique(Liste_dynamique * psListe, TypeDonneeListe * pContenu_elem)
 * \brief fonction pour ajouter un element dont le contenu est donne en parametre en tete d une liste dynamique
 * \param psListe Pointeur vers une liste dynamique dans laquelle on va ajouter l element
 * \param pContenu_elem pointeur vers le contenu de l element a ajouter
 * \return un entier correspondant a 1 si il y a probleme de pointeurs (pointeur null), 2 si la reservation de memoire a echoue et 0 sinon
 */

int Ajouter_elem_tete_liste_dynamique(Liste_dynamique * psListe, TypeDonneeListe * pContenu_elem) {
    if (psListe == NULL || pContenu_elem == NULL) {
        printf("erreur adresse liste ou contenu NULL");
        return 1;
    }
    Element_liste_dynamique * psElem_ajout = (Element_liste_dynamique *) malloc(sizeof(Element_liste_dynamique));
    if (psElem_ajout == NULL) {
        printf("\n erreur impossible de reserver de la memoire");
        return 2;
    }
    psElem_ajout->tdDonnee = *pContenu_elem;
    psElem_ajout->Elementprecedent = NULL ;
    psElem_ajout->ElementSuivant = psListe->psTete;
    if(psListe->iTaille != 0)
        psListe->psTete->Elementprecedent = psElem_ajout;
    psListe->psTete = psElem_ajout;
    if (psListe->iTaille == 0) {
        psListe->psFin = psElem_ajout;
    }
    psListe->iTaille ++;
    return 0;
}

/**
 * \fn int Ajouter_elem_fin_liste_dynamique(Liste_dynamique * psListe, TypeDonneeListe * pContenu_elem)
 * \brief fonction pour ajouter un element dont le contenu est donne en parametre en fin d une liste dynamique
 * \param psListe Pointeur vers une liste dynamique dans laquelle on va ajouter l element
 * \param pContenu_elem pointeur vers le contenu de l element a ajouter
 * \return un entier correspondant a 1 si il y a un probleme de pointeurs (pointeur null), 2 si la reservation de memoire a echoue et 0 sinon
 */

int Ajouter_elem_fin_liste_dynamique(Liste_dynamique * psListe, TypeDonneeListe * pContenu_elem) {
    if (psListe == NULL || pContenu_elem == NULL) {
        printf("erreur adresse liste ou contenu NULL");
        return 1;
    }
    Element_liste_dynamique * psElem_ajout = (Element_liste_dynamique *) malloc(sizeof(Element_liste_dynamique));
    if (psElem_ajout == NULL) {
        printf("\n erreur impossible de reserver de la memoire");
        return 2;
    }
    psElem_ajout->tdDonnee = *pContenu_elem;
    psElem_ajout->Elementprecedent = psListe->psFin ;
    psElem_ajout->ElementSuivant = NULL;
    if(psListe->iTaille != 0)
        psListe->psFin->ElementSuivant = psElem_ajout;
    psListe->psFin = psElem_ajout;
    if (psListe->iTaille == 0) {
        psListe->psTete = psElem_ajout;
    }
    psListe->iTaille ++;
    return 0;
}

/**
 * \fn int Enlever_elem_tete_liste_dynamique(Liste_dynamique * psListe, TypeDonneeListe * pContenu_elem)
 * \brief fonction pour enlever un element en tete d'une liste dynamique et retourner sa valeur
 * \param psListe Pointeur vers une liste dynamique dans laquelle on va enlever un element
 * \param contenu_elem adresse remplie avec le contenu de l element en tete
 * \return un entier correspondant a 1 si il y a un probleme de pointeurs (pointeur null), 2 si la liste est vide et 0 sinon
 */
int Enlever_elem_tete_liste_dynamique(Liste_dynamique * psListe, TypeDonneeListe * pContenu_elem) {
    if (psListe == NULL || pContenu_elem == NULL) {
        printf("erreur adresse liste ou case resultat NULL");
        return 1;
    }
    if(psListe->iTaille <= 0) {
        printf("\nErreur liste vide");
        return 2;
    }
    *pContenu_elem = psListe->psTete->tdDonnee;
    Element_liste_dynamique * elem_enleve = psListe->psTete;
    psListe->psTete = elem_enleve->ElementSuivant;
    if(psListe->iTaille > 1)
        psListe->psTete->Elementprecedent = NULL;
    psListe->iTaille--;
    free(elem_enleve);
    // si il y a plus d element, mettre le fin a NULL
    if (psListe->iTaille == 0) {
        psListe->psFin = NULL;
    }
    return 0;
}

/**
 * \fn int Enlever_elem_fin_liste_dynamique(Liste_dynamique * psListe, TypeDonnee * contenu_elem)
 * \brief fonction pour enlever un element en fin d'une liste dynamique et retourner sa valeur
 * \param psListe Pointeur vers une liste dynamique dans laquelle on va enlever un element
 * \param contenu_elem adresse remplie avec le contenu de l element en tete
 * \return un entier correspondant a 1 si il y a probleme de pointeurs (pointeur null), 2 si la liste est vide et 0 sinon
 */
int Enlever_elem_fin_liste_dynamique(Liste_dynamique * psListe, TypeDonneeListe  * pContenu_elem) {
    if (psListe == NULL || pContenu_elem == NULL) {
        printf("erreur adresse liste ou case resultat NULL");
        return 1;
    }
    if(psListe->iTaille <= 0) {
        printf("\nErreur liste vide");
        return 2;
    }
    *pContenu_elem = psListe->psFin->tdDonnee;
    Element_liste_dynamique * elem_enleve = psListe->psFin;
    psListe->psFin = elem_enleve->Elementprecedent;
    if(psListe->iTaille > 1)
        psListe->psFin->ElementSuivant = NULL ;
    psListe->iTaille--;
    free(elem_enleve);
    // si il y a plus d element, mettre le fin a NULL
    if (psListe->iTaille == 0) {
        psListe->psTete = NULL;
    }
    return 0;
}

/**
 * \fn int tete_liste_dynamique(Liste_dynamique * psListe, TypeDonneeListe * pContenu_elem)
 * \brief fonction pour recuperer l element en tete d une liste dynamique sans l enlever
 * \param psListe Pointeur vers une liste dynamique dont on veut le contenu de l element de tete
 * \param contenu_elem adresse remplie avec le contenu de l element en tete
 * \return un entier correspondant a 1 si il y a probleme de pointeurs (pointeur null), 2 si la liste est vide et 0 sinon
 */
int tete_liste_dynamique(Liste_dynamique * psListe, TypeDonneeListe * pContenu_elem) {
    if (psListe == NULL || pContenu_elem == NULL) {
        printf("erreur adresse liste ou case resultat NULL");
        return 1;
    }
    if(psListe->iTaille <= 0) {
        printf("\nErreur liste vide");
        return 2;
    }
    *pContenu_elem = psListe->psTete->tdDonnee;
    return 0;
}
/**
 * \fn int fin_liste_dynamique(Liste_dynamique * psListe, TypeDonneeListe * pContenu_elem)
 * \brief fonction pour recuperer l element en fin d une liste dynamique sans l enlever
 * \param psListe Pointeur vers une liste dynamique dont on veut le contenu de l element de fin
 * \param contenu_elem adresse remplie avec le contenu de l element en fin
 * \return un entier correspondant a 1 si il y a probleme de pointeurs (pointeur null), 2 si la liste est vide et 0 sinon
 */
int fin_liste_dynamique(Liste_dynamique * psListe, TypeDonneeListe * pContenu_elem) {
    if (psListe == NULL || pContenu_elem == NULL) {
        printf("erreur adresse liste ou case resultat NULL");
        return 1;
    }
    if(psListe->iTaille <= 0) {
        printf("\nErreur liste vide");
        return 2;
    }
    *pContenu_elem = psListe->psFin->tdDonnee;
    return 0;
}

/**
 * \fn int test_liste_dynamique_vide(Liste_dynamique * psListe)
 * \brief fonction pour tester si une liste dynamique est vide
 * \param psListe Pointeur vers la liste dynamique a tester
 * \return un entier correspondant 1 si la liste est vide, 0 si elle ne l'est pas et 2 si le pointeur est null
 */
int test_liste_dynamique_vide(Liste_dynamique * psListe) {
    if (psListe == NULL) {
        printf("Erreur adresse liste NULL");
        return 2;
    } else {
        if (psListe->iTaille == 0) {
            return 1;
        } else {
            return 0;
        }
    }
}

/**
 * \fn int Taille_liste_dynamique(Liste_dynamique * psListe)
 * \brief fonction qui retourne la taille de la liste dynamique (nb d elements stockes)
 * \param psListe Pointeur vers la liste dynamique dont on veut connaitre la taille
 * \return un entier correspondant au nombre d'éléments et -1 si le pointeur est null
 */
int Taille_liste_dynamique(Liste_dynamique * psListe) {
    if (psListe == NULL) {
        printf("Erreur adresse liste NULL");
        return -1;
    } else {
        return psListe->iTaille;
    }
}

/**
 * \fn void Afficher_Contenu_element_liste_dynamique(TypeDonneeListe * psDonnee)
 * \brief fonction qui affiche la liste dynamique
 * \param psListe Pointeur vers la liste dynamique
 * \return un entier correspondant à -1 si le pointeur est null et 0 sinon
 */
void Afficher_Contenu_element_liste_dynamique(TypeDonneeListe * psDonnee) {
    if (psDonnee == NULL) {
        printf("Erreur adresse donnee NULL");
    }
    printf("%f\n", *psDonnee);

}

/**
 * \fn int Afficher_liste_dynamique(Liste_dynamique * psListe)
 * \brief fonction qui affiche la liste dynamique
 * \param psListe Pointeur vers la liste dynamique
 * \return un entier correspondant à -1 si le pointeur est null et 0 sinon
 */
int Afficher_liste_dynamique(Liste_dynamique * psListe) {
    if (psListe == NULL) {
        printf("Erreur adresse liste NULL");
        return -1;
    } else {
        // printf("Liste :\n");
        Element_liste_dynamique * psElem = psListe->psTete;
        while (psElem!=NULL) {
            // pour le debug j affiche tout
            //     printf("Element %p: %f, prec :%p, suiv:%p\n",psElem,psElem->tdDonnee,psElem->Elementprecedent,psElem->ElementSuivant);
            // sinon que le contenu
            Afficher_Contenu_element_liste_dynamique(&psElem->tdDonnee);
            psElem = psElem->ElementSuivant;
        }
        return 0;

    }
}

/********************* Liste dynamique generique **********************************/

/**
 * \fn int Recuperer_elem_fin_liste_dynamique_generique(Liste_dynamique_generique * psListe, TypeDonnee contenu_elem)
 * \brief fonction pour recuperer un element en fin d'une liste dynamique et retourner sa valeur
 * \param psListe Pointeur vers une liste dynamique dans laquelle on va enlever un element
 * \param contenu_elem adresse remplie avec le contenu de l element en tete
 * \return un entier correspondant a 1 si il y a probleme de pointeurs (pointeur null), 2 si la liste est vide et 0 sinon
 */
int Recuperer_elem_fin_liste_dynamique_generique(Liste_dynamique_generique * psListe, TypeDonneeListeGenerique  pContenu_elem,size_t taille_donnee) {
    if (psListe == NULL || pContenu_elem == NULL) {
        printf("erreur adresse liste ou case resultat NULL");
        return 1;
    }
    if(psListe->iTaille <= 0) {
        printf("\nErreur liste vide");
        return 2;
    }
    memcpy(pContenu_elem,psListe->psFin->tdDonnee,taille_donnee);

    return 0;
}


/** @author: groupe
 * \fn int Recuperer_elem_tete_liste_dynamique_generique(Liste_dynamique_generique * psListe, TypeDonneeListeGenerique pContenu_elem)
 * \brief fonction pour recuperer un element en tete d'une liste dynamique et retourner sa valeur
 * \param psListe Pointeur vers une liste dynamique dans laquelle on va enlever un element
 * \param contenu_elem adresse remplie avec le contenu de l element en tete
 * \return un entier correspondant a 1 si il y a un probleme de pointeurs (pointeur null), 2 si la liste est vide et 0 sinon
 */
int Recuperer_elem_tete_liste_dynamique_generique(Liste_dynamique_generique * psListe, TypeDonneeListeGenerique pContenu_elem,size_t taille_donnee) {
    if (psListe == NULL || pContenu_elem == NULL) {
        printf("erreur adresse liste ou case resultat NULL");
        return 1;
    }
    if(psListe->iTaille <= 0) {
        printf("\nErreur liste vide");
        return 2;
    }
    memcpy(pContenu_elem,psListe->psTete->tdDonnee,taille_donnee);

    return 0;
}

/** @author : bastien enjalbert
 * \fn int Recuperer_elem_ieme_liste_dynamique_generique(Liste_dynamique_generique * psListe, TypeDonneeListeGenerique contenu_elem,size_t taille_donnee, int iPlace_enleve)
 * \brief fonction pour recuperer un element en ieme position d'une liste dynamique et retourner sa valeur
 * \param psListe Pointeur vers une liste dynamique dans laquelle on va enlever un element
 * \param contenu_elem adresse remplie avec le contenu de l element en tete
 * \param taille_donnee taille du contenu a stocke
 * \param iPlace_enleve place d ajout de l element    remarque : 1 <= iPlace_enleve <= iTaille
 * \return un entier correspondant a 1 si il y a probleme de pointeurs (pointeur null), 2 si la liste est vide, , 3 si le numero de la place n existe pas et 0 sinon
 */
int Recuperer_elem_ieme_liste_dynamique_generique(Liste_dynamique_generique * psListe, TypeDonneeListeGenerique pContenu_elem, int iPlace_enleve, int taille_donnee){
    int iCompteur_element = 1;
    if (psListe == NULL || pContenu_elem == NULL) {
        printf("erreur adresse liste ou contenu NULL");
        return 1;
    }
    if (psListe->iTaille <= 0) {
        printf("\n erreur impossible liste vide");
        return 2;
    }
    if(iPlace_enleve > psListe->iTaille || iPlace_enleve <= 0){
        printf("\n erreur place inexistante dans la liste");
        return 3;
    }
    if(iPlace_enleve == 1 ){
        return Recuperer_elem_tete_liste_dynamique_generique(psListe,pContenu_elem,taille_donnee);
    }
    if(iPlace_enleve == psListe->iTaille){
        return Recuperer_elem_fin_liste_dynamique_generique(psListe,pContenu_elem,taille_donnee);
    }
    // recherche de l element en i eme position actuellement
    Element_liste_dynamique_generique * psElem_i_eme = psListe->psTete;
    while(iCompteur_element<iPlace_enleve){
        psElem_i_eme = psElem_i_eme->ElementSuivant;
        iCompteur_element++;
    }
    memcpy(pContenu_elem,psElem_i_eme->tdDonnee,taille_donnee);

    return 0;
}

/** @author : bastien enjalbert
 * \fn int Dupliquer_liste_dynamique_generique (Liste_dynamique_generique * psListe)
 * \brief fonction pour dupliquer une liste dynamique générique dans une autre, cette fonction garde intacte les données (aucun free)
 * \param psListe Pointeur vers la liste  a dupliquer
 * \param aRetourner Pointeur vers la liste  a initialiser
 * \return un entier correspondant a 1 si il y a probleme (pointeur null) et 0 sinon
 */
int Dupliquer_liste_dynamique_generique (Liste_dynamique_generique * psListe, Liste_dynamique_generique * aRetourner, size_t taille_donnee) {
    if (psListe == NULL || aRetourner == NULL) {
        printf("erreur adresse liste  NULL");
        return 1;
    }
    if(Taille_liste_dynamique_generique(aRetourner) != 0) {
        printf("erreur liste qui va contenir les contenus dupliqués pas vide");
        return 1;
    }
    Creer_liste_dynamique_generique(aRetourner);

    TypeDonneeListeGenerique uneValeur;

    // on récupére les valeurs de la liste initiale et on les copies dans la nouvelle liste
    for(int i = 1 ; i <= psListe->iTaille ; i++) {
        // on affecte de la mémoire à une nouvelle données générique
        uneValeur = (TypeDonneeListeGenerique) malloc(taille_donnee);

        // on récupére la donnée dans la liste
        Recuperer_elem_ieme_liste_dynamique_generique(psListe, uneValeur, i, taille_donnee);

        if(i == 1) {
            // on ajoute la nouvelle donnée à la nouvelle liste
            Ajouter_elem_tete_liste_dynamique_generique(aRetourner, uneValeur, taille_donnee);
        } else {
            // on ajoute la nouvelle donnée à la nouvelle liste
            Ajouter_elem_fin_liste_dynamique_generique(aRetourner, uneValeur, taille_donnee);
        }

    }

    return 0;

}



/**
 * \fn int Vider_liste_dynamique_generique (Liste_dynamique_generique * psListe,size_t taille_donnee)
 * \brief fonction pour vider une liste dynamique
 * \param psListe Pointeur vers la liste a vider
 * \return un entier correspondant a 1 si il y a probleme (pointeur null), 2 si il n y a plus de memoire disponible et 0 sinon
 */

int Vider_liste_dynamique_generique (Liste_dynamique_generique * psListe,size_t taille_donnee) {
    if (psListe == NULL) {
        printf("erreur adresse liste NULL");
        return 1;
    }
    TypeDonneeListeGenerique valeur  = (TypeDonneeListeGenerique) malloc(taille_donnee);
    if (valeur == NULL) {
        printf("\n erreur impossible de reserver de la memoire");
        return 2;
    }
    while(psListe->iTaille!=0) {
        Enlever_elem_fin_liste_dynamique_generique(psListe,valeur,taille_donnee);
    }
    return 0;
}

/**
 * \fn int Creer_liste_dynamique_generique (Liste_dynamique_generique * psListe)
 * \brief fonction pour initialiser une liste dynamique
 * \param psListe Pointeur vers la liste  a initialiser
 * \return un entier correspondant a 1 si il y a probleme (pointeur null) et 0 sinon
 */
int Creer_liste_dynamique_generique (Liste_dynamique_generique * psListe) {
    if (psListe == NULL) {
        printf("erreur adresse liste NULL");
        return 1;
    }
    psListe->iTaille =0;
    psListe->psFin = NULL;
    psListe->psTete = NULL;
    return 0;
}

/**
 * \fn int Ajouter_elem_tete_liste_dynamique_generique(Liste_dynamique_generique * psListe, TypeDonneeListeGenerique pContenu_elem)
 * \brief fonction pour ajouter un element dont le contenu est donne en parametre en tete d une liste dynamique
 * \param psListe Pointeur vers une liste dynamique dans laquelle on va ajouter l element
 * \param pContenu_elem pointeur vers le contenu de l element a ajouter
 * \return un entier correspondant a 1 si il y a probleme de pointeurs (pointeur null), 2 si la reservation de memoire a echoue et 0 sinon
 */

int Ajouter_elem_tete_liste_dynamique_generique(Liste_dynamique_generique * psListe, TypeDonneeListeGenerique pContenu_elem,size_t taille_donnee) {
    if (psListe == NULL || pContenu_elem == NULL) {
        printf("erreur adresse liste ou contenu NULL");
        return 1;
    }
    Element_liste_dynamique_generique * psElem_ajout = (Element_liste_dynamique_generique *) malloc(sizeof(Element_liste_dynamique_generique));
    if (psElem_ajout == NULL) {
        printf("\n erreur impossible de reserver de la memoire");
        return 2;
    }
    // reservation de memoire pour stocker les donnees
    TypeDonneeListeGenerique pZoneMemoireDonnee = (TypeDonneeListeGenerique) malloc(taille_donnee);
    if (pZoneMemoireDonnee == NULL) {
        printf("\n erreur impossible de reserver de la memoire");
        return 2;
    }
    // sur proposition de Mr SANSAS utilisation de memcpy
    // avant je faisais avec un pointeur sur fonction comme dans la fonction affichage ci dessous
    memcpy(pZoneMemoireDonnee,pContenu_elem,taille_donnee);
    psElem_ajout->tdDonnee = pZoneMemoireDonnee;
    psElem_ajout->Elementprecedent = NULL ;
    psElem_ajout->ElementSuivant = psListe->psTete;
    if(psListe->iTaille != 0)
        psListe->psTete->Elementprecedent = psElem_ajout;
    psListe->psTete = psElem_ajout;
    if (psListe->iTaille == 0) {
        psListe->psFin = psElem_ajout;
    }
    psListe->iTaille ++;
    return 0;
}

/**
 * \fn int Ajouter_elem_fin_liste_dynamique_generique(Liste_dynamique_generique * psListe, TypeDonneeListeGenerique pContenu_elem)
 * \brief fonction pour ajouter un element dont le contenu est donne en parametre en fin d une liste dynamique
 * \param psListe Pointeur vers une liste dynamique dans laquelle on va ajouter l element
 * \param pContenu_elem pointeur vers le contenu de l element a ajouter
 * \return un entier correspondant a 1 si il y a un probleme de pointeurs (pointeur null), 2 si la reservation de memoire a echoue et 0 sinon
 */

int Ajouter_elem_fin_liste_dynamique_generique(Liste_dynamique_generique * psListe, TypeDonneeListeGenerique pContenu_elem,size_t taille_donnee) {
    if (psListe == NULL || pContenu_elem == NULL) {
        printf("erreur adresse liste ou contenu NULL");
        return 1;
    }
    Element_liste_dynamique_generique * psElem_ajout = (Element_liste_dynamique_generique *) malloc(sizeof(Element_liste_dynamique_generique));
    if (psElem_ajout == NULL) {
        printf("\n erreur impossible de reserver de la memoire");
        return 2;
    }
    // reservation de memoire pour stocker les donnees
    TypeDonneeListeGenerique pZoneMemoireDonnee = (TypeDonneeListeGenerique) malloc(taille_donnee);
    if (pZoneMemoireDonnee == NULL) {
        printf("\n erreur impossible de reserver de la memoire");
        return 2;
    }
    memcpy(pZoneMemoireDonnee,pContenu_elem,taille_donnee);
    psElem_ajout->tdDonnee = pZoneMemoireDonnee;
    psElem_ajout->Elementprecedent = psListe->psFin ;
    psElem_ajout->ElementSuivant = NULL;
    if(psListe->iTaille != 0)
        psListe->psFin->ElementSuivant = psElem_ajout;
    psListe->psFin = psElem_ajout;
    if (psListe->iTaille == 0) {
        psListe->psTete = psElem_ajout;
    }
    psListe->iTaille ++;
    return 0;
}

/**
 * \fn int Ajouter_elem_ieme_liste_dynamique_generique(Liste_dynamique_generique * psListe, TypeDonneeListeGenerique contenu_elem,size_t taille_donnee, int iPlace_ajout)
 * \brief fonction pour ajouter un element dont le contenu est donne en parametre en i eme position d une liste dynamique
 * \param psListe Pointeur vers une liste dynamique dans laquelle on va ajouter l element
 * \param contenu_elem contenu de l element a ajouter
 * \param taille_donnee taille du contenu a stocke
 * \param iPlace_ajout place d ajout de l element  remarque : 1 <= iPlace_ajout <= iTaille+1
 * \return un entier correspondant a 1 si il y a probleme de pointeurs (pointeur null), 2 si la reservation de memoire a echoue, 3 si le numero de la place n existe pas et 0 sinon
 */

int Ajouter_elem_ieme_liste_dynamique_generique(Liste_dynamique_generique * psListe, TypeDonneeListeGenerique pContenu_elem,size_t taille_donnee, int iPlace_ajout) {
    int iCompteur_element = 1;
    if (psListe == NULL || pContenu_elem == NULL) {
        printf("erreur adresse liste ou contenu NULL");
        return 1;
    }
    Element_liste_dynamique_generique * psElem_ajout = (Element_liste_dynamique_generique *) malloc(sizeof(Element_liste_dynamique_generique));
    if (psElem_ajout == NULL) {
        printf("\n erreur impossible de reserver de la memoire");
        return 2;
    }
    if(iPlace_ajout > psListe->iTaille+1 || iPlace_ajout <= 0){
        printf("\n erreur place inexistante dans la liste");
        return 3;
    }
    if(iPlace_ajout == 1 || psListe->iTaille == 0){
        return Ajouter_elem_tete_liste_dynamique_generique(psListe,pContenu_elem,taille_donnee);
    }
    if(iPlace_ajout == psListe->iTaille+1){
        return Ajouter_elem_fin_liste_dynamique_generique(psListe,pContenu_elem,taille_donnee);
    }
    // recherche de l element en i eme position actuellement
    Element_liste_dynamique_generique * psElem_i_eme = psListe->psTete;
    while(iCompteur_element<iPlace_ajout){
        psElem_i_eme = psElem_i_eme->ElementSuivant;
        iCompteur_element++;
    }
    // reservation de memoire pour stocker les donnees
    TypeDonneeListeGenerique pZoneMemoireDonnee = (TypeDonneeListeGenerique) malloc(taille_donnee);
    if (pZoneMemoireDonnee == NULL) {
        printf("\n erreur impossible de reserver de la memoire");
        return 2;
    }
    memcpy(pZoneMemoireDonnee,pContenu_elem,taille_donnee);
    psElem_ajout->tdDonnee = pZoneMemoireDonnee;
    // le precedant du nouveau i eme est le precedant de l ancien i eme
    psElem_ajout->Elementprecedent = psElem_i_eme->Elementprecedent ;
    // le suivant du nouveau i eme est l ancien i eme
    psElem_ajout->ElementSuivant = psElem_i_eme;
    // le suivant du precedant de l'ancien i eme est le nouveau i eme (si il existe)
    if (psElem_i_eme->Elementprecedent != NULL)
        psElem_i_eme->Elementprecedent->ElementSuivant = psElem_ajout;
    // le precedant de l'ancien i eme est le nouveau i eme
    psElem_i_eme->Elementprecedent = psElem_ajout;
    psListe->iTaille ++;
    return 0;
}

/**
 * \fn int Enlever_elem_ieme_liste_dynamique_generique(Liste_dynamique_generique * psListe, TypeDonneeListeGenerique contenu_elem,size_t taille_donnee, int iPlace_enleve)
 * \brief fonction pour enlever un element en ieme position d'une liste dynamique et retourner sa valeur
 * \param psListe Pointeur vers une liste dynamique dans laquelle on va enlever un element
 * \param contenu_elem adresse remplie avec le contenu de l element en tete
 * \param taille_donnee taille du contenu a stocke
 * \param iPlace_enleve place d ajout de l element    remarque : 1 <= iPlace_enleve <= iTaille
 * \return un entier correspondant a 1 si il y a probleme de pointeurs (pointeur null), 2 si la liste est vide, , 3 si le numero de la place n existe pas et 0 sinon
 */
int Enlever_elem_ieme_liste_dynamique_generique(Liste_dynamique_generique * psListe, TypeDonneeListeGenerique pContenu_elem,size_t taille_donnee, int iPlace_enleve ){
    int iCompteur_element = 1;
    if (psListe == NULL || pContenu_elem == NULL) {
        printf("erreur adresse liste ou contenu NULL");
        return 1;
    }
    if (psListe->iTaille <= 0) {
        printf("\n erreur impossible liste vide");
        return 2;
    }
    if(iPlace_enleve > psListe->iTaille || iPlace_enleve <= 0){
        printf("\n erreur place inexistante dans la liste");
        return 3;
    }
    if(iPlace_enleve == 1 ){
        return Enlever_elem_tete_liste_dynamique_generique(psListe,pContenu_elem,taille_donnee);
    }
    if(iPlace_enleve == psListe->iTaille){
        return Enlever_elem_fin_liste_dynamique_generique(psListe,pContenu_elem,taille_donnee);
    }
    // recherche de l element en i eme position actuellement
    Element_liste_dynamique_generique * psElem_i_eme = psListe->psTete;
    while(iCompteur_element<iPlace_enleve){
        psElem_i_eme = psElem_i_eme->ElementSuivant;
        iCompteur_element++;
    }
    memcpy(pContenu_elem,psElem_i_eme->tdDonnee,taille_donnee);
    // le precedant de l ancien i eme devient le precedant du suivant de l'ancien i eme
    psElem_i_eme->ElementSuivant->Elementprecedent = psElem_i_eme->Elementprecedent;
    psElem_i_eme->Elementprecedent->ElementSuivant = psElem_i_eme->ElementSuivant ;
    psListe->iTaille --;
    return 0;
}


/**
 * \fn int Enlever_elem_tete_liste_dynamique_generique(Liste_dynamique_generique * psListe, TypeDonneeListeGenerique pContenu_elem)
 * \brief fonction pour enlever un element en tete d'une liste dynamique et retourner sa valeur
 * \param psListe Pointeur vers une liste dynamique dans laquelle on va enlever un element
 * \param contenu_elem adresse remplie avec le contenu de l element en tete
 * \return un entier correspondant a 1 si il y a un probleme de pointeurs (pointeur null), 2 si la liste est vide et 0 sinon
 */
int Enlever_elem_tete_liste_dynamique_generique(Liste_dynamique_generique * psListe, TypeDonneeListeGenerique pContenu_elem,size_t taille_donnee) {
    if (psListe == NULL || pContenu_elem == NULL) {
        printf("erreur adresse liste ou case resultat NULL");
        return 1;
    }
    if(psListe->iTaille <= 0) {
        printf("\nErreur liste vide");
        return 2;
    }
    memcpy(pContenu_elem,psListe->psTete->tdDonnee,taille_donnee);
    Element_liste_dynamique_generique * elem_enleve = psListe->psTete;
    psListe->psTete = elem_enleve->ElementSuivant;
    if(psListe->iTaille > 1)
        psListe->psTete->Elementprecedent = NULL;
    psListe->iTaille--;
    // il faut maintenant libere aussi la memoire de stockage des donnees
    free(elem_enleve->tdDonnee);
    free(elem_enleve);
    // si il y a plus d element, mettre le fin a NULL
    if (psListe->iTaille == 0) {
        psListe->psFin = NULL;
    }
    return 0;
}

/**
 * \fn int Enlever_elem_fin_liste_dynamique_generique(Liste_dynamique_generique * psListe, TypeDonnee contenu_elem)
 * \author P.PITIOT / Correction R HORVAT / A GUILLON
 * \version 0.2
 * \date 05/04/2016
 * \brief fonction pour enlever un element en fin d'une liste dynamique et retourner sa valeur
 * \param psListe Pointeur vers une liste dynamique dans laquelle on va enlever un element
 * \param contenu_elem adresse remplie avec le contenu de l element en tete
 * \return un entier correspondant a 1 si il y a probleme de pointeurs (pointeur null), 2 si la liste est vide et 0 sinon
 */
int Enlever_elem_fin_liste_dynamique_generique(Liste_dynamique_generique * psListe, TypeDonneeListeGenerique  pContenu_elem,size_t taille_donnee) {
    if (psListe == NULL || pContenu_elem == NULL) {
        printf("erreur adresse liste ou case resultat NULL");
        return 1;
    }
    if(psListe->iTaille <= 0) {
        printf("\nErreur liste vide");
        return 2;
    }
    memcpy(pContenu_elem,psListe->psFin->tdDonnee,taille_donnee);
    Element_liste_dynamique_generique * elem_enleve = psListe->psFin;
    psListe->psFin = elem_enleve->Elementprecedent;
    if(psListe->iTaille > 1)
        psListe->psFin->ElementSuivant = NULL ;
    psListe->iTaille--;
    // il faut maintenant libere aussi la memoire de stockage des donnees
    free(elem_enleve->tdDonnee);
    free(elem_enleve);
    // si il y a plus d element, mettre le fin a NULL
    if (psListe->iTaille == 0) {
        psListe->psTete = NULL;
    }
    return 0;
}

/**
 * \fn int tete_liste_dynamique_generique(Liste_dynamique_generique * psListe, TypeDonneeListeGenerique pContenu_elem)
 * \brief fonction pour recuperer l element en tete d une liste dynamique sans l enlever
 * \param psListe Pointeur vers une liste dynamique dont on veut le contenu de l element de tete
 * \param contenu_elem adresse remplie avec le contenu de l element en tete
 * \return un entier correspondant a 1 si il y a probleme de pointeurs (pointeur null), 2 si la liste est vide et 0 sinon
 */
int tete_liste_dynamique_generique(Liste_dynamique_generique * psListe, TypeDonneeListeGenerique pContenu_elem,size_t taille_donnee) {
    if (psListe == NULL || pContenu_elem == NULL) {
        printf("erreur adresse liste ou case resultat NULL");
        return 1;
    }
    if(psListe->iTaille <= 0) {
        printf("\nErreur liste vide");
        return 2;
    }
    memcpy(pContenu_elem,psListe->psTete->tdDonnee,taille_donnee);
    return 0;
}
/**
 * \fn int fin_liste_dynamique_generique(Liste_dynamique_generique * psListe, TypeDonneeListeGenerique pContenu_elem)
 * \brief fonction pour recuperer l element en fin d une liste dynamique sans l enlever
 * \param psListe Pointeur vers une liste dynamique dont on veut le contenu de l element de fin
 * \param contenu_elem adresse remplie avec le contenu de l element en fin
 * \return un entier correspondant a 1 si il y a probleme de pointeurs (pointeur null), 2 si la liste est vide et 0 sinon
 */
int fin_liste_dynamique_generique(Liste_dynamique_generique * psListe, TypeDonneeListeGenerique pContenu_elem,size_t taille_donnee) {
    if (psListe == NULL || pContenu_elem == NULL) {
        printf("erreur adresse liste ou case resultat NULL");
        return 1;
    }
    if(psListe->iTaille <= 0) {
        printf("\nErreur liste vide");
        return 2;
    }
    memcpy(pContenu_elem,psListe->psFin->tdDonnee,taille_donnee);
    return 0;
}

/**
 * \fn int test_liste_dynamique_generique_vide(Liste_dynamique_generique * psListe)
 * \brief fonction pour tester si une liste dynamique est vide
 * \param psListe Pointeur vers la liste dynamique a tester
 * \return un entier correspondant 1 si la liste est vide, 0 si elle ne l'est pas et 2 si le pointeur est null
 */
int test_liste_dynamique_generique_vide(Liste_dynamique_generique * psListe) {
    if (psListe == NULL) {
        printf("Erreur adresse liste NULL");
        return 2;
    } else {
        if (psListe->iTaille == 0) {
            return 1;
        } else {
            return 0;
        }
    }
}

/**
 * \fn int Taille_liste_dynamique_generique(Liste_dynamique_generique * psListe)
 * \brief fonction qui retourne la taille de la liste dynamique (nb d elements stockes)
 * \param psListe Pointeur vers la liste dynamique dont on veut connaitre la taille
 * \return un entier correspondant au nombre d'éléments et -1 si le pointeur est null
 */
int Taille_liste_dynamique_generique(Liste_dynamique_generique * psListe) {
    if (psListe == NULL) {
        printf("Erreur adresse liste NULL");
        return -1;
    } else {
        return psListe->iTaille;
    }
}


/**
 * \fn int Afficher_liste_dynamique_generique(Liste_dynamique_generique * psListe)
 * \brief fonction qui affiche la liste dynamique
 * \param psListe Pointeur vers la liste dynamique
 * \return un entier correspondant à -1 si le pointeur est null et 0 sinon
 */
int Afficher_liste_dynamique_generique(Liste_dynamique_generique * psListe, void (*Afficher_Contenu_element_liste_dynamique_generique)(TypeDonneeListeGenerique psDonnee)) {
    if (psListe == NULL) {
        printf("Erreur adresse liste NULL");
        return -1;
    } else {
        printf("\nListe :\n");
        Element_liste_dynamique_generique * psElem = psListe->psTete;
        while (psElem!=NULL) {
            // pour le debug j affiche tout
            //    printf("Element %p: %f, prec :%p, suiv:%p\n",psElem,*((float *)psElem->tdDonnee),psElem->Elementprecedent,psElem->ElementSuivant);
            // sinon que le contenu
            (*Afficher_Contenu_element_liste_dynamique_generique)(psElem->tdDonnee);
            psElem = psElem->ElementSuivant;
        }
        return 0;

    }
}

/********************* Liste statique generique **********************************/

/**
 * \fn int Vider_liste_statique_generique (Liste_statique_generique * psListe,size_t taille_donnee)
 * \brief fonction pour vider une liste statique
 * \param psListe Pointeur vers la liste a vider
 * \return un entier correspondant a 1 si il y a probleme (pointeur null), 2 si il n y a plus de memoire disponible et 0 sinon
 */
int Vider_liste_statique_generique (Liste_statique_generique * psListe,size_t taille_donnee) {
    if (psListe == NULL) {
        printf("erreur adresse liste NULL");
        return 1;
    }
    TypeDonneeListeGenerique valeur  = (TypeDonneeListeGenerique) malloc(taille_donnee);
    if (valeur == NULL) {
        printf("\n erreur impossible de reserver de la memoire");
        return 2;
    }
    while(psListe->iTaille!=0) {
        Enlever_elem_fin_liste_statique_generique(psListe,valeur,taille_donnee);
    }
    return 0;
}

/**
 * \fn int Creer_liste_statique_generique (Liste_statique_generique * psListe, int iNb_max)
 * \brief fonction pour initialiser une liste statique
 * \param psListe Pointeur vers la liste  a initialiser
 * \param iNb_max un entier correspondant au nombre d element a stocker (taille initiale)
 * \return un entier correspondant a 1 si il y a probleme de pointeur,
 *                                   2 si la taille est inferieure a 1
 *                                   3 si il  n'a pas pu reserver la memoire (retour malloc NULL)
 *                                   et 0 sinon
 */
int Creer_liste_statique_generique (Liste_statique_generique * psListe, int iNb_max) {
    int iBoucle;            // compteur de boucle
    if (psListe == NULL) {
        printf("erreur adresse liste NULL");
        return 1;
    }
    if (iNb_max < 1) {
        printf("erreur taille liste inferieur a 1");
        return 2;
    }
    // allocation du tableau en dynamique
    psListe->TsListe = (TypeDonneeListeGenerique *) malloc(iNb_max*sizeof(TypeDonneeListeGenerique));
    if (psListe->TsListe == NULL) {
        printf("\n erreur impossible de reserver de la memoire");
        return 3;
    }

    psListe->iFin = -1;
    psListe->iTete = -1;
    psListe->iTaille = 0;
    psListe->iNb_elem_max = iNb_max;
    // initialisation du tableau de pointeur a NULL
    for(iBoucle = 0 ; iBoucle < iNb_max ; iBoucle++ ) {
        psListe->TsListe[iBoucle] = NULL;
    }
    return 0;
}

/**
 * \fn int Detruire_liste_statique_generique (Liste_statique_generique * psListe)
 * \brief fonction pour detruire le tableau de pointeur d une liste statique generique
 * \param psListe Pointeur vers une structure liste a detruire
 * \return un entier correspondant a 1 si il y a probleme de pointeur null, 2 si la liste n est pas vide et 0 sinon
 */
int Detruire_liste_statique_generique (Liste_statique_generique * psListe) {
    if (psListe == NULL) {
        printf("erreur adresse pile NULL");
        return 1;
    }
    if (test_liste_statique_generique_vide(psListe) != 1) {
        printf("liste non vide : enlever element avant destruction (fuite memoire)");
        return 2;
    }
    free(psListe->TsListe);
    return 0 ;
}


/**
 * \fn int Ajouter_elem_tete_liste_statique_generique(Liste_statique_generique * psListe, TypeDonneeListeGenerique contenu_elem,size_t taille_donnee)
 * \brief fonction pour ajouter un element dont le contenu est donne en parametre en tete d une liste statique
 * \param psListe Pointeur vers une liste statique dans laquelle on va ajouter l element
 * \param pContenu_elem contenu de l element a ajouter
 * \param taille_donnee taille de l objet a stocker
 * \return un entier correspondant a 1 si il y a probleme de pointeurs (pointeur null),
 *                                   2 si la taille de l objet est inferieure a 1
 *                                   3 si la reservation de memoire a echouee
 *                                   et 0 sinon
 */

int Ajouter_elem_tete_liste_statique_generique(Liste_statique_generique * psListe, TypeDonneeListeGenerique pContenu_elem,size_t taille_donnee) {
    int iBoucle;
    if (psListe == NULL || pContenu_elem == NULL) {
        printf("Erreur adresse liste ou element NULL");
        return 1;
    }
    if (taille_donnee < 1) {
        printf("Erreur taille element inferieur a 1");
        return 2;
    }
    // on verifie la taille
    if(Taille_liste_statique_generique(psListe) == psListe->iNb_elem_max) {
        // augmentation de la zone memoire allouee, on multiple par I_FACTEUR_REDIMENSIONNEMENT la taille
        TypeDonneeListeGenerique * nouvelle_adresse = (TypeDonneeListeGenerique *) realloc(psListe->TsListe,psListe->iNb_elem_max*I_FACTEUR_REDIMENSIONNEMENT*sizeof(TypeDonneeListeGenerique));
        if (nouvelle_adresse == NULL) {
            printf("\nerreur reallocation impossible");
            return 3;
        }
        // si l'allocation a fonctionne on met a jour les champs
        psListe->TsListe = nouvelle_adresse;
        // il faut maintenant deplacer les elements si tete > fin
        if (psListe->iTete > psListe->iFin) {
            // attention on a pas mis a jour le nb d elem max -> il vaut toujours l'ancienne taille
            for(iBoucle=psListe->iTete; iBoucle < psListe->iNb_elem_max ; iBoucle ++) {
                psListe->TsListe[iBoucle+psListe->iNb_elem_max] = psListe->TsListe[iBoucle];
                psListe->TsListe[iBoucle] = NULL;
            }
            //il faut mettre a jour l indice de tete
            psListe->iTete +=  psListe->iNb_elem_max;
        }
        psListe->iNb_elem_max*=I_FACTEUR_REDIMENSIONNEMENT;
    }
    // reservation de memoire pour stocker les donnees
    TypeDonneeListeGenerique pZoneMemoireDonnee = (TypeDonneeListeGenerique) malloc(taille_donnee);
    if (pZoneMemoireDonnee == NULL) {
        printf("\n erreur impossible de reserver de la memoire");
        return 3;
    }
    memcpy(pZoneMemoireDonnee,pContenu_elem,taille_donnee);
    if(psListe->iTaille == 0) {
        psListe->iTete = 0;
        psListe->iFin = 0;
    } else {
        psListe->iTete--;
        if (psListe->iTete < 0) {
            psListe->iTete = psListe->iNb_elem_max-1;
        }
    }
    psListe->TsListe[psListe->iTete] = pZoneMemoireDonnee;
    psListe->iTaille++;
    return 0;
}
/**
 * \fn int Ajouter_elem_fin_liste_statique_generique(Liste_statique_generique * psListe, TypeDonneeListeGenerique contenu_elem,size_t taille_donnee)
 * \brief fonction pour ajouter un element dont le contenu est donne en parametre en fin d une liste statique
 * \param psListe Pointeur vers une liste statique dans laquelle on va ajouter l element
 * \param pCcontenu_elem contenu de l element a ajouter
 * \param taille_donnee taille de l objet a stocker
 * \return un entier correspondant a 1 si il y a probleme de pointeurs (pointeur null),
 *                                   2 si la taille de l objet est inferieure a 1
 *                                   3 si la reservation de memoire a echouee
 *                                   et 0 sinon
 */
int Ajouter_elem_fin_liste_statique_generique(Liste_statique_generique * psListe, TypeDonneeListeGenerique pContenu_elem,size_t taille_donnee) {
    int iBoucle;
    if (psListe == NULL || pContenu_elem == NULL) {
        printf("Erreur adresse liste ou element NULL");
        return 1;
    }
    if (taille_donnee < 1) {
        printf("Erreur taille element inferieur a 1");
        return 2;
    }
    // on verifie la taille
    if(Taille_liste_statique_generique(psListe) == psListe->iNb_elem_max) {
        // augmentation de la zone memoire allouee, on multiple par I_FACTEUR_REDIMENSIONNEMENT la taille
        TypeDonneeListeGenerique * nouvelle_adresse = (TypeDonneeListeGenerique *) realloc(psListe->TsListe,psListe->iNb_elem_max*I_FACTEUR_REDIMENSIONNEMENT*sizeof(TypeDonneeListeGenerique));
        if (nouvelle_adresse == NULL) {
            printf("\nerreur reallocation impossible");
            return 3;
        }
        // si l'allocation a fonctionne on met a jour les champs
        psListe->TsListe = nouvelle_adresse;
        // il faut maintenant deplacer les elements si tete > fin
        if (psListe->iTete > psListe->iFin) {
            // attention on a pas mis a jour le nb d elem max -> il vaut toujours l'ancienne taille
            for(iBoucle=psListe->iTete; iBoucle < psListe->iNb_elem_max ; iBoucle ++) {
                psListe->TsListe[iBoucle+psListe->iNb_elem_max] = psListe->TsListe[iBoucle];
                psListe->TsListe[iBoucle] = NULL;
            }
            //il faut mettre a jour l indice de tete
            psListe->iTete +=  psListe->iNb_elem_max;
        }
        psListe->iNb_elem_max*=I_FACTEUR_REDIMENSIONNEMENT;
    }
    // reservation de memoire pour stocker les donnees
    TypeDonneeListeGenerique pZoneMemoireDonnee = (TypeDonneeListeGenerique) malloc(taille_donnee);
    if (pZoneMemoireDonnee == NULL) {
        printf("\n erreur impossible de reserver de la memoire");
        return 3;
    }
    memcpy(pZoneMemoireDonnee,pContenu_elem,taille_donnee);
    if(psListe->iTaille == 0) {
        psListe->iTete = 0;
        psListe->iFin = 0;
    } else {
        psListe->iFin++;
        if (psListe->iFin >= psListe->iNb_elem_max) {
            psListe->iFin = 0;
        }
    }
    psListe->TsListe[psListe->iFin] = pZoneMemoireDonnee;
    psListe->iTaille++;
    return 0;
}

/**
 * \fn int Enlever_elem_tete_liste_statique_generique(Liste_statique_generique * psListe, TypeDonneeListeGenerique contenu_elem,size_t taille_donnee)
 * \brief fonction pour enlever un element en tete d'une liste statique et retourner sa valeur
 * \param psListe Pointeur vers une liste statique dans laquelle on va enlever un element
 * \param pContenu_elem adresse remplie avec le contenu de l element en tete
 * \return un entier correspondant a 1 si il y a probleme de pointeurs (pointeur null), 2 si la liste est vide et 0 sinon
 */
int Enlever_elem_tete_liste_statique_generique(Liste_statique_generique * psListe, TypeDonneeListeGenerique pContenu_elem,size_t taille_donnee) {
    if (psListe == NULL || pContenu_elem == NULL) {
        printf("Erreur adresse liste ou element NULL");
        return 1;
    }
    if (psListe->iTaille == 0) {
        printf("\nErreur liste vide");
        return 2;
    }
    memcpy(pContenu_elem,psListe->TsListe[psListe->iTete],taille_donnee);
    // il faut maintenant libere la memoire de stockage des donnees
    free(psListe->TsListe[psListe->iTete]);
    psListe->TsListe[psListe->iTete] = NULL ; // pas obligatoire c'est juste pour etre sûr de declencher une alerte du systeme si on tente de dereferencer
    psListe->iTete++;
    if(psListe->iTete >= psListe->iNb_elem_max)
        psListe->iTete = 0;
    psListe->iTaille--;
    if (psListe->iTaille == 0) {
        psListe->iTete = -1;
        psListe->iFin = -1;
    }
    return 0;
}

/**
 * \fn int Enlever_elem_fin_liste_statique_generique(Liste_statique_generique * psListe, TypeDonneeListeGenerique contenu_elem,size_t taille_donnee)
 * \brief fonction pour enlever un element en fin d'une liste statique et retourner sa valeur
 * \param psListe Pointeur vers une liste statique dans laquelle on va enlever un element
 * \param pContenu_elem adresse remplie avec le contenu de l element en tete
 * \return un entier correspondant a 1 si il y a probleme de pointeurs (pointeur null), 2 si la liste est vide et 0 sinon
 */
int Enlever_elem_fin_liste_statique_generique(Liste_statique_generique * psListe, TypeDonneeListeGenerique pContenu_elem,size_t taille_donnee) {
    if (psListe == NULL || pContenu_elem == NULL) {
        printf("\nErreur adresse liste ou element NULL\n");
        return 1;
    }
    if (psListe->iTaille == 0) {
        printf("\nErreur liste vide\n");
        return 2;
    }
    memcpy(pContenu_elem,psListe->TsListe[psListe->iFin],taille_donnee);
    // il faut maintenant libere la memoire de stockage des donnees
    free(psListe->TsListe[psListe->iFin]);
    psListe->TsListe[psListe->iFin]=NULL;
    psListe->iFin--;
    if(psListe->iFin < 0)
        psListe->iFin = psListe->iNb_elem_max-1;
    psListe->iTaille--;
    if (psListe->iTaille == 0) {
        psListe->iTete = -1;
        psListe->iFin = -1;
    }
    return 0;
}

/**
 * \fn int tete_liste_statique_generique(Liste_statique_generique * psListe, TypeDonneeListeGenerique contenu_elem,size_t taille_donnee)
 * \brief fonction pour recuperer l element en tete d une liste statique sans l enlever
 * \param psListe Pointeur vers une liste statique dont on veut le contenu de l element de tete
 * \param pContenu_elem adresse remplie avec le contenu de l element en tete
 * \return un entier correspondant a 1 si il y a probleme de pointeurs (pointeur null), 2 si la liste est vide et 0 sinon
 */
int tete_liste_statique_generique(Liste_statique_generique * psListe, TypeDonneeListeGenerique pContenu_elem,size_t taille_donnee) {
    if (psListe == NULL || pContenu_elem == NULL) {
        printf("\nerreur adresse liste ou case resultat NULL\n");
        return 1;
    }
    if(psListe->iTaille <= 0) {
        printf("\nErreur liste vide");
        return 2;
    }
    memcpy(pContenu_elem,psListe->TsListe[psListe->iTete],taille_donnee);
    return 0;
}

/**
 * \fn int fin_liste_statique_generique(Liste_statique_generique * psListe, TypeDonneeListeGenerique pContenu_elem,size_t taille_donnee)
 * \brief fonction pour recuperer l element en fin d une liste statique sans l enlever
 * \param psListe Pointeur vers une liste statique dont on veut le contenu de l element de fin
 * \param pContenu_elem adresse remplie avec le contenu de l element en fin
 * \return un entier correspondant a 1 si il y a probleme de pointeurs (pointeur null), 2 si la liste est vide et 0 sinon
 */
int fin_liste_statique_generique(Liste_statique_generique * psListe, TypeDonneeListeGenerique pContenu_elem,size_t taille_donnee) {
    if (psListe == NULL || pContenu_elem == NULL) {
        printf("\nerreur adresse liste ou case resultat NULL\n");
        return 1;
    }
    if(psListe->iTaille <= 0) {
        printf("\nErreur liste vide\n");
        return 2;
    }
    memcpy(pContenu_elem,psListe->TsListe[psListe->iFin],taille_donnee);
    return 0;
}

/**
 * \fn int test_liste_statique_generique_vide(Liste_statique_generique * psListe)
 * \brief fonction pour tester si une liste statique est vide
 * \param psListe Pointeur vers la liste statique a tester
 * \return un entier correspondant 1 si la liste est vide, 0 si elle ne l'est pas et 2 si le pointeur est null
 */
int test_liste_statique_generique_vide(Liste_statique_generique * psListe) {
    if (psListe == NULL) {
        printf("\nErreur adresse liste NULL\n");
        return 2;
    } else {
        if (psListe->iTaille == 0) {
            return 1;
        } else {
            return 0;
        }
    }
}

/**
 * \fn int Taille_liste_statique_generique(Liste_statique_generique * psListe)
 * \brief fonction qui retourne la taille de la liste statique (nb d elements stockes)
 * \param psListe Pointeur vers la liste statique dont on veut connaitre la taille
 * \return un entier correspondant au nombre d'éléments et -1 si le pointeur est null
 */
int Taille_liste_statique_generique(Liste_statique_generique * psListe) {
    if (psListe == NULL ) {
        printf("\nErreur adresse liste NULL\n");
        return -1;
    }
    return psListe->iTaille;
}


/**
 * \fn int Afficher_liste_statique_generique(Liste_statique_generique * psListe, void (*pfAfficher_Contenu_element_liste_statique_generique)(TypeDonneeListeGenerique psDonnee))
 * \brief fonction qui affiche la liste statique
 * \param psListe Pointeur vers la liste statique
 * \param pfAfficher_Contenu_element_liste_statique_generique Pointeur sur fonction d'affichage
 * \return un entier correspondant à -1 si le pointeur est null et 0 sinon
 */
int Afficher_liste_statique_generique(Liste_statique_generique * psListe, void (*pfAfficher_Contenu_element_liste_statique_generique)(TypeDonneeListeGenerique psDonnee)) {
    int iBoucle;
    if (psListe == NULL) {
        printf("\nErreur adresse liste NULL\n");
        return -1;
    } else {
        printf("\nListe :\n");
        if(test_liste_statique_generique_vide(psListe)==0) {
            for(iBoucle = 0; iBoucle < psListe->iTaille ; iBoucle++) {
                (*pfAfficher_Contenu_element_liste_statique_generique)(psListe->TsListe[(psListe->iTete+iBoucle)%psListe->iNb_elem_max]);
                // modulo si iTete + iBoucle >iNb_elem_max
            }
        }
        return 0;

    }
}
