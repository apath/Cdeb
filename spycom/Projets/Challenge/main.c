/*
*Erreur 001: doublons.
*Erreur 002: Probléme sur les familles.
*Erreur 003: Conversion Modulo.
*Erreur 004: Points.
*/
#include <stdio.h>
#include <time.h>
#include <windows.h>
#include "fonctions.h"
#include "Simon.h"
#include "Suite.h"
#include "PlusMoins.h"
#include "Challenge.h"
#include "Fricfrac.h"


int main ( int argc, char** argv )
{
    int choixJeu=0,exit=1;
    int points=0;

    srand(time(NULL));
    while(exit==1)
    {
        system("cls");
        printf("##########################################################\n");
        printf("#************ LE JEU DU JUSTE PRIX DE C-DEB *************#\n");
        printf("##########################################################\n\n");
        printf("CHOIX DU JEU:\n\n");
        printf("                  1:: SIMON\n");
        printf("                  2:: LA GRANDE SUITE\n");
        printf("                  3:: PLUS OU MOINS\n");
        printf("                  4:: FRICFRAC\n");
        printf("                  5:: MODE CHALLENGE\n");
        printf("                  6:: CLASSEMENT CHALLENGE\n");
        printf("                  7:: CREDITS\n");
        printf("                  8:: EXIT\n\n");
        printf("Choix:");
        scanf("%d",&choixJeu);
        switch(choixJeu)
        {
        case 1:
            system("cls");
            simon(points);
            break;
        case 2:
            system("cls");
            suite(points);
            break;
        case 3:
            system("cls");
            plusMoins(points);
            break;
        case 4:
            system("cls");
            fricfrac(points);
            break;
        case 5:
            system("cls");
            challenge(points);
            break;
        case 6:
            system("cls");
            classement();
            system("PAUSE");
            break;
        case 7:
            system("cls");
            printf("##########################################################\n");
            printf("#************  INFORMATION JEU JUSTE PRIX   *************#\n");
            printf("##########################################################\n\n");
            printf("LE JEU JUSTE PRIX DE C-DEB A ETE CREE PAR SPYCOM.\n");
            printf("POUR TOUTE AIDE: SPYCOM@ORANGE.FR\n");
            printf("BON JEU !!!!! ;) \n");
            system("PAUSE");
            break;
        case 8:
            exit=0;
            break;
        default:
            system("cls");
            printf("Merci de saisir un nombre entre 1 et 8.\n");

            break;
        }

    }
    return 0;
}
