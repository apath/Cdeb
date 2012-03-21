#include <stdio.h>
#include <stdlib.h>
#include "fonctions.h"

int main()
{
    int i=0, emplacement_libre=0;
    struct Fiche contact[10];

    //test
    contact[0].nom = longueur_chaine("Dupont");
    printf("%s",contact[0].nom);

    for(i=0;i<10;i++){
        contact[i].id=+1;
        printf("Quel est votre nom ? ");
        scanf("%s", contact[i].nom);
        printf("Votre prenom ? ");
        scanf("%s", contact[i].prenom);
    }
    emplacement_libre = recherche_id(Fiche contact[i],4,10);

    return 0;
}
