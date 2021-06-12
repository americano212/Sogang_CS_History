#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(){
	char *arr;
	arr = (char *)calloc(101,sizeof(char));
	scanf("%s",arr);
	int len;
	len = strlen(arr);
	
	char *target;
	target = (char *)calloc(101,sizeof(char));
	int target_count = 0;
	int i,j;
	for (i=0;i<len;i++){
		if ('0'<=*(arr+i) && *(arr+i)<='9' && '0'<=*(arr+i+1) && *(arr+i+1)<='9'){
			for (j=0;j<((*(arr+i)-'0')*10+*(arr+i+1)-'0');j++){
				printf("%s",target);
				
			}
			target = (char *)calloc(101,sizeof(char));
			target_count = 0;
		}
		else if ('0'<=*(arr+i) && *(arr+i)<='9'){			
			if ('0'<=*(arr+i-1) && *(arr+i-1)<='9'){
				int	a=1;
			}
			else{
				for (j=0;j<(*(arr+i)-'0');j++){
				printf("%s",target);
					
				}
				target = (char *)calloc(101,sizeof(char));
				target_count = 0;
			}
			
		}
		else{
			*(target+target_count) = *(arr+i);
			target_count++;
		}
		
	}
	printf("\n");
	return 0;
}

