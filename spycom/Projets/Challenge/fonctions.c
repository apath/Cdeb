#include <stdio.h>

/**********convertie valeur carteSuivante en nombrede 0 a 12*******************/
int conversions(int carteSuivante)
{
    int carteModulo;
    carteModulo=carteSuivante % 13;
    //printf("\n\nDesole le programmeur c'est plante. Erreur 003;) SPYCOM.");
    return carteModulo;
}
/******Transforme la valeur convertie 0/1/11/12 en as roi dame valet***********/
int transforme(int valeurCarte)
{

    if(valeurCarte==11)
    {
        printf("CARTE ACTUELLE:    VALET");
    }
    else if(valeurCarte==12)
    {
        printf("CARTE ACTUELLE:    DAME");
    }
    else if (valeurCarte==0)
    {
        printf("CARTE ACTUELLE:    ROI");
        valeurCarte=13;
    }
    else if (valeurCarte==1)
    {
        printf("CARTE ACTUELLE:    AS");
        valeurCarte=14;
    }
    else
    {
        printf("CARTE ACTUELLE:    %d",valeurCarte);
    }
    return valeurCarte;
}
/*********************Menu decision joueur*************************************/
int decision()
{
    int choix=0;

    while(choix<1 || choix>2)
    {
        printf("CHOISISSEZ SI LA CARTE SUIVANTE SERA:\n\n");
        printf("            1-SUPERIEURE\n");
        printf("            2-INFERIEURE\n");
        printf("Choix:");
        scanf("%d",&choix);
    }
    return choix;
}
/****************fonctions affichant valeur carte avec la famille**************/
int afficheCarte(int carteSuivante)
{
    int carteModulo;
    int valeurCarte;


    if (carteSuivante>0 && carteSuivante<14)
    {
        char famille[]="de PIQUE\n";
        carteModulo=conversions(carteSuivante);
        valeurCarte=transforme(carteModulo);
        printf(" %s",famille);
    }
    else if(carteSuivante>13 && carteSuivante<27)
    {
        char famille[]="de COEUR\n";
        carteModulo=conversions(carteSuivante);
        valeurCarte=transforme(carteModulo);
        printf(" %s",famille);
    }
    else if(carteSuivante>26 && carteSuivante<40)
    {
        char famille[]="de CARREAU\n";
        carteModulo=conversions(carteSuivante);
        valeurCarte=transforme(carteModulo);
        printf(" %s",famille);
    }
    else if(carteSuivante>39 && carteSuivante<53)
    {
        char famille[]="de TREFLE\n";
        carteModulo=conversions(carteSuivante);
        valeurCarte=transforme(carteModulo);
        printf(" %s",famille);
    }
    else
    {
        printf("\n\nDesole le programmeur c'est plante. Erreur 002;) SPYCOM.");
    }

    return valeurCarte;
}
/*************************************************************************/
void scores(int points)
{
    if(points==0)
        printf("\n\nVotre score est de %d point. Vraiment zero.\n",points);
    else if(points==5)
        printf("\n\nVotre score est de %d points. Va falloir reflechir.\n",points);
    else if(points==10)
        printf("\n\nVotre score est de %d points. Bof,bof, pas tres performant.\n",points);
    else if(points==15)
        printf("\n\nVotre score est de %d points. Moyen tout cela. Allez !\n",points);
    else if(points==20)
        printf("\n\nVotre score est de %d points. Pas mal, mais doit s'ameliorer.\n",points);
    else if(points==25)
        printf("\n\nVotre score est de %d points. Tres bien, on sent le winner.\n",points);
    else if(points==30)
        printf("\n\nVotre score est de %d points. Top score, alors la chapeau !!!!\n",points);
    else
        printf("\n\nDesole le programmeur c'est plante. Erreur 004;) SPYCOM.\n");

}
/**************************CLASSEMENT********************************************/
void classement(){
    int i=0;
    int  scoreClassement[10] = {0};
    char nom[10][12]= {{""},{""}};
    FILE* fichier= NULL;

    fichier = fopen("scores.txt", "r");//ouvre sauvegarde des 5 meilleurs scores.
    if (fichier != NULL)
    {
        for(i=0; i<10; i++)
            fscanf(fichier, "%s %d",nom[i],&scoreClassement[i]);
    }
    fclose(fichier);
    printf("##########################################################\n");
    printf("#****************   LE TOP 10 DES SCORES   **************#\n");
    printf("##########################################################\n\n");
    for(i=0; i<10; i++)
        printf("%d:: %s %d points\n",i+1,nom[i],scoreClassement[i]);
}
