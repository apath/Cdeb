#include <stdio.h>
#include <stdlib.h>
#include "flk.h"
/*
 * alpha test
 */

void callback_categories(char *titre){
    printf("ListCategories - Categorie : %s\n",titre);
}
void callback_sujets(char *titre_categorie,char *titre){
    printf("ListSujets - dans categorie : %s\tSujet : %s\n",titre_categorie,titre);
}
void callback_liens(char *titre_sujet,char *titre_categorie,char *url){
    printf("ListLiens - dans sujet : %s\t dans categorie :%s\tLien : %s\n",
            titre_sujet,titre_categorie,url);
}

int main(void)
  {
    FLK *test;
    e_moderr ee;
    char *ctitre="categorie1",*stitre="sujet1";
    test=flk_init();
    if(test){
        ee=flk_mod_categorie(ADD,ctitre,NULL,test);
        print_err(ee,1);
        ee=flk_mod_sujet(ADD,stitre,NULL,ctitre,test);
        print_err(ee,1);
        ee=flk_mod_sujet(ADD,"sujet2",NULL,ctitre,test);
        print_err(ee,1);
        ee=flk_mod_url(ADD,"http://www.hi.test/",NULL,
                stitre,ctitre,test);
        print_err(ee,1);
        ee=flk_mod_url(ADD,"http://www.ho.test/",NULL,
                stitre,ctitre,test);
        print_err(ee,1);

        printf("\ntest erreur\n");
        ee=flk_mod_url(ADD,"qsdflkjsfd",NULL,
                "sqdf",ctitre,test);
        print_err(ee,1);
        printf("\ntest foreach\n");

        get_categories(test,callback_categories);
        get_sujets(test,"categorie1",callback_sujets);
        get_liens(test,"sujet1","categorie1",callback_liens);

        printf("\ntest free_liens\n");
        free_liens("sujet1","categorie1",test);
        flk_mod_url(ADD,"http://test.com/",NULL,"sujet1","categorie1"
                ,test);
        get_liens(test,"sujet1","categorie1",callback_liens);

        flk_free(test);
    }
    return EXIT_SUCCESS;
  }
