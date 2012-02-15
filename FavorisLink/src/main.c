#include <stdio.h>
#include <stdlib.h>
#include "flk.h"

int main(void)
{
    FLK *test;
    char *str="test";
    test=flk_init();
    if(test){
        flk_mod_categorie(ADD,str,test);
        printf("%s\n",test->categories_index->titre);
    }
    return EXIT_SUCCESS;
}
