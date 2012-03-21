#ifndef FONCTIONS_H_INCLUDED
#define FONCTIONS_H_INCLUDED

int recherche_id(struct Fiche,int id_rechercher,int capacite);

char longueur_chaine(char *chaine) ;

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


#endif // FONCTIONS_H_INCLUDED
