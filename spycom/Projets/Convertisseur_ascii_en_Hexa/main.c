#include <stdio.h>
#include <ctype.h>

int main ( int argc, char** argv )
{
    size_t i,k,compteur;
    int j;
    unsigned char buff[1024];
    FILE *fichier=NULL;

    if(argc==2)
    {
        printf("%s:\n",argv[1]);
        fichier=fopen(argv[1],"rb");
        if (fichier != NULL)
        {
            while((compteur=fread(buff,sizeof(char),1024,fichier)))
            {
                i=0;
                k=0;
                while(i<compteur)
                {
                    j=16;
                    while(j!=0 && i<compteur)
                    {
                        printf("%2x ",buff[i]);
                        i++;
                        j--;
                    }
                    j=16;
                    while(j!=0 && k<compteur)
                    {
                        if(isalnum(buff[k]))
                        {
                            printf("%c",buff[k]);
                        }
                        else
                        {
                            printf(".");
                        }
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
