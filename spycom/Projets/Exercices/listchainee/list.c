#include <stdio.h>
#include <stdlib.h>
#include "list.h"

list *init_list(void)
{
    /* initialisation retourne un pointeur type list
     * et met l'adresse start à NULL */
    list *list = malloc(sizeof(*list));
    test *test = malloc(sizeof(*test));
    if (list == NULL || test == NULL)
    {
        exit(EXIT_FAILURE);
    }
    test->id = 0;
    test->val= 0;
    test->next = NULL;
    list->start = test;

    return list;
}

int ajout(list *lptr,int nvid,int nvval)
{
    /* alloue un nouveau bloc struct test lui donne
     * les valeurs en paramètre et l'adresse start en next
     * et met dans l'adresse start du lptr sa propre adresse
     * retourne un code d'erreur */
    test *nouveau = malloc(sizeof(*nouveau));
    if (lptr == NULL || nouveau == NULL)
    {
        exit(EXIT_FAILURE);
    }
    nouveau->id = nvid;
    nouveau->val= nvval;
    nouveau->next = lptr->start;
    lptr->start = nouveau;
}

int supp(list *lptr, int suppid)
{
    /* traverse la list à partir du ptr start dans lptr,
     * si l'id est trouvé l'adresse next du bloc précendant reçoit
     * l'adresse next du bloc ayant l'id recherché
     * puis free le bloc ayant l'id recherché
     * retourne un code si id introuvable */
    int idIntrouvable=0;
    if (lptr == NULL)
    {
        exit(EXIT_FAILURE);
    }
    test *actuel = lptr->start;
    test *precedent = lptr->start;
    while (actuel != NULL && precedent != NULL)
    {

        if (actuel->id==suppid)
        {
            precedent->next = actuel->next;
            free(actuel);
        }

        precedent = actuel;
        actuel = actuel->next;

        if(actuel==NULL)
        {
            idIntrouvable=1;
        }
    }
    return idIntrouvable;
}

int recherche(list *lptr,int rechid,int rechval)
{
    /* traverse la list à la recherche d'un id comme pour la suppression
     * si val<0 on ne modifie pas la val et on affiche la val actuel
     * si val>=0 on affiche la val actuel puis on la modifie
     * retourne un code si id introuvable */
    int idIntrouvable=0;

    if (lptr == NULL)
    {
        exit(EXIT_FAILURE);
    }
    test *actuel = lptr->start;
    while (actuel != NULL)
    {
        if (actuel->id==rechid)
        {
            printf(" La valeur actuel pour id:%d est:%d\n", actuel->id,actuel->val);
            if(rechval>=0)
            {
                actuel->val = rechval;
            }
        }

        actuel = actuel->next;

        if(actuel==NULL)
        {
            idIntrouvable=1;
        }
    }
    return idIntrouvable;
}

void affiche_list(list *lptr)
{
    if (lptr == NULL)
    {
        exit(EXIT_FAILURE);
    }

    test *actuel = lptr->start;

    while (actuel != NULL)
    {
        printf(" id:%d val:%d\n", actuel->id,actuel->val);
        actuel = actuel->next;
    }
}

void free_list(list *lptr)
{
    /* traverse la list tout en supprimant chaque bloc rencontré */
    if (lptr == NULL)
    {
        exit(EXIT_FAILURE);
    }

    test *actuel = lptr->start;

    while (actuel != NULL)
    {
        free(actuel);
        actuel = actuel->next;
    }
    free(lptr);
}
