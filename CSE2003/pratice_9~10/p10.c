#include <stdio.h>

void swap(float *x, float *y);

int main(void){
	float x, y;
	printf("Input two Number\n\tx : ");
	scanf("%g",&x);
	printf("\ty : ");
	scanf("%g",&y);
	printf("------------------------------------------\n");
	printf("Before : x [%g] y [%g]\n",x,y);
	printf("------------------------------------------\n");
	swap(&x,&y);
	printf("After  : x [%g] y [%g]\n",x,y);
	return 0;
}

void swap(float *x, float *y){
	float temp;
	temp = *x;
	*x = *y;
	*y = temp;
}
