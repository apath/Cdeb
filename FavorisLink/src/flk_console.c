#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include "flk.h"

struct dir{
    int type; /* 0-FLK 1-CAT 2-SUJ */
    int n,m,tn;
    char *cat,*suj,*tmp;
};

/* callback commande ls */
int affiche_cat(FLK *f,char *ctitre,const void *ud){
    (void)f;
    int *x=(int*)ud;
    printf("%d %s\n",*x,ctitre);
    ++*x;
    return 0;
}
int affiche_suj(FLK *f,char *ctitre,char *stitre,const void *ud){
    (void)f,(void)ctitre;
    int *x=(int*)ud;
    printf("%d %s\n",*x,stitre);
    ++*x;
    return 0;
}
int affiche_url(FLK *f,char *stitre,char *ctitre,char *url,const void *ud){
    (void)f,(void)stitre,(void)ctitre;
    int *x=(int*)ud;
    printf("%d %s\n",*x,url);
    ++*x;
    return 0;
}

/* callback commande tree */
int tree_url(FLK *f,char *stitre,char *ctitre,char *url,const void *ud){
    (void)f,(void)stitre,(void)ctitre,(void)ud;
    printf("|   |   |---%s\n",url);
    return 0;
}
int tree_suj(FLK *f,char *ctitre,char *stitre,const void *ud){
    (void)ud;
    printf("|   |\n|   |---%s\n",stitre);
    get_liens(f,stitre,ctitre,tree_url,NULL);
    return 0;
}
int tree_cat(FLK *f,char *ctitre,const void *ud){
    (void)ud;
    printf("|\n|---%s\n",ctitre);
    get_sujets(f,ctitre,tree_suj,NULL);
    return 0;
}

/* callback commande cd */
int recup_suj(FLK *f,char *ctitre,char *stitre,const void *ud){
    (void)f;
    struct dir *dd=(struct dir*)ud;
    if((dd->tn==1)&&(dd->n==dd->m)){
        dd->type=2;
        dd->cat=ctitre;
        dd->suj=stitre;
        dd->n+=1;
        return 1;
    }
    if((dd->tn==2)&&(!strcmp(stitre,dd->tmp))){
        dd->type=2;
        dd->cat=ctitre;
        dd->suj=stitre;
        dd->n=-1;
        return 1;
    }
    dd->n+=1;
    return 0;
}
int recup_cat(FLK *f,char *ctitre,const void *ud){
    (void)f;
    struct dir *dd=(struct dir*)ud;
    if((dd->tn==1)&&(dd->n==dd->m)){
        dd->type=1;
        dd->cat=ctitre;
        dd->n+=1;
        return 1;
    }
    if((dd->tn==2)&&(!strcmp(ctitre,dd->tmp))){
        dd->type=1;
        dd->cat=ctitre;
        dd->n=-1;
        return 1;
    }
    dd->n+=1;
    return 0;
}
/* callback commande del */
int supp_cat(FLK *f,char *ctitre,const void *ud){
    struct dir *dd=(struct dir*)ud;
    if(dd->n==dd->m){
        flk_mod_categorie(DEL,ctitre,NULL,f);
        dd->n+=1;
        return 1;
    }
    dd->n+=1;
    return 0;
}
int supp_suj(FLK *f,char *ctitre,char *stitre,const void *ud){
    struct dir *dd=(struct dir*)ud;
    if(dd->n==dd->m){
        flk_mod_sujet(DEL,stitre,NULL,ctitre,f);
        dd->n+=1;
        return 1;
    }
    dd->n+=1;
    return 0;
}
int supp_url(FLK *f,char *stitre,char *ctitre,char *url,const void *ud){
    struct dir *dd=(struct dir*)ud;
    if(dd->n==dd->m){
        flk_mod_url(DEL,url,NULL,stitre,ctitre,f);
        dd->n+=1;
        return 1;
    }
    dd->n+=1;
    return 0;
}

