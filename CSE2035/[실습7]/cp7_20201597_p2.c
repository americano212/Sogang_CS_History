#include <stdio.h>
#include <stdlib.h>
void swap(int *a, int *b);
void double_double(int **a,int *size);

int main(){
	int n,i,j;
	int *arr;
	scanf("%d",&n);
	arr = (int *) malloc(sizeof(int)*(n));
	for (i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	for (i=0;i<3;i++){
		n = n*2;
		double_double(&arr,&n);
		
		for (j=0;j<n;j++){
			printf("%d ",arr[j]);
		}
		printf("\n");
	}
	return 0;
}

void double_double(int **a,int *size){
	int temp,i;
	int k,p;
	temp = *size / 2;
	*a = realloc(*a,(*size)*sizeof(int));
	for (i=0;i<temp;i++){
		(*a)[i+temp] = 2 * (*a)[i];
	}
	for (k=(*size)-1;k>0;k--){
        for (p=0;p<k;p++){
            if ((*a)[p]>(*a)[p+1]){
                swap(& (*a)[p],& (*a)[p+1]);
            }
        }
    }
}


void swap(int *a, int *b){
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}
