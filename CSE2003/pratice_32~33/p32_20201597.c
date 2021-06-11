#include <stdio.h>
float sum_score(int,int,int,int,int);
int main(void){
	int state_1,state_2;
	int N,a,b,c,d,e,i,j=0,k=0;
	float score[10];
	char arr[2000],name[200];
	FILE* intxt = fopen("Input.txt","r");
	FILE* outtxt = fopen("out.txt","w");
	if (intxt == NULL || outtxt == NULL){
		printf("file open error\n");
		return 1;
	}
	fscanf(intxt,"%d",&N);
	fgets(arr, sizeof(arr), intxt);
	fgets(arr, sizeof(arr), intxt);


    for (i=0;i<N;i++){
    	fscanf(intxt,"%d %d %d %d %d",&a,&b,&c,&d,&e);
    	score[i] = sum_score(a,b,c,d,e);
    	
	}


	for (i=0;i<N;i++){
    	do{
    		if (arr[j]!=' ' && arr[j]!=13){
    			name[k] = arr[j];
    			k+=1;
			}
    		j+=1;
    		
		} while (arr[j]!=' ' && arr[j]!=13);
		k=0;
		fprintf(outtxt,"%s 의 최종 점수는 %.2f\n",name,score[i]);
	}
	
    state_1=fclose(intxt);
    state_2=fclose(outtxt);
	if(state_1 != 0 || state_2 != 0){
		printf("file close error\n");
		return 1;
	}
	return 0;
}
float sum_score(int a,int b,int c,int d,int e){
	return a*0.15 + b*0.4 + c*0.2 + d*0.2 + e*0.05;
}
