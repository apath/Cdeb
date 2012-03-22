#include <stdio.h>
#include <stdlib.h>

int main()
{
    int choix = 0;
    printf("1.Consulter contact\n"
           "2.Traiter contact\n"
           "3.Quitter\n");
    scanf("%d", &choix);

    if(choix == 1)
    {
        // envoyer vers la fiche de contact
    }

    else if(choix == 2)
    {
        // envoyer vers le menu de traitement
    }

    else if(choix == 3)
    {
        // quitter
    }

    else
    {
        // quitter
    }
    return 0;
}
