#include <stdio.h>
void shift_n_left(int *a, int n){
	int temp = *a,i,j;
	
	for (i=0;i<n;i++){
		temp = *a;
		for (j=0;j<9;j++){
			*(a+j) = *(a+j+1);
		}
		*(a+9) = temp;
	}
}

void shift_n_right(int *a, int n){
	int temp = *a,i,j;
	
	for (i=0;i<n;i++){
		temp = *(a+9);
		for (j=0;j<9;j++){
			*(a+9-j) = *(a+8-j);
		}
		*a = temp;
	}
}

void print_array(int *a){
	int i;
	for (i=0; i<10;i++){
		printf("%d ",*(a+i));
	}
	printf("\n");
}

int main(void){
	int n,a[10]={1,2,3,4,5,6,7,8,9,10},m;
	scanf("%d",&n);
	scanf("%d",&m);
	if (m==0){
		shift_n_left(a,n);
	}
	if (m==1){
		shift_n_right(a,n);
	}
	print_array(a);
	return 0;
}

