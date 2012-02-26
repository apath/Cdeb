#ifndef _FLK_FILE_FORMAT_
#define _FLK_FILE_FORMAT_
/*
 * hierarchie du format FLK et de l'utilisation des structures :
 *
 * FLK -.
 *      |- Categorie -.
 *      |             |- Sujet -.
 *      |             |         |- Lien
 *      |             |         |- Lien
 *      |             |
 *      |             |- Sujet -.
 *      |                       |- Lien
 *      |                       |- Lien
 *      |- Categorie -.
 *                    |- Sujet -.
 *                              |- Lien
 *
 */

/*
 * les structures sont chaqu'une utilisées en liste chaînée simple
 * les ajouts sont fait sur l'index,la tête de liste.
 * il n'y a pas de queue donc que des pointeurs "suivant" (*next) et
 * des index pour la tête de liste.
 */
struct lien{
    char *url;
    struct lien *next;
};
struct sujet{
    char *titre;
    struct lien *liens_index;
    struct sujet *next;
};
struct categorie{
    char *titre;
    struct sujet *sujets_index;
    struct categorie *next;
};

/*
 * une autre façon de representer les structures :
 *
struct categorie{
    char *titre;
    struct sujet{
        char *titre;
        struct lien{
            char *url;
            struct lien *next;
        }*liens_index;
        struct sujet *next;
    }*sujets_index;
    struct categorie *next;
};*/

/*
 * le type FLK garde l'index de toutes ses categories
 * chaque categorie garde l'index de tout ses sujets et
 * chaque sujet garde l'index de tout ses liens
 */
typedef struct flk{
    struct categorie *categories_index;
}FLK;

/*
 * flk_init initialise un FLK
 * exemple :
 * FLK *f=flk_init();
 * en cas d'impossibilité d'allouer la mémoire
 * flk_init() retourne NULL
 */
FLK *flk_init(void);
/*
 * flk_free libere la memoire utilisee par un FLK
 * exemple :
 * flk_free(f);
 */
void flk_free(FLK *f);

/*
 * e_moderr est un type il contient des types d'erreurs 
 * retournees par les fonction qui l'utilisent
 * il sert pour debugger le retour des fonctions
 * en affichant l'erreur à l'aide de print_err
 * OKEY indique qu'aucune erreur connue n'a eu lieu.
 */
typedef enum{OKEY,ERR_EXIST,ERR_NOEXIST,ERR_CATNOEXIST,ERR_SUJNOEXIST,
    ERR_ALLOC_TITRE,ERR_ALLOC_STRUCT,ERR_UNKMOD}e_moderr;

/*
 * e_modtype est un type utilisé dans les fonctions de modifications
 * il sert à préciser le type de modification qu'on apporte,
 * un ajout : ADD
 * une suppression : DEL
 * un changement de titre ou d'url : RENAME
 */
typedef enum{DEL,ADD,RENAME}e_modtype;

/*
 * print_err est une simple fonction pour afficher les e_moderr
 * sert à debugger.
 * le paramètre okey lorsqu'il est différent de zéro, indique aussi
 * le cas d'une réussite : OKEY
 */
void print_err(e_moderr error,int okey);

/*
 * flk_mod_categorie fonction servant à 
 * ajouter, supprimer une categorie ou changer son titre.
 * le paramètre nouveau_titre_categorie n'est utilisé qu'avec
 * le type de modification RENAME
 * exemple d'utilisation pour un ajout de categorie dans
 * un FLK :
 * FLK *f=init_flk();
 * flk_mod_categorie(ADD,"letitre",NULL,f);
 * flk_mod_categorie(DEL,"letitre",NULL,f);
 * flk_mod_categorie(RENAME,"letitre","nouveautitre",f);
 */
e_moderr flk_mod_categorie(e_modtype mod,
        char *titre_categorie,
        char *nouveau_titre_categorie,
        FLK *f);
/*
 * flk_mod_sujet fonction servant à
 * ajouter, supprimer un sujet dans une categorie et changer
 * son titre.
 * le paramètre nouveau_titre_sujet n'est utilisé qu'avec le
 * type de modification RENAME
 * un sujet faisant partie d'une categorie il faut préciser
 * la catégorie dans laquelle le sujet sera ajouté/supprimé ou
 * renommé.
 * exemple d'utilisation :
 * flk_mod_sujet(ADD,"monsujet",NULL,"lacategorie",f);
 * flk_mod_sujet(DEL,"monsujet",NULL,"lacategorie",f);
 * flk_mod_sujet(RENAME,"monsujet","nouveausujet","lacategorie",f);
 */
e_moderr flk_mod_sujet(e_modtype mod,
        char *titre_sujet,
        char *nouveau_titre_sujet,
        char *titre_categorie,
        FLK *f);
/*
 * flk_mod_url fonction servant à
 * ajouter, supprimer un lien dans un sujet et une categorie en
 * particulier, ainsi que de le changer en utilisant RENAME.
 * cette fonction s'utilise comme flk_mod_categorie.
 * exemple :
 * flk_mod_url(ADD,"http://...",NULL,"sujet","categorie",f);
 */
e_moderr flk_mod_url(e_modtype mod,
        char *url,
        char *nouvelle_url,
        char *titre_sujet,
        char *titre_categorie,
        FLK *f);
