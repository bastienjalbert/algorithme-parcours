#ifndef LIB_LISTE_H_INCLUDED
#define LIB_LISTE_H_INCLUDED

// Liste dynamique non generique
// L'utilisateur doit mettre ses donn�es dans la structure TypeDonneeListe
// ici il n'y a qu'une information (un float) donc je n'ai pas fait de structure

typedef float TypeDonneeListe;

typedef struct element_liste_dynamique {
    TypeDonneeListe tdDonnee;             // valeur stockee dans l'element
    struct element_liste_dynamique * ElementSuivant;
    struct element_liste_dynamique * Elementprecedent;
} Element_liste_dynamique;

typedef struct liste_dynamique {
    Element_liste_dynamique * psTete;               // pointeur sur l'element de t�te
    Element_liste_dynamique * psFin;                // pointeur sur l'element de fin
    int iTaille;                                    // nombre d'element de la liste
} Liste_dynamique;




/**
 * \fn int Vider_liste_dynamique (Liste_dynamique * psListe)
 * \brief fonction pour vider une liste dynamique
 * \param psListe Pointeur vers la liste a vider
 * \return un entier correspondant a 1 si il y a probleme (pointeur null) et 0 sinon
 */

int Vider_liste_dynamique (Liste_dynamique * psListe);

/**
 * \fn int Creer_liste_dynamique (Liste_dynamique * psListe)
 * \brief fonction pour initialiser une liste dynamique
 * \param psListe Pointeur vers la liste  a initialiser
 * \return un entier correspondant a 1 si il y a probleme (pointeur null) et 0 sinon
 */
int Creer_liste_dynamique (Liste_dynamique * psListe);

/**
 * \fn int Ajouter_elem_tete_liste_dynamique(Liste_dynamique * psListe, TypeDonneeListe *contenu_elem)
 * \brief fonction pour ajouter un element dont le contenu est donne en parametre en tete d une liste dynamique
 * \param psListe Pointeur vers une liste dynamique dans laquelle on va ajouter l element
 * \param contenu_elem contenu de l element a ajouter
 * \return un entier correspondant a 1 si il y a probleme de pointeurs (pointeur null), 2 si la reservation de memoire a echoue et 0 sinon
 */

int Ajouter_elem_tete_liste_dynamique(Liste_dynamique * psListe, TypeDonneeListe *contenu_elem);

/**
 * \fn int Ajouter_elem_fin_liste_dynamique(Liste_dynamique * psListe, TypeDonneeListe contenu_elem)
 * \brief fonction pour ajouter un element dont le contenu est donne en parametre en fin d une liste dynamique
 * \param psListe Pointeur vers une liste dynamique dans laquelle on va ajouter l element
 * \param contenu_elem contenu de l element a ajouter
 * \return un entier correspondant a 1 si il y a probleme de pointeurs (pointeur null), 2 si la reservation de memoire a echoue et 0 sinon
 */

int Ajouter_elem_fin_liste_dynamique(Liste_dynamique * psListe, TypeDonneeListe * contenu_elem);

/**
 * \fn int Enlever_elem_tete_liste_dynamique(Liste_dynamique * psListe, TypeDonneeListe * contenu_elem)
 * \brief fonction pour enlever un element en tete d'une liste dynamique et retourner sa valeur
 * \param psListe Pointeur vers une liste dynamique dans laquelle on va enlever un element
 * \param contenu_elem adresse remplie avec le contenu de l element en tete
 * \return un entier correspondant a 1 si il y a probleme de pointeurs (pointeur null), 2 si la liste est vide et 0 sinon
 */
int Enlever_elem_tete_liste_dynamique(Liste_dynamique * psListe, TypeDonneeListe * contenu_elem);

/**
 * \fn int Enlever_elem_fin_liste_dynamique(Liste_dynamique * psListe, TypeDonneeListe * contenu_elem)
 * \brief fonction pour enlever un element en fin d'une liste dynamique et retourner sa valeur
 * \param psListe Pointeur vers une liste dynamique dans laquelle on va enlever un element
 * \param contenu_elem adresse remplie avec le contenu de l element en tete
 * \return un entier correspondant a 1 si il y a probleme de pointeurs (pointeur null), 2 si la liste est vide et 0 sinon
 */
