#include<stdio.h>

float find_x (int, int, int, int);
float find_y (int, int, int, int);


int main (void){

	int a,b,c,d;
	printf("1st equation: y = ax - b, input 'a' and 'b'\n");
	printf("a = ");
	scanf("%d",&a);
	printf("b = ");
	scanf("%d",&b);
	
	printf("2nd equation: y = cx - d, input 'c' and 'd'\n");
	printf("c = ");
	scanf("%d",&c);
	printf("d = ");
	scanf("%d",&d);
	printf("result:\n");
	printf("x is %f\n",find_x(a,b,c,d));
	printf("y is %f\n",find_y(a,b,c,d));

	return 0;

}

float find_x (int a, int b, int c, int d){
	float x;
	x = (float)(b-d)/(float)(a-c);
	return x;

}

float find_y (int a, int b, int c, int d) {
	float y;
	y = (float)(a*d-b*c)/(float)(c-a);
	return y;
}
