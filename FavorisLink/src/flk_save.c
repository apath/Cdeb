#include <stdlib.h>
#include "flk.h"

FLK *flk_init(void){
    FLK *ptr;
    ptr=malloc(sizeof(FLK));
    if(ptr){
        ptr->categories_index=NULL;
    }
    return ptr;
}