int Enlever_elem_fin_liste_dynamique(Liste_dynamique * psListe, TypeDonneeListe * contenu_elem);

/**
 * \fn int tete_liste_dynamique(Liste_dynamique * psListe, TypeDonneeListe * contenu_elem)
 * \brief fonction pour recuperer l element en tete d une liste dynamique sans l enlever
 * \param psListe Pointeur vers une liste dynamique dont on veut le contenu de l element de tete
 * \param contenu_elem adresse remplie avec le contenu de l element en tete
 * \return un entier correspondant a 1 si il y a probleme de pointeurs (pointeur null), 2 si la liste est vide et 0 sinon
 */
int tete_liste_dynamique(Liste_dynamique * psListe, TypeDonneeListe * contenu_elem);

/**
 * \fn int fin_liste_dynamique(Liste_dynamique * psListe, TypeDonneeListe * contenu_elem)
 * \brief fonction pour recuperer l element en fin d une liste dynamique sans l enlever
 * \param psListe Pointeur vers une liste dynamique dont on veut le contenu de l element de fin
 * \param contenu_elem adresse remplie avec le contenu de l element en fin
 * \return un entier correspondant a 1 si il y a probleme de pointeurs (pointeur null), 2 si la liste est vide et 0 sinon
 */
int fin_liste_dynamique(Liste_dynamique * psListe, TypeDonneeListe * contenu_elem);

/**
 * \fn int test_liste_dynamique_vide(Liste_dynamique * psListe)
 * \brief fonction pour tester si une liste dynamique est vide
 * \param psListe Pointeur vers la liste dynamique a tester
 * \return un entier correspondant 1 si la liste est vide, 0 si elle ne l'est pas et 2 si le pointeur est null
 */
int test_liste_dynamique_vide(Liste_dynamique * psListe);

/**
 * \fn int Taille_liste_dynamique(Liste_dynamique * psListe)
 * \brief fonction qui retourne la taille de la liste dynamique (nb d elements stockes)
 * \param psListe Pointeur vers la liste dynamique dont on veut connaitre la taille
 * \return un entier correspondant au nombre d'�l�ments et -1 si le pointeur est null
 */
int Taille_liste_dynamique(Liste_dynamique * psListe);


/**
 * \fn int Afficher_liste_dynamique(Liste_dynamique * psListe)
 * \brief fonction qui affiche la liste dynamique
 * \param psListe Pointeur vers la liste dynamique
 * \return un entier correspondant � -1 si le pointeur est null et 0 sinon
 */
int Afficher_liste_dynamique(Liste_dynamique * psListe);

/********************** Liste dynamique generique ********************************/
// L'utilisateur peut utiliser la liste sans modifier ce fichier

typedef void * TypeDonneeListeGenerique;

typedef struct element_liste_dynamique_generique {
    TypeDonneeListeGenerique tdDonnee;             // pointeur vers les donnees
    struct element_liste_dynamique_generique * ElementSuivant;
    struct element_liste_dynamique_generique * Elementprecedent;
} Element_liste_dynamique_generique;

typedef struct liste_dynamique_generique {
    Element_liste_dynamique_generique * psTete;               // pointeur sur l'element de t�te
    Element_liste_dynamique_generique * psFin;                // pointeur sur l'element de fin
    int iTaille;                                    // nombre d'element de la liste
} Liste_dynamique_generique;

/**
 * \fn int Vider_liste_dynamique_generique (Liste_dynamique_generique * psListe,size_t taille_donnee)
 * \brief fonction pour vider une liste dynamique
 * \param psListe Pointeur vers la liste a vider
 * \return un entier correspondant a 1 si il y a probleme (pointeur null), 2 si il n y a plus de memoire disponible et 0 sinon
 */

int Vider_liste_dynamique_generique (Liste_dynamique_generique * psListe,size_t taille_donnee);

/**
 * \fn int Creer_liste_dynamique_generique (Liste_dynamique_generique * psListe)
 * \brief fonction pour initialiser une liste dynamique
 * \param psListe Pointeur vers la liste  a initialiser
 * \return un entier correspondant a 1 si il y a probleme (pointeur null) et 0 sinon
 */
