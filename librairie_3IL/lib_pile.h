#ifndef LIB_PILE_H_INCLUDED
#define LIB_PILE_H_INCLUDED

#define LGPIL 2  /* longueur maximale de la pile statique */

// L'utilisateur doit mettre ses données dans la structure TypeDonneePile
// ici il n'y a qu'une information donc je n'ai pas fait de structure juste une redefinition de type

typedef float TypeDonneePile;

typedef struct element_pile_statique {
    TypeDonneePile tdDonnee;             // contenu stocke dans l'element
} Element_statique;

typedef struct pile_statique {
    int iSommet;               // indice de l'element de tête
    Element_statique TsPile[LGPIL];  // tableau d'elements de la pile statique
} Pile_statique;

/**
 * \fn int Vider_pile_statique (Pile_statique * psPile)
 * \brief fonction pour vider une pile statique
 * \param psPile Pointeur vers une structure pile a vider
 * \return un entier correspondant a 1 si il y a probleme (pointeur null) et 0 sinon
 */

int Vider_pile_statique (Pile_statique * psPile);

/**
 * \fn int Creer_pile_statique (Pile_statique * psPile)
 * \brief fonction pour initialiser une pile statique
 * \param psPile Pointeur vers une structure pile a initialiser
 * \return un entier correspondant a 1 si il y a probleme (pointeur null) et 0 sinon
 */
int Creer_pile_statique (Pile_statique * psPile);

/**
 * \fn int Ajouter_elem_pile_statique(Pile_statique * psPile, TypeDonneePile *pContenu_elem)
 * \brief fonction pour ajouter un element donne a une pile statique
 * \param psPile Pointeur vers une structure pile dans laquelle on va ajouter l'element
 * \param psElem Pointeur vers le contenu a ajouter
 * \return un entier correspondant a 1 si il y a probleme de pointeurs (pointeur null), 2 si la pile est pleine et 0 sinon
 */

int Ajouter_elem_pile_statique(Pile_statique * psPile, TypeDonneePile *pContenu_elem);

/**
 * \fn int Enlever_elem_pile_statique(Pile_statique * psPile, TypeDonneePile *pCcontenu_elem )
 * \brief fonction pour enlever un element en tête d'une pile statique
 * \param psPile Pointeur vers une structure pile dans laquelle on va enlever un element
 * \param psElem Pointeur vers le contenu de l'element retire
 * \return un entier correspondant a 1 si il y a probleme de pointeurs (pointeur null), 2 si la pile est vide et 0 sinon
 */
int Enlever_elem_pile_statique(Pile_statique * psPile, TypeDonneePile *pContenu_elem);
/**
 * \fn int sommet_pile_statique(Pile_statique * psPile, TypeDonneePile *pContenu_elem )
 * \brief fonction pour recuperer l'element en tête d'une pile statique sans l'enlever
 * \param psPile Pointeur vers une structure pile dans laquelle on va enlever un element
 * \param psElem Pointeur vers le contenu de l'element recupere en tête
 * \return un entier correspondant a 1 si il y a probleme de pointeurs (pointeur null), 2 si la pile est vide et 0 sinon
 */
int sommet_pile_statique(Pile_statique * psPile, TypeDonneePile *pContenu_elem);

/**
 * \fn int test_pile_vide(Pile_statique * psPile)
 * \brief fonction pour tester si une pile statique est vide
 * \param psPile Pointeur vers une structure pile a tester
 * \return un entier correspondant 1 si la pile est vide, 0 si elle ne l'est pas et 2 si le pointeur est null
 */
int test_pile_vide_statique(Pile_statique * psPile);

/**
 * \fn int Taille_pile(Pile_statique * psPile)
 * \brief fonction qui retourne la taille effective de la pile (nb d elements stocke)
 * \param psPile Pointeur vers une structure pile dont on veut connaitre la taille
 * \return un entier correspondant au nombre d'éléments et -1 si le pointeur est null
 */
int Taille_pile_statique(Pile_statique * psPile);

/**********************************version 3 : pile dyna-statique *********************************************/
typedef struct element_dyna_statique {
    TypeDonneePile tdDonnee;                      // contenu stocke dans l'element
} Element_dyna_statique;

