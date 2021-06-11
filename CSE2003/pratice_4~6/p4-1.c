#include <stdio.h>

int main (void)
{	
	int birth,year,month,day,now;
	
	printf("Birthday : ");
	scanf("%d",&birth);
	year = birth/10000;
	month = birth%10000/100;
	day = birth%100;
	printf("Your birthday is %d / %d / %d\n",year,month,day);
	printf("Year : ");
	scanf("%d",&now);
	printf("In %d, your age is %d\n",now,now-year+1);
	return 0;
}
