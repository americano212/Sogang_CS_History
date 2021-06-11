#include <stdio.h>
void check_year(int year);
int flag = 0;

int main (void){
	int get_year;
	printf("Enter the year to be tested: ");
	scanf("%d",&get_year);
	check_year(get_year);
	if (flag == 0){
		printf("It is a leap year.\n");
		}
	else {
		printf("It is not a leap year.\n");
		while (flag == 1){
			get_year -= 1;
			check_year(get_year);
		}
		printf("%d is a leap year\n",get_year);
	}
	return 0;
}

void check_year(int year){
	if (year%4==0 && year%100!=0){
		flag = 0;
	}
	else if (year%400==0){
		flag = 0;
	}
	else {
		flag = 1;
	}
}
