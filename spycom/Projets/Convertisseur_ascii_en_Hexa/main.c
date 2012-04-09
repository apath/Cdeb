#include <stdio.h>

int main ( int argc, char** argv )
{
    size_t i,j,compteur;
    char tampon[1000];
    char retour='\n';
    unsigned char buff[256];
    FILE *fichier=NULL,*fichierlog=NULL; /* attention lorsque tu déclares tes variables
                                            ne les met pas n'importe où, ça doit se trouver
                                            avant les instructions et permet en plus de rapidement
                                            savoir quel sont les variables&types en jeu sans
                                            les chercher partout dans le code */

    if(argc==2)
    {
        printf("%s:\n",argv[1]);
        fichier=fopen(argv[1],"rb");
        if (fichier != NULL)
        {
           /* ici tu peux ouvrir ton nouveau fichier en ecriture, l'ouverture du fichier à lire s'etant
            * bien déroulée */
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
                    /* ,ici aussi tu peux utiliser ton fwrite pour ton fichier ouvert en écriture
                     * attention n'utilise pas append (ab) même si j'ai appelé ça un "log" son vrai
                     * nom c'est un "dump" (un dechargement en gros) et append ne permet pas de
                     * remplacer un fichier qui existe déjà il va continuer d'écrire à la suite
                     * imaginons que tu veuilles faire un dump en hexa de deux fichiers differents
                     * au même endrois, dans le log.txt les deux résultats vont se retrouver collés
                     * à la suite et c'est pas terrible dans nôtre cas, utilise wb simplement */
                    /* dans le commentaire suivant j'explique en mieux ce que j'avais dit sur le tchat et
                     * que tu as pu mal comprendre pour l'écriture de la sortie dans un fichier */
                }
            }
        }
        fclose(fichier);
        /* en fait tu n'es pas forcé de créer un fichier toi-même (de le programmer)
         * lorsqu'on utilise le caractère de redirection de flux en console ( le caractère > ou < )
         * et qu'on précise un nom de fichier le système créer le fichier et redirige la sortie de
         * tes printf directement dedans.
         * essaie ton programme à partir de la console (cmd.exe) tu te déplace dans le repertoire
         * où se trouve ton executable à l'aide de la commande cd, et tu fais comme ceci :
         * main.exe > log.txt
         * la sortie de main.exe se retrouvera dans log.txt */
        /* Sans quoi si tu veux vraiment créer un fichier de sortie à partir de ton programme
         * tu peux le faire directement durant la lecture et l'affichage, dans la même fonction et fermer
         * les deux fichier en même temps */
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
