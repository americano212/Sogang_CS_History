#include <stdio.h>
#include <stdlib.h>

typedef struct {
	float real;
	float imag;
}complex;

complex* multiple(complex* a, complex* b);

int main(void) {
	complex a, b, *ans;
	scanf("%f %f", &a.real, &a.imag);
	scanf("%f %f", &b.real, &b.imag);

	ans = multiple(&a, &b);
	printf(" %0.2f + (%0.2f)i\n", ans->real, ans->imag);
	
	return 0;
}

complex* multiple(complex* a, complex* b) {
	complex* com = (complex*)malloc(sizeof(complex));
	
	com->real = a->real * b->real - a->imag * b->imag;
	com->imag = a->real * b->imag + a->imag * b->real;
	
	return com;
}
