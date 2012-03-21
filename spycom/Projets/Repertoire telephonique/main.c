#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fonctions.h"

int main()
{
    struct Fiche contact[10];
    initialise_fiche(contact,10);

    contact[0].id=1;
    contact[0].nom=longueur_chaine("Dupont");

    if(!recherche_id(contact,1,10)){
        affiche_id(contact,1);
    }

    return 0;
}
