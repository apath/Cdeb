#include <stdio.h>
#include <stdlib.h>
#include "stucture.h" // Inclusion du .h qui contient les prototypes et structures

int main()
{
    Fiche contact;
    contact.identifiant=1;
    printf("Quel est votre nom ? ");
    scanf("%s", contact.nom);
    printf("Votre prenom ? ");
    scanf("%s", contact.prenom);

    printf("Identifiant: %d\nNom: %s\nPrenom: n%s", contact.identifiant, contact.nom, contact.prenom);
    return 0;
}
