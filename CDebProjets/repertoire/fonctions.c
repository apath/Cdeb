#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "fonctions.h"

/*sert a vider le buffer pour enlever les entr�es rest�es en memoires*/
void viderBuffer()
{
    int c = 0;
    while (c != '\n' && c != EOF)
    {
        c = getchar();
    }
}
/*recherche par nom*/
int recherche_nom(struct Fiche *contact,const char *nom_rechercher,int capacite)
{
    char *buff_nom;
    int i,l;
    l=strlen(nom_rechercher);
    buff_nom=malloc(sizeof(char)*l+1); /* l'erreur de heap etait ici
                                          j'avais oubli� le +1 pour le
                                          caract�re \0 */
    if(!buff_nom) exit(1);
    strcpy(buff_nom,nom_rechercher);
    for(i=0; i<l; i++)
    {
        if(i==0)
        {
            buff_nom[i]=toupper(buff_nom[i]);
        }
        else
        {
            buff_nom[i]=tolower(buff_nom[i]);
        }
    }
    for(i=0; i<capacite; i++)
    {
        if(contact[i].id!=0)
        {
            if(!strcmp(contact[i].nom,buff_nom))
            {
                affiche_id(contact,i+1);
                return 0; /* le nom est trouv� */
            }
        }
    }
    free(buff_nom);
    return 1; /* le nom n'est pas trouv� */
}


/*supprime toutes les fiches existantes par recherche d'ID*/
void supprime_tout(struct Fiche *contact,int capacite)
{
    int i;
    for(i=0; i<capacite; i++)
    {
        if(contact[i].id!=0) supp_contact(contact,i+1);
    }
}

/*Ajout de la fonction supp_contact.
 *int i correspond a l'id de la fiche contact � supprimer. */
void supp_contact(struct Fiche *contact,int i)
{
    i--;
    contact[i].id=0;
    free(contact[i].nom),contact[i].nom=NULL;
    free(contact[i].prenom),contact[i].prenom=NULL;
    free(contact[i].sexe),contact[i].sexe=NULL;
    free(contact[i].email),contact[i].email=NULL;
    free(contact[i].numfix),contact[i].numfix=NULL;
    free(contact[i].nummobil),contact[i].nummobil=NULL;
    free(contact[i].adresse),contact[i].adresse=NULL;
}

/* get_str remplace le scanf, on lui passe un buffer en param�tre et la taille max
 * de celui-ci (max-1 pour le 0 de fin de cha�ne) et la fonction utilise getchar()
 * pour remplir le buffer puis termine la ch�ine par z�ro et la retourne */
char *get_str(char *s,int max)
{
    int i;
    char c;
    for(i=0; (c=getchar())!='\n'&&i<max-1; i++) s[i]=c;
    s[i]='\0';
    return s;
}

void ajouter_contact(struct Fiche *contact, int capacite)
{
    char buff[256];
    int i,j;

    for(i=0; i<capacite; i++)
        if(contact[i].id==0)
        {
            contact[i].id=i+1;
            break;
        }
    viderBuffer();
    printf("Nom: ");
    contact[i].nom=longueur_chaine(get_str(buff,256));

    for(j=0; contact[i].nom[j]; j++)
    {
        if(j==0)
        {
            contact[i].nom[j]=toupper(contact[i].nom[j]);
        }
        else
        {
            contact[i].nom[j]=tolower(contact[i].nom[j]);
        }
    }
    printf("Prenom: ");
    contact[i].prenom=longueur_chaine(get_str(buff,256));
    printf("Sexe: ");
    contact[i].sexe=longueur_chaine(get_str(buff,256));
    printf("Date de naissance JJ/MM/AAAA : ");
    contact[i].date_naissance=s_naissance(get_str(buff,256));
    printf("Email: ");
    contact[i].email=longueur_chaine(get_str(buff,256));
    printf("Telephone fixe: ");
    contact[i].numfix=longueur_chaine(get_str(buff,256));
    printf("Telephone mobile: ");
    contact[i].nummobil=longueur_chaine(get_str(buff,256));
    printf("Adresse: ");
    contact[i].adresse=longueur_chaine(get_str(buff,256));
}

void initialise_fiche(struct Fiche *contact,int capacite)
{
    int i;

    for(i=0; i<capacite; i++)
    {
        contact[i].id=0;
        contact[i].nom=NULL;
        contact[i].prenom=NULL;
        contact[i].sexe=NULL;
        contact[i].email=NULL;
        contact[i].numfix=NULL;
        contact[i].nummobil=NULL;
        contact[i].adresse=NULL;
    }
}

