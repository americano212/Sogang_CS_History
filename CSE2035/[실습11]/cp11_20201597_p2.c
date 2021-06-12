#include <stdio.h>
#include <string.h>

void initialization(char *a, int n){
	int i;
	for (i=strlen(a)-n;i<strlen(a);i++){
		a[i] = '*';
	}
}

char *my_strncpy(char *a, char *b,int n){
	int i;
	for (i=0;i<n;i++){
		a[i] = b[i];
	}
}


int main() {
   char str1[1001];
   char str[1001];
   int i;
   printf("input str : ");
   gets(str1);
   strcpy(str,str1);
   for (i=0;i<strlen(str1)+1;i++){
		initialization(str,strlen(str)-i);
		my_strncpy(str,str1,i);
		printf("%s\n",str);
   }
   return 0;
}
