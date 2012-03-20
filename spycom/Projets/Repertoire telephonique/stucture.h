#ifndef STUCTURE_H_INCLUDED
#define STUCTURE_H_INCLUDED
typedef struct Fiche Fiche;
struct Fiche
{
    int identifiant;
    char nom[100];
    char prenom[100];
    char sexe[1];
    int naissance;
    char mail[100];
    int telephone;
    char adresse[200];
};

#endif // STUCTURE_H_INCLUDED