/*
 * free_liens libere tout les liens d'un sujet faisant partie
 * d'une categorie
 */
e_moderr free_liens(char *titre_sujet,char *titre_categorie,FLK *f);
/*
 * free_sujets libere tout les sujets d'une categorie
 * et tout les liens qu'ils contiennent
 */
e_moderr free_sujets(char *titre_categorie,FLK *f);
/*
 * free_categories libere toutes les categories d'un FLK
 * donc tout les sujets et liens qu'elles contiennent
 */
e_moderr free_categories(FLK *f);

/* get_categories est une fonction foreach 
 * littéralement : pour chaque.
 * pour chaque categories dans un FLK cette fonction va en appeler
 * une autre qu'on lui aura envoyé en paramètre,
 * cette fonction doit être sous la forme :
 * int mafonction(FLK *flk,char *str,const void* userdefine){ ... }
 * str recevra le titre de la categorie actuellement scannée.
 * flk recevra le FLK utilisé par get_categories *f.
 * userdefine recevra le pointeur passé en paramètre de get_categories
 * ce pointeur est à la discrétion du codeur donc ça peut être un
 * pointeur vers un tableau de char, une structure, un fichier, etc..
 *
 * pour appeler get_categories avec mafonction :
 * get_categories(f,mafonction,userdefine);
 * si userdefine n'est pas utilisé :
 * get_categories(f,mafonction,NULL);
 * > mafonction doit retourner un int soit 1 ou 0
 *   1 stop le scan en cours si non besoin de le continuer
 *   0 continue le scan en cours
 */
e_moderr get_categories(FLK *f,int (*callback)(FLK *flk,char *recup,const void *userdef),const void *userdefine);
/*
 * get_sujets est une fonction foreach comme get_categories
 * à la différence qu'il faut lui préciser la categorie à scanner
 * evidemment.
 * La fonction qu'on lui passe en parametre
 * reçoit aussi le titre de la catégorie pour chaque sujets scannés
 * forme de la fonction à lui passer en parametre :
 * int mafonction(FLK *flk,char *str1,char *str2,const void* userdefine){ ... }
 * str1 recevra le titre de la categorie scannée,
 * str2 recevra le sujet actuellement scanné.
 * flk recevra le FLK utilisé par get_sujets *f.
 * userdefine recevra le pointeur qu'on aura passé à get_sujets.
 *
 * appel de get_sujets avec mafonction :
 * get_sujets(f,"lacategorie",mafonction,userdefine);
 * si userdefine n'est pas utilisé :
 * get_sujets(f,"lacategorie",mafonction,NULL);
 *
 * > ma fonction doit retourner un int soit 0 ou 1 :
 *   1 stop le scan en cours
 *   0 continue le scan en cours
 */
e_moderr get_sujets(FLK *f,char *titre_categorie,
        int (*callback)(FLK *flk,char *titre_categorie,char *recup,const void *userdef),const void *userdefine);
/*
 * get_liens est une fonction foreach comme les deux precedentes
 * servant à recuperer les liens d'un sujet dans une categorie
 * La fonction qu'on lui passe en parametre
 * reçoit le titre du sujet et de la categorie traitée
 * son prototype doit être le suivant :
 * int mafonction(FLK *flk,char *str1,char *str2,char *str3,const void *userdefine){ ... }
 *    str1 recevra le titre du sujet scanné,
 *    str2 recevra le titre de la categorie auquel le sujet appartient,
 *    str3 recevra le lien actuellement scanné.
 *    userdefine est du type void* il recevera le pointeur qu'on lui aura
 * passé en paramètre de get_liens.
 *    flk recevra le FLK utilisé par get_liens *f.
 *
 * > mafonction doit retourner un int, soit 1 ou 0, on retourne 1 pour
 *   stoper le scan en cours et donc ne pas lister tout les objets suivants
 *   et on retourne 0 pour continuer le scan.
 *
 * l'appel de get_liens avec mafonction :
 * get_liens(f,"sujet","categorie",mafonction,userdefine);
 * userdefine est un pointeur, on peut lui passer une adresse pour ensuite
 * la récupérer dans nôtre fonction callback.
 * Si userdefine n'est pas utilisé on le met à NULL
 * exemple :
 * get_liens(f,"sujet8","categorie1",macallback,NULL);
 */
e_moderr get_liens(FLK *f,char *titre_sujet,char *titre_categorie,
        int (*callback)(FLK *flk,char *titre_sujet,char *titre_categorie,
            char *recup,const void *userdef),const void *userdefine);

/*
 * flk_load sert à charger un fichier dans un FLK
 * un int pour le retour codes d'erreur :
 * 2 - erreur ouverture du fichier
 * 1 - erreur f non initialisé (s'il est NULL = erreur)
 * 0 - si le chargement s'est déroulé correctement
 */
int flk_load(FLK *f,char *fichier);

/*
 * EN PROGRESSION / A TERMINER
 * flk_save devra servir à enregistrer un FLK directement dans
 * un fichier en lui précisant l'adresse/nom d'un fichier à enregistré
 * et le FLK
 * int pour le retour codes d'erreur
 */
int flk_save(FLK *f,char *fichier);

#endif