typedef struct pile_dyna_statique {
    int iSommet;                          // indice de l'element de tête
    int taille_affectee_TsPile;           // on a maintenant besoin d'un champs taille pour stocker la taille qui est variable
                                          // initialisé à LGPIL
    Element_dyna_statique * TsPile;       // pointeur vers un tableau d'elements de la pile dyna-statique
} Pile_dyna_statique;

/**
 * \fn int Vider_pile_dyna_statique (Pile_dyna_statique * psPile)
 * \brief fonction pour vider une pile dyna-statique
 * \param psPile Pointeur vers une structure pile a vider
 * \return un entier correspondant a 1 si il y a probleme (pointeur null) et 0 sinon
 */

int Vider_pile_dyna_statique (Pile_dyna_statique * psPile);

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

int Creer_pile_dyna_statique (Pile_dyna_statique * psPile, int iNb_max);

/**
 * \fn int Ajouter_elem_pile_dyna_statique(Pile_dyna_statique * psPile, TypeDonneePile *pContenu_elem)
 * \brief fonction pour ajouter un element donne a une pile dyna-statique
 * \param psPile Pointeur vers une structure pile dans laquelle on va ajouter l'element
 * \param psElem Pointeur vers le contenu de l'element a ajouter
 * \return un entier correspondant a 1 si il y a probleme de pointeurs (pointeur null), 2 si la pile est pleine et 0 sinon
 */

int Ajouter_elem_pile_dyna_statique(Pile_dyna_statique * psPile, TypeDonneePile *pContenu_elem);

/**
 * \fn int Enlever_elem_pile_dyna_statique(Pile_dyna_statique * psPile, TypeDonneePile *pContenu_elem )
 * \brief fonction pour enlever un element en tête d'une pile dyna-statique
 * \param psPile Pointeur vers une structure pile dans laquelle on va enlever un element
 * \param psElem Pointeur vers le contenu de l'element retire
 * \return un entier correspondant a 1 si il y a probleme de pointeurs (pointeur null), 2 si la pile est vide et 0 sinon
 */
int Enlever_elem_pile_dyna_statique(Pile_dyna_statique * psPile, TypeDonneePile *pContenu_elem );
/**
 * \fn int sommet_pile_dyna_statique(Pile_dyna_statique * psPile, TypeDonneePile *pContenu_elem )
 * \brief fonction pour recuperer l'element en tête d'une pile dyna-statique sans l'enlever
 * \param psPile Pointeur vers une structure pile dans laquelle on va enlever un element
 * \param psElem Pointeur vers le contenu de l'element recupere en tête
 * \return un entier correspondant a 1 si il y a probleme de pointeurs (pointeur null), 2 si la pile est vide et 0 sinon
 */
int sommet_pile_dyna_statique(Pile_dyna_statique * psPile, TypeDonneePile *pContenu_elem );

/**
 * \fn int test_pile_vide(Pile_dyna_statique * psPile)
 * \brief fonction pour tester si une pile dyna-statique est vide
 * \param psPile Pointeur vers une structure pile a tester
 * \return un entier correspondant 1 si la pile est vide, 0 si elle l'est et 2 si le pointeur est null
 */
int test_pile_vide_dyna_statique(Pile_dyna_statique * psPile);

/**
 * \fn int Taille_pile_dyna_statique(Pile_dyna_statique * psPile)
 * \brief fonction qui retourne la taille effective de la pile (nb d elements stocke)
 * \param psPile Pointeur vers une structure pile dont on veut connaitre la taille
 * \return un entier correspondant au nombre d'éléments et -1 si le pointeur est null
 */
int Taille_pile_dyna_statique(Pile_dyna_statique * psPile);

/**********************************version 4 : pile dynamique *********************************************/
// remarque : en orienté objet, on ferait un héritage de liste dynamique

#include "lib_liste.h"

typedef Liste_dynamique Pile_dynamique;
typedef Element_liste_dynamique Element_pile_dynamique;

/**
 * \fn int Vider_pile_dynamique (Pile_dynamique * psPile)
 * \brief fonction pour vider une pile dynamique
 * \param psPile Pointeur vers une structure pile a vider
 * \return un entier correspondant a 1 si il y a probleme (pointeur null) et 0 sinon
 */

int Vider_pile_dynamique (Pile_dynamique * psPile);

