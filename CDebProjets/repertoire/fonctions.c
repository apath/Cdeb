#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "fonctions.h"

/*recherche par nom*/
int recherche_nom(struct Fiche *contact,char *nom_rechercher,int capacite){
    int i,l;
    /*Met la premiere letre en ma j et le reste en mini*/
    l=strlen(nom_rechercher);
    for(i=0;i<l;i++){
        if(i==0){
            nom_rechercher[i]=toupper(nom_rechercher[i]);
        }
        else{
            nom_rechercher[i]=tolower(nom_rechercher[i]);
        }
    }
    for(i=0;i<capacite;i++){
        if(strcmp(contact[i].nom,nom_rechercher)) {
            affiche_id(contact,i);
            return 0; /* le nom est trouvé */
        }
    }
    return 1; /* le nom n'est pas trouvé */
}


/*supprime toutes les fiches existantes par recherche d'ID*/
void supprime_tout(struct Fiche *contact,int capacite){
 int i;
 for(i=0;i<capacite;i++){
    if(contact[i].id!=0) supp_contact(contact,i+1);
 }
}

/*Ajout de la fonction supp_contact.
 *int i correspond a l'id de la fiche contact à supprimer. */
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

/* get_str remplace le scanf, on lui passe un buffer en paramètre et la taille max
 * de celui-ci (max-1 pour le 0 de fin de chaîne) et la fonction utilise getchar()
 * pour remplir le buffer puis termine la châine par zéro et la retourne */
char *get_str(char *s,int max){
    int i; char c;
    for(i=0;(c=getchar())!='\n'&&i<max-1;i++) s[i]=c;
    s[i]='\0';
    return s;
}

void ajouter_contact(struct Fiche *contact, int capacite){
    char buff[256];
    int i,j,l;

    for(i=0;i<capacite;i++)
        if(recherche_id(contact,i+1,capacite)) break;
    contact[i-1].id=i; i-=1;
    printf("Nom: ");
    contact[i].nom=longueur_chaine(get_str(buff,256));
     /* Formatage de contact[i].nom ici*/
    /* tu n'es pas forcé de créer un nouveau tableau pour modifier le nom
     * car la taille ne changera pas seulement les valeurs, utilises
     * directement contact[i].nom */
    l=strlen(contact[i].nom);
    char nom_formate[l]; /* attention on déclare les var avant les instructions dans les proprietes de ton projet dans build option de compilation
    coche l'option "ansi", "wall" et "wallextra" pour avoir des warinings
    dans ces cas là */
    strcpy(nom_formate,contact[i].nom);
    for(j=0;j<l;j++){
        if(j==0){
            nom_formate[j]=toupper(nom_formate[j]);
        }
        else{
            nom_formate[j]=tolower(nom_formate[j]);
        }
    }
    strcpy(contact[i].nom,nom_formate);
       /* Fin formatage */
    printf("Prenom: ");
    contact[i].prenom=longueur_chaine(get_str(buff,256));
    printf("Sexe: ");
    contact[i].sexe=longueur_chaine(get_str(buff,256));
    printf("Date de naissance: ");
    /*pour la date attendre que yrnas ait fait la fonction de parsing "0/0/0" */
    /*contact[id_libre].date_naissance=x(get_str(buff,256));*/
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
        if(contact[i].id==(id_rechercher-1)) return 0; /* l'id est trouvé */
    }
    return 1; /* l'id n'est pas trouvé */
}

char *longueur_chaine(char *chaine){ /* la fonction retourne un pointeur */
    char *pointeur= NULL;
    pointeur= malloc(sizeof(char)*(strlen(chaine)+1));
    if (pointeur == NULL) {   /* On vérifie si l'allocation a marché ou pas */
        exit(0); /* On arrête tout */
    }
    strcpy(pointeur,chaine);
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
