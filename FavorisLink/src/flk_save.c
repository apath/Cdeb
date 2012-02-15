#include <string.h>
#include <stdlib.h>
#include "flk.h"

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

struct categorie *cherche_categorie(char *titre,FLK *f)
  {
    struct categorie *cptr;
    cptr=f->categories_index;
    while(cptr){
        if(!strcmp(cptr->titre,titre)) return cptr;
        cptr=cptr->next;
    }
    return NULL;
  }
struct sujet *cherche_sujet(char *stitre,char *ctitre,FLK *f)
  {
    struct categorie *cptr;
    struct sujet *sptr;
    cptr=cherche_categorie(ctitre,f);
    if(cptr){
        sptr=cptr->sujets_index;
        while(sptr){
            if(!strcmp(sptr->titre,stitre)) return sptr;
            sptr=sptr->next;
        }
    }
    return NULL;
  }
struct lien *chercher_lien(char *url,char *stitre,char *ctitre,FLK *f)
  {
    struct categorie *cptr;
    struct sujet *sptr;
    struct lien *lptr;
    cptr=cherche_categorie(ctitre,f);
    if(cptr){
        sptr=cherche_sujet(stitre,ctitre,f);
        if(sptr){
            lptr=sptr->liens_index;
            while(lptr){
                if(!strcmp(lptr->url,url)) return lptr;
                lptr=lptr->next;
            }
        }
    }
    return NULL;
  }

e_moderr flk_mod_categorie(e_modtype mod,char *titre_categorie,FLK *f)
  {
    struct categorie *cptr,*cptr_tmp;
    cptr=cherche_categorie(titre_categorie,f);
    if(mod==ADD){
        if(!cptr){
            cptr=malloc(sizeof(struct categorie));
            if(cptr){
                if((cptr->titre=alloc_chaine(titre_categorie))){
                    cptr->sujets_index=NULL;
                    cptr->next=f->categories_index;
                    f->categories_index=cptr;
                    return OKEY;
                } else return ERR_ALLOC;
            } else return ERR_ALLOC;
        } else return ERR_EXIST;
    }
    if(mod==DEL){
        if(cptr){
            /**/
        } else return ERR_NOEXIST;
    }
    if(mod==REPLACE){
    }
    return OKEY;
  }