/**
 * \fn int Creer_pile_dynamique (Pile_dynamique * psPile)
 * \brief fonction pour initialiser une pile dynamique
 * \param psPile Pointeur vers une structure pile a initialiser
 * \return un entier correspondant a 1 si il y a probleme (pointeur null) et 0 sinon
 */
int Creer_pile_dynamique (Pile_dynamique * psPile);

/**
 * \fn int Ajouter_elem_pile_dynamique(Pile_dynamique * psPile, TypeDonneePile *pContenu_elem)
 * \brief fonction pour ajouter un element donne a une pile dynamique
 * \param psPile Pointeur vers une structure pile dans laquelle on va ajouter l'element
 * \param pContenu_elem Pointeur vers le contenu de l'element a ajouter
 * \return un entier correspondant a 1 si il y a probleme de pointeurs (pointeur null), 2 si la pile est pleine et 0 sinon
 */

int Ajouter_elem_pile_dynamique(Pile_dynamique * psPile, TypeDonneePile *pContenu_elem);

/**
 * \fn int Enlever_elem_pile_dynamique(Pile_dynamique * psPile, TypeDonneePile *pContenu_elem )
 * \brief fonction pour enlever un element en tête d'une pile dynamique
 * \param psPile Pointeur vers une structure pile dans laquelle on va enlever un element
 * \param pContenu_elem Pointeur vers le contenu de l'element retire
 * \return un entier correspondant a 1 si il y a probleme de pointeurs (pointeur null), 2 si la pile est vide et 0 sinon
 */
int Enlever_elem_pile_dynamique(Pile_dynamique * psPile, TypeDonneePile *pContenu_elem );
/**
 * \fn int sommet_pile(Pile_dynamique * psPile, TypeDonneePile *pContenu_elem)
 * \brief fonction pour recuperer l'element en tête d'une pile dynamique sans l'enlever
 * \param psPile Pointeur vers une structure pile dans laquelle on va enlever un element
 * \param pContenu_elem Pointeur vers le contenu de l'element recupere en tête
 * \return un entier correspondant a 1 si il y a probleme de pointeurs (pointeur null), 2 si la pile est vide et 0 sinon
 */
int sommet_pile_dynamique(Pile_dynamique * psPile, TypeDonneePile *pContenu_elem );

/**
 * \fn int test_pile_dynamique_vide(Pile_dynamique * psPile)
 * \brief fonction pour tester si une pile dynamique est vide
 * \param psPile Pointeur vers une structure pile a tester
 * \return un entier correspondant 1 si la pile est vide, 0 si elle l'est et 2 si le pointeur est null
 */
int test_pile_dynamique_vide(Pile_dynamique * psPile);

/**
 * \fn int Taille_pile_dynamique(Pile_dynamique * psPile)
 * \brief fonction qui retourne la taille effective de la pile dynamique (nb d elements stocke)
 * \param psPile Pointeur vers une structure pile dont on veut connaitre la taille
 * \return un entier correspondant au nombre d'éléments et -1 si le pointeur est null
 */
int Taille_pile_dynamique(Pile_dynamique * psPile);


/**
 * \fn void Afficher_pile_dynamique(Pile_dynamique * psPile)
 * \brief fonction qui affiche la pile dynamique
 * \param psPile Pointeur vers une structure pile a afficher
 */
void Afficher_pile_dynamique(Pile_dynamique * psPile);

/**********************************version 5 : pile dynamique generique *********************************************/
// remarque : en orienté objet, on ferait un héritage de liste dynamique generique

#include "lib_liste.h"

typedef void * TypeDonneePileGenerique;

typedef Liste_dynamique_generique Pile_dynamique_generique;
typedef Element_liste_dynamique_generique Element_pile_dynamique_generique;

/**
 * \fn int Vider_pile_dynamique_generique (Pile_dynamique_generique * psPile,size_t taille_donnee)
 * \brief fonction pour vider une pile dynamique
 * \param psPile Pointeur vers une structure pile a vider
 * \return un entier correspondant a 1 si il y a probleme (pointeur null) et 0 sinon
 */

int Vider_pile_dynamique_generique (Pile_dynamique_generique * psPile,size_t taille_donnee);

