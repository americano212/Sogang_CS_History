#include <stdio.h>
void func_gcd(int a, int b, int* gcd);

int main(void){
    int a,b,gcd;
    printf("Input first number: ");
	scanf("%d",&a);
	printf("Input second number: ");
	scanf("%d",&b);
    func_gcd(a,b,&gcd);
    printf("GCD: %d\n",gcd);
    return 0;
}

void func_gcd(int a, int b, int* gcd){
	int c=1;
	while(c!=0){
		c = a%b;
		a=b;
		b=c;
	}
	*gcd = a;
}
