#include<stdio.h>

float Mean (int,int,int,int);
float Devi (float,int);

int main (void) {
	int a,b,c,d;

	printf("Enter the first number : ");
	scanf("%d",&a);
	printf("Enter the second number : ");
	scanf("%d",&b);
	printf("Enter the third number : ");
	scanf("%d",&c);
	printf("Enter the fourth number : ");
	scanf("%d",&d);
	printf("******** average is %.2f ********\n",Mean(a,b,c,d));
	
	printf("first number :\t\t%10d  -- deviation : %10.2f\n",a,Devi(Mean(a,b,c,d),a));
	printf("second number :\t\t%10d  -- deviation : %10.2f\n",b,Devi(Mean(a,b,c,d),b));
	printf("third number :\t\t%10d  -- deviation : %10.2f\n",c,Devi(Mean(a,b,c,d),c));
	printf("fourth number :\t\t%10d  -- deviation : %10.2f\n",d,Devi(Mean(a,b,c,d),d));	
}


float Mean (int a, int b, int c, int d) {
	float mean;
	mean = (float)(a+b+c+d)/4;
	return mean;
}

float Devi (float mean, int number) {
	float devi;
	devi = number - mean;
	return devi;
}
