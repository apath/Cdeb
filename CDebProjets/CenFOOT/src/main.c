#include <stdio.h>
#include <stdlib.h>
#include "country.h"
#include "match.h"
#include "calend.h" /* calendrier saison */

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
    int ***calend,g[2];
    calend=alloc_calend();
    if(calend){
        gen_calend(calend);
        printf("print_calend\n------\n");
        print_calend(calend);
        printf("get_calend_nt j12 m3\n------\n");
        get_calend_nt(12,3,calend,g);
        printf("T_dom = %d\tT_vis = %d\n",g[0],g[1]);
        printf("get_calend_dm T_dom = 17 T_vis = 9\n------\n");
        get_calend_dm(17,9,calend,g);
        printf("jour = %d\tmatch = %d\n",g[0],g[1]);
        free_calend(calend);
    }
    return 0;
}
