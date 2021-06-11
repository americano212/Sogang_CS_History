#include <stdio.h>
int palindrome (int num, int digit);
int check=1;

int main(void){
	int N;
	printf("Input: ");
	scanf("%d",&N);
	while ((N/check) != 0){
		check *= 10;
	}
	check /= 10;
	
	if (N<0){
		printf("Input number cannot be negative.\n");
	}
	else{
		if (palindrome(N,1)){
			printf("%d is a palindrome number.\n",N);
		}
		else{
			printf("%d is not a palindrome number.\n",N);
		}
	}
	
	return 0;
}

int palindrome (int num, int digit){
	if (check == digit || check == 0){
		return 1;
	}
	else{
		if ((num%(check*10))/check == (num%(digit*10))/digit){
			check /= 10;
			palindrome(num,digit * 10);
		}
		else{
			return 0;
		}
	}

}
