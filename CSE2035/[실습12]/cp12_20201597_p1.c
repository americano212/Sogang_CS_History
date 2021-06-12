#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
	char *arr1;
	char *arr2;
	arr1 = calloc(1000,sizeof(char));
	arr2 = calloc(1000,sizeof(char));
	
	gets(arr1);
	gets(arr2);
	int len=strlen(arr1);
	int i;
	int check = 0;
	for (i=0;i<len;i++){
		if ((*(arr1+i)==*(arr2+i)) || (*(arr1+i)-*(arr2+i))==32 || (*(arr2+i)-*(arr1+i)==32)){
			continue;
		}
		else{
			check = 1;
		}
	}
	if (check==0){
		printf("Equal\n");
	}
	else{
		printf("Not Equal\n");
	}
	return 0;
}

