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

int recherche_nom(struct Fiche *contact,const char *nom_rechercher,int capacite);
void viderBuffer();
void modifier_contact(struct Fiche *contact,int capacite);
void supprime_tout(struct Fiche *contact,int capacite);
void affiche_tout(struct Fiche *contact,int capacite);
void supp_contact(struct Fiche *contact,int i);
void ajouter_contact(struct Fiche *contact, int capacite);
void initialise_fiche(struct Fiche *contact,int capacite);
int recherche_id(struct Fiche *contact,int id_rechercher,int capacite);
void affiche_id(struct Fiche *contact,int i);
char *longueur_chaine(char *chaine);
time_t ret_naissance(int j,int m,int a);
time_t s_naissance(char *date);
void affiche_naissance(time_t date);
int save_fiche(struct Fiche *contact,int capacite,const char *fichier);
int load_fiche(struct Fiche *contact,int capacite,char *nom_fichier);

#endif /* FONCTIONS_H_INCLUDED */
