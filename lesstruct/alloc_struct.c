#include <stdio.h> /* printf */
#include <string.h> /* strcpy */
#include <stdlib.h> /* malloc, free */

struct test{
    int a;
    char s[10];
};

int main(void)
  {
    char *chaine = "simple";
    struct test *t; /* t est un pointeur du type de la structure test */
    t=malloc(sizeof(struct test)); /* allocation de la mémoire à la
                                      taille de la structure, malloc
                                      retourne alors la nouvelle adresse
                                      et la met dans t */
    if(t!=NULL) /* si malloc ne peut allouer la mémoire il retourne
                   une adresse NULL, dans ce cas il y a un problème */
      {
        t->a=2; /* on accède aux membres de la structure à l'aide de
                   -> lorsqu'on utilise un pointeur */
        strcpy(t->s,chaine);
        printf("a : %d\ns : %s\n",t->a,t->s);
        free(t); /* on libère la mémoire qui se trouve à l'adresse pointée
                    par t */
      } else {
          fprintf(stderr,"erreur malloc\n");
      }
    return 0;
  }
