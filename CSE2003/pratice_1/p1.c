#include <stdio.h>

int main(void){
	char ch;
	int integer;
	float real;

	printf("Input one character, one integer, one real number : ");
	scanf("%c %d %f", &ch, &integer, &real);
	printf("%c %d %f\n", ch, integer, real);

	return 0;

}	
