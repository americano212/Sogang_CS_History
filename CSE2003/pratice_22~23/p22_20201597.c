#include <stdio.h>
void swap(int *a, int *b);
int main(void){
	int x,y,count=0,i;
	printf("Input first number: ");
	scanf("%d",&x);
	printf("Input second number: ");
	scanf("%d",&y);
	if (x>y){
		swap(&x,&y);
	}
	if (x<1 || y<1){
		printf("Input is less than 1\n");
	}
	else{
		for(i=x;i<y+1;i++){
			if (i%2==0 || i%3==0){
				count+=i;
			}
		}
		printf("Result: %d\n",count);
	}
	return 0;
}

void swap(int *a, int *b){
	int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