/*affiche toute les fiches existantes par recherche d'ID*/
void affiche_tout(struct Fiche *contact,int capacite)
{
    int i;
    for(i=0; i<capacite; i++)
    {
        if(contact[i].id!=0) affiche_id(contact,i+1);
    }
}

/*affiche une fiche demande par son id*/
void affiche_id(struct Fiche *contact,int i)
{
    i--;
    printf("------------------------------------------------------------------------\n");
    printf("Identifiant: %d\n", contact[i].id);
    printf("Nom: %s\n", contact[i].nom);
    printf("Prenom: %s\n", contact[i].prenom);
    printf("Sexe: %s\n", contact[i].sexe);
    printf("Date de naissance: ");
    affiche_naissance(contact[i].date_naissance);
    printf("Email: %s\n", contact[i].email);
    printf("Telephone fixe: %s\n", contact[i].numfix);
    printf("Telephone mobile: %s\n", contact[i].nummobil);
    printf("Adresse: %s\n", contact[i].adresse);
    printf("------------------------------------------------------------------------\n");
}



void modifier_contact(struct Fiche *contact,int i)
{
    int choix,j;
    char buff[256];
    i--;
    printf("Que souhaitez vous modifier: \n");
    printf("1-Nom\n");
    printf("2-Prenom\n");
    printf("3-Sexe\n");
    printf("4-Date de naissance\n");
    printf("5-Email\n");
    printf("6-Telephone fixe\n");
    printf("7-Telephone mobile\n");
    printf("8-Adresse\n");
    printf("9-Annuler\n");
    printf("Votre choix: ");
    scanf("%d",&choix);
    viderBuffer();
    switch(choix)
    {
    case 1:
        printf("Nom: ");
        contact[i].nom=longueur_chaine(get_str(buff,256));
        for(j=0; contact[i].nom[j]; j++)
        {
            if(j==0)
            {
                contact[i].nom[j]=toupper(contact[i].nom[j]);
            }
            else
            {
                contact[i].nom[j]=tolower(contact[i].nom[j]);
            }
        }

        break;
    case 2:
        printf("Prenom: ");
        contact[i].prenom=longueur_chaine(get_str(buff,256));
        break;
    case 3:
        printf("Sexe: ");
        contact[i].sexe=longueur_chaine(get_str(buff,256));
        break;
    case 4:
        printf("Date de naissance JJ/MM/AAAA : ");
        contact[i].date_naissance=s_naissance(get_str(buff,256));
        break;
    case 5:
        printf("Email: ");
        contact[i].email=longueur_chaine(get_str(buff,256));
        break;
    case 6:
        printf("Telephone fixe: ");
        contact[i].numfix=longueur_chaine(get_str(buff,256));
        break;
    case 7:
        printf("Telephone mobile: ");
        contact[i].nummobil=longueur_chaine(get_str(buff,256));
        break;
    case 8:
        printf("Adresse: ");
        contact[i].adresse=longueur_chaine(get_str(buff,256));
        break;
    case 9:
        printf("Vous avez choisi de ne rien modifier\n");
        break;
    default :
        printf("Ce choix n'existe pas\n");
        break;
    }
}


int recherche_id(struct Fiche *contact,int id_rechercher,int capacite)
{
    int i;
    for(i=0; i<capacite; i++)
    {
        if(contact[i].id==(id_rechercher-1)) return 0; /* l'id est trouv� */
    }
    return 1; /* l'id n'est pas trouv� */
}

char *longueur_chaine(char *chaine)  /* la fonction retourne un pointeur */
{
    char *pointeur= NULL,vide[5]="vide";
    int n;
    n=strlen(chaine);
    if(n!=0)
    {
        pointeur = malloc(sizeof(char)*(n+1));
        if(pointeur) strcpy(pointeur,chaine);
    }
    else
    {
        pointeur = malloc(sizeof(char)*5);
        if(pointeur) strcpy(pointeur,vide);
    }
    if (pointeur == NULL)     /* On v�rifie si l'allocation a march� ou pas */
    {
        exit(1); /* On arr�te tout */
    }
    return pointeur;
}

/* ret_naissance retourne une date dans un time_t
 * on affiche le time_t avec la fonction ctime() */
