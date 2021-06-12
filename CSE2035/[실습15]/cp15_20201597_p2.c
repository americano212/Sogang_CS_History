#include <stdio.h>
#include <stdlib.h>

typedef struct {
	float price, number;
} Buying;

Buying getAverage(Buying* pBuying, int n);

int main(void) {
	int n,i;
	Buying* arr, ans;
	scanf("%d", &n);
	arr = (Buying*)malloc(sizeof(Buying) * n);
	for (i = 0; i < n; i++)
		scanf("%f %f", &arr[i].price, &arr[i].number);
	ans = getAverage(arr, n);
	printf("%0.2f %0.2f\n", ans.price, ans.number);
	
	
	return 0;
}

Buying getAverage(Buying* pBuying, int n) {
	int i;
	for (i = 1; i < n; i++) {
		pBuying[0].price += pBuying[i].price;
		pBuying[0].number += pBuying[i].number;
	}
	pBuying[0].price /= n;
	pBuying[0].number /= n;
	
	
	return pBuying[0];
}
