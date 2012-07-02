#include <stdio.h>
#include <stdlib.h>
#include "country.h"
#include "match.h"

/* main de test et debug */

int main(void)
{
    /*printf("alias2code = %d\n",country_alias2code("FR"));
    printf("alias2name = %s\n",country_alias2name("FR"));
    printf("name2code  = %d\n",country_name2code("France"));
    printf("name2alias = %s\n",country_name2alias("France"));
    printf("code2name  = %s\n",country_code2name(84));
    printf("code2alias = %s\n",country_code2alias(84));*/
    /* test */
    MATCH *m;
    m=malloc(sizeof(MATCH));
    if(m){
        m->amical_start=NULL;
        m->coupe_start=NULL;
        m->saison_start=NULL;
    }
    free(m);
    return 0;
}