/**
 * \fn int Creer_pile_dynamique_generique (Pile_dynamique_generique * psPile)
 * \brief fonction pour initialiser une pile dynamique
 * \param psPile Pointeur vers une structure pile a initialiser
 * \return un entier correspondant a 1 si il y a probleme (pointeur null) et 0 sinon
 */
int Creer_pile_dynamique_generique (Pile_dynamique_generique * psPile);

/**
 * \fn int Ajouter_elem_pile_dynamique_generique(Pile_dynamique_generique * psPile, TypeDonneePileGenerique pContenu_elem,size_t taille_donnee)
 * \brief fonction pour ajouter un element donne a une pile dynamique
 * \param psPile Pointeur vers une structure pile dans laquelle on va ajouter l'element
 * \param pContenu_elem Pointeur vers le contenu de l'element a ajouter
 * \return un entier correspondant a 1 si il y a probleme de pointeurs (pointeur null), 2 si la pile est pleine et 0 sinon
 */

int Ajouter_elem_pile_dynamique_generique(Pile_dynamique_generique * psPile, TypeDonneePileGenerique pContenu_elem,size_t taille_donnee);

/**
 * \fn int Enlever_elem_pile_dynamique_generique(Pile_dynamique_generique * psPile, TypeDonneePileGenerique pContenu_elem,size_t taille_donnee )
 * \brief fonction pour enlever un element en tête d'une pile dynamique
 * \param psPile Pointeur vers une structure pile dans laquelle on va enlever un element
 * \param pContenu_elem Pointeur vers le contenu de l'element retire
 * \return un entier correspondant a 1 si il y a probleme de pointeurs (pointeur null), 2 si la pile est vide et 0 sinon
 */
int Enlever_elem_pile_dynamique_generique(Pile_dynamique_generique * psPile, TypeDonneePile *pContenu_elem ,size_t taille_donnee);
/**
 * \fn int sommet_pile(Pile_dynamique_generique * psPile, TypeDonneePileGenerique pContenu_elem  ,size_t taille_donnee)
 * \brief fonction pour recuperer l'element en tête d'une pile dynamique sans l'enlever
 * \param psPile Pointeur vers une structure pile dans laquelle on va enlever un element
 * \param pContenu_elem Pointeur vers le contenu de l'element recupere en tête
 * \return un entier correspondant a 1 si il y a probleme de pointeurs (pointeur null), 2 si la pile est vide et 0 sinon
 */
int sommet_pile_dynamique_generique(Pile_dynamique_generique * psPile, TypeDonneePileGenerique pContenu_elem,size_t taille_donnee);

/**
 * \fn int test_pile_dynamique_generique_vide(Pile_dynamique_generique * psPile)
 * \brief fonction pour tester si une pile dynamique est vide
 * \param psPile Pointeur vers une structure pile a tester
 * \return un entier correspondant 1 si la pile est vide, 0 si elle l'est et 2 si le pointeur est null
 */
int test_pile_dynamique_generique_vide(Pile_dynamique_generique * psPile);

/**
 * \fn int Taille_pile_dynamique_generique(Pile_dynamique_generique * psPile)
 * \brief fonction qui retourne la taille effective de la pile dynamique (nb d elements stocke)
 * \param psPile Pointeur vers une structure pile dont on veut connaitre la taille
 * \return un entier correspondant au nombre d'éléments et -1 si le pointeur est null
 */
int Taille_pile_dynamique_generique(Pile_dynamique_generique * psPile);


/**
 * \fn void Afficher_pile_dynamique_generique(Pile_dynamique_generique * psPile, void (*pfAfficher_Contenu_element_pile_dynamique_generique)(TypeDonneePileGenerique psDonnee))
 * \brief fonction qui affiche la pile dynamique
 * \param psPile Pointeur vers une structure pile a afficher
 */
void Afficher_pile_dynamique_generique(Pile_dynamique_generique * psPile, void (*pfAfficher_Contenu_element_pile_dynamique_generique)(TypeDonneePileGenerique psDonnee));


/*******************************pile dyna statique generique *****************/
typedef Liste_statique_generique Pile_statique_generique;

/**
 * \fn int Vider_pile_statique_generique (Pile_statique_generique * psPile,size_t taille_donnee)
 * \brief fonction pour vider une pile statique
 * \param psPile Pointeur vers une structure pile a vider
 * \return un entier correspondant a 1 si il y a probleme (pointeur null) et 0 sinon
 */

