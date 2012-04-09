#include <stdio.h>

int main ( int argc, char** argv )
{
    size_t i,j,compteur;
    char tampon[1000];
    char retour='\n';
    unsigned char buff[256];

    if(argc==2)
    {
        printf("%s:\n",argv[1]);
        FILE *fichier=NULL;
        fichier=fopen(argv[1],"rb");
        if (fichier != NULL)
        {
            while((compteur=fread(buff,sizeof(char),256,fichier)))
            {
                printf("Lecture du fichier ascii:\n");
                for(i=0; i<compteur; i++)
                {
                    printf("%c",buff[i]);
                }
                printf("\nConversion en Hexadecimal:\n");
                for(i=0; i<compteur; i++)
                {
                    printf("%2x ",buff[i]);
                }
            }
        }
        fclose(fichier);
        /***fichier log***/
        FILE *fichierlog=NULL;
        fichierlog=fopen("log.txt","ab");
        if (fichierlog != NULL)
        {
            fwrite(&buff,sizeof(char),strlen(buff),fichierlog);
            fwrite(&retour,sizeof(char),1,fichierlog);
            for(i=0; i<compteur; i++)
            {
                sprintf(tampon, "%2x", buff[i]);
                fwrite(&tampon,sizeof(char),strlen(tampon),fichierlog);
            }
        }
        fwrite(&retour,sizeof(char),1,fichierlog);
        fwrite(&retour,sizeof(char),1,fichierlog);
        fclose(fichierlog);
    }
    return 0;
}
