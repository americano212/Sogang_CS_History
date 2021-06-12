#include <stdio.h>
#include <string.h>


int main() {
	char path[1001];
	char fname[1001];
	
	printf("Path : ");
	gets(path);
	printf("File name : ");
	gets(fname);
	
	int count = strlen(path);
	
	while (1){
		if (path[count]=='/'){
			break;
		}
		path[count]='\0';
		count--;
	}
	
	printf("New path : %s%s\n",path,fname);
	return 0;
}
