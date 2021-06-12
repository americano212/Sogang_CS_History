#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void strPk(char* s1, char* s2){
	char *temp;
	temp = calloc(100,sizeof(int));
	char *temp1;
	temp1 = calloc(100,sizeof(int));
	int count =0;
	int len1,len2;
	len1 = strlen(s1);
	int i;
	for (i=0;i<len1;i++){
		if ((*(s1+i)>=65 && *(s1+i)<=90) || (*(s1+i)>=97 && *(s1+i)<=122)){
			temp[count]=*(s1+i);
			count++;
		}
	}
	strcpy(s1,temp);
	
	count =0;
	len2 = strlen(s2);
	for (i=0;i<len2;i++){
		if ((*(s2+i)>=65 && *(s2+i)<=90) || (*(s2+i)>=97 && *(s2+i)<=122)){
			temp1[count]=*(s2+i);
			count++;
		}
	}
	strcpy(s2,temp1);
}

int strCmpPk(char* s1,char* s2){
	return (strcmp(s1,s2));
}

int main(){
	char *arr1;
	char *arr2;
	arr1 = calloc(100,sizeof(int));
	arr2 = calloc(100,sizeof(int));
	printf("first string : ");
	scanf("%s",arr1);
	printf("second string : ");
	scanf("%s",arr2);
	strPk(arr1,arr2);
	if (strCmpPk(arr1,arr2)==0){
		printf("string1 == string2");
	}
	else if (strCmpPk(arr1,arr2)>0){
		printf("string1 > string2");
	}
	else{
		printf("string2 < string1");
	}
	printf("\n");
	return 0;
}

