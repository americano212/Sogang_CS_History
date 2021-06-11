#include <stdio.h>
void dec2oct(int*,int*,int*,int*,int);
void dec2hex(char*,char*,char*,int);
char digithex(int);
int main(void){
	int inp,e1=0,e2=0,e3=0,e4=0;
	char h1='0',h2='0',h3='0';
	scanf("%d",&inp);
	printf("%04o\n",inp);
	dec2oct(&e1,&e2,&e3,&e4,inp);
	printf("%d%d%d%d\n",e1,e2,e3,e4);
	printf("%03X\n",inp);
	dec2hex(&h1,&h2,&h3,inp);
	printf("%c%c%c\n",h1,h2,h3);
	return 0;
}
void dec2oct(int *e1,int *e2,int *e3,int *e4,int inp){
	*e1=inp/512;
	*e2=(inp%512)/64;
	*e3=(inp%64)/8;
	*e4=inp%8;
}

void dec2hex(char *h1,char *h2,char *h3,int inp){
	*h1=digithex(inp/256);
	*h2=digithex((inp%256)/16);
	*h3=digithex(inp%16);
}

char digithex(int number){
	if (9>=number && number>=0){
		return number+48;
	}
	else {
		return number+55;
	}
}
