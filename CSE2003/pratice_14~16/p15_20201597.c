#include <stdio.h>
int main(void){
	int number;
	printf("Input: ");
	scanf("%d",&number);
	(number%2==1) ? printf("%d is odd number.\n",number):printf("%d is even number.\n",number);
	return 0;
}
