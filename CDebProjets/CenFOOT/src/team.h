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

/*
 * Toutes les fonctions de la partie "team" auront en premier
 * dans leur nom : club_ suivie d'un diminutif le plus commun
 * possible pour d�finir ce que la fonction fait.
 * Dans le commentaire sur le prototype entre crochet on
 * indiquera si la fonction est complete ou non.
 * Uniquement les fonctions utilisables "directement" pour
 * g�rer les donn�es equipe/joueurs (ajout/supression/modification)
 * donc les fonctions manipulant ces donn�es par le biais du type
 * CLUB seront plac�es dans l'header team.h ici, les autres fonction
 * �tant interne pas besoin de les y mettre.
 * */


/*
 * club_init [Progress : ok]
 * pour l'initialisation d'une liste de club */
CLUB *club_init(void);

/*
 * club_free [Progress : � faire apr�s club_del_team]
 * pour la lib�ration de la m�moire utilis� par une liste
 * de club, doit lib�rer en premier tout les joueurs de toutes
 * les �quipes, puis toutes les �quipes, et le pointeur CLUB en dernier
 * return : 0 si ok, 1 si *c est NULL */
int club_free(CLUB *c);

/*
 * club_add_team [Progress : � tester]
 * pour l'ajout d'une �quipe dans la liste club
 * params : ptr list club,nom de l'�quipe, niveau, code pays.
 * return : 3 d�ja present, 2 erreur alloc nom, 1 erreur malloc,
 *          0 ok. */
int club_add_team(CLUB *c,const char *team_name,int team_lvl,
        int country_code);
/*
 * club_del_team [Progress : � faire apres club_del_player]
 * pour la suppression d'une �quipe, supprime tout les joueurs,
 * puis l'�quipe de la list club
 * params : ptr list club,nom de l'�quipe
 * return : entier positif si erreur (team n'existe pas), 0 si ok.*/
int club_del_team(CLUB *c,const char *team_name);

/*
 * club_add_player [Progress : � faire maitenant]
 * pour l'ajout d'un joueur dans une �quipe
 * params : ptr list club,nom de l'�quipe, nom du joueur,
 * position,numero,points def,atk,pen.
 * return : un entier positif en cas d'erreurs (joueur existe d�j�,
 * �quipe n'existe pas,probl�me malloc etc) et 0 si ajout ok.*/
int club_add_player(CLUB *c,const char *team_name,
        const char *player_name,int pos,int num,
        int def,int atk,int pen);

/*
 * club_del_player [Progress : � faire apr�s club_add_player]
 * pour la suppression d'un joueur d'une �quipe
 * params : ptr list club,nom de l'�quipe, nom du joueur.
 * return : entier positif en cas d'erreur (si l'�quipe n'existe pas,
 * le joueur n'existe pas), 0 si suppression ok.*/
int club_del_player(CLUB *c,const char *team_name,
        const char *player_name);

/* la suite sera les fonctions de modifications
 * puis les fonctions load et write pour les sauvegardes */

#endif
