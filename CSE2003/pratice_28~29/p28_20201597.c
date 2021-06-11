#include <stdio.h>
void CtU(char x[]);
int count=0;
int main(void){
	char arr[49],i;
	
	for (i=0;i<50;i++){
		count+=1;
		scanf("%c",&arr[i]);
		if (arr[i]=='\n') break;
	}
	CtU(arr);
	for (i=0;i<count;i++){
		printf("%c",arr[i]);
	}
	printf("\n");
	return 0;
}

void CtU(char x[]){
	int i;
	for (i=0;i<count;i++){
		if (x[i]<123 && x[i]>96){
			x[i] = x[i]-32;
		}
	}
}
