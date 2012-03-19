#include <stdio.h>
#include <time.h>
#include <windows.h>
#include <string.h>
#include "fonctions.h"
#include "Simon.h"
#include "Suite.h"
#include "PlusMoins.h"
#include "Fricfrac.h"
#include "Challenge.h"

void challenge()
{
    int pointsSimon=0, pointsSuite=0, pointsPlusMoins=0, pointsFricfrac=0;
    int i=0,x=0,j=0,z=0, nbJoueur=0, joueurNumero=0;
    int joueur[4]= {0}, score[4][4]= {{0},{0}},scoreClassement[10] = {0},copieScoreClassement[10] = {0};
    char nomJoueur[4][12]= {{""},{""}},nomClassement[10][12]= {{""},{""}},copieNomClassement[10][12]= {{""},{""}};



    printf("##########################################################\n");
    printf("#****************    LE CHALLENGE C-DEB    **************#\n");
    printf("##########################################################\n\n");
    printf("\n\nVous jouerez a toutes les epreuves seul ou en multijoueur.\n");
    printf("A vous d'obtenir le meilleur score.\n");
    while(nbJoueur<1 || nbJoueur>4)//Nombre joueur mode challenge entre 1 et 4
    {
        printf("Choisissez le nombre de joueurs (1 a 4 joueurs):");
        scanf("%d",&nbJoueur);
        printf("\n");
    }
    while(joueurNumero!=nbJoueur)//ENTREZ NOM CHAQUE JOUEUR
    {
        system("cls");
        printf("##########################################################\n");
        printf("#****************    LE CHALLENGE C-DEB    **************#\n");
        printf("##########################################################\n\n");
        printf("Joueur %d votre nom: ",joueurNumero+1);
        scanf("%s",nomJoueur[i]);
        system("PAUSE");
        system("cls");
        joueurNumero++;
        i++;
    }
    joueurNumero=0;
    i=0;
    while(joueurNumero!=nbJoueur)//JOUEURS JOUE A SIMON CHACUN LEUR TOUR
    {
        system("cls");
        printf("##########################################################\n");
        printf("#****************    LE CHALLENGE C-DEB    **************#\n");
        printf("##########################################################\n\n");
        printf("%s a vous de jouez.\n",nomJoueur[i]);
        system("PAUSE");
        system("cls");
        score[i][0]=simon(pointsSimon);//INSERE LES POINTS DANS TABLEAU SCORE
        joueurNumero++;
        i++;
    }
    joueurNumero=0;
    i=0;
    while(joueurNumero!=nbJoueur)//JOUEURS JOUE A LA GRANDE SUITE CHACUN LEUR TOUR
    {
        system("cls");
        printf("##########################################################\n");
        printf("#****************    LE CHALLENGE C-DEB    **************#\n");
        printf("##########################################################\n\n");
        printf("%s a vous de jouez.\n",nomJoueur[i]);
        system("PAUSE");
        system("cls");
        score[i][1]=suite(pointsSuite);//INSERE LES POINTS DANS TABLEAU SCORE
        joueurNumero++;
        i++;
    }
    joueurNumero=0;
    i=0;
    while(joueurNumero!=nbJoueur)//JOUEURS JOUE A PLUS OU MOINS CHACUN LEUR TOUR
    {
        system("cls");
        printf("##########################################################\n");
        printf("#****************    LE CHALLENGE C-DEB    **************#\n");
        printf("##########################################################\n\n");
        printf("%s a vous de jouez.\n",nomJoueur[i]);
        system("PAUSE");
        system("cls");
        score[i][2]=plusMoins(pointsPlusMoins);//INSERE LES POINTS DANS TABLEAU SCORE
        joueurNumero++;
        i++;
    }
    joueurNumero=0;
    i=0;
    while(joueurNumero!=nbJoueur)//JOUEURS JOUE A LA GRANDE SUITE CHACUN LEUR TOUR
    {
        system("cls");
        printf("##########################################################\n");
        printf("#****************    LE CHALLENGE C-DEB    **************#\n");
        printf("##########################################################\n\n");
        printf("%s a vous de jouez.\n",nomJoueur[i]);
        system("PAUSE");
        system("cls");
        score[i][3]=fricfrac(pointsFricfrac);//INSERE LES POINTS DANS TABLEAU SCORE
        joueurNumero++;
        i++;
    }
    for(i=0; i<4; i++)//ON ADDITIONNE LES POINTS DE CHAQUE JEU POUR CHAQUE JOUEUR
    {
        joueur[0]+=score[0][i];
        joueur[1]+=score[1][i];
        joueur[2]+=score[2][i];
        joueur[3]+=score[3][i];
    }
    system("cls");
    for(i=0; i<nbJoueur; i++)//ON AFFICHE LES POINTS DE CHAQUE JOUEUR
    {
        printf("%s votre score est de : %d points.\n",nomJoueur[i] ,joueur[i]);
    }
    system("PAUSE");
    FILE* fichier= NULL;

    fichier = fopen("scores.txt", "r");//ouvre sauvegarde des 10 meilleurs scores.
    if (fichier != NULL)
    {
        for(i=0; i<10; i++)
            fscanf(fichier, "%s %d",nomClassement[i],&scoreClassement[i]);
    }
    fclose(fichier);
    for(x=0; x<10; x++)
    {
        copieScoreClassement[x]=scoreClassement[x];
        strcpy(copieNomClassement[x],nomClassement[x]);
    }
    for(j=0; j<nbJoueur; j++)
    {
        for(i=0; i<10; i++)
        {
            if(scoreClassement[i]<joueur[j])
            {
                z=i;
                for(x=i; x<10; x++)
                {
                    i++;
                    copieScoreClassement[i]=scoreClassement[x];
                    strcpy(copieNomClassement[i],nomClassement[x]);
                }
                copieScoreClassement[z]=joueur[j];
                strcpy(copieNomClassement[z],nomJoueur[j]);
                i=10;
            }
        }
        for(x=0; x<10; x++)
        {
            scoreClassement[x]=copieScoreClassement[x];
            strcpy(nomClassement[x],copieNomClassement[x]);
        }
    }
    for(i=0; i<10; i++)
    fichier = fopen("scores.txt", "w");//ouvre sauvegarde des 10 meilleurs scores.
    if (fichier != NULL)
    {
        for(i=0; i<10; i++)
            fprintf(fichier, "%s %d\n",nomClassement[i],scoreClassement[i]);
    }
    fclose(fichier);
    system("cls");
    classement();
    system("PAUSE");
}
