#include <stdio.h>
#include <stdlib.h>
#include <string.h>
enum Date {
	Sunday = 0,
	Monday,
    Tuesday,
    Wednesday,
    Thursday,
    Friday,
    Saturday
};

struct Calendar{
	int year, month,day;
	enum Date date;
	char* dateString;
};

enum Date getDate(int y, int m, int d){
	int k;
	k = (y+y/4-y/100+y/400+(13 * m + 8)/5 +d)%7;
	return k;
}
char* getDay(enum Date currDate){
	static char temp[10];
	if (currDate==0){
		strcpy(temp,"Sunday");
	}
	if (currDate==1){
		strcpy(temp,"Monday");
	}
	if (currDate==2){
		strcpy(temp,"Tuesday");
	}
	if (currDate==3){
		strcpy(temp,"Wednesday");
	}
	if (currDate==4){
		strcpy(temp,"Thursday");
	}
	if (currDate==5){
		strcpy(temp,"Friday");
	}
	if (currDate==6){
		strcpy(temp,"Saturday");
	}
	return temp;
}

int main(){
	struct Calendar c1;
	scanf("%d",&c1.year);
	scanf("%d",&c1.month);
	scanf("%d",&c1.day);
	c1.date = getDate(c1.year,c1.month,c1.day);
	
	c1.dateString = getDay(c1.date);
	printf("%s\n",c1.dateString);
	return 0;
}

