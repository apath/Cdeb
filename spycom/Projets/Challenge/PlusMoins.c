#include <stdio.h>
#include <windows.h>

int plusMoins(int points)
{

    int nombreMystere=0,a=0,b=500,nombreJoueur=1,coup=0;
    nombreMystere=rand()%(b-a) +a;

    printf("##########################################################\n");
    printf("#**************   LE PLUS OU MOINS DE C-DEB   ***********#\n");
    printf("##########################################################\n\n");
    printf("\n\nVous devez trouver un nombre mystere en moins de 10 coups.\n");
    printf("Le nombre est compris entre 0 et 500\n");
    points=20;
    system("PAUSE");
    while(nombreMystere!=nombreJoueur && coup<10)
    {
        coup++;
        system("cls");
        printf("##########################################################\n");
        printf("#**************   LE PLUS OU MOINS DE C-DEB   ***********#\n");
        printf("##########################################################\n\n");
        printf("\n\nEntrez votre nombre: ");
        scanf("%d",&nombreJoueur);
        if(nombreJoueur<nombreMystere)
        {
            printf("LE NOMBRE MYSTERE EST PLUS GRAND.\n");
            points-=2;
        }
        else if(nombreJoueur>nombreMystere)
        {
            printf("LE NOMBRE MYSTERE EST PLUS PETIT.\n");
            points-=2;
        }
        else if(nombreJoueur==nombreMystere)
        {
            printf("Le nombre mystere etait: %d.\n",nombreMystere);
            printf("Bravo vous avez trouve le nombre mystere en %d coup.\n",coup);
            printf("Vous avez  %d points.\n",points);
        }
        else if(nombreJoueur!=nombreMystere && coup==10)
        {
            points=0;
            printf("PERDU !!!!!\n");
            system("PAUSE");
            printf("Le nombre mystere etait: %d.\n",nombreMystere);
            printf("Vous n'avez pas trouve le nombre mystere en moins de 10 coup.\n");
            printf("Vous avez  %d points.\n",points);
        }
        system("PAUSE");
    }
    return points;
}
