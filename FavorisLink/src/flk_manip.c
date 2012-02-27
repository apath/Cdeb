#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include "flk.h"

  /*
   * print_err fonction basique pour l'affichage des erreurs, permet
   * de debugger plus facilement les fonctions qui retournent un
   * e_moderr
   */
void print_err(e_moderr error,int ok){
    switch(error){
        case ERR_EXIST:
            fprintf(stderr,"ERR_EXIST\n"); break;
        case ERR_NOEXIST:
            fprintf(stderr,"ERR_NOEXIST\n"); break;
        case ERR_ALLOC_TITRE:
            fprintf(stderr,"ERR_ALLOC_TITRE\n"); break;
        case ERR_ALLOC_STRUCT:
            fprintf(stderr,"ERR_ALLOC_STRUCT\n"); break;
        case ERR_CATNOEXIST:
            fprintf(stderr,"ERR_CATNOEXIST\n"); break;
        case ERR_SUJNOEXIST:
            fprintf(stderr,"ERR_SUJNOEXIST\n"); break;
        case ERR_UNKMOD:
            fprintf(stderr,"ERR_UNKMOD\n"); break;
        case OKEY:
            if(ok) fprintf(stderr,"OKEY\n"); break;
        default:;
    }
}

  /*
   * alloc_chaine
   * fonction simplifiant une tâche répétitive qui est la copie
   * d'une chaîne de caractères dans les pointeurs de char situés
   * dans les structures
   */
char *alloc_chaine(char *s){
    char *ptr;
    ptr=malloc(sizeof(char)*strlen(s)+1);
    if(ptr) strcpy(ptr,s);
    return ptr;
}

  /*
   * flk_init
   * initialisation d'un FLK , alloue la mémoire pour l'index
   * des catégories
   */
FLK *flk_init(void){
    FLK *ptr;
    ptr=malloc(sizeof(FLK));
    if(ptr)
        ptr->categories_index=NULL;
    return ptr;
}
  /*
   * flk_free
   * libere toutes les categories d'un FLK avec les sujets et
   * liens qu'elles contiennent.
   * puis libere la structure flk gardant l'index des categories.
   */
void flk_free(FLK *f){
    free_categories(f);
    free(f);
}

  /*
   * structure temporaire servant à garder l'item précédent celui que
   * l'on recherche, ça permet de pouvoir supprimer un item et replacer
   * les liens dans la liste chaînée sans devoir la re boucler à nouveau
   */
struct temp{
    struct categorie *cptr,*cptrtmp;
    struct sujet *sptr,*sptrtmp;
    struct lien *lptr,*lptrtmp;
};

  /*
   * fonctions internes pour la recherche des items
   * categorie,sujet,lien
   */
struct temp *cherche_categorie(char *titre,FLK *f)
  {
    struct temp *tmp;
    tmp=malloc(sizeof(struct temp));
    assert(tmp);
    tmp->cptr=NULL,tmp->cptrtmp=NULL,
        tmp->sptr=NULL,tmp->sptrtmp=NULL,
        tmp->lptr=NULL,tmp->lptrtmp=NULL;
    tmp->cptr=f->categories_index;
    while(tmp->cptr){
        if(!strcmp(tmp->cptr->titre,titre)) return tmp;
        tmp->cptrtmp=tmp->cptr;
        tmp->cptr=tmp->cptr->next;
    }
    free(tmp);
    return NULL;
  }
struct temp *cherche_sujet(char *stitre,char *ctitre,FLK *f)
  {
    struct temp *tmp;
    tmp=cherche_categorie(ctitre,f);
    if(tmp){
        tmp->sptr=tmp->cptr->sujets_index;
        while(tmp->sptr){
            if(!strcmp(tmp->sptr->titre,stitre)) return tmp;
            tmp->sptrtmp=tmp->sptr;
            tmp->sptr=tmp->sptr->next;
        }
    }
    free(tmp);
    return NULL;
  }
struct temp *cherche_lien(char *url,char *stitre,char *ctitre,FLK *f)
  {
    struct temp *tmp;
    tmp=cherche_sujet(stitre,ctitre,f);
    if(tmp){
        tmp->lptr=tmp->sptr->liens_index;
        while(tmp->lptr){
            if(!strcmp(tmp->lptr->url,url)) return tmp;
            tmp->lptrtmp=tmp->lptr;
            tmp->lptr=tmp->lptr->next;
        }
    }
    free(tmp);
    return NULL;
  }

  /*
   * fonctions free
   * liberation de tout les liens,sujets ou categories.
   */