int Creer_liste_dynamique_generique (Liste_dynamique_generique * psListe);

/**
 * \fn int Ajouter_elem_tete_liste_dynamique_generique(Liste_dynamique_generique * psListe, TypeDonneeListeGenerique contenu_elem,size_t taille_donnee)
 * \brief fonction pour ajouter un element dont le contenu est donne en parametre en tete d une liste dynamique
 * \param psListe Pointeur vers une liste dynamique dans laquelle on va ajouter l element
 * \param contenu_elem contenu de l element a ajouter
 * \param taille_donnee taille du contenu a stocke
 * \return un entier correspondant a 1 si il y a probleme de pointeurs (pointeur null), 2 si la reservation de memoire a echoue et 0 sinon
 */

int Ajouter_elem_tete_liste_dynamique_generique(Liste_dynamique_generique * psListe, TypeDonneeListeGenerique contenu_elem,size_t taille_donnee);

/**
 * \fn int Ajouter_elem_fin_liste_dynamique_generique(Liste_dynamique_generique * psListe, TypeDonneeListeGenerique contenu_elem,size_t taille_donnee)
 * \brief fonction pour ajouter un element dont le contenu est donne en parametre en fin d une liste dynamique
 * \param psListe Pointeur vers une liste dynamique dans laquelle on va ajouter l element
 * \param contenu_elem contenu de l element a ajouter
 * \param taille_donnee taille du contenu a stocke
 * \return un entier correspondant a 1 si il y a probleme de pointeurs (pointeur null), 2 si la reservation de memoire a echoue et 0 sinon
 */

int Ajouter_elem_fin_liste_dynamique_generique(Liste_dynamique_generique * psListe, TypeDonneeListeGenerique contenu_elem,size_t taille_donnee);

/**
 * \fn int Ajouter_elem_ieme_liste_dynamique_generique(Liste_dynamique_generique * psListe, TypeDonneeListeGenerique contenu_elem,size_t taille_donnee, int iPlace_ajout)
 * \brief fonction pour ajouter un element dont le contenu est donne en parametre en i eme position d une liste dynamique
 * \param psListe Pointeur vers une liste dynamique dans laquelle on va ajouter l element
 * \param contenu_elem contenu de l element a ajouter
 * \param taille_donnee taille du contenu a stocke
 * \param iPlace_ajout place d ajout de l element   remarque : 1 <= iPlace_ajout <= iTaille
 * \return un entier correspondant a 1 si il y a probleme de pointeurs (pointeur null), 2 si la reservation de memoire a echoue, 3 si le numero de la place n existe pas et 0 sinon
 */

int Ajouter_elem_ieme_liste_dynamique_generique(Liste_dynamique_generique * psListe, TypeDonneeListeGenerique contenu_elem,size_t taille_donnee, int iPlace_ajout);

/**
 * \fn int Enlever_elem_tete_liste_dynamique_generique(Liste_dynamique_generique * psListe, TypeDonneeListeGenerique contenu_elem,size_t taille_donnee)
 * \brief fonction pour enlever un element en tete d'une liste dynamique et retourner sa valeur
 * \param psListe Pointeur vers une liste dynamique dans laquelle on va enlever un element
 * \param contenu_elem adresse remplie avec le contenu de l element en tete
 * \param taille_donnee taille du contenu a stocke
 * \return un entier correspondant a 1 si il y a probleme de pointeurs (pointeur null), 2 si la liste est vide et 0 sinon
 */
int Enlever_elem_tete_liste_dynamique_generique(Liste_dynamique_generique * psListe, TypeDonneeListeGenerique contenu_elem,size_t taille_donnee);

/**
 * \fn int Enlever_elem_fin_liste_dynamique_generique(Liste_dynamique_generique * psListe, TypeDonneeListeGenerique contenu_elem,size_t taille_donnee)
 * \brief fonction pour enlever un element en fin d'une liste dynamique et retourner sa valeur
 * \param psListe Pointeur vers une liste dynamique dans laquelle on va enlever un element
 * \param contenu_elem adresse remplie avec le contenu de l element en tete
 * \param taille_donnee taille du contenu a stocke
 * \return un entier correspondant a 1 si il y a probleme de pointeurs (pointeur null), 2 si la liste est vide et 0 sinon
 */
