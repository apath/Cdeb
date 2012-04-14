#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main( int argc, char** argv )
{
    size_t i,compteur;
    char lettre;
    unsigned char buff[1024];
    FILE *fichier=NULL;

    printf ("Nombre d'argument : %d\n", argc);
    if(argc==4)
    {
        lettre = *(argv[1]);
        if(lettre=='c'){
            printf("CRYPTEUR:\n");
            fichier=fopen(argv[2],"rb");
            if (fichier != NULL){
                while((compteur=fread(buff,sizeof(char),1024,fichier)))
                {
                    for(i=0;i<compteur;i++)
                        printf("%i",buff[i]);
                }
            printf("COUCOU %s",argv[3]);
            }
        }
        else if(lettre=='d'){
            printf("Decrypteur");
            printf("Pas coucou %s",argv[3]);
        }
        else{
            printf("Le parametre n'est pas correct. 'c' pour crypter et 'd' pour decrypter");
        }
    }
    return 0;
}

