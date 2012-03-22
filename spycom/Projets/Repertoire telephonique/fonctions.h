#ifndef FONCTIONS_H_INCLUDED
#define FONCTIONS_H_INCLUDED
#include <time.h>

struct Fiche
{
    int id;
    char *nom;
    char *prenom;
    char *sexe;
    time_t date_naissance;
    char *email;
    char *numfix;
    char *nummobil;
    char *adresse;
};
void ajouter_contact(struct Fiche *contact, int capacite);
void initialise_fiche(struct Fiche *contact,int capacite,int i);
int recherche_id(struct Fiche *contact,int id_rechercher,int capacite);
void affiche_id(struct Fiche *contact,int i);
char *longueur_chaine(char *chaine);
time_t ret_naissance(int j,int m,int a);

#endif /* FONCTIONS_H_INCLUDED */
