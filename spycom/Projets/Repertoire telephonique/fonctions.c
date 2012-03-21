#include <stdio.h>
#include <stdlib.h>
#include "fonctions.h"

int recherche_id(struct Fiche,int id_rechercher,int capacite){
    int i, emplacement_libre;
    for(i=0;i<10;i++){
        if(contact[i].id==id_rechercher){
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
         else if(contact[i].id==0)
            emplacement_libre = i;//l'id est vide
    }
    return emplacement_libre;
}

char longueur_chaine(char *chaine){
    char *pointeur= NULL;
    pointeur= malloc(sizeof(char)*strlen(chaine)+1);
    if (pointeur == NULL) {   // On vérifie si l'allocation a marché ou pas
            exit(0); // On arrête tout
    }
    strcpy(pointeur,chaine);
    return pointeur;
}
