#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "fonctions.h"

  /*recherche par nom*/
int recherche_nom(struct Fiche *contact,const char *nom_rechercher,int capacite){
    char *buff_nom;
    int i,l;
    l=strlen(nom_rechercher);
    buff_nom=malloc(sizeof(char)*l+1); /* l'erreur de heap etait ici
                                          j'avais oubli� le +1 pour le
                                          caract�re \0 */
    if(!buff_nom) exit(1);
    strcpy(buff_nom,nom_rechercher);
    for(i=0;i<l;i++){
        if(i==0){
            buff_nom[i]=toupper(buff_nom[i]);
        }
        else{
            buff_nom[i]=tolower(buff_nom[i]);
        }
    }
    for(i=0;i<capacite;i++){
        if(contact[i].id!=0){
            if(!strcmp(contact[i].nom,buff_nom)) {
                affiche_id(contact,i);
                return 0; /* le nom est trouv� */
            }
        }
    }
    free(buff_nom);
    return 1; /* le nom n'est pas trouv� */
}


  /*supprime toutes les fiches existantes par recherche d'ID*/
void supprime_tout(struct Fiche *contact,int capacite){
    int i;
    for(i=0;i<capacite;i++){
        if(contact[i].id!=0) supp_contact(contact,i+1);
    }
}

  /*Ajout de la fonction supp_contact.
   *int i correspond a l'id de la fiche contact � supprimer. */
void supp_contact(struct Fiche *contact,int i){
    i--;
    contact[i].id=0;
    free(contact[i].nom),contact[i].nom=NULL;
    free(contact[i].prenom),contact[i].prenom=NULL;
    free(contact[i].sexe),contact[i].sexe=NULL;
    free(contact[i].email),contact[i].email=NULL;
    free(contact[i].numfix),contact[i].numfix=NULL;
    free(contact[i].nummobil),contact[i].nummobil=NULL;
    free(contact[i].adresse),contact[i].adresse=NULL;
}

  /* get_str remplace le scanf, on lui passe un buffer en param�tre et la taille max
   * de celui-ci (max-1 pour le 0 de fin de cha�ne) et la fonction utilise getchar()
   * pour remplir le buffer puis termine la ch�ine par z�ro et la retourne */
char *get_str(char *s,int max){
    int i; char c;
    for(i=0;(c=getchar())!='\n'&&i<max-1;i++) s[i]=c;
    s[i]='\0';
    return s;
}

void ajouter_contact(struct Fiche *contact, int capacite){
    char buff[256];
    int i,j;

    for(i=0;i<capacite;i++)
        if(contact[i].id==0){
            contact[i].id=i+1;
            break;
        }
    printf("Nom: ");
    contact[i].nom=longueur_chaine(get_str(buff,256));

    for(j=0;contact[i].nom[j];j++){
        if(j==0){
            contact[i].nom[j]=toupper(contact[i].nom[j]);
        }
        else{
            contact[i].nom[j]=tolower(contact[i].nom[j]);
        }
    }
    printf("Prenom: ");
    contact[i].prenom=longueur_chaine(get_str(buff,256));
    printf("Sexe: ");
    contact[i].sexe=longueur_chaine(get_str(buff,256));
    printf("Date de naissance: ");
      /*pour la date attendre que yrnas ait fait la fonction de parsing "0/0/0" */
      /*contact[i].date_naissance=x(get_str(buff,256));*/
    printf("Email: ");
    contact[i].email=longueur_chaine(get_str(buff,256));
    printf("Telephone fixe: ");
    contact[i].numfix=longueur_chaine(get_str(buff,256));
    printf("Telephone mobile: ");
    contact[i].nummobil=longueur_chaine(get_str(buff,256));
    printf("Adresse: ");
    contact[i].adresse=longueur_chaine(get_str(buff,256));
}

void initialise_fiche(struct Fiche *contact,int capacite){
    int i;

    for(i=0;i<capacite;i++){
        contact[i].id=0;
        contact[i].nom=NULL;
        contact[i].prenom=NULL;
        contact[i].sexe=NULL;
        contact[i].email=NULL;
        contact[i].numfix=NULL;
        contact[i].nummobil=NULL;
        contact[i].adresse=NULL;
    }
}

  /*affiche toute les fiches existantes par recherche d'ID*/
void affiche_tout(struct Fiche *contact,int capacite){
    int i;
    for(i=0;i<capacite;i++){
        if(contact[i].id!=0) affiche_id(contact,i+1);
    }
}

  /*affiche une fiche demande par son id*/
void affiche_id(struct Fiche *contact,int i){
    i--;
    printf("---------------------------\n");
    printf("Identifiant: %d\n", contact[i].id);
    printf("Nom: %s\n", contact[i].nom);
    printf("Prenom: %s\n", contact[i].prenom);
    printf("Sexe: %s\n", contact[i].sexe);
    printf("Date de naissance: "); affiche_naissance(contact[i].date_naissance);
    printf("Email: %s\n", contact[i].email);
    printf("Telephone fixe: %s\n", contact[i].numfix);
    printf("Telephone mobile: %s\n", contact[i].nummobil);
    printf("Adresse: %s\n", contact[i].adresse);
    printf("---------------------------\n");
}

int recherche_id(struct Fiche *contact,int id_rechercher,int capacite){
    int i;
    for(i=0;i<capacite;i++){
        if(contact[i].id==(id_rechercher-1)) return 0; /* l'id est trouv� */
    }
    return 1; /* l'id n'est pas trouv� */
}

