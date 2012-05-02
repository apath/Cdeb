#include <stdio.h>
#include <stdlib.h>
#include "fonctions.h"

#define TAILLE_REPERTOIRE 250

int main(void)
{
    int choix,sortir=2,choix_recherche,ID_recherche,choix_supp,resultat,choix_ajout;
    char nom[20];

    struct Fiche contact[TAILLE_REPERTOIRE];
    initialise_fiche(contact,TAILLE_REPERTOIRE);
    load_fiche(contact,TAILLE_REPERTOIRE,"fichier.txt");
    while(sortir!=1)
    {
        printf("---------------------------------------------------------------\n");
        printf("---------REPERTOIRE PREMIER PROJET DE L EQUIPE C-DEB-----------\n");
        printf("---------------------------------------------------------------\n\n");
        printf("1-RECHERCHER CONTACT\n");
        printf("2-AJOUTER CONTACT\n");
        printf("3-AFFICHER TOUS LES CONTACTS\n");
        printf("4-MODIFIER CONTACT\n");
        printf("5-SUPPRIMER UN CONTACT\n");
        printf("6-SUPPRIMER TOUS LES CONTACTS\n");
        printf("7-QUITTER\n");
        printf("Votre choix: ");
        scanf("%d",&choix);

        switch(choix)
        {
        case 1:
            printf("---------------------------------------------------------------\n");
            printf("                      RECHERCHER CONTACT\n");
            printf("---------------------------------------------------------------\n");
            printf("1-Rechercher par nom\n");
            printf("2-Rechercher par ID\n");
            printf("Votre choix: ");
            scanf("%d",&choix_recherche);
            if(choix_recherche==1)
            {
                printf("Entrez le nom a rechercher: ");
                scanf("%s",nom);
                resultat=recherche_nom(contact,nom,TAILLE_REPERTOIRE);
                if (resultat==1)
                {
                    printf("---------------------------------------------------------------\n");
                    printf("              Contact inexistant. Voulez vous le rajoutter ?\n");
                    printf("---------------------------------------------------------------\n");
                    printf("1-oui\n");
                    printf("2-non\n");
                    printf("Votre choix: ");
                    scanf("%d",&choix_ajout);
                    if (choix_ajout==1)
                    {
                        ajouter_contact(contact,TAILLE_REPERTOIRE);
                        save_fiche(contact,TAILLE_REPERTOIRE,"fichier.txt");
                    }
                }
            }
            else if(choix_recherche==2)
            {
                printf("Entrez le numero d' ID a rechercher: ");
                scanf("%d",&ID_recherche);
                affiche_id(contact,ID_recherche);
            }

            break;
        case 2:
            printf("---------------------------------------------------------------\n");
            printf("                        AJOUTER CONTACT\n");
            printf("---------------------------------------------------------------\n");
            ajouter_contact(contact,TAILLE_REPERTOIRE);
            save_fiche(contact,TAILLE_REPERTOIRE,"fichier.txt");
            break;
        case 3:
            printf("---------------------------------------------------------------\n");
            printf("                  AFFICHER TOUS LES CONTACTS\n");
            printf("---------------------------------------------------------------\n");
            affiche_tout(contact,TAILLE_REPERTOIRE);
            break;
        case 4:
            printf("---------------------------------------------------------------\n");
            printf("                      MODIFIER CONTACT\n");
            printf("---------------------------------------------------------------\n");
            printf("Entrez le numero d' ID a modifier: ");
            scanf("%d",&ID_recherche);
            affiche_id(contact,ID_recherche);
            modifier_contact(contact,ID_recherche);
            save_fiche(contact,TAILLE_REPERTOIRE,"fichier.txt");
            break;
        case 5:
            printf("---------------------------------------------------------------\n");
            printf("                      SUPPRIMER UN CONTACT\n");
            printf("---------------------------------------------------------------\n");
            printf("Entrez le numero d' ID de la fiche a supprimer: ");
            scanf("%d",&ID_recherche);
            printf("Etes vous sur de vouloir supprimer la fiche id ===> %d ?\n",ID_recherche);
            printf("1-oui\n");
            printf("2-non\n");
            printf("Votre choix: ");
            scanf("%d",&choix_supp);
            if(choix_supp==1)
            {
                supp_contact(contact,ID_recherche);
            }
            else
            {
                printf("---------------------------------------------------------------\n");
                printf("               Le contact ne sera pas supprime.\n");
                printf("---------------------------------------------------------------\n");
            }
            save_fiche(contact,TAILLE_REPERTOIRE,"fichier.txt");
            break;
        case 6:
            printf("---------------------------------------------------------------\n");
            printf("                   SUPPRIMER TOUS LES CONTACTS\n");
            printf("---------------------------------------------------------------\n");
            printf("Etes vous sur de vouloir tout supprimer ?\n");
            printf("1-oui\n");
            printf("2-non\n");
            printf("Votre choix: ");
            scanf("%d",&choix_supp);
            if(choix_supp==1)
            {
                supprime_tout(contact,TAILLE_REPERTOIRE);
            }
            else
            {
                printf("---------------------------------------------------------------\n");
                printf("               Les contacts ne seront pas supprimes.\n");
                printf("---------------------------------------------------------------\n");
            }
            save_fiche(contact,TAILLE_REPERTOIRE,"fichier.txt");
            break;

        case 7:
            printf("---------------------------------------------------------------\n");
            printf("                            QUITTER\n");
            printf("---------------------------------------------------------------\n");
            printf("Etes vous sur de vouloir quitter ?\n");
            printf("1-oui\n");
            printf("2-non\n");
            printf("Votre choix: ");
            scanf("%d",&sortir);
            save_fiche(contact,TAILLE_REPERTOIRE,"fichier.txt");
            break;
        default:
            printf("---------------------------------------------------------------\n");
            printf("                  Ce choix n'existe pas\n");
            printf("                  Merci de recommencer.\n");
            printf("---------------------------------------------------------------\n");
            break;
        }
    }
    return 0;
}
