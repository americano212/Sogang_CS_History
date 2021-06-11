#include <stdio.h>
float avgFunc(float a, float b, float c);
void gradeFunc(float avg);
int check =0;
int main(void){
	float a,b,c,avg;
	printf("Input: ");
	scanf("%f %f %f",&a,&b,&c);
	avg = avgFunc(a,b,c);
	gradeFunc(avg);
	return 0;
}
float avgFunc(float a, float b, float c){
	return (a+b+c)/3;
}
void gradeFunc(float avg){
	if (avg>=50){
		if (avg>=70){
			if (avg>=80){
				if (avg>=90){
					check += 1;
				}
				check += 1;
			}
			check += 1;
		}
		check += 1;
	}
	else {
		printf("F\n");
	}
	switch(check){
		case (1) : printf("D\n"); break;
		case (2) : printf("C\n"); break;
		case (3) : printf("B\n"); break;
		case (4) : printf("A\n"); break;
	}
}
