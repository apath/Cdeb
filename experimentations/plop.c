#include <stdio.h>

int main(void)
  {
    char tableau[100]="hello tout le monde";
    char *p;
    tableau[5]='\0';
    printf("a : %s\n%s\n",tableau,&tableau[6]);
    p=&tableau[6];
    printf("b : %s\n%s\n",tableau,p);
    return 0;
  }