e_moderr free_liens(char *stitre,char *ctitre,FLK *f)
  {
    struct temp *tmp;
    struct lien *l;
    tmp=cherche_sujet(stitre,ctitre,f);
    if(tmp){
        tmp->lptr=tmp->sptr->liens_index;
        while(tmp->lptr){
            l=tmp->lptr;
            tmp->lptr=tmp->lptr->next;
            free(l->url),l->url=NULL;
            free(l),l=NULL;
        }
        tmp->sptr->liens_index=NULL;
        free(tmp);
        return OKEY;
    }
    return ERR_SUJNOEXIST;
  }
e_moderr free_sujets(char *ctitre,FLK *f)
  {
    struct temp *tmp;
    struct sujet *s;
    tmp=cherche_categorie(ctitre,f);
    if(tmp){
        tmp->sptr=tmp->cptr->sujets_index;
        while(tmp->sptr){
            s=tmp->sptr;
            tmp->sptr=tmp->sptr->next;
            free_liens(s->titre,tmp->cptr->titre,f);
            free(s->titre),s->titre=NULL;
            free(s),s=NULL;
            tmp->cptr->sujets_index=tmp->sptr;
        }
        tmp->cptr->sujets_index=NULL;
        free(tmp);
        return OKEY;
    }
    return ERR_CATNOEXIST;
  }
e_moderr free_categories(FLK *f)
  {
    struct categorie *ctmp;
    while(f->categories_index){
        ctmp=f->categories_index->next;
        free_sujets(f->categories_index->titre,f);
        free(f->categories_index->titre),f->categories_index->titre=NULL;
        free(f->categories_index);
        f->categories_index=ctmp;
    }
    f->categories_index=NULL;
    return OKEY;
  }

  /*
   * fonctions mod
   * fonctions de modification de categorie,sujet ou lien
   */
e_moderr flk_mod_categorie(e_modtype mod,
        char *titre_categorie,char *ntitre,FLK *f)
  {
    struct temp *tmp;
    struct categorie *cptr,*cptrtmp;
    tmp=cherche_categorie(titre_categorie,f);
    if(tmp){
        cptr=tmp->cptr;
        cptrtmp=tmp->cptrtmp;
        free(tmp),tmp=NULL;
    } else cptr=NULL,cptrtmp=NULL;
    if(mod==ADD){
        if(!cptr){
            cptr=malloc(sizeof(struct categorie));
            if(cptr){
                if((cptr->titre=alloc_chaine(titre_categorie))){
                    cptr->sujets_index=NULL;
                    cptr->next=f->categories_index;
                    f->categories_index=cptr;
                    return OKEY;
                } else return ERR_ALLOC_TITRE;
            } else return ERR_ALLOC_STRUCT;
        } else return ERR_EXIST;
    }
    if(mod==DEL){
        if(cptr){
            if(cptrtmp!=NULL) cptrtmp->next=cptr->next;
            free_sujets(titre_categorie,f);
            free(cptr->titre),cptr->titre=NULL;
            free(cptr),cptr=NULL;
            return OKEY;
        } else return ERR_NOEXIST;
    }
    if(mod==RENAME){
        if(cptr){
            free(cptr->titre),cptr->titre=NULL;
            if((cptr->titre=alloc_chaine(ntitre))) return OKEY;
            else return ERR_ALLOC_TITRE;
        } else return ERR_NOEXIST;
    }
    return ERR_UNKMOD;
  }

e_moderr flk_mod_sujet(e_modtype mod,
        char *titre_sujet,
        char *nouveau_titre_sujet,
        char *titre_categorie,
        FLK *f)
  {
    struct temp *tmp;
    struct categorie *cptr;
    struct sujet *sptr,*sptrtmp;
    tmp=cherche_sujet(titre_sujet,titre_categorie,f);
    if(tmp){
        cptr=tmp->cptr;
        sptr=tmp->sptr;
        sptrtmp=tmp->sptrtmp;
        free(tmp),tmp=NULL;
    } else {
        tmp=cherche_categorie(titre_categorie,f);
        if(!tmp) return ERR_CATNOEXIST;
        cptr=tmp->cptr;
        sptr=NULL,sptrtmp=NULL;
        free(tmp),tmp=NULL;
    }
    if(mod==ADD){
        if(!sptr){
            sptr=malloc(sizeof(struct sujet));
            if(sptr){
                if((sptr->titre=alloc_chaine(titre_sujet))){
                    sptr->liens_index=NULL;
                    sptr->next=cptr->sujets_index;
                    cptr->sujets_index=sptr;
                    return OKEY;
                } else return ERR_ALLOC_TITRE;
            } else return ERR_ALLOC_STRUCT;
        } else return ERR_EXIST;
    }
    if(mod==DEL){
        if(sptr){
            if(sptrtmp!=NULL) sptrtmp->next=sptr->next;
            free_liens(titre_sujet,titre_categorie,f);
            free(sptr->titre),sptr->titre=NULL;
            free(sptr),sptr=NULL;
            return OKEY;
        } else return ERR_NOEXIST;
    }
    if(mod==RENAME){
        if(sptr){
            free(sptr->titre),sptr->titre=NULL;
            if((sptr->titre=alloc_chaine(nouveau_titre_sujet)))
                return OKEY;
            else return ERR_ALLOC_TITRE;
        } else return ERR_NOEXIST;
    }
    return ERR_UNKMOD;
  }

