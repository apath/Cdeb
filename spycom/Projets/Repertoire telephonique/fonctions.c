#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fonctions.h"

void initialise_fiche(struct Fiche *contact,int capacite){
    int i;
    for(i=0;i<capacite;i++){
        contact[i].id=0;
        contact[i].nom=NULL;
        contact[i].prenom=NULL;
        contact[i].sexe=NULL;
        contact[i].date_naissance=NULL;
        contact[i].email=NULL;
        contact[i].numfix=NULL;
        contact[i].nummobil=NULL;
        contact[i].adresse=NULL;
    }
}

void affiche_id(struct Fiche *contact,int i){
    i-=1;
    printf("Identifiant: %d\n", contact[i].id);
    printf("Nom: %s\n", contact[i].nom);
    printf("Prenom: %s\n", contact[i].prenom);
    printf("Sexe: %s\n", contact[i].sexe);
    printf("Date de naissance: %s\n", contact[i].date_naissance);
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
