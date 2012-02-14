#include <stdio.h>

int main(void)
  {
    char buffer[256];
    size_t c,i;
    FILE *f;
    f=fopen("lire.txt","rb");
    if(f){
        while((c=fread(buffer,sizeof(char),256,f))){
            for(i=0;i<c;i++)
                printf("%c",buffer[i]);
        }
        fclose(f);
    } else {
        fprintf(stderr,"probleme lecture du fichier\n");
    }
    return 0;
  }
