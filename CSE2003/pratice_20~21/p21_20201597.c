#include <stdio.h>
int main(void){
	int h,i=0,j,space,k=1;
	printf("Input: ");
	scanf("%d",&h);
	space = h;
	while (i<h){
		j=0;
		while (j<space){
			printf(" ");
			j += 1;
		}
		space -= 1;
		j=0;
		while (j<k){
			printf("*");
			j+=1;
		}
		k+=2;
		printf("\n");
		i+=1;
	}
	return 0;
}

