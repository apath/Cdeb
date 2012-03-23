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

    if(!recherche_id(contact,1,10)){
        affiche_id(contact,1);
    }

    affiche_tout(contact,10);

    if(!recherche_id(contact,1,10)){
        supp_contact(contact,1);
    }

    /* ajouter_contact trouve automatiquement un emplacement libre
     * et donne l'id qui convient pour le nouveau contact
     * ici ce sera le second emplacement qui sera libre */
    ajouter_contact(contact,10);

    if(!recherche_id(contact,2,10)){
        affiche_id(contact,2);
    }

    return 0;
}