int Enlever_elem_fin_liste_dynamique_generique(Liste_dynamique_generique * psListe, TypeDonneeListeGenerique contenu_elem,size_t taille_donnee);

/**
 * \fn int Enlever_elem_fin_liste_dynamique_generique(Liste_dynamique_generique * psListe, TypeDonnee contenu_elem)
 * \brief fonction pour enlever un element en fin d'une liste dynamique
 * \param psListe Pointeur vers une liste dynamique dans laquelle on va enlever un element
 * \param contenu_elem adresse remplie avec le contenu de l element en tete
 * \return un entier correspondant a 1 si il y a probleme de pointeurs (pointeur null), 2 si la liste est vide et 0 sinon
 */
int Enlever_elem_fin_liste_dynamique_generique_sans_recup(Liste_dynamique_generique * psListe);

/**
 * \fn int Enlever_elem_ieme_liste_dynamique_generique(Liste_dynamique_generique * psListe, TypeDonneeListeGenerique contenu_elem,size_t taille_donnee, int iPlace_enleve)
 * \brief fonction pour enlever un element en ieme position d'une liste dynamique et retourner sa valeur
 * \param psListe Pointeur vers une liste dynamique dans laquelle on va enlever un element
 * \param contenu_elem adresse remplie avec le contenu de l element en tete
 * \param taille_donnee taille du contenu a stocke
 * \param iPlace_enleve place d ajout de l element    remarque : 1 <= iPlace_enleve <= iTaille+1
 * \return un entier correspondant a 1 si il y a probleme de pointeurs (pointeur null), 2 si la liste est vide et 0 sinon
 */
int Enlever_elem_ieme_liste_dynamique_generique(Liste_dynamique_generique * psListe, TypeDonneeListeGenerique contenu_elem,size_t taille_donnee, int iPlace_enleve );


/**
 * \fn int tete_liste_dynamique_generique(Liste_dynamique_generique * psListe, TypeDonneeListeGenerique contenu_elem,size_t taille_donnee)
 * \brief fonction pour recuperer l element en tete d une liste dynamique sans l enlever
 * \param psListe Pointeur vers une liste dynamique dont on veut le contenu de l element de tete
 * \param contenu_elem adresse remplie avec le contenu de l element en tete
 * \param taille_donnee taille du contenu a stocke
 * \return un entier correspondant a 1 si il y a probleme de pointeurs (pointeur null), 2 si la liste est vide et 0 sinon
 */
int tete_liste_dynamique_generique(Liste_dynamique_generique * psListe, TypeDonneeListeGenerique contenu_elem,size_t taille_donnee);

/**
 * \fn int fin_liste_dynamique_generique(Liste_dynamique_generique * psListe, TypeDonneeListeGenerique contenu_elem,size_t taille_donnee)
 * \brief fonction pour recuperer l element en fin d une liste dynamique sans l enlever
 * \param psListe Pointeur vers une liste dynamique dont on veut le contenu de l element de fin
 * \param contenu_elem adresse remplie avec le contenu de l element en fin
 * \param taille_donnee taille du contenu a stocke
 * \return un entier correspondant a 1 si il y a probleme de pointeurs (pointeur null), 2 si la liste est vide et 0 sinon
 */
int fin_liste_dynamique_generique(Liste_dynamique_generique * psListe, TypeDonneeListeGenerique contenu_elem,size_t taille_donnee);

/**
 * \fn int test_liste_dynamique_generique_vide(Liste_dynamique_generique * psListe)
 * \brief fonction pour tester si une liste dynamique est vide
 * \param psListe Pointeur vers la liste dynamique a tester
 * \return un entier correspondant 1 si la liste est vide, 0 si elle ne l'est pas et 2 si le pointeur est null
 */
int test_liste_dynamique_generique_vide(Liste_dynamique_generique * psListe);

