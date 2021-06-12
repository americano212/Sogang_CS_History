#include <stdio.h>
#include <stdlib.h>
#include <string.h>

union utemp{
	int i;
	float f;
	double d;
};

typedef struct {
	int type;
	char name[20];
	union utemp u;
	
}stemp;

void power(stemp *s){
	if (s->type==1){
		s->u.i = s->u.i * s->u.i;
	}
	if (s->type==2){
		s->u.f = s->u.f * s->u.f;
	}
	if (s->type==3){
		s->u.d = s->u.d * s->u.d;
	}
	
}
int main(){
	int t,check;
	printf("Number of Iterations : ");
	scanf("%d",&t);
	stemp* arr;
	arr = (stemp*)malloc(sizeof(stemp) * t);
	int i;
	
	for (i=0;i<t;i++){
		
		printf("Type [1 for int, 2 for float, 3 for double] : ");
		scanf("%d",&check);
		
		if (check==1){
			arr[i].type = 1;
			
			printf("Enter an integer value : ");
			strcpy(arr[i].name,"integer");
			scanf("%d",&arr[i].u.i);
		}
		if (check==2){
			arr[i].type = 2;
			
			printf("Enter a float value : ");
			strcpy(arr[i].name,"float");
			scanf("%f",&arr[i].u.f);
		}
		if (check==3){
			arr[i].type = 3;
			
			printf("Enter a double value : ");
			strcpy(arr[i].name,"double");
			scanf("%lf",&arr[i].u.d);
		}
		power(&arr[i]);
	}
	printf("----------Result----------\n");
	for (i=0;i<t;i++){
		if (arr[i].type==1){
			printf(arr[i].name);
			printf(" : %d",arr[i].u.i);
		}
		if (arr[i].type==2){
			printf(arr[i].name);
			printf("   : %.4f",arr[i].u.f);
		}
		if (arr[i].type==3){
			printf(arr[i].name);
			printf("  : %.4lf",arr[i].u.d);
		}
		printf("\n");
	}
}
