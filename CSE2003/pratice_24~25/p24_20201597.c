#include <stdio.h>
int reverse(int x);
int power(int x,int n);
int main(void){
	int x,result;
	scanf("%d",&x);
	result = reverse(x);
	printf("%d\n",result);
	return 0;
}
int reverse(int x){
	int temp,a,sum=0,count=0;
	temp = x;
	do{
		temp /= 10;
		count += 1;
	} while(10<temp);
	do{
		a = x % 10;
		x = x / 10;
		sum += a*(power(10,count));
		count -= 1;
	} while(x!=0);
	return sum;
}
int power(int x,int n){
	int result=1,i;
	for (i=0;i<n;i++){
		result *= x;
	}
	return result;
}
