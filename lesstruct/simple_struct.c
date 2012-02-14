#include <stdio.h> /* printf */
#include <string.h> /* strcpy */

struct test{
    int a;
    char s[10]; /* tableau de 10 char, soit 9 char + le \0
                   de fin de chaîne */
};

int main(void)
  {
    struct test t;
    char *chaine = "simple"; /* attention chaine ne doit pas
                                dépasser les 9 char */
    t.a = 2; /* on accède aux membres de la structure par un .
                lorsqu'on utilise pas de pointeur */
    strcpy(t.s,chaine); /* copie chaine dans s sans vérifier la
                           taille, on pourrait utiliser strncpy
                           ou memcpy a la place */
    printf("a : %d\ns : %s\n",t.a,t.s);
    return 0;
  }