time_t ret_naissance(int j,int m,int a)
{ /* http://www.cplusplus.com/reference/clibrary/ctime/ */
    time_t date_naissance; /* time_t c'est un type standard (time.h)
							  �quivalent � un entier non sign� (unsigned int) qui
							  ne repr�sente que les secondes �coul�e depuis l'ann�e 70
							  heure "unix" je crois, n'ai pas cherch� plus loin */
    struct tm *dn; /* la structure tm fait partie de time.h ici on cr�er un pointeur
					  de type "struct tm" cette structure contient des membres pour
					  repr�senter une date : jour, mois, annee, heure, minute, seconde... 
					  http://www.cplusplus.com/reference/clibrary/ctime/tm/ */
    date_naissance = time(NULL); /* time() donne la date actuel sous forme d'un time_t 
                                    ici �a permet pour la suite de completer la structure
									avec des donn�es coh�rantes avant de la modifier */
    dn = localtime(&date_naissance); /* localtime() remplie la structure tm � l'aide du time_t */
    dn->tm_year = a-1900; /* modification des membres de la structure qui nous interesse : ann�e, */
    dn->tm_mon = m-1; /* mois */
    dn->tm_mday = j; /* jour */
	/* le -1900 et -1 mis en rapport � un exemple trouv� sur le net
	n'ayant pas cherch� � savoir pourquoi car trop bancal pour �tre interessant je ne peux commenter d'avantage */
    date_naissance = mktime(dn); /* mktime() fait l'inverse de localtime en retournant les donn�es
	                                sous la forme d'un time_t */
    return date_naissance; /* retourne le time_t */
}

/* affichage de la date de naissance en time_t sous la forme j/m/a */
void affiche_naissance(time_t date)
{
    struct tm *dn;
    dn = localtime(&date); /* r�cup�ration du time_t dans les membres d'une structure tm
	                          pour y lire l'annee,mois et jour */
    printf("%d/%d/%d\n",dn->tm_mday,dn->tm_mon+1,dn->tm_year+1900);
}
/* copie et retourne le time_t dans un tableau de char sous la forme JJ/MM/AA */
char *cp_naissance(char *s,time_t date)
{
    struct tm *dn;
    dn = localtime(&date);
	/* utilisation de sprintf pour le format JJ/MM/AAAA */
    sprintf(s,"%d/%d/%d\0",dn->tm_mday,dn->tm_mon+1,dn->tm_year+1900);
    return s;
}
/* s_naissance
 * retourne un time_t en utilisant une date dans une cha�ne sous la forme
 * JJ/MM/AA (jour/mois/ann�e) */
time_t s_naissance(char *tab) /* tab n'est pas un const char car il se doit d'�tre modifiable */
{ /* simple parsing du format "JJ/MM/AAAA"
     a=JJ, b=MM, c=AAAA */
    int i,cpt=1,a,b,c;
    char *p[3]; /* tableau de 3 pointeurs */
    p[0]=tab; /* premier pointeur pointe sur le debut de "JJ/MM/AAAA" */
    for(i=0; tab[i]; i++) /* traverse "JJ/MM/AAAA" */
    {
        if(tab[i]=='/')
        {
            p[cpt]=&tab[i+1]; /* le second et troisieme pointeront sur le debut MM et AAAA */
            tab[i]='\0'; /* les slash "/" sont remplac�s par un \0 pour cr�er trois cha�nes
			                ind�pendante � partir des pointeurs */
            cpt+=1;
        }
    }
	/* atoi() est une fonction standard pour la convertion d'une cha�ne en entier */
    a=atoi(p[0]),b=atoi(p[1]),c=atoi(p[2]);
    return ret_naissance(a,b,c); /* utilisation de ret_naissance qui se charge de
	                                retourner un time_t � l'aide des trois int */
}

