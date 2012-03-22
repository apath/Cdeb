#include <stdio.h>
#include <stdlib.h>
#include "fonctions.h"

int main()
{
    struct Fiche contact[10];
    initialise_fiche(contact,10,0);

    ajouter_contact(contact,10);

    contact[0].id=1;
    contact[0].nom=longueur_chaine("Dupont");
    contact[0].date_naissance=ret_naissance(30,1,1980);

    if(!recherche_id(contact,1,10)){
        affiche_id(contact,1);
    }

    return 0;
}
