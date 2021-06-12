#include <stdio.h>
#include <stdlib.h>
int* merge(int* ary1,int size1,int* ary2,int size2, int* ary3,int size3);

void swap(int *a, int *b){
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

int main(){
	int *arr,i,*result,*ary1,*ary2,*ary3;
	arr = (int *) calloc(12,sizeof(int));
	result = (int *) calloc(12,sizeof(int));
	ary1 = (int *) calloc(3,sizeof(int));
	ary2 = (int *) calloc(4,sizeof(int));
	ary3 = (int *) calloc(5,sizeof(int));
	printf("Input 12 integer : ");
	for (i=0;i<12;i++){
		scanf("%d",&arr[i]);
	}
	printf("Array 1\t\t: ");
	for (i=0;i<3;i++){
		printf("%d ",arr[i]);
		ary1[i] = arr[i];
	}
	printf("\nArray 2\t\t: ");
	for (i=0;i<4;i++){
		printf("%d ",arr[i+3]);
		ary2[i] = arr[i+3];
	}
	printf("\nArray 3\t\t: ");
	for (i=0;i<5;i++){
		printf("%d ",arr[i+7]);
		ary3[i] = arr[i+7];
	}
	printf("\nresult Array : ");
	result = merge(ary1,3,ary2,4,ary3,5);
	for (i=0;i<12;i++){
		printf("%d ",result[i]);
	}
	printf("\n");
	return 0;
}

int* merge(int* ary1,int size1,int* ary2,int size2, int* ary3,int size3){
	int k,p;
	int i;
	int *ans;
	ans = (int *) calloc(12,sizeof(int));
	for (k=(size1)-1;k>0;k--){
        for (p=0;p<k;p++){
            if ((ary1)[p]>(ary1)[p+1]){
                swap(& (ary1)[p],& (ary1)[p+1]);
            }
        }
    }
    for (k=(size2)-1;k>0;k--){
        for (p=0;p<k;p++){
            if ((ary2)[p]>(ary2)[p+1]){
                swap(& (ary2)[p],& (ary2)[p+1]);
            }
        }
    }
    for (k=(size3)-1;k>0;k--){
        for (p=0;p<k;p++){
            if ((ary3)[p]>(ary3)[p+1]){
                swap(& (ary3)[p],& (ary3)[p+1]);
            }
        }
    }
    int check1=0,check2=0,check3=0;
    for (i=0;i<size1+size2+size3;i++){
    	if (check1==3){
    		ary1[check1] = 2147483647;
		}
		if (check2==4){
    		ary2[check2] = 2147483647;
		}
		if (check3==5){
    		ary3[check3] = 2147483647;
		}
    	if (ary1[check1]<=ary2[check2] && ary1[check1]<=ary3[check3]){
    		ans[i] = ary1[check1];
    		check1+=1;
		}
		else if (ary2[check2]<=ary1[check1] && ary2[check2]<=ary3[check3]){
    		ans[i] = ary2[check2];
    		check2+=1;
		}
		else{
			ans[i] = ary3[check3];
			check3+=1;
		}
	}
	return ans;
}
