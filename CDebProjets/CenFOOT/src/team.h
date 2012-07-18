#ifndef __team__
#define __team__
/*
 * cet header est utilis� pour la gestion des �quipes
 */

/* structures temporaire bas�es sur le cahier des charges et conditions du jeu
 * necessaire de modifier si besoin avant de se lancer plus loin */

struct team{
    char *name; /* nom du joueur */
    int pos,num,def,atk,pen; /* position,numero,points def,atk et pen */
    struct team *next; /* ptr next (liste cha�n�e) */
};
struct club{
    char *team_name; /* nom de l'equipe */
    int country,lvl; /* code pays, niveau de l'equipe */
    struct team *tm; /* ptr sur la liste de joueurs dans l'equipe */
    struct club *next; /* ptr next (liste cha�n�e) */
};
typedef struct{/* type CLUB garde l'adr de debut d'une liste d'equipe */
    struct club *start;
}CLUB;

/* si structures ok, la suite les fonctions pour les utiliser */
/* construction et destruction d'une equipe, creation de club
 * enregistrement dans fichier et chargement pour la sauvegarde des clubs */


#endif
