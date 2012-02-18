#include <stdio.h>

void calcul(int *a,int b,int c){ *a=b+c; }

int main(void)
  {
    int x;
    calcul(&x,4,6);
    printf("%d\n",x);
    return 0;
  }
