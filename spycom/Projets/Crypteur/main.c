#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main( int argc, char** argv )
{
    int caractere_lu=0,i=0,compteur=0,compteur_point=0;
    char *key, * lettre, *nom_fichier;
    char ajout_crypt[11]=".crypt.txt",ajout_supcrypt[5]=".txt",nom_fichier_modif[256];

    /* c'est une erreur de cr�er une extension "� la main" car si on venait �
     * crypter un fichier .jpg (ton algorithme le permet) ou autre, il se retrouvera avec l'extension
     * .txt etc,
     * c'est pourquoi je t'avais conseill� de faire txt.crypt en exemple, d'ajouter le .crypt
     * � la fin du nom du fichier simplement, et de le retirer lors du decrypt, �a t'aurai
     * �pargn� les boucles etc, rendant du m�me fait ton programme "utilisable pour tout"
     * suffisait d'un strcat pour l'ajout de .crypt et d'ajouter un \0
     * plac� � la place du . de .crypt pour supprimer le .crypt lors du decryptage.
     * reduisant le code actuel pour le faire � seulement quelques lignes */

    /* comme tu as pu le remarqu�, le cryptage et decryptage avec le xor utilise la m�me
     * m�thode, il n'y a que l'extension du fichier qui change tu peux alors cr�er une fonction
     * qui prend en parametre le nom du fichier � lire, le nom du fichier � cr�er, et le mot de passe utilis� */
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
                /**permet de renommer le ficher a crypter avec extension .crypt.txt**/
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
                /**permet de renommer le ficher crypter avec extension .txt**/
                compteur=strlen(nom_fichier);
                strcpy(nom_fichier_modif,nom_fichier);
                for (i= compteur; i>0; i--)
                {
                    if (nom_fichier_modif[i] == '.')
                    {
                        compteur_point++;
                        if(compteur_point==2)
                        {
                            while(i!=compteur)
                            {
                                nom_fichier_modif[i] = '\0';
                                i++;
                            }
                            i=0;
                        }
                    }
                }
                strcat(nom_fichier_modif,ajout_supcrypt);
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