char *longueur_chaine(char *chaine){ /* la fonction retourne un pointeur */
    char *pointeur= NULL,vide[5]="vide";
    int n;
    n=strlen(chaine);
    if(n!=0){
        pointeur = malloc(sizeof(char)*(n+1));
        if(pointeur) strcpy(pointeur,chaine);
    } else {
        pointeur = malloc(sizeof(char)*5);
        if(pointeur) strcpy(pointeur,vide);
    }
    if (pointeur == NULL) {   /* On v�rifie si l'allocation a march� ou pas */
        exit(1); /* On arr�te tout */
    }
    return pointeur;
}

  /* ret_naissance retourne une date dans un time_t
   * on affiche le time_t avec la fonction ctime() */
time_t ret_naissance(int j,int m,int a){
    time_t date_naissance;
    struct tm *dn;
    date_naissance = time(NULL);
    dn = localtime(&date_naissance);
    dn->tm_year = a-1900;
    dn->tm_mon = m-1;
    dn->tm_mday = j;
    date_naissance = mktime(dn);
    return date_naissance;
}

  /* affichage de la date de naissance en time_t sous la forme j/m/a */
void affiche_naissance(time_t date){
    struct tm *dn;
    dn = localtime(&date);
    printf("%d/%d/%d\n",dn->tm_mday,dn->tm_mon+1,dn->tm_year+1900);
}

  /*Ajout dans un fichier texte*/
int save_fiche(struct Fiche *contact,int capacite,const char *fichier){
    int i;
    char retour='\n',virgule=',';
    char date[9]="00/00/00";

    FILE *FICHIER=NULL;
    FICHIER=fopen(fichier,"ab");
    if (FICHIER != NULL){
        for(i=0;i<capacite;i++){
            if(contact[i].id!=0){
                fwrite(contact[i].nom,sizeof(char),strlen(contact[i].nom),FICHIER);
                fwrite(&virgule,sizeof(char),1,FICHIER);
                fwrite(contact[i].prenom,sizeof(char),strlen(contact[i].prenom),FICHIER);
                fwrite(&virgule,sizeof(char),1,FICHIER);
                fwrite(contact[i].sexe,sizeof(char),strlen(contact[i].sexe),FICHIER);
                fwrite(&virgule,sizeof(char),1,FICHIER);
                fwrite(date,sizeof(char),strlen(date),FICHIER);
                fwrite(&virgule,sizeof(char),1,FICHIER);
                fwrite(contact[i].email,sizeof(char),strlen(contact[i].email),FICHIER);
                fwrite(&virgule,sizeof(char),1,FICHIER);
                fwrite(contact[i].numfix,sizeof(char),strlen(contact[i].numfix),FICHIER);
                fwrite(&virgule,sizeof(char),1,FICHIER);
                fwrite(contact[i].nummobil,sizeof(char),strlen(contact[i].nummobil),FICHIER);
                fwrite(&virgule,sizeof(char),1,FICHIER);
                fwrite(contact[i].adresse,sizeof(char),strlen(contact[i].adresse),FICHIER);
                fwrite(&retour,sizeof(char),1,FICHIER);
            }
        }
        fclose(FICHIER);
        return 0;
    }
    return 1;
}

 /* Lecture du fichier .txt*/
int load_fiche(struct Fiche *contact,int capacite,char *nom_fichier){
    int i;
    char retour='\n',virgule=',';
    char date;

    FILE *FICHIER=NULL;
    FICHIER=fopen(nom_fichier,"rb");
    if (FICHIER != NULL){
        fseek(FICHIER,0, SEEK_SET);
        for(i=0;i<capacite;i++){
            if(contact[i].id!=0){
                contact[i].id=fread(&contact[i],sizeof(int),strlen (contact[i].id),FICHIER);
                fread(&virgule,sizeof(char),1,FICHIER);
                contact[i].nom=fread(&contact[i],sizeof(char),strlen(contact[i].nom),FICHIER);
                fread(&virgule,sizeof(char),1,FICHIER);
                contact[i].prenom=fread(&contact[i],sizeof(char),strlen(contact[i].prenom),FICHIER);
                fread(&virgule,sizeof(char),1,FICHIER);
                contact[i].sexe=fread(&contact[i],sizeof(char),strlen(contact[i].sexe),FICHIER);
                fread(&virgule,sizeof(char),1,FICHIER);
                contact[i].date_naissance=fread(&contact[i],sizeof(char),strlen(date),FICHIER);
                fread(&virgule,sizeof(char),1,FICHIER);
                contact[i].email=fread(&contact[i],sizeof(char),strlen(contact[i].email),FICHIER);
                fread(&virgule,sizeof(char),1,FICHIER);
                contact[i].numfix=fread(&contact[i],sizeof(char),strlen(contact[i].numfix),FICHIER);
                fread(&virgule,sizeof(char),1,FICHIER);
                contact[i].nummobil=fread(&contact[i],sizeof(char),strlen(contact[i].nummobil),FICHIER);
                fread(&virgule,sizeof(char),1,FICHIER);
                contact[i].adresse=fread(&contact[i],sizeof(char),strlen(contact[i].adresse),FICHIER);
                fread(&retour,sizeof(char),1,FICHIER);
            }
        }
        fclose(FICHIER);
        return 0;
    }
    return 1;
}