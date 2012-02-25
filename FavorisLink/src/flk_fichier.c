#include <stdio.h>
#include "flk.h"
#define MAXCSL 2048 /* longueur max pour les chaines */
/*
 * flk_load sert à charger un fichier .flk
 * dans un FLK initialisé,
 * le FLK peut déjà contenir des categories,sujets,liens
 * avant le chargement d'un fichier dans celui-ci.
 * usage :
 *         flk_load(f,"lefichier.flk");
 * En cas d'erreur la fonction retournera un entier :
 *         2 - probleme d'ouverture du fichier
 *         1 - le FLK n'est pas initialisé
 * En cas de réussite la fonction retournera zero 0
 */
int flk_load(FLK *f,char *fichier){
    size_t c,i, /* compteur fread et buff */
           ct,st,lu,/* drapeaux cat,suj,url */
           z; /* compteur cat,suj,url */
    char buff[256], /* buff fread */
         categorie_titre[MAXCSL],
         sujet_titre[MAXCSL],
         lien_url[MAXCSL];
    FILE *rf;
    if(f){
        rf=fopen(fichier,"rb");
        if(rf){
            while((c=fread(buff,sizeof(char),256,rf))){
                for(i=0;i<c;i++)
                  {
                    if((buff[i]!='\r')&&(buff[i]!='\n')){
                        if((lu==1)&&((buff[i]!='`')&&(buff[i]!='}'))){
                            if(z<MAXCSL) lien_url[z]=buff[i];
                            z++;
                        }
                        if((st==1)&&(buff[i]!='{')){
                            if(z<MAXCSL) sujet_titre[z]=buff[i];
                            z++;
                        }
                        if((ct==1)&&(buff[i]!=']')){
                            if(z<MAXCSL) categorie_titre[z]=buff[i];
                            z++;
                        }
                        if(buff[i]=='['){
                            z=0; ct=1; st=0; lu=0;
                        }
                        if(buff[i]==']'){
                            categorie_titre[z]='\0';
                            if(*categorie_titre)
                                flk_mod_categorie(ADD,
                                        categorie_titre,
                                        NULL,f);
                            ct=0; st=1; z=0; lu=0; sujet_titre[0]='\0';
                        }
                        if(buff[i]=='{'){
                            sujet_titre[z]='\0';
                            if(*sujet_titre)
                                flk_mod_sujet(ADD,
                                        sujet_titre,NULL,
                                        categorie_titre,f);
                            st=0; z=0; lu=1;
                        }
                        if(buff[i]=='}'){
                            lien_url[z]='\0';
                            if(*lien_url)
                                flk_mod_url(ADD,
                                        lien_url,NULL,
                                        sujet_titre,categorie_titre,f);
                            sujet_titre[0]='\0';
                            lien_url[0]='\0';
                            z=0; st=1; lu=0;
                        }
                        if(buff[i]=='`'){
                            lien_url[z]='\0';
                            if(*lien_url)
                                flk_mod_url(ADD,
                                        lien_url,NULL,
                                        sujet_titre,categorie_titre,f);
                            lien_url[0]='\0';
                            z=0;
                        }
                    }
                  }
            }
            fclose(rf);
        } else return 2;/* probleme ouverture fichier */
    } else return 1;/* problem flk n'existe pas */
    return 0;/* tout est ok */
}
