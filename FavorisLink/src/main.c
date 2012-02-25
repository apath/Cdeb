#include <stdio.h>
#include <stdlib.h>
#include "flk.h"
/*
 * alpha test
 */

void callback_liens(FLK *f,char *titre_sujet,char *titre_categorie,
        char *url){
    printf("%s`",url);
}
void callback_sujets(FLK *f,char *titre_categorie,char *titre){
    printf("%s{",titre);
    get_liens(f,titre,titre_categorie,callback_liens);
    printf("}\n");
}
void callback_tout(FLK *f,char *titre){
    printf("[%s]\n",titre);
    get_sujets(f,titre,callback_sujets);
}

int main(void)
  {
    FLK *test;
    e_moderr ee;
    test=flk_init();
    if(test){
        /* creer une categorie */
        ee=flk_mod_categorie(ADD,"categorie1",NULL,test);
        print_err(ee,1);
        /* ajoute un sujet dans la categorie */
        ee=flk_mod_sujet(ADD,"sujet1",NULL,"categorie1",test);
        print_err(ee,1);
        /* ajoute un second sujet */
        ee=flk_mod_sujet(ADD,"sujet2",NULL,"categorie1",test);
        print_err(ee,1);
        /* ajoute un lien dans le sujet1 */
        ee=flk_mod_url(ADD,"http://www.hi.test/",NULL,
                "sujet1","categorie1",test);
        print_err(ee,1);
        /* ajoute un second lien dans le sujet1 */
        ee=flk_mod_url(ADD,"http://www.ho.test/",NULL,
                "sujet1","categorie1",test);
        print_err(ee,1);
/**/
        printf("\n*test erreur\n");
        /* test l'ajout d'un lien dans un sujet inexistant */
        ee=flk_mod_url(ADD,"qsdflkjsfd",NULL,"sqdf","categorie1",test);
        print_err(ee,1);
/**/
        printf("\n*test affiche tout\n----------------\n");
        /* affiche les categories leurs sujets les liens des sujets
         * en utilisant les foreach entre eux et ajoutant un test
         * d'affichage de la syntaxe du flk pourrait servir pour la
         * sauvegarde */
        get_categories(test,callback_tout);
/**/
        printf("\n*test free_liens\n");
        /* test de liberation des liens d'un sujet d'une categorie */
        free_liens("sujet1","categorie1",test);
        /* test d'ajout apres la suppression */
        flk_mod_url(ADD,"http://test.com/",NULL,"sujet1","categorie1",
                test);
        flk_mod_url(ADD,"http://abcd.test/",NULL,"sujet2","categorie1",
                test);
/**/
        printf("\n*test affiche tout\n----------------\n");
        get_categories(test,callback_tout);

        /* test lecture fichier */
        printf("\n*test chargement d'un fichier .flk\n");
        flk_load(test,"test.flk"); /* chargement */
        printf("\naffichage du FLK apres chargement fichier test.flk\n");
        get_categories(test,callback_tout);

        /* liberation du FLK */
        flk_free(test);
    }
    return EXIT_SUCCESS;
  }
