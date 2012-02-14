#include <stdio.h> /* pour fprintf, fwrite, fclose */
#include <string.h> /* pour strlen */

int main(void)
  {
    char *buff="ecrire dans un fichier";
    FILE *f;
    f=fopen("test.txt","wb");
    if(f){
        fwrite(buff,sizeof(char),strlen(buff),f);
        fclose(f);
    } else {
        fprintf(stderr,"erreur creation fichier");
    }
    return 0;
  }
