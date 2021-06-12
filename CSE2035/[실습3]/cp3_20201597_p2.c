#include <stdio.h>
void make_array(int *a,int *b, int n){
	int j;
	*(b+n-1) = *a;
	for (j=0;j<n-1;j++){
		*(b+j) = *(a+j+1);
	}
}

void print_array(int *a,int n){
	int i;
	for (i=0; i<n;i++){
		printf("%d ",*(a+i));
	}
	printf("\n");
}

int main(void){
	int n,a[10],b[10],i;
	scanf("%d",&n);
	for (i=0;i<n;i++){
		scanf("%d",a+i);
	}
	make_array(a,b,n);
	print_array(b,n);
	return 0;
}

