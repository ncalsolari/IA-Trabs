#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>


int main(){

	int *pont;
	int **ppont;
	int *a;
	int i = 10;
	int x;

	pont = &i;

	//*ppont = pont;
	
	a = pont;
	//*a = *ppont;

	printf("end pont: %d\n",&i);
	//printf("valor pont: %d\n",*pont);
	//printf("pont: %d\n",*ppont);
	//printf("pont: %d\n",**ppont);
	printf("apont: %d\n",*a);
	printf("apont: %d\n",a);









return 0;





}