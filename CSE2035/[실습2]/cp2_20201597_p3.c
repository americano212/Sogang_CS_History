#include <stdio.h>
void swap(int *a, int *b);
void sort(int *a,int n);
void print_array(int *a,int n);
int main(void){
	int arr[1001],n,i;
	scanf("%d",&n);
	for (i=0;i<n;i++){
		scanf("%d",arr+i);
	}
	sort(arr,n);
	print_array(arr,n);
	
	
	return 0;
}

void print_array(int *a,int n){
	int i;
	for (i=0;i<n;i++){
		printf("%d ",*(a+i));
	}
	printf("\n");
}

void sort(int *a,int n){
	int i,j;
	for (i=n-1;i>0;i--){
        for (j=0;j<i;j++){
            if (*(a+j)>*(a+(j+1))){
                swap(& *(a+j),& *(a+j+1));
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
