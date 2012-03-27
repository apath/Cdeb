#include <stdio.h>
#include <stdlib.h>
#include "fonctions.h"

int main(void)
{

    struct Fiche contact[10];
    initialise_fiche(contact,10);

    ajouter_contact(contact,10);
    ajouter_contact(contact,10);

    recherche_nom(contact,"DUPONT",10);

    affiche_tout(contact,10);
    save_fiche(contact,10,"fichier.txt");

    supprime_tout(contact,10);

    affiche_tout(contact,10);

    return 0;
}
