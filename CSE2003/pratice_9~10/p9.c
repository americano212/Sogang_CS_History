#include <stdio.h>

void divideRemainder (int *a, int *b);

int main(void){ 
	int a,b;
	printf("Input two Number : ");
	scanf("%d %d",&a,&b);
	printf("-------------------------------------------------------------\n");
	divideRemainder(&a,&b);
	printf("OUTPUT : divide [%d] remainder [%d]\n",a,b);
	return 0;
}


void divideRemainder (int *a, int *b){
	int temp;
	temp = *a / *b;
	*b = *a % *b;
	*a = temp;
}

