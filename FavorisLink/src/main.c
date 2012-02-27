#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "flk.h"
/*
 * alpha test
 */

int callback_liens(FLK *f,char *titre_sujet,char *titre_categorie,
        char *url,const void *userdefine){
    printf("%s`",url);
    return 0;
}
int callback_sujets(FLK *f,char *titre_categorie,char *titre,const void *userdefine){
    printf("%s{",titre);
    get_liens(f,titre,titre_categorie,callback_liens,userdefine);
    printf("}\n");
    return 0;
}
int callback_tout(FLK *f,char *titre,const void *userdefine){
    printf("[%s]\n",titre);
    get_sujets(f,titre,callback_sujets,userdefine);
    return 0;
}

/* test userdefine recherche url */
int callback_test(FLK *f,char *stitre,char *ctitre,char *url,
        const void *userdefine){
    int n;
    const char *str = (const char*)userdefine;/* recuperation pointeur */
    n=strlen(str);
    if(!memcmp(url,str,n)){/* si l'url commence par la chaine passée dans
                             userdefine */
        printf("%s\n",url); /* alors affichage de l'url */
        flk_mod_url(DEL,url,NULL,stitre,ctitre,f); /* et suppression
                                                      de celle-ci */
    }
    return 0;
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
        get_categories(test,callback_tout,NULL);
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
        get_categories(test,callback_tout,NULL);

        /* test lecture fichier */
        printf("\n*test chargement d'un fichier .flk\n");
        flk_load(test,"test.flk"); /* chargement */
        printf("\n*affichage du FLK apres chargement fichier test.flk\n");
        get_categories(test,callback_tout,NULL);
/**/
        flk_mod_url(ADD,"ftp://bla.bla/",NULL,"sujet1","categorie1",test);
        flk_mod_url(ADD,"http://test/a/",NULL,"sujet1","categorie1",test);
        flk_mod_url(ADD,"https://aa/",NULL,"sujet1","categorie1",test);
        /* affiche tout à nouveau */
        printf("\n*affiche tout a nouveau\n");
        get_categories(test,callback_tout,NULL);
        /* test callback avec userdefine pour afficher uniquement les
         * liens du sujet1 dans la categorie1 qui commencent par
         * "http:" */
        printf("\n*test callback userdefine http: sur sujet1 categorie1\n");
        get_liens(test,"sujet1","categorie1",callback_test,"http:");
        printf("\n*affiche tout apres suppression des liens http: du sujet1 categorie1\n");
        get_categories(test,callback_tout,NULL);
/**/
        /* enregistrement du FLK dans un fichier */
        flk_save(test,"enregistre.flk");

        /* liberation du FLK */
        flk_free(test);
    }
    return EXIT_SUCCESS;
  }
