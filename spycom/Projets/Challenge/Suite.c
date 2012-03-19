#include <stdio.h>
#include <windows.h>
#include "fonctions.h"

int suite(int points)
{
    int perdu=0,i=0,j=0,a=1,b=53;
    int carteSuivante,carteEnDouble=1,testDouble=0,choix,valeurCarte,valeurCarteTire;
    int doublons[5]= {0};

    printf("##########################################################\n");
    printf("#**************** LA GRANDE SUITE DE C-DEB **************#\n");
    printf("##########################################################\n\n");
    carteSuivante=rand()%(b-a) +a;//tirage d'une carte entre 1 et 52 inclus
    doublons[i]=carteSuivante;//met la carte tirée dans un tableau pour éviter les doublons
    printf("\n\n##########################################################\n");
    valeurCarte=afficheCarte(carteSuivante);
    printf("##########################################################\n");
    while(perdu==0 && i!=6) //tant qu'on ne perd pas on joue
    {
        i++;
        carteEnDouble=1;
        while(carteEnDouble==1)
        {
            testDouble=0;
            carteSuivante=rand()%(b-a) +a;//tirage d'une carte entre 1 et 52 inclus
            for(j=0; j<i; j++)
            {
                if(carteSuivante==doublons[j])
                {
                    //printf("\n\nDesole le programmeur c'est plante.Erreur 0001 ;) SPYCOM.");
                    //getch();

                    testDouble+=1;
                }
            }
            if (testDouble==0)
                carteEnDouble=0;
            else
                carteEnDouble=1;
        }
        doublons[i]=carteSuivante;//met la carte tirée dans le tableau pour éviter les doublons
        valeurCarteTire=valeurCarte;//Attribue la valeur de la carte à la variable carte tiree
        choix=decision();//Affiche le menu decision
        printf("\n##########################################################\n");
        valeurCarte=afficheCarte(carteSuivante); //tirage d'une carte
        printf("##########################################################\n");
        if (valeurCarte>valeurCarteTire && choix== 1)//si choix superieure et carte superieure +5 pts
        {
            points+=5;
        }
        else if(valeurCarte<valeurCarteTire && choix== 2)//si choix inferieure et carte inferieure +5 pts

        {
            points+=5;
        }
        else if(valeurCarte==valeurCarteTire && (choix== 2 || choix==1))//si choix inferieure et carte inferieure +5 pts

        {
            points+=5;
        }
        else//sinon perdu
            perdu=1;

    }
    scores(points);
    system("PAUSE");
    return points;
}

