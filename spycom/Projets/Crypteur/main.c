#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main( int argc, char** argv )
{
    int caractere_lu=0,i=0,compteur=0;
    char *key, * lettre, *nom_fichier;
    char ajout_crypt[7]=".crypt",nom_fichier_modif[256];

    FILE *fichier_decrypte=NULL;
    FILE *fichier_crypte=NULL;

    if(argc==4)
    {
        lettre = argv[1];
        nom_fichier = argv [2];
        key = argv[3];

        if (key!='\0')
        {
            /****************************************cryptage***********************************/
            if(*lettre=='c')
            {
                /**permet de renommer le ficher a crypter avec extension .crypt**/
                strcpy(nom_fichier_modif,nom_fichier);
                strcat(nom_fichier_modif,ajout_crypt);
                /*****************************************************/
                fichier_decrypte=fopen(argv[2],"rb");
                if (fichier_decrypte != NULL)
                {
                    fichier_crypte=fopen(nom_fichier_modif,"wb");
                    if (fichier_crypte != NULL)
                    {
                        while((caractere_lu=getc(fichier_decrypte))!= EOF)
                        {
                            if(!*key)key=argv[3];
                            caractere_lu ^= *(key++);
                            putc(caractere_lu,fichier_crypte);
                        }
                        fclose(fichier_crypte);
                    }
                    fclose(fichier_decrypte);
                }
            }
            /****************************************decryptage*********************************/
            else if(*lettre=='d')
            {
                /**permet de renommer le ficher crypter sans l'extension .crypt**/
                compteur=strlen(nom_fichier);
                strcpy(nom_fichier_modif,nom_fichier);
                for (i= compteur; i>0; i--)
                {
                    if (nom_fichier_modif[i] == '.')
                    {
                        while(i!=compteur)
                        {
                            nom_fichier_modif[i] = '\0';
                            i++;
                        }
                        i=0;
                    }
                }
                /*****************************************************/
                fichier_crypte=fopen(argv[2],"rb");
                if (fichier_crypte != NULL)
                {
                    fichier_decrypte=fopen(nom_fichier_modif,"wb");
                    if (fichier_decrypte != NULL)
                    {
                        while((caractere_lu=getc(fichier_crypte))!= EOF)
                        {
                            if(!*key)key=argv[3];
                            caractere_lu ^= *(key++);
                            putc(caractere_lu,fichier_decrypte);
                        }
                        fclose(fichier_decrypte);
                    }
                    fclose(fichier_crypte);
                }
            }
            else
            {
                printf("Le parametre n'est pas correct.\nLes caracteres 'c' pour crypter et 'd' pour decrypter.\n");
            }
        }
    }
    else
    {
        printf("Le nombre d'argument n'est pas correct.\n");
    }
    return 0;
}

