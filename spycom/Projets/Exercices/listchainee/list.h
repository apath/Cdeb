#ifndef __list__
#define __list__

typedef struct test test;
struct test{
    int id; /* identifiant */
    int val; /* valeur */
    test *next; /* pointeur gardant l'adresse du "bloc" suivant */
};

/* le type suivant "list" sera utilis� pour ne garder
 * que l'adresse du d�but d'une list, �a simplifie
 * les fonctions pour modifier l'adresse start, chaque
 * nouvelle entr�e sera ajout�e au d�but de la liste */
typedef struct list list;
struct list
{
    test *start;
};

/* quelque prototype de fonction pour donner une id�e
 * de comment tu pourrais faire pour gerer la liste tu
 * n'est pas oblig� de les utiliser */


/* init_list fera un malloc de type list pour allouer une nouvelle
 * list, et mettra dans le pointeur start NULL pour l'initialisation
 * et retournera alors l'adresse du ptr list */
list *init_list(void);

/* la fonction ajout allouera un bloc "struct test" pour une nouvelle
 * entr�e et y mettra l'id et le val qui sont pass�s en param�tre.
 * Dans le pointeur next du struct test il faudra mettre l'adresse
 * start contenu dans le lptr : lptr->start. Et dans lptr->start il faudra
 * mettre l'adresse du nouveau bloc "struct test". Utiliser des ptr
 * temporaire pour l'echange des addresse.
 * L'adresse start du lptr doit contenir l'adresse du nouveau struct test
 * et l'adresse next du nouveau struct test doit contenir l'adresse start.
 * Ainsi l'ajout se fait par le d�but de la list et la toute premi�re
 * entr�e se retrouve � la fin.
 * en cas o� lptr est NULL (problem d'initialisation ou que malloc
 * retourne NULL la fonction retourne 1 (erreur) si l'ajout c'est
 * bien d�roul�e la fonction retourne 0 (tout est ok) */
int ajout(list *lptr,int nvid,int nvval);

/* la fonction supp recherche dans la list un bloc contenant l'id
 * pass� en param�tre, si elle le trouve elle replace les adresse
 * correctement dans l'item suivant celui � supp. (voir illustration)
 * puis free l'item ayant l'id recherch�
 * la fonction retourne 1 si l'id est introuvable
 * et retourne 0 si l'id est trouv� et supprim� */
int supp(list *lptr,int suppid);

/* la fonction recherche, recherche dans la list un bloc contenant l'id
 * pass� en param�tre et affiche sa valeur actuel, aucune
 * modification si le param�tre "val" est � -1, si le param�tre val est
 * sup�rieur ou �gale � z�ro alors le bloc contenant l'id recherch�
 * vera sa valeur modifi�e en fonction du param�tre val.
 * la fonction retourne 1 en cas o� l'id est introuvable
 * la fonction retourne 0 si l'id est trouv� */
int recherche(list *lptr,int rechid,int rechval);


/* la fonction affiche_list traverse la list sans la modifier
 * et affiche l'id et la val de chaque bloc rencontr� */
void affiche_list(list *lptr);

/* la fonction free_list supprime tout les blocs de la list */
void free_list(list *lptr);



#endif
