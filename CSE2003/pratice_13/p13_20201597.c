#include <stdio.h>
int main(void){ 
	float inp;
	printf("Input: ");
	scanf("%f",&inp);
	printf("Use \">\": %d\n",(int)(inp+0.5)>(int)(inp));
	printf("Use \">=\": %d\n",(int)(inp+0.5)>=(int)(inp)+1);
	printf("Use \"==\": %d\n",(int)(inp+0.5)==(int)(inp)+1);
	printf("Use \"!=\": %d\n",(int)(inp+0.5)!=(int)(inp));
	return 0;
}
