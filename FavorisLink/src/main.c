#include <stdio.h>
#include <stdlib.h>
#include "flk.h"

int main(void)
{
    FLK *test;
    char *str="test",*new="nouveau titre";
    test=flk_init();
    e_moderr err;
    if(test){
        err=flk_mod_categorie(ADD,str,NULL,test);
        print_err(err);
        err=flk_mod_categorie(ADD,str,NULL,test); /* essai doublon */
        print_err(err);
        printf("%s\n",test->categories_index->titre);
        err=flk_mod_categorie(RENAME,str,new,test);
        print_err(err);
        printf("%s\n",test->categories_index->titre);
        err=flk_mod_categorie(DEL,str,NULL,test);
        print_err(err);
        err=flk_mod_categorie(DEL,new,NULL,test);
        print_err(err);
        printf("ok\n");
    }
    return EXIT_SUCCESS;
}
