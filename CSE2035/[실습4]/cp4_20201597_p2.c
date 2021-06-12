#include <stdio.h>

void swap(int *a, int *b);
void sort(int *a,int m){
	int i,j;
	for (i=m-1;i>0;i--){
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

void all_sort(int a[][100],int n, int m){
	int i;
	for(i=0;i<n;i++){
		sort(*(a+i),m);
	}
}

int binary_search(int *a,int* endPtr,int key,int **findPtr){
	int* firstPtr;
	int* midPtr;
	int* lastPtr;
	firstPtr = a;
	lastPtr = endPtr;
	while (firstPtr <= lastPtr){
		midPtr = firstPtr + (lastPtr - firstPtr) / 2;
		if (key > *midPtr){
			firstPtr = midPtr + 1;
		}
		else if (key < *midPtr){
			lastPtr = midPtr - 1;
		}
		else{
			firstPtr = lastPtr + 1;
		}
	}
	*findPtr = midPtr;
	return (key == *midPtr);
}

int all_binary_search(int a[][100],int n,int m, int key, int **findPtr){
	int test,i;
	for (i=0;i<n;i++){
		test = binary_search(*(a+i),(*(a+i)+m-1),key,findPtr);
		if (test==1) return 1;
	}
	return 0;
}

int main(void){
	int n,m,k,a[100][100],i,j;
	int* findPtr;
	int check;
	scanf("%d %d %d",&n,&m,&k);
	for (i=0;i<n;i++){
		for (j=0;j<m;j++){
			scanf("%d",(*(a+i)+j));
		}
	}
	
	all_sort(a,n,m);
	check = all_binary_search(a,n, m, k, &findPtr);
	
	printf("%d\n",check);
	printf("%p\n",findPtr);
	return 0;
}

