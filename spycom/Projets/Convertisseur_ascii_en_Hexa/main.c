#include <stdio.h>

int main ( int argc, char** argv )
{
    size_t i,j,compteur;
    char tampon[1000];
    char retour='\n';
    unsigned char buff[256];
    FILE *fichier=NULL,*fichierlog=NULL; /* attention lorsque tu d�clares tes variables
                                            ne les met pas n'importe o�, �a doit se trouver
                                            avant les instructions et permet en plus de rapidement
                                            savoir quel sont les variables&types en jeu sans
                                            les chercher partout dans le code */

    if(argc==2)
    {
        printf("%s:\n",argv[1]);
        fichier=fopen(argv[1],"rb");
        if (fichier != NULL)
        {
           /* ici tu peux ouvrir ton nouveau fichier en ecriture, l'ouverture du fichier � lire s'etant
            * bien d�roul�e */
            while((compteur=fread(buff,sizeof(char),256,fichier)))
            {
                printf("Lecture du fichier ascii:\n");
                for(i=0; i<compteur; i++)
                {
                    printf("%c",buff[i]);
                    /* ensuite ici et */
                }
                printf("\nConversion en Hexadecimal:\n");
                for(i=0; i<compteur; i++)
                {
                    printf("%2x ",buff[i]);
                    /* ,ici aussi tu peux utiliser ton fwrite pour ton fichier ouvert en �criture
                     * attention n'utilise pas append (ab) m�me si j'ai appel� �a un "log" son vrai
                     * nom c'est un "dump" (un dechargement en gros) et append ne permet pas de
                     * remplacer un fichier qui existe d�j� il va continuer d'�crire � la suite
                     * imaginons que tu veuilles faire un dump en hexa de deux fichiers differents
                     * au m�me endrois, dans le log.txt les deux r�sultats vont se retrouver coll�s
                     * � la suite et c'est pas terrible dans n�tre cas, utilise wb simplement */
                    /* dans le commentaire suivant j'explique en mieux ce que j'avais dit sur le tchat et
                     * que tu as pu mal comprendre pour l'�criture de la sortie dans un fichier */
                }
            }
        }
        fclose(fichier);
        /* en fait tu n'es pas forc� de cr�er un fichier toi-m�me (de le programmer)
         * lorsqu'on utilise le caract�re de redirection de flux en console ( le caract�re > ou < )
         * et qu'on pr�cise un nom de fichier le syst�me cr�er le fichier et redirige la sortie de
         * tes printf directement dedans.
         * essaie ton programme � partir de la console (cmd.exe) tu te d�place dans le repertoire
         * o� se trouve ton executable � l'aide de la commande cd, et tu fais comme ceci :
         * main.exe > log.txt
         * la sortie de main.exe se retrouvera dans log.txt */
        /* Sans quoi si tu veux vraiment cr�er un fichier de sortie � partir de ton programme
         * tu peux le faire directement durant la lecture et l'affichage, dans la m�me fonction et fermer
         * les deux fichier en m�me temps */
        /***fichier log***/
        fichierlog=fopen("log.txt","ab");
        if (fichierlog != NULL)
        {
            fwrite(&buff,sizeof(char),strlen(buff),fichierlog); /* pas besoin du & car buff
                                                                   est un tableau */
            fwrite(&retour,sizeof(char),1,fichierlog);/* ici c'est correct */
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
