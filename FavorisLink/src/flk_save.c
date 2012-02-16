#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include "flk.h"

void print_err(e_moderr error){
    switch(error){
        case ERR_EXIST:
            fprintf(stderr,"ERR_EXIST\n");
            break;
        case ERR_NOEXIST:
            fprintf(stderr,"ERR_NOEXIST\n");
            break;
        case ERR_ALLOC_TITRE:
            fprintf(stderr,"ERR_ALLOC_TITRE\n");
            break;
        case ERR_ALLOC_STRUCT:
            fprintf(stderr,"ERR_ALLOC_STRUCT\n");
            break;
        default:;
    }
}

char *alloc_chaine(char *s){
    char *ptr;
    ptr=malloc(sizeof(char)*strlen(s)+1);
    if(ptr) strcpy(ptr,s);
    return ptr;
}

FLK *flk_init(void){
    FLK *ptr;
    ptr=malloc(sizeof(FLK));
    if(ptr)
        ptr->categories_index=NULL;
    return ptr;
}

struct temp{
    struct categorie *cptr,*cptrtmp;
    struct sujet *sptr,*sptrtmp;
    struct lien *lptr,*lptrtmp;
};
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
            free(l),l=NULL;
        }
        tmp->sptr->liens_index=NULL;
        return OKEY;
    }
    free(tmp);
    return ERR_NOEXIST;
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
            free(s),s=NULL;
        }
        tmp->cptr->sujets_index=NULL;
        return OKEY;
    }
    free(tmp);
    return ERR_NOEXIST;
  }
e_moderr free_categories(FLK *f)
  {
    struct categorie *c;
    while(f->categories_index){
        c=f->categories_index;
        f->categories_index=f->categories_index->next;
        free_sujets(c->titre,f);
        free(c),c=NULL;
    }
    f->categories_index=NULL;
    return OKEY;
  }

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
              free(cptr);
              return OKEY;
        } else return ERR_NOEXIST;
    }
    if(mod==RENAME){
        if(cptr){
            free(cptr->titre);
            if((cptr->titre=alloc_chaine(ntitre))) return OKEY;
            else return ERR_ALLOC_TITRE;
        } else return ERR_NOEXIST;
    }
    return OKEY;
  }