/**
 * \fn int Taille_liste_dynamique_generique(Liste_dynamique_generique * psListe)
 * \brief fonction qui retourne la taille de la liste dynamique (nb d elements stockes)
 * \param psListe Pointeur vers la liste dynamique dont on veut connaitre la taille
 * \return un entier correspondant au nombre d'�l�ments et -1 si le pointeur est null
 */
int Taille_liste_dynamique_generique(Liste_dynamique_generique * psListe);


/**
 * \fn int Afficher_liste_dynamique_generique(Liste_dynamique_generique * psListe, void (*pfAfficher_Contenu_element_liste_dynamique_generique)(TypeDonneeListeGenerique psDonnee))
 * \brief fonction qui affiche la liste dynamique
 * \param psListe Pointeur vers la liste dynamique
 * \param pfAfficher_Contenu_element_liste_dynamique_generique Pointeur sur fonction d'affichage
 * \return un entier correspondant � -1 si le pointeur est null et 0 sinon
 */
int Afficher_liste_dynamique_generique(Liste_dynamique_generique * psListe, void (*pfAfficher_Contenu_element_liste_dynamique_generique)(TypeDonneeListeGenerique psDonnee));

// Ajouté par le groupe pour le projet de parcours spécifiquement
/** @author : groupe
 * \fn int Recuperer_elem_ieme_liste_dynamique_generique(Liste_dynamique_generique * psListe, TypeDonneeListeGenerique contenu_elem,size_t taille_donnee, int iPlace_enleve)
 * \brief fonction pour recuperer un element en ieme position d'une liste dynamique et retourner sa valeur
 * \param psListe Pointeur vers une liste dynamique dans laquelle on va enlever un element
 * \param contenu_elem adresse remplie avec le contenu de l element en tete
 * \param taille_donnee taille du contenu a stocke
 * \param iPlace_enleve place d ajout de l element    remarque : 1 <= iPlace_enleve <= iTaille
 * \return un entier correspondant a 1 si il y a probleme de pointeurs (pointeur null), 2 si la liste est vide, , 3 si le numero de la place n existe pas et 0 sinon
 */
int Recuperer_elem_ieme_liste_dynamique_generique(Liste_dynamique_generique * psListe, TypeDonneeListeGenerique pContenu_elem, int iPlace_enleve, int taille_donnee);

/** @author: groupe
 * \fn int Recuperer_elem_tete_liste_dynamique_generique(Liste_dynamique_generique * psListe, TypeDonneeListeGenerique pContenu_elem)
 * \brief fonction pour recuperer un element en tete d'une liste dynamique et retourner sa valeur
 * \param psListe Pointeur vers une liste dynamique dans laquelle on va enlever un element
 * \param contenu_elem adresse remplie avec le contenu de l element en tete
 * \return un entier correspondant a 1 si il y a un probleme de pointeurs (pointeur null), 2 si la liste est vide et 0 sinon
 */
int Recuperer_elem_tete_liste_dynamique_generique(Liste_dynamique_generique * psListe, TypeDonneeListeGenerique pContenu_elem,size_t taille_donnee);

/**
 * \fn int Recuperer_elem_fin_liste_dynamique_generique(Liste_dynamique_generique * psListe, TypeDonnee contenu_elem)
 * \brief fonction pour recuperer un element en fin d'une liste dynamique et retourner sa valeur
 * \param psListe Pointeur vers une liste dynamique dans laquelle on va enlever un element
 * \param contenu_elem adresse remplie avec le contenu de l element en tete
 * \return un entier correspondant a 1 si il y a probleme de pointeurs (pointeur null), 2 si la liste est vide et 0 sinon
 */
int Recuperer_elem_fin_liste_dynamique_generique(Liste_dynamique_generique * psListe, TypeDonneeListeGenerique  pContenu_elem,size_t taille_donnee);

// fin ajout

/********************** Liste dyna-statique generique(tableau avec gestion circulaire)  ********************************/
// L'utilisateur peut utiliser la liste sans modifier ce fichier
// version dyna-statique : on demande une taille initiale pour le tableau
// si on a besoin de plus de memoire on peut faire un realloc + deplacer les donnees

