#include <stdio.h>

int main(void)
{
	const int thr = 3;
	const int six = 6;
	int inp,thr_p,six_p;

	printf("Price : ");
	scanf("%d", &inp);

	printf("----------------output---------------\n");
	printf("Month\t\t:%10d%10d\n",thr,six);
	thr_p = inp;
	six_p = inp*1.05*1.05*1.05;
	printf("Payment\t\t:%10d%10d\n",thr_p,six_p);
	printf("-------------------------------------\n");
	printf("Pay/month\t:%10.2f%10.2f\n",(float)thr_p/thr,(float)six_p/six);
	return 0;

} 
