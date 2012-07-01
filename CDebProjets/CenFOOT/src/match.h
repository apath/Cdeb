#ifndef __match__
#define __match__

/*
 * cet header est utilisé pour les matchs
 */
struct amical{

    int score_dom,score_ext;/*Initialisation des scores */
    int remp_dom,remp_ext;/*Initialisation du nombre de remplacant 3 max par equipe*/
    char *team_name_dom;
    char *team_name_ext;
};
struct coupe{
    int score_dom,score_ext;/*Initialisation des scores */
    int remp_dom,remp_ext;/*Initialisation du nombre de remplacant 3 max par equipe*/
    int tour[5][16];/* 5 tour de coupe avec 16 rencontre au depart puis 8, 4, 2, 1*/
    char *team_name_dom;
    char *team_name_ext;
};
struct saison{
    int score_dom,score_ext;/*Initialisation des scores */
    int remp_dom,remp_ext;/*Initialisation du nombre de remplacant 3 max par equipe*/
    int journee[38][10];/*38 journee avec des 10 rencontres a chaque journee*/
    char *team_name_dom;
    char *team_name_ext;
    struct *coupe;
};

#endif
