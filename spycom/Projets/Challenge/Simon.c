#include <stdio.h>
#include <windows.h>

int simon( int points)
{
    int tour=0,i=0,test=0,tourJoueur=0,nombre=0,a=0,b=1000;
    int memoire[10],joueur[10];

    printf("##########################################################\n");
    printf("#****************     LE SIMON DE C-DEB    **************#\n");
    printf("##########################################################\n\n");
    printf("\n\nVous devez memoriser un suite de nombre et la reecrire.\n");
    printf("Chaque nombre est compris entre 0 et 1000\n");
    system("PAUSE");
    while (tour<10 && test==0)
    {
        tour++;
        nombre=rand()%(b-a) +a;
        memoire[i]=nombre;
        system("cls");
        for(i=0; i<tour; i++)
        {
            printf("##########################################################\n");
            printf("#****************     LE SIMON DE C-DEB    **************#\n");
            printf("##########################################################\n\n");
            printf("*********************** Memorisez ************************\n\n");
            printf("\n\n                           %d",memoire[i]);
            Sleep(1500);
            system("cls");
        }
        tourJoueur=0;
        for(i=0; i<tour; i++)
        {
            printf("##########################################################\n");
            printf("#****************     LE SIMON DE C-DEB    **************#\n");
            printf("##########################################################\n\n");
            printf("************************** Ecrivez ***********************\n\n");
            tourJoueur++;
            printf("\n\n      A votre tour nombre numero %d:",tourJoueur);
            scanf("%d",&joueur[i]);
            system("cls");
        }
        for(i=0; i<tour; i++)
        {
            if (memoire[i]==joueur[i])
                test=0;
            else
                test=1;
        }
        system("cls");
    }
    tour-=1;
    printf("##########################################################\n");
    printf("#****************     LE SIMON DE C-DEB    **************#\n");
    printf("##########################################################\n\n");
    if(tour==10)
    {
        points=30;
        printf("\n\nBravo vous etes le champion avec le score maximum de 30 points\n");
    }
    else if(tour==9 )
    {
        points=28;
        printf("\nVous n'avez pas saisie la suite correctement votre score est de: %d points\n",points);
    }
    else if(tour==8 )
    {
        points=24;
        printf("\nVous n'avez pas saisie la suite correctement votre score est de: %d points\n",points);
    }
    else if(tour==7 )
    {
        points=21;
        printf("\nVous n'avez pas saisie la suite correctement votre score est de: %d points\n",points);
    }
    else if(tour==6 )
    {
        points=18;
        printf("\nVous n'avez pas saisie la suite correctement votre score est de: %d points\n",points);
    }
    else if(tour==5 )
    {
        points=15;
        printf("\nVous n'avez pas saisie la suite correctement votre score est de: %d points\n",points);
    }
    else if(tour==4 )
    {
        points=10;
        printf("\nVous n'avez pas saisie la suite correctement votre score est de: %d points\n",points);
    }
    else if(tour==3 )
    {
        points=7;
        printf("\nVous n'avez pas saisie la suite correctement votre score est de: %d points\n",points);
    }
    else if(tour==2 )
    {
        points=5;
        printf("\nVous n'avez pas saisie la suite correctement votre score est de: %d points\n",points);
    }
    else if(tour==1 )
    {
        points=2;
        printf("\nVous n'avez pas saisie la suite correctement votre score est de: %d points\n",points);
    }
    else if(tour==0 )
    {
        points=0;
        printf("\nVous n'avez pas saisie la suite correctement votre score est de: %d points\n",points);
    }
    else
        printf("\nErreur programme, celui-ci va se fermer\n");
    system("PAUSE");

    return points;
}
