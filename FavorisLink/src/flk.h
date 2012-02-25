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
 * les structures sont chaqu'une utilis�es en liste cha�n�e simple
 * les ajouts sont fait sur l'index,la t�te de liste.
 * il n'y a pas de queue donc que des pointeurs "suivant" (*next) et
 * des index pour la t�te de liste.
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
 * une autre fa�on de representer les structures :
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
 * en cas d'impossibilit� d'allouer la m�moire
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
 * en affichant l'erreur � l'aide de print_err
 * OKEY indique qu'aucune erreur connue n'a eu lieu.
 */
typedef enum{OKEY,ERR_EXIST,ERR_NOEXIST,ERR_CATNOEXIST,ERR_SUJNOEXIST,
    ERR_ALLOC_TITRE,ERR_ALLOC_STRUCT,ERR_UNKMOD}e_moderr;

/*
 * e_modtype est un type utilis� dans les fonctions de modifications
 * il sert � pr�ciser le type de modification qu'on apporte,
 * un ajout : ADD
 * une suppression : DEL
 * un changement de titre ou d'url : RENAME
 */
typedef enum{DEL,ADD,RENAME}e_modtype;

/*
 * print_err est une simple fonction pour afficher les e_moderr
 * sert � debugger.
 * le param�tre okey lorsqu'il est diff�rent de z�ro, indique aussi
 * le cas d'une r�ussite : OKEY
 */
void print_err(e_moderr error,int okey);

/*
 * flk_mod_categorie fonction servant � 
 * ajouter, supprimer une categorie ou changer son titre.
 * le param�tre nouveau_titre_categorie n'est utilis� qu'avec
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
 * flk_mod_sujet fonction servant �
 * ajouter, supprimer un sujet dans une categorie et changer
 * son titre.
 * le param�tre nouveau_titre_sujet n'est utilis� qu'avec le
 * type de modification RENAME
 * un sujet faisant partie d'une categorie il faut pr�ciser
 * la cat�gorie dans laquelle le sujet sera ajout�/supprim� ou
 * renomm�.
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
 * flk_mod_url fonction servant �
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
 * litt�ralement : pour chaque.
 * pour chaque categories dans un FLK cette fonction va en appeler
 * une autre qu'on lui aura envoy� en param�tre,
 * cette fonction doit �tre sous la forme :
 * void mafonction(FLK *flk,char *str){ ... }
 * str recevra le titre de la categorie actuellement scann�e.
 * flk recevra le FLK utilis� par get_categories *f.
 * pour appel� get_categories avec mafonction :
 * get_categories(f,mafonction);
 */
e_moderr get_categories(FLK *f,void (*callback)(FLK *flk,char *recup));
/*
 * get_sujets est une fonction foreach comme get_categories
 * � la diff�rence qu'il faut lui pr�ciser la categorie � scanner
 * evidemment.
 * La fonction qu'on lui passe en parametre
 * re�oit aussi le titre de la cat�gorie pour chaque sujet scann�
 * forme de la fonction � lui passer en parametre :
 * void mafonction(FLK *flk,char *str1,char *str2){ ... }
 * str1 recevra le titre de la categorie scann�e,
 * str2 recevra le sujet actuellement scann�.
 * flk recevra le FLK utilis� par get_sujets *f.
 * get_sujets(f,"lacategorie",mafonction);
 */
e_moderr get_sujets(FLK *f,char *titre_categorie,
        void (*callback)(FLK *flk,char *titre_categorie,char *recup));
/*
 * get_liens est une fonction foreach comme les deux precedentes
 * servant � recuperer les liens d'un sujet dans une categorie
 * La fonction qu'on lui passe en parametre
 * re�oit le titre du sujet et de la categorie trait�e
 * sa forme doit �tre la suivante :
 * void mafonction(FLK *flk,char *str1,char *str2,char *str3){ ... }
 * str1 recevra le titre du sujet scann�,
 * str2 recevra le titre de la categorie auquel le sujet appartient,
 * str3 recevra le lien actuellement scann�.
 * flk recevra le FLK utilis� par get_liens *f.
 * l'appel de get_liens avec mafonction :
 * get_liens(f,"sujet","categorie",mafonction);
 */
e_moderr get_liens(FLK *f,char *titre_sujet,char *titre_categorie,
        void (*callback)(FLK *flk,char *titre_sujet,char *titre_categorie,
            char *recup));

/*
 * EN PROGRESSION / A TERMINER
 * flk_load devra servir � charger un fichier dans un FLK
 * int pour le retour codes d'erreur
 */
int flk_load(FLK *f,char *fichier);
/*
 * EN PROGRESSION / A TERMINER
 * flk_save devra servir � enregistrer un FLK directement dans
 * un fichier en lui pr�cisant l'adresse/nom d'un fichier � enregistr�
 * et le FLK
 * int pour le retour codes d'erreur
 */
int flk_save(FLK *f,char *fichier);

#endif