/* les commandes */
int getcmd(FLK *f,struct dir *dd,char *b,int max){
    int i,count=0; char c,*p=NULL,*rename=NULL;
    e_moderr err=0;
    for(i=0;i<max-1&&(c=getchar())!='\n';i++)
        b[i]=c;
    b[i]='\0';
    for(i=0;b[i];i++) if(b[i]==' '){ b[i]='\0'; p=&b[i+1]; break; }

    if(!strcmp(b,"ls")){
        if(!p){
            if(dd->type==0)
                err=get_categories(f,affiche_cat,&count);
            else if(dd->type==1)
                err=get_sujets(f,dd->cat,affiche_suj,&count);
            else
                err=get_liens(f,dd->suj,dd->cat,affiche_url,&count);
        } else fprintf(stderr,"usage : ls\n");
    }
    else if(!strcmp(b,"tree")){
        if(!p){
            if(dd->type==0)
                get_categories(f,tree_cat,NULL);
            else if(dd->type==1)
                get_sujets(f,dd->cat,tree_suj,NULL);
            else
                get_liens(f,dd->suj,dd->cat,tree_url,NULL);
        } else fprintf(stderr,"usage : tree\n");
    }
    else if(!strcmp(b,"cd")){
        if(p){
            for(i=0;isdigit(p[i]);i++);
            if(p[i]==0){
                dd->m=atoi(p);
                if(dd->type==1){
                    dd->tn=1;
                    err=get_sujets(f,dd->cat,recup_suj,dd);
                }
                else if(dd->type==0){
                    dd->tn=1;
                    err=get_categories(f,recup_cat,dd);
                } else fprintf(stderr,"ERR deplacement aucun sens.\n");
                if(dd->m>=dd->n) fprintf(stderr,"ERR selection %d introuvable.\n",dd->m);
            }
            else if(!strcmp(p,"..")){
                if(dd->type==2)dd->type=1;
                else if(dd->type==1)dd->type=0;
            }
            else if(!strcmp(p,"../..")){
                if(dd->type==2)dd->type=0;
            } else {
                dd->tmp=p;
                if(dd->type==1){
                    dd->tn=2;
                    err=get_sujets(f,dd->cat,recup_suj,dd);
                }
                else if(dd->type==0){
                    dd->tn=2;
                    err=get_categories(f,recup_cat,dd);
                } else fprintf(stderr,"ERR deplacement aucun sens.\n");
                if(dd->n>=0) fprintf(stderr,"ERR selection %s introuvable.\n",dd->tmp);
            }
        } else fprintf(stderr,"usage :\tcd 0\n\tcd ..\n\tcd title\n");
    }
    else if(!strcmp(b,"del")){
        if(p){
            for(i=0;isdigit(p[i]);i++);
            if(p[i]==0){
                dd->m=atoi(p);
                if(dd->type==0){
                    dd->tn=1;
                    err=get_categories(f,supp_cat,dd);
                }
                else if(dd->type==1){
                    dd->tn=1;
                    err=get_sujets(f,dd->cat,supp_suj,dd);
                } else {
                    dd->tn=1;
                    err=get_liens(f,dd->suj,dd->cat,supp_url,dd);
                }
                if(dd->m>=dd->n) fprintf(stderr,"ERR selection %d introuvable.\n",dd->m);
            }
            else if(!strcmp(p,"*")){
                if(dd->type==0)
                    err=free_categories(f);
                else if(dd->type==1)
                    err=free_sujets(dd->cat,f);
                else
                    err=free_liens(dd->suj,dd->cat,f);
            } else {
                dd->tmp=p;
                if(dd->type==0){
                    err=flk_mod_categorie(DEL,dd->tmp,NULL,f);
                }
                else if(dd->type==1){
                    err=flk_mod_sujet(DEL,dd->tmp,NULL,dd->cat,f);
                } else {
                    err=flk_mod_url(DEL,dd->tmp,NULL,dd->suj,dd->cat,f);
                }
            }
        } else fprintf(stderr,"usage :\tdel *\n\tdel 0\n\tdel title\n");
    }
    else if(!strcmp(b,"add")){
        if(p){
            if(dd->type==0)
                err=flk_mod_categorie(ADD,p,NULL,f);
            else if(dd->type==1)
                err=flk_mod_sujet(ADD,p,NULL,dd->cat,f);
            else
                err=flk_mod_url(ADD,p,NULL,dd->suj,dd->cat,f);
        } else fprintf(stderr,"usage : add title\n");
    }
    else if(!strcmp(b,"rename")){
        if(p){
            for(i=0;p[i];i++) if(p[i]==' '){ p[i]='\0'; rename=&p[i+1]; break; }
            if(rename){
                if(dd->type==0)
                    err=flk_mod_categorie(RENAME,p,rename,f);
                else if(dd->type==1)
                    err=flk_mod_sujet(RENAME,p,rename,dd->cat,f);
                else
                    err=flk_mod_url(RENAME,p,rename,dd->suj,dd->cat,f);
            } else fprintf(stderr,"usage : rename title newtitle\n");
        } else fprintf(stderr,"usage : rename title newtitle\n");
    }
    else if(!strcmp(b,"save")){
        if(p){
            if(flk_save(f,p)) fprintf(stderr,"ERR creation fichier.\n");
        } else fprintf(stderr,"usage : save file.flk\n");
    }
    else if(!strcmp(b,"load")){
        if(p){
            if(flk_load(f,p)) fprintf(stderr,"ERR ouverture fichier.\n");
        } else fprintf(stderr,"usage : load file.flk\n");
    }
    else if((!strcmp(b,"quit"))||(!strcmp(b,"exit"))){
        return 1;
    }
    else if(!strcmp(b,"help")){
        printf("HELP console FLK\n\nCommandes :\n"
                "ls\t\t- affiche le contenu du repertoire actuel.\n"
                "tree\t\t- affiche l'arbre du repertoire actuel.\n"
                "cd ..|n|s\t- pour se deplacer dans un repertoire ou revenir en arriere.\n"
                "del *|n|s\t- pour supprimer une (ou toutes) selection(s)\n"
                "\t\t  du repertoire actuel.\n"
                "add s\t\t- permet d'ajouter une entree dans le repertoire actuel.\n"
                "rename s1 s2\t- renomme s1 du repertoire actuel en s2.\n"
                "save s.flk\t- enregistrer le FLK dans un fichier.\n"
                "load s.flk\t- charger un fichier.\n"
                "quit|exit\t- fermer la console FLK.\n"
                "help\t\t- afficher l'aide.\n\n"
                "Les parametres :\n"
                "*\t\t- tout.\n"
                "n\t\t- un nombre.\n"
                "s\t\t- une chaine de caracteres.\n"
                "..\t\t- repertoire precedent.\n\n");
    } else
        fprintf(stderr,"ERR commande introuvable.\n");
    print_err(err,0);
    return 0;
}

  /* la console */
void flk_console(FLK *f)
  {
    struct dir dd;
    char buff[4096];
    dd.type=0;
    printf("Console FLK v0\nPour afficher l'aide commande help\n\n");
    while(1){
        memset(buff,'\0',sizeof(char)*4096);
        dd.n=0,dd.tn=0;dd.tmp=NULL;dd.m=0;
        if(dd.type==0) printf("$FLK>");
        else if(dd.type==1) printf("$FLK/%s>",dd.cat);
        else printf("$FLK/%s/%s>",dd.cat,dd.suj);
        if(getcmd(f,&dd,buff,4096)) break;
    }
  }
