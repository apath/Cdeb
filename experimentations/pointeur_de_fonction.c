#include <stdio.h>

void mafonction(int a){
    printf("%d\n",a);
}
void mafonction2(int a){
	printf("%d\n",a*a);
}
void dixfois(void(*pointeur)(int),int a){
    int i;
    for(i=0;i<10;i++)
        pointeur(a);
}

int main ( int argc, char** argv ){

    void (*pointeur2) (int a);
    pointeur2=mafonction2;

    pointeur2(7);

    mafonction(5);

    dixfois(mafonction,5);

    return 0;
}
