#include <stdio.h>

void recup_date(char *date){
	int j,m,a; /* jour, mois, annee */
	/* ... */
	printf("j=%d\tm=%d\ta=%d\n",j,m,a);
}

int main(void){
	char *test="17/4/1981";
	recup_date(test);
	/* recup_date doit afficher :
	j=17	m=4		a=1981
	*/
	return 0;
}