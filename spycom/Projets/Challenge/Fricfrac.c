#include <stdio.h>
#include <windows.h>

int fricfrac ( int points)
{
    int a=1000,b=9999,i=0,gagner=0,essai=0,fin=0;
    int nombre,nombreM=0,nombreC=0,nombreD=0,nombreU=0;
    int codeEntre[4]= {};
    int codeSecret[4]= {};

    nombre=rand()%(b-a) +a;
    nombreM=nombre/1000;
    nombreC=(nombre-(nombreM*1000))/100;
    nombreD=(nombre-(nombreM*1000)-(nombreC*100))/10;
    nombreU=(nombre-(nombreM*1000)-(nombreC*100)-(nombreD*10));
    codeSecret[0]=nombreM;
    codeSecret[1]=nombreC;
    codeSecret[2]=nombreD;
    codeSecret[3]=nombreU;
    printf("##########################################################\n");
    printf("#******************    FRICFRAC C-DEB    ****************#\n");
    printf("##########################################################\n\n");
    printf("\n\nVous devez trouver une combinaison a 4 chiffres.\n");
    printf("Celle-ci se situe entre 1 0 0 0 et 9 9 9 9.\n");
    printf("Surtout n'oubliez pas les espaces entre les chiffres.\n");
    printf("Bonne chance.\n");
    system("PAUSE");
    system("cls");
    printf("##########################################################\n");
    printf("#******************    FRICFRAC C-DEB    ****************#\n");
    printf("##########################################################\n\n");
    printf("Voici la combinaison: * * * *");
    while(fin==0)
    {
        gagner=0;
        fflush(stdin);//commande servant à vider buffer
        printf("\nVeuillez entrer votre combinaison: ");
        scanf("%d %d %d %d",&codeEntre[0],&codeEntre[1],&codeEntre[2],&codeEntre[3]);
        essai++;
        system("cls");
        printf("##########################################################\n");
        printf("#******************    FRICFRAC C-DEB    ****************#\n");
        printf("##########################################################\n\n");
        printf("Voici la combinaison:");
        for(i=0; i<4; i++)
        {

            if(codeSecret[i]==codeEntre[i])
            {
                printf(" %d",codeEntre[i]);
                gagner++;
            }
            else
                printf(" *");
        }
        if(gagner==4 && essai<=8)
        {
            points=20;
            printf("\nVous avez trouve la combinaison: %d\n",nombre);
            printf("Bravo vous avez gagne %d points.\n",points);
            fin=1;
        }
        else if(essai==8 && gagner!=4)
        {
            if(gagner==0)
                points=0;
            else if(gagner==1)
                points=5;
            else if(gagner==2)
                points=10;
            else if(gagner==3)
                points=15;
            printf("\nLa combinaison etait: %d\n",nombre);
            printf("Vous avez perdu. Vous gagnez %d points.\n",points);
            fin=1;
        }
    }
    system("PAUSE");
    return points;
}
