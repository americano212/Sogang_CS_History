#include <stdio.h>
int main(void){ 
	int a,b,count=0;
	printf("Enter 2 number: ");
	scanf("%d %d",&a,&b);
	if ((a%10 + b%10)>=10){count +=1;}
	if ((a%100 + b%100)>=100){count +=1;}
	if ((a + b)>=1000){count +=1;}
	printf("%d carry operations\n",count);
	return 0;
}