/*Ajout dans un fichier texte*/
int save_fiche(struct Fiche *contact,int capacite,const char *fichier)
{
    int i;
    char retour='\n',virgule=',';
    char date[30]="00/00/00";

    FILE *FICHIER=NULL;
    FICHIER=fopen(fichier,"wb");
    if (FICHIER != NULL)
    {
        for(i=0; i<capacite; i++)
        {
            if(contact[i].id!=0)
            {
                fwrite(contact[i].nom,sizeof(char),strlen(contact[i].nom),FICHIER);
                fwrite(&virgule,sizeof(char),1,FICHIER);
                fwrite(contact[i].prenom,sizeof(char),strlen(contact[i].prenom),FICHIER);
                fwrite(&virgule,sizeof(char),1,FICHIER);
                fwrite(contact[i].sexe,sizeof(char),strlen(contact[i].sexe),FICHIER);
                fwrite(&virgule,sizeof(char),1,FICHIER);
                cp_naissance(date,contact[i].date_naissance);
                fwrite(date,sizeof(char),strlen(date),FICHIER);
                fwrite(&virgule,sizeof(char),1,FICHIER);
                fwrite(contact[i].email,sizeof(char),strlen(contact[i].email),FICHIER);
                fwrite(&virgule,sizeof(char),1,FICHIER);
                fwrite(contact[i].numfix,sizeof(char),strlen(contact[i].numfix),FICHIER);
                fwrite(&virgule,sizeof(char),1,FICHIER);
                fwrite(contact[i].nummobil,sizeof(char),strlen(contact[i].nummobil),FICHIER);
                fwrite(&virgule,sizeof(char),1,FICHIER);
                fwrite(contact[i].adresse,sizeof(char),strlen(contact[i].adresse),FICHIER);
                fwrite(&virgule,sizeof(char),1,FICHIER);
                fwrite(&retour,sizeof(char),1,FICHIER);
            }
        }
        fclose(FICHIER);
        return 0;
    }
    return 1;
}

/* Lecture du fichier .txt*/
int load_fiche(struct Fiche *contact,int capacite,char *nom_fichier)
{
    size_t i,count; /* i et count sont des compteurs en size_t car fread nous retourne
                       le nombre d'elements lu ici des char : le nombre de bytes lu */
    char tampon[500];
    char buff[256]; /* pareil qu'avec fwrite, on utilisera un buffer ici
                       pour charger le fichier par morceaux avec fread */
    int ct_donnee,ct_contact,ct_byte; /* compteur de donn�e,de contacts,de bytes */

    FILE *FICHIER=NULL;
    ct_donnee=ct_contact=ct_byte=0; /* on met tout les compteurs � z�ro */
    FICHIER=fopen(nom_fichier,"rb"); /* pas besoin de fseek on se trouve d�j� au d�but du fichier
                                        fseek ralentit concid�rablement le temps de lecture il ne
                                        faut l'utiliser que lorsqu'on ne peut pas faire autrement, ou
                                        simplement pour r�cup�rer la taille d'un fichier */
    if (FICHIER != NULL)
    {
        while((count=fread(buff,sizeof(char),256,FICHIER)))  /* tant que fread lit quelque chose */
        {
            for(i=0; i<count; i++)
            {
                /* on peut alors utiliser ce que fread a charg� dans buff en sachant
                                         le nombre de char qu'il a charg� dedans */
                if(buff[i]==',') /* si on tombe sur une virgule */
                {
                    tampon[ct_byte]='\0';
                    switch(ct_donnee)
                    {
                        /* on peut utiliser un switch pour le compteur de donn�es nous
                                        permettant de savoir quelle est le type de la donn�e lu */
                    case 0:
                        contact[ct_contact].nom=longueur_chaine(tampon);
                        contact[ct_contact].id=ct_contact+1;
                        break;
                    case 1:
                        contact[ct_contact].prenom=longueur_chaine(tampon);
                        break;
                    case 2:
                        contact[ct_contact].sexe=longueur_chaine(tampon);
                        break;
                    case 3:
                        contact[ct_contact].date_naissance=s_naissance(tampon);
                        break;
                    case 4:
                        contact[ct_contact].email=longueur_chaine(tampon);
                        break;
                    case 5:
                        contact[ct_contact].numfix=longueur_chaine(tampon);
                        break;
                    case 6:
                        contact[ct_contact].nummobil=longueur_chaine(tampon);
                        break;
                    case 7:
                        contact[ct_contact].adresse=longueur_chaine(tampon);
                        break;
                    default:; /* le default vide pour fermer le switch */
                    }
                    ct_byte=0; /* compteur de bytes � z�ro pour la chaine suivante */
                    ct_donnee+=1; /* incr�mente le compteur de donn�es */
                }
                else if(buff[i]=='\n')  /* si on tombe sur un saut de ligne */
                {
                    ct_contact+=1; /* incr�mente le compteur de contacts */
                    if(ct_contact-1==capacite)break;
                    ct_donnee=0; /* met le compteur de donn�es � z�ro pour la suite */
                    ct_byte=0; /* met le compteur de bytes � z�ro pour la chaine suivante */

                }
                else
                {
                    tampon[ct_byte]=buff[i];
                    ct_byte+=1; /* incr�mente le compteur de bytes */
                }
            }
        }
        fclose(FICHIER);
        return 0;
    }
    return 1;
}
