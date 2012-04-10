#include <stdio.h>

int main ( int argc, char** argv )
{
    size_t i=0,k=0,compteur;
    int j;
    unsigned char buff[1024];
    FILE *fichier=NULL,*fichierlog=NULL;

    if(argc==2)
    {
        printf("%s:\n",argv[1]);
        fichier=fopen(argv[1],"rb");
        if (fichier != NULL)
        {
            /* ici tu peux ouvrir ton nouveau fichier en ecriture, l'ouverture du fichier à lire s'etant
             * bien déroulée */
            while((compteur=fread(buff,sizeof(char),1024,fichier)))
            {
                while(i<compteur)
                {
                    j=16;
                    while(j!=0){
                        printf("%2x ",buff[i]);
                        i++;
                        j--;
                    }
                    j=16;
                    while(j!=0){
                        printf("%c",buff[k]);
                        k++;
                        j--;
                    }
                    printf("\n");
                }
            }
        }
        fclose(fichier);

    }
    return 0;
}