int Vider_pile_statique_generique (Pile_statique_generique * psPile,size_t taille_donnee);

/**
 * \fn int Creer_pile_statique_generique (Pile_statique_generique * psPile, int iNbMax)
 * \brief fonction pour initialiser une pile statique
 * \param psPile Pointeur vers une structure pile a initialiser
 * \param iNbMax un entier correspondant au nombre d element a stocker (taille initiale)
 * \return un entier correspondant a 1 si il y a probleme de pointeur,
 *                                   2 si la taille est inferieure a 1
 *                                   3 si il  n'a pas pu reserver la memoire (retour malloc NULL)
 *                                   et 0 sinon
 */
int Creer_pile_statique_generique (Pile_statique_generique * psPile, int iNbMax);

/**
 * \fn int Ajouter_elem_pile_statique_generique(Pile_statique_generique * psPile, TypeDonneePileGenerique pContenu_elem,size_t taille_donnee)
 * \brief fonction pour ajouter un element donne a une pile statique
 * \param psPile Pointeur vers une structure pile dans laquelle on va ajouter l'element
 * \param pContenu_elem Pointeur vers le contenu de l'element a ajouter
 * \return un entier correspondant a 1 si il y a probleme de pointeurs (pointeur null), 2 si la pile est pleine et 0 sinon
 */

int Ajouter_elem_pile_statique_generique(Pile_statique_generique * psPile, TypeDonneePileGenerique pContenu_elem,size_t taille_donnee);

/**
 * \fn int Enlever_elem_pile_statique_generique(Pile_statique_generique * psPile, TypeDonneePileGenerique pContenu_elem,size_t taille_donnee )
 * \brief fonction pour enlever un element en tête d'une pile statique
 * \param psPile Pointeur vers une structure pile dans laquelle on va enlever un element
 * \param pContenu_elem Pointeur vers le contenu de l'element retire
 * \return un entier correspondant a 1 si il y a probleme de pointeurs (pointeur null), 2 si la pile est vide et 0 sinon
 */
int Enlever_elem_pile_statique_generique(Pile_statique_generique * psPile, TypeDonneePile *pContenu_elem ,size_t taille_donnee);
/**
 * \fn int sommet_pile(Pile_statique_generique * psPile, TypeDonneePileGenerique pContenu_elem  ,size_t taille_donnee)
 * \brief fonction pour recuperer l'element en tête d'une pile statique sans l'enlever
 * \param psPile Pointeur vers une structure pile dans laquelle on va enlever un element
 * \param pContenu_elem Pointeur vers le contenu de l'element recupere en tête
 * \return un entier correspondant a 1 si il y a probleme de pointeurs (pointeur null), 2 si la pile est vide et 0 sinon
 */
int sommet_pile_statique_generique(Pile_statique_generique * psPile, TypeDonneePileGenerique pContenu_elem,size_t taille_donnee);

/**
 * \fn int test_pile_statique_generique_vide(Pile_statique_generique * psPile)
 * \brief fonction pour tester si une pile statique est vide
 * \param psPile Pointeur vers une structure pile a tester
 * \return un entier correspondant 1 si la pile est vide, 0 si elle l'est et 2 si le pointeur est null
 */
int test_pile_statique_generique_vide(Pile_statique_generique * psPile);

/**
 * \fn int Taille_pile_statique_generique(Pile_statique_generique * psPile)
 * \brief fonction qui retourne la taille effective de la pile statique (nb d elements stocke)
 * \param psPile Pointeur vers une structure pile dont on veut connaitre la taille
 * \return un entier correspondant au nombre d'éléments et -1 si le pointeur est null
 */
int Taille_pile_statique_generique(Pile_statique_generique * psPile);


/**
 * \fn void Afficher_pile_statique_generique(Pile_statique_generique * psPile, void (*pfAfficher_Contenu_element_pile_statique_generique)(TypeDonneePileGenerique psDonnee))
 * \brief fonction qui affiche la pile statique
 * \param psPile Pointeur vers une structure pile a afficher
 */
void Afficher_pile_statique_generique(Pile_statique_generique * psPile, void (*pfAfficher_Contenu_element_pile_statique_generique)(TypeDonneePileGenerique psDonnee));



#endif // LIB_PILE_H_INCLUDED
