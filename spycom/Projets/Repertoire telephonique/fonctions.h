#ifndef FONCTIONS_H_INCLUDED
#define FONCTIONS_H_INCLUDED

struct Fiche
{
    int id;
    char *nom;
    char *prenom;
    char *sexe;
    char *date_naissance;
    char *email;
    char *numfix;
    char *nummobil;
    char *adresse;
};

void initialise_fiche(struct Fiche *contact,int capacite);
int recherche_id(struct Fiche *contact,int id_rechercher,int capacite);
void affiche_id(struct Fiche *contact,int i);
char *longueur_chaine(char *chaine);

#endif /* FONCTIONS_H_INCLUDED */
