#include <stdio.h>
int power(int N,int r);
int main(void){
	int state_1,state_2,Max,temp_Max=1;
	int bucket[10][100]={0,},check[10]={0,};
	int arr[100],i=0,N,count=0,j,where,x,y;
	FILE* intxt = fopen("input.txt","r");
	FILE* outtxt = fopen("output.txt","w");
	
	if (intxt == NULL || outtxt == NULL){
		printf("file open error\n");
		return 1;
	}
	
	while(!feof(intxt)){
		fscanf(intxt,"%d ",&N);
		arr[i] = N;
		while(1){
			N = N/10;
			if (N==0){
				if (temp_Max>Max){
					Max = temp_Max;
				}
				temp_Max=1;
				break;
			} 
			temp_Max+=1;
		}
		i++;
		count+=1;
	}
	
	for (j=0;j<count;j++){
		where = (arr[j]%power(10,1)-arr[j]%power(10,0))/power(10,0);
		bucket[where][check[where]]=arr[j];
		check[where] +=1;
	}
	
	int z;
	for (z=2;z<Max+1;z++){
		int temp_check[10]={0,}, temp_bucket[10][100]={0,};
		for (x=0;x<10;x++){
			for (y=0;y<100;y++){
				if (check[x]>0){
					where = (bucket[x][y]%power(10,z)-bucket[x][y]%power(10,z-1))/power(10,z-1);
				
					temp_bucket[where][temp_check[where]]=bucket[x][y];
					temp_check[where]+=1;
					check[x] -= 1;
				}

			}
		}
		
		for (i=0;i<100;i++){
			for (j=0;j<10;j++){
				bucket[j][i]=temp_bucket[j][i];
			}
		}
		for (i=0;i<10;i++){
			check[i]=temp_check[i];
		}
	}
	
	for (i=0;i<10;i++){
		for (j=0;j<100;j++){
			if (check[i]>0){
				fprintf(outtxt,"%d ",bucket[i][j]);
				check[i]--;
			}

		}
	}
	
	state_1=fclose(intxt);
    state_2=fclose(outtxt);
	if(state_1 != 0 || state_2 != 0){
		printf("file close error\n");
		return 1;
	}
	return 0;
}

int power(int N,int r){
	int i,result=1;
	for (i=0;i<r;i++){
		result *= N;
	}
	return result;
}

