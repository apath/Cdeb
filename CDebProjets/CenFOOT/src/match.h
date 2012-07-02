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
    struct amical *next; /* pointeur next */
};
struct coupe{
    int score_dom,score_ext;/*Initialisation des scores */
    int remp_dom,remp_ext;/*Initialisation du nombre de remplacant 3 max par equipe*/
    int tour[5][16];/* 5 tour de coupe avec 16 rencontre au depart puis 8, 4, 2, 1*/
    char *team_name_dom;
    char *team_name_ext;
    struct coupe *next; /* pointeur next */
};
struct saison{
    int score_dom,score_ext;/*Initialisation des scores */
    int remp_dom,remp_ext;/*Initialisation du nombre de remplacant 3 max par equipe*/
    int journee[38][10];/*38 journee avec des 10 rencontres a chaque journee*/
    char *team_name_dom;
    char *team_name_ext;
    struct saison *next; /* pointeur next */
    struct coupe *start; /* < est-ce correct ? ça permet d'incorporer une liste des resultats
    de coupe dans une saison */
};

struct match{
    struct amical *amical_start; /* contiendra l'adr depart pour liste amical */
    struct coupe *coupe_start; /* contiendra l'adr depart pour liste coupe */
    struct saison *saison_start; /* contiendra l'adr depart pour liste saison */
};
typedef struct match MATCH; /* le type MATCH pour simplifier les fonctions (quand on passe
                        les pointeurs en paramètre des fonctions là un seul pointeur
                        type MATCH permet de passer les trois pointeurs et de les modif
                        à la voler sans avoir à retourner les pointeurs etc */

#endif
