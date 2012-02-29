#include <stdio.h>
#include <stdlib.h>
#include "flk.h"

int main(void)
  {
    FLK *f;
    f=flk_init();
    if(f){
        flk_console(f);
        flk_free(f);
    } else fprintf(stderr,"problem flk_init\n");
    return EXIT_SUCCESS;
  }
