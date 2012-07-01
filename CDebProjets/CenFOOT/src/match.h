#ifndef __match__
#define __match__

/*
 * cet header est utilisé pour les matchs
 */
struct match{
    char typeMatch[3][7]={"amical","coupe","saison"};/*En fonction du mode de jeu */
    int score_dom=0,score_ext=0;/*Initialisation des scores */
    int remp_dom=0,remp_ext=0;/*Initialisation du nombre de remplacant 3 max par equipe*/

    /* Je sais pas trop comment declarer le nombre de tour et journee*/
    /*mode amical: 1 tour,mode coupe:5 tours et mode saison:38 journée de championnat + 5 tours de coupe*/
    /*je propose ca pour l'ensemble des types de match avec les valeurs les plus grandes*/
    int tour[44][16];
    /*ou pour chaque type sachant qu'amicale n'en a pas besoin*/
    int tour[5][16];/* 5 tour de coupe avec 16 rencontre au depart puis 8, 4, 2, 1*/
    int journee[38][10];/*38 journee avec des 10 rencontres a chaque journee*/

    struct club.dom;/*Les 2 club qui vont se rencontrer*/
    struct club.ext;
};

#endif
