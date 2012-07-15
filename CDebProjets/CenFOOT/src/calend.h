#ifndef __calend__
#define __calend__

/* alloc_calend
 * retourne un pointeur tableau de taille [38][10][2]
 * contenant les matchs avec numéro des equipes */
int ***alloc_calend(void);
/* free_calend
 * libere le pointeur retourné par alloc_calend */
void free_calend(int ***ptr);
/* gen_calend
 * genere le calendrier complet des matchs à l'aide
 * d'un pointeur alloué avec alloc_calend
 * retourne le même pointeur pour usage optionnel */
int ***gen_calend(int ***ptr);
/* print_calend
 * affiche le contenu du calendrier passé en paramètre */
void print_calend(int ***ptr);
/* get_calend_nt
 * recuperation du numéro des équipes à l'aide
 * du jour et du match dans un tableau int[2] dont on passe l'adresse
 * dans *get
 * exemple :
 * int g[2];
 * get_calend_nt(4,13,ptr,g);
 * pour le match 4 du 13e jour, le tableau g va récuperer
 * le numéro de l'équipe à domicile dans g[0] et visiteur en g[1]
 * retourne un entier >0 si erreur et 0 si ok */
int get_calend_nt(int day,int match,int ***ptr,int *get);
/* get_calend_dm
 * recuperation du jour ansi que du match à partir des informations
 * de la rencontre
 * team1 = equipe à domicile
 * team2 = equipe visiteur
 * *get pareil que pour get_calend_nt
 * tableau de 2 entier recupere en g[0] le jour et en g[1] le match
 * retourne un entier >0 si erreur et 0 si ok */
int get_calend_dm(int team1,int team2,int ***ptr,int *get);

#endif
