#include <stdio.h>
#include <stdlib.h>
#include "fonctions.h"

int main(void)
{

    struct Fiche contact[10];
    initialise_fiche(contact,10);

    contact[0].id=1;
    contact[0].nom=longueur_chaine("Dupont");
    contact[0].date_naissance=ret_naissance(30,1,1980);

    ajouter_contact(contact,10);

    recherche_nom(contact,longueur_chaine("DUPONT"),10);
    
    affiche_tout(contact,10);
    save_fiche(contact,10,"fichier.txt");

    supprime_tout(contact,10);

    affiche_tout(contact,10);

    return 0;
}