//typedef void * TypeDonneeListeGenerique;  // deja definit pour la liste dynamique

#define I_FACTEUR_REDIMENSIONNEMENT 2     // coefficent de redimensionnement de la taille

typedef struct liste_statique_generique {
    int iNb_elem_max;                    // nombre d elements maxi du tableau, donne lors de la creation du tableau
    int iTete;                           // indice de l'element de t�te
    int iFin;                            // indice de l'element de fin
    int iTaille;
    TypeDonneeListeGenerique * TsListe;  // tableau de pointeurs vers les donn�es de la liste statique
    // je prefere un tableau de pointeur vers les donnees car dans certains cas lorsqu on agrandit le tableau
    // il faut deplacer son contenu et il est plus rapide de deplacer des pointeurs que des donnees
} Liste_statique_generique;

/**
 * \fn int Vider_liste_statique_generique (Liste_statique_generique * psListe,size_t taille_donnee)
 * \brief fonction pour vider une liste statique
 * \param psListe Pointeur vers la liste a vider
 * \return un entier correspondant a 1 si il y a probleme (pointeur null), 2 si il n y a plus de memoire disponible et 0 sinon
 */

int Vider_liste_statique_generique (Liste_statique_generique * psListe,size_t taille_donnee);

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
int Creer_liste_statique_generique (Liste_statique_generique * psListe, int iNb_max) ;

/**
 * \fn int Detruire_liste_statique_generique (Liste_statique_generique * psListe)
 * \brief fonction pour detruire le tableau de pointeur d une liste statique generique
 * \param psListe Pointeur vers une structure liste a detruire
 * \return un entier correspondant a 1 si il y a probleme de pointeur null, 2 si la liste n est pas vide et 0 sinon
 */
int Detruire_liste_statique_generique (Liste_statique_generique * psListe);

/**
 * \fn int Ajouter_elem_tete_liste_statique_generique(Liste_statique_generique * psListe, TypeDonneeListeGenerique contenu_elem,size_t taille_donnee)
 * \brief fonction pour ajouter un element dont le contenu est donne en parametre en tete d une liste statique
 * \param psListe Pointeur vers une liste statique dans laquelle on va ajouter l element
 * \param contenu_elem contenu de l element a ajouter
 * \param taille_donnee taille de l objet a stocker
 * \return un entier correspondant a 1 si il y a probleme de pointeurs (pointeur null),
 *                                   2 si la taille de l objet est inferieure a 1
 *                                   3 si la reservation de memoire a echouee
 *                                   et 0 sinon
 */

int Ajouter_elem_tete_liste_statique_generique(Liste_statique_generique * psListe, TypeDonneeListeGenerique contenu_elem,size_t taille_donnee);

/**
 * \fn int Ajouter_elem_fin_liste_statique_generique(Liste_statique_generique * psListe, TypeDonneeListeGenerique contenu_elem,size_t taille_donnee)
 * \brief fonction pour ajouter un element dont le contenu est donne en parametre en fin d une liste statique
 * \param psListe Pointeur vers une liste statique dans laquelle on va ajouter l element
 * \param contenu_elem contenu de l element a ajouter
 * \param taille_donnee taille de l objet a stocker
 * \return un entier correspondant a 1 si il y a probleme de pointeurs (pointeur null),
 *                                   2 si la taille de l objet est inferieure a 1
 *                                   3 si la reservation de memoire a echouee
 *                                   et 0 sinon
 */

int Ajouter_elem_fin_liste_statique_generique(Liste_statique_generique * psListe, TypeDonneeListeGenerique pContenu_elem,size_t taille_donnee);

/**
 * \fn int Enlever_elem_tete_liste_statique_generique(Liste_statique_generique * psListe, TypeDonneeListeGenerique contenu_elem,size_t taille_donnee)
 * \brief fonction pour enlever un element en tete d'une liste statique et retourner sa valeur
 * \param psListe Pointeur vers une liste statique dans laquelle on va enlever un element
 * \param contenu_elem adresse remplie avec le contenu de l element en tete
 * \param taille_donnee taille du contenu a stocke
 * \return un entier correspondant a 1 si il y a probleme de pointeurs (pointeur null), 2 si la liste est vide et 0 sinon
 */
