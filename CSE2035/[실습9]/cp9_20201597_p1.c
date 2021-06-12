#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(){
	char *arr;
	arr = (char *)calloc(101,sizeof(char));
	scanf("%s",arr);
	int len;
	len = strlen(arr);
	int check = 1;
	int i;
	for (i=0;i<len/2;i++){
		if (*(arr+i)!=*(arr+(len-i-1))){
			check = 0;
		}
	}
	
	if (check==1){
		printf("Palindrome.\n");
	}
	else{
		printf("Not palindrome.\n");
	}
	return 0;
}
