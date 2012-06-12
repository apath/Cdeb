#include <stdio.h>
#include <stdlib.h>
#include "list.h"

list *init_list(void){
    /* initialisation retourne un pointeur type list
     * et met l'adresse start à NULL */
}

int ajout(list *lptr,int id,int val){
    /* alloue un nouveau bloc struct test lui donne
     * les valeurs en paramètre et l'adresse start en next
     * et met dans l'adresse start du lptr sa propre adresse
     * retourne un code d'erreur */
}

int supp(list *lptr, int id){
    /* traverse la list à partir du ptr start dans lptr,
     * si l'id est trouvé l'adresse next du bloc précendant reçoit
     * l'adresse next du bloc ayant l'id recherché
     * puis free le bloc ayant l'id recherché
     * retourne un code si id introuvable */
}

int recherche(list *lptr,int id,int val){
    /* traverse la list à la recherche d'un id comme pour la suppression
     * si val<0 on ne modifie pas la val et on affiche la val actuel
     * si val>=0 on affiche la val actuel puis on la modifie
     * retourne un code si id introuvable */
}

void affiche_list(list *lptr){
    /* traverse la list et affiche chaque bloc rencontré
     * id et val\n */
}

void free_list(list *lptr){
    /* traverse la list tout en supprimant chaque bloc rencontré */
}
