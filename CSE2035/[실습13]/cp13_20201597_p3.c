#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct complex{
	float real;
	float imag;
} complex;

struct complex add(struct complex n1,struct complex n2){
	struct complex temp;
	temp.real = n1.real + n2.real;
	temp.imag = n1.imag + n2.imag;
	return temp;
}

int main(){
	struct complex cp1;
	struct complex cp2;
	struct complex result;
	
	scanf("%f %f",&cp1.real,&cp1.imag);
	scanf("%f %f",&cp2.real,&cp2.imag); 
	result = add(cp1,cp2);
	
	printf("Sum = %.1f + %.1fi\n",result.real,result.imag);
	
	return 0;
}

