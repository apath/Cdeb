#include <stdio.h>
#include <stdlib.h>
#include "calend.h"

int ***alloc_calend(){
    int ***ptr,i,j;
    ptr=malloc(sizeof(int**)*38);
    if(ptr)
        for(i=0;i<38;i++){
            ptr[i]=malloc(sizeof(int*)*10);
            if(ptr[i]){
                for(j=0;j<10;j++){
                    ptr[i][j]=malloc(sizeof(int)*2);
                    if(ptr[i][j]){
                        ptr[i][j][0]=0;
                        ptr[i][j][1]=0;
                    } else {
                        fprintf(stderr,"error malloc file %s at line %d\n",
                                __FILE__,__LINE__); exit(1);
                    }
                }
            } else {
                fprintf(stderr,"error malloc file %s at line %d\n",
                        __FILE__,__LINE__); exit(1);
            }
        }
    return ptr;
}
void free_calend(int ***ptr){
    int i,j;
    for(i=0;i<38;i++){
        for(j=0;j<10;j++)
            free(ptr[i][j]);
        free(ptr[i]);
    } free(ptr);
}
int ***gen_calend(int ***ptr){
    int i,j,q[2],t[20]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
    for(i=0;i<38;i++){/* boucle 38 jours */
        for(j=0;j<10;j++){/* boucle 10 rencontres par jour */
            if(!(i%2)){ /* inversion jour pair & impair */
                q[0]=((j+1)+(j-1));
                q[1]=((j+1)+(j-1)+1);
            } else {
                q[0]=((j+1)+(j-1)+1);
                q[1]=((j+1)+(j-1));
            }
            ptr[i][j][0]=t[q[0]];
            ptr[i][j][1]=t[q[1]];
        }
        for(j=1;j<18;j+=2){/* boucle rotation t[] */
            q[0]=t[j]; q[1]=t[j+1];
            t[j]=t[j+2];
            t[j+1]=q[0];
            t[j+2]=q[1];
        }
    }
    return ptr;
}
void print_calend(int ***ptr){
    int i,j;
    for(i=0;i<38;i++){
        printf("\njour %d\n------\n",(i+1));
        for(j=0;j<10;j++){
            printf("\tequipe%d vs equipe%d\n",ptr[i][j][0],ptr[i][j][1]);
        }
    }
}
int get_calend_nt(int day,int match,int ***ptr,int *get){
    if(day>0 && day<=38)
        if(match>0 && match<=10){
            *get=ptr[day-1][match-1][0];
            *(get+1)=ptr[day-1][match-1][1];
        } else return 1; /* erreur match incorrect <0 ou >10 */
        else return 2; /* erreur jour incorrect <0 ou >38 */
    return 0; /* ok */
}
int get_calend_dm(int team1,int team2,int ***ptr,int *get){
    int i,j;
    if(team1>0 && team1<=20)
        if(team2>0 && team2<=20){
            for(i=0;i<38;i++)
                for(j=0;j<10;j++)
                    if(ptr[i][j][0]==team1 && ptr[i][j][1]==team2){
                        *get=i+1;
                        *(get+1)=j+1;
                        return 0; /* ok */
                    }
            return 3; /* match introuvable */
        } return 2; /* erreur team2 incorrect <0 ou >20 */
    return 1; /* erreur team1 incorrect <0 ou >20 */
}
