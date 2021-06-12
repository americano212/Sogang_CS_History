#include <stdio.h>

int main(void){
	int a,b,c;
	int *pa,*pb,*pc;
	scanf("%d%d%d",&a,&b,&c);
	pa = &a; pb  = &b; pc = &c;
	
	
	if ((*pa <= *pb) && (*pb <= *pc)){
		printf("%d %d\n",*pa, *pc);
		printf("%p %p\n",pa, pc);
	}
		
	else if (*pa <= *pc && *pc <= *pb){
		printf("%d %d\n",*pa, *pb);
		printf("%p %p\n",pa, pb);
	}		
	else if (*pb <= *pa && *pa <= *pc){
		printf("%d %d\n",*pb, *pc);
		printf("%p %p\n",pb, pc);
	}
	else if (*pb <= *pc && *pc <= *pa){
		printf("%d %d\n",*pb, *pa);
		printf("%p %p\n",pb, pa);
	}
	else if (*pc <= *pb && *pb <= *pa){
		printf("%d %d\n",*pc, *pa);
		printf("%p %p\n",pc, pa);
	}
	else if (*pc <= *pa && *pa <= *pb){
		printf("%d %d\n",*pc, *pb);
		printf("%p %p\n",pc, pb);
	}
	
	return 0;
}
