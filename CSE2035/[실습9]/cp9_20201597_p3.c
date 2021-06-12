#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(){
	int n,m;
	char *arr1,*arr2;
	scanf("%d %d",&n,&m);
	arr1 = (char *)calloc(n,sizeof(char));
	arr2 = (char *)calloc(m,sizeof(char));
	scanf("%s",arr1);
	scanf("%s",arr2);
	int **table;
	table = (int **)calloc(m+1,sizeof(int));
	int i,j;
	for (i=0;i<m+1;i++){
		*(table+i) = (int *)calloc(n+1,sizeof(int));
	}
	for (i=0;i<n+1;i++){
		*(*(table)+i)=0;
	}
	
	int max = 0,max_i,max_j;
	for (i=1;i<m+1;i++){
		for (j=1;j<n+1;j++){
			if (*(arr1+j-1)==*(arr2+i-1)){
				*(*(table+i)+j) = *(*(table+i-1)+j-1)+1;
				if (max<*(*(table+i)+j)){
					max = *(*(table+i)+j);
					max_i = i;
					max_j = j;
				}
			}
		}
	}
	printf("Longest Common Substring = ");
	for (i=0;i<max;i++){
		printf("%c",*(arr2+max_i-max+i));
	}

	printf("\n");
	return 0;
}

