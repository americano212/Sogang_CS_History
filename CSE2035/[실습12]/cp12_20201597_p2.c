#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
	int n;
	scanf("%d",&n);
	char **arr;
	char *temp;
	temp = calloc(100,sizeof(int));
	int i,j;
	arr = calloc(n,sizeof(char));
	for (i=0;i<n;i++){
		*(arr+i) = calloc(100,sizeof(char));
	}
	for (i=0;i<n;i++){
		scanf("%s",*(arr+i));
	}
	for (i=0;i<n-1;i++){
		for (j=0;j<n-1;j++){
			if (strcmp(*(arr+j),*(arr+j+1))>=0){
				strcpy(temp,*(arr+j));
				strcpy(*(arr+j),*(arr+j+1));
				strcpy(*(arr+j+1),temp);
			}
		}
	}
	printf("-Lexicographic Order-\n");
	for (i=0;i<n;i++){
		printf("%s\n",*(arr+i));
	}
	return 0;
}

