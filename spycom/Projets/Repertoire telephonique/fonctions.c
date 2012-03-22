#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fonctions.h"

void ajouter_contact(struct Fiche *contact, int capacite){
    int i, id_libre = -1;
     /*recherche d'une fiche libre*/
    for(i=0;i<capacite;i++){
        if(contact[i].id==0){
            id_libre=i;
        }
    }
    if(id_libre!= -1){
        initialise_fiche(contact,id_libre+1,id_libre);/*Initialisation de la fiche libre*/
        contact[id_libre].id=id_libre+1;
        printf("Identifiant: %d\n", contact[id_libre].id);
        printf("Nom: ");
        scanf("%s",&contact[id_libre].nom);
        printf("Prenom: ");
        scanf("%s",&contact[id_libre].prenom);
        printf("Sexe: ");
        scanf("%s",&contact[id_libre].sexe);
        printf("Date de naissance: ");
        scanf("%s",&contact[id_libre].date_naissance);
        printf("Email: ");
        scanf("%s",&contact[id_libre].email);
        printf("Telephone fixe: ");
        scanf("%s",&contact[id_libre].numfix);
        printf("Telephone mobile: ");
        scanf("%s",&contact[id_libre].nummobil);
        printf("Adresse: ");
        scanf("%s",&contact[id_libre].adresse);
    }
}

/*ajout en parametre de int i pour permettre l'initialisation
 *d'une seule fiche*/
void initialise_fiche(struct Fiche *contact,int capacite,int i){
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

void affiche_id(struct Fiche *contact,int i){
    i--;
    printf("Identifiant: %d\n", contact[i].id);
    printf("Nom: %s\n", contact[i].nom);
    printf("Prenom: %s\n", contact[i].prenom);
    printf("Sexe: %s\n", contact[i].sexe);
    printf("Date de naissance: %s", ctime(&contact[i].date_naissance));
    printf("Email: %s\n", contact[i].email);
    printf("Telephone fixe: %s\n", contact[i].numfix);
    printf("Telephone mobile: %s\n", contact[i].nummobil);
    printf("Adresse: %s\n", contact[i].adresse);
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