int Enlever_elem_tete_liste_statique_generique(Liste_statique_generique * psListe, TypeDonneeListeGenerique contenu_elem,size_t taille_donnee);

/**
 * \fn int Enlever_elem_fin_liste_statique_generique(Liste_statique_generique * psListe, TypeDonneeListeGenerique contenu_elem,size_t taille_donnee)
 * \brief fonction pour enlever un element en fin d'une liste statique et retourner sa valeur
 * \param psListe Pointeur vers une liste statique dans laquelle on va enlever un element
 * \param contenu_elem adresse remplie avec le contenu de l element en tete
 * \param taille_donnee taille du contenu a stocke
 * \return un entier correspondant a 1 si il y a probleme de pointeurs (pointeur null), 2 si la liste est vide et 0 sinon
 */
int Enlever_elem_fin_liste_statique_generique(Liste_statique_generique * psListe, TypeDonneeListeGenerique contenu_elem,size_t taille_donnee);

/**
 * \fn int tete_liste_statique_generique(Liste_statique_generique * psListe, TypeDonneeListeGenerique contenu_elem,size_t taille_donnee)
 * \brief fonction pour recuperer l element en tete d une liste statique sans l enlever
 * \param psListe Pointeur vers une liste statique dont on veut le contenu de l element de tete
 * \param contenu_elem adresse remplie avec le contenu de l element en tete
 * \param taille_donnee taille du contenu a stocke
 * \return un entier correspondant a 1 si il y a probleme de pointeurs (pointeur null), 2 si la liste est vide et 0 sinon
 */
int tete_liste_statique_generique(Liste_statique_generique * psListe, TypeDonneeListeGenerique contenu_elem,size_t taille_donnee);

/**
 * \fn int fin_liste_statique_generique(Liste_statique_generique * psListe, TypeDonneeListeGenerique contenu_elem,size_t taille_donnee)
 * \brief fonction pour recuperer l element en fin d une liste statique sans l enlever
 * \param psListe Pointeur vers une liste statique dont on veut le contenu de l element de fin
 * \param contenu_elem adresse remplie avec le contenu de l element en fin
 * \param taille_donnee taille du contenu a stocke
 * \return un entier correspondant a 1 si il y a probleme de pointeurs (pointeur null), 2 si la liste est vide et 0 sinon
 */
int fin_liste_statique_generique(Liste_statique_generique * psListe, TypeDonneeListeGenerique contenu_elem,size_t taille_donnee);

/**
 * \fn int test_liste_statique_generique_vide(Liste_statique_generique * psListe)
 * \brief fonction pour tester si une liste statique est vide
 * \param psListe Pointeur vers la liste statique a tester
 * \return un entier correspondant 1 si la liste est vide, 0 si elle ne l'est pas et 2 si le pointeur est null
 */
int test_liste_statique_generique_vide(Liste_statique_generique * psListe);

/**
 * \fn int Taille_liste_statique_generique(Liste_statique_generique * psListe)
 * \brief fonction qui retourne la taille de la liste statique (nb d elements stockes)
 * \param psListe Pointeur vers la liste statique dont on veut connaitre la taille
 * \return un entier correspondant au nombre d'�l�ments et -1 si le pointeur est null
 */
int Taille_liste_statique_generique(Liste_statique_generique * psListe);


/**
 * \fn int Afficher_liste_statique_generique(Liste_statique_generique * psListe, void (*pfAfficher_Contenu_element_liste_statique_generique)(TypeDonneeListeGenerique psDonnee))
 * \brief fonction qui affiche la liste statique
 * \param psListe Pointeur vers la liste statique
 * \param pfAfficher_Contenu_element_liste_statique_generique Pointeur sur fonction d'affichage
 * \return un entier correspondant � -1 si le pointeur est null et 0 sinon
 */
int Afficher_liste_statique_generique(Liste_statique_generique * psListe, void (*pfAfficher_Contenu_element_liste_statique_generique)(TypeDonneeListeGenerique psDonnee));




#endif // LIB_LISTE_H_INCLUDED