e_moderr flk_mod_url(e_modtype mod,
        char *url,
        char *nouvelle_url,
        char *titre_sujet,
        char *titre_categorie,
        FLK *f)
  {
    struct sujet *sptr;
    struct lien *lptr,*lptrtmp;
    struct temp *tmp;
    tmp=cherche_lien(url,titre_sujet,titre_categorie,f);
    if(tmp){
        lptr=tmp->lptr;
        lptrtmp=tmp->lptrtmp;
        sptr=tmp->sptr;
        free(tmp),tmp=NULL;
    } else {
        tmp=cherche_sujet(titre_sujet,titre_categorie,f);
        if(!tmp) return ERR_SUJNOEXIST;
        sptr=tmp->sptr;
        lptr=NULL,lptrtmp=NULL;
        free(tmp),tmp=NULL;
    }
    if(mod==ADD){
        if(!lptr){
            lptr=malloc(sizeof(struct lien));
            if(lptr){
                if((lptr->url=alloc_chaine(url))){
                    lptr->next=sptr->liens_index;
                    sptr->liens_index=lptr;
                    return OKEY;
                } else return ERR_ALLOC_TITRE;
            } else return ERR_ALLOC_STRUCT;
        } else return ERR_EXIST;
    }
    if(mod==DEL){
        if(lptr){
            if(lptrtmp!=NULL) lptrtmp->next=lptr->next;
            free(lptr->url),lptr->url=NULL;
            free(lptr),lptr=NULL;
            return OKEY;
        } else return ERR_NOEXIST;
    }
    if(mod==RENAME){
        if(lptr){
            free(lptr->url),lptr->url=NULL;
            if((lptr->url=alloc_chaine(nouvelle_url))) return OKEY;
            else return ERR_ALLOC_TITRE;
        } else return ERR_NOEXIST;
    }
    return ERR_UNKMOD;
  }

  /*
   * foreach fonction pour scanner un FLK, une categorie, un sujet
   * permet d'appeler une fonction tiers et de lui retourner les
   * items scannés.
   */
e_moderr get_categories(FLK *f,int (*callback)(FLK *flk,char *recup,
            const void *userdef),const void *userdefine)
  {
    struct categorie *cptr,*cptrtmp;
    cptr=f->categories_index;
    if(cptr){
        while(cptr){
            cptrtmp=cptr->next;
            if(callback(f,cptr->titre,userdefine)) break;
            cptr=cptrtmp;
        }
    } else return ERR_NOEXIST;
    return OKEY;
  }
e_moderr get_sujets(FLK *f,char *titre_categorie,
        int (*callback)(FLK *flk,char *titre_categorie,char *recup,
            const void *userdef),const void *userdefine)
  {
    struct sujet *sptr,*sptrtmp;
    struct temp *tmp;
    tmp=cherche_categorie(titre_categorie,f);
    if(tmp){
        sptr=tmp->cptr->sujets_index;
        free(tmp),tmp=NULL;
        while(sptr){
            sptrtmp=sptr->next;
            if(callback(f,titre_categorie,sptr->titre,userdefine))
                break;
            sptr=sptrtmp;
        }
    } else return ERR_CATNOEXIST;
    return OKEY;
  }
e_moderr get_liens(FLK *f,char *titre_sujet,char *titre_categorie,
        int (*callback)(FLK *flk,char *titre_sujet,char *titre_categorie,
            char *recup,const void *userdef),const void *userdefine)
  {
    struct lien *lptr,*lptrtmp;
    struct temp *tmp;
    tmp=cherche_sujet(titre_sujet,titre_categorie,f);
    if(tmp){
        lptr=tmp->sptr->liens_index;
        free(tmp),tmp=NULL;
        while(lptr){
            lptrtmp=lptr->next;
            if(callback(f,titre_sujet,titre_categorie,lptr->url,userdefine))
                break;
            lptr=lptrtmp;
        }
    } else return ERR_SUJNOEXIST;
    return OKEY;
  }
