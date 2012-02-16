#ifndef _FLK_FILE_FORMAT_
#define _FLK_FILE_FORMAT_

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
};

typedef struct flk{
    struct categorie *categories_index;
}FLK;

FLK *flk_init(void);
void flk_free(FLK *f);

typedef enum{OKEY,ERR_EXIST,ERR_NOEXIST,
    ERR_ALLOC_TITRE,ERR_ALLOC_STRUCT}e_moderr;
typedef enum{DEL,ADD,RENAME}e_modtype;
void print_err(e_moderr error);

e_moderr flk_mod_categorie(e_modtype mod,
        char *titre_categorie,
        char *nouveau_titre_categorie,
        FLK *f);
e_moderr flk_mod_sujet(e_modtype mod,
        char *titre_sujet,
        char *nouveau_titre_sujet,
        char *titre_categorie,
        FLK *f);
e_moderr flk_mod_url(e_modtype mod,
        char *url,
        char *nouvelle_url,
        char *titre_sujet,
        char *titre_categorie,
        FLK *f);

e_moderr free_liens(char *titre_sujet,char *titre_categorie,FLK *f);
e_moderr free_sujets(char *titre_categorie,FLK *f);
e_moderr free_categories(FLK *f);

FLK *flk_load(char *fichier);
int flk_save(char *fichier,FLK *f);

#endif
