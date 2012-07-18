/* gestion des equipes */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "team.h"

char *alloc_string(const char *str){
    char *ptr;
    int size;
    size=strlen(str);
    ptr=malloc(sizeof(char)*(size+1));
    if(ptr) strcpy(ptr,str);
    return ptr;
}

CLUB *club_init(void){
    CLUB *ptr;
    ptr=malloc(sizeof(CLUB));
    if(ptr) ptr->start=NULL;
    return ptr;
}

struct club *club_getptrbyname(CLUB *c,const char *team_name){
    struct club *ptr;
    ptr=c->start;
    wile(ptr){
        if(!strcmp(team_name,ptr->team_name))
            return ptr;
        ptr=ptr->next;
    }
    return NULL;
}

int club_add_team(CLUB *c,const char *team_name,int team_lvl,int country_code){
    struct club *ptr;
    if(club_getptrbyname(team_name)) return 3; /* nom deja present dans la liste */
    ptr=malloc(sizeof(struct club));
    if(ptr){
        if(!(ptr->team_name=alloc_string(team_name))){
            fprintf(stderr,"error alloc_string file %s at line %d\n",__FILE__,__LINE__);
            return 2;
        }
        ptr->lvl=team_lvl;
        ptr->country=country_code;
        ptr->tm=NULL;
        ptr->next=c->start;
        c->start=ptr;
    } else {
        fprintf(stderr,"error malloc file %s at line %d\n",__FILE__,__LINE__);
        return 1;
    }
    return 0;
}
