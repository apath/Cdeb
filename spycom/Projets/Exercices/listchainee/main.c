#include <stdio.h>
#include "list.h"

/* exemple */

int main(void){
    list *lptr;
    lptr=init_list();
    if(lptr){
        ajout(lptr,10,94);
        ajout(lptr,3,234);
        ajout(lptr,20,858);
        supp(lptr,3);
        recherche(lptr,10,-1);
        affiche_list(lptr);
        free_list(lptr);
        affiche_list(lptr);
    }
    return 0;
}
