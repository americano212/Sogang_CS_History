#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 10000000
#include <time.h>
#define MAX_ELEMENTS 1000001
#define HEAP_FULL(n) (n == MAX_ELEMENTS-1)
#define HEAP_EMPTY(n) (!n)

int heap[MAX_ELEMENTS];
int heap2[MAX_ELEMENTS];
int n = 0;

void insert_max_heap(int item, int *n){
	int i;
	if(HEAP_FULL(*n)){
		fprintf(stderr,"The heap is full.\n");
		exit(1);
	}
	i = ++(*n);
	while((i != 1) && (item > heap[i/2])) {
		heap[i] = heap[i/2];
		i /= 2;
	}
	heap[i] = item;
}

int delete_max_heap(int *n){
	int parent, child;
	int item, temp;
	if (HEAP_EMPTY(*n)){
		fprintf(stderr,"The heap is empty.\n");
		exit(1);
	}
	item = heap[1];
	temp = heap[(*n)--];
	parent = 1;
	child = 2;
	while(child <= *n){
		if((child < *n) && (heap[child] < heap[child+1])){
			child++;
		}
		if(temp >= heap[child]) break;
		heap[parent] = heap[child];
		parent = child;
		child *= 2;
		
	}
	heap[parent] = temp;
	return item;
}
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
void heapify(int L[], int current, int size) {
    int left = current * 2 + 1;
    int right = current * 2 + 2;
    int max=current;
    if (left<size&&L[left]>L[max])
        max = left;
    if (right < size&&L[right]>L[max])
        max = right;
 
    if (max != current) {
        swap(&L[current], &L[max]);
        heapify(L, max, size);
    }
}

void buildHeap(int L[], int size) {
    int i,j;
    for (i = size / 2 - 1; i >= 0; i--) {
        heapify(L, i, size);
    }
}
void heapSort(int L[],int size) {
    int tS;
    buildHeap(L, size);
    for (tS = size - 1; tS >= 0; tS--) {
        swap(&L[0], &L[tS]);
        heapify(L, 0,tS);
    }
}
int main(int argc, char *argv[]){
	if (argv[1]==NULL){
		printf("The input file does not exist.\n");
		return 1;
	}
	FILE* in_f = fopen(argv[1], "r");
	//FILE* in_f = fopen("input.txt", "r");
	
	FILE* out_f = fopen("hw2_result.txt", "w");
	clock_t start, finish;
	double duration;
	char line[255];
	char number[10];
	int p;
	int j;
	int nb;
	start = clock();
	while(fgets(line, sizeof(line), in_f) != NULL){
		memset(number,0,sizeof(char)*10);
		if (line[0]=='I'){
			for (j=7;;j++){
				if (line[j]=='\n') break;
				number[j-7] = line[j];
			}
			nb = atoi(number);
			p = nb;
			insert_max_heap(p,&n);
		}
		if (line[0]=='A'){
			
			int i;
			for(i=0;i<n;i++){
				heap2[i] = heap[i+1];
			}
			heapSort(heap2, n);
			for (i=0;i<n;i++){
				fprintf(out_f,"%d ",heap2[i]);
			}
			fprintf(out_f,"\n");
			
		}
		if (line[0]=='D'){
			int i;
			for(i=0;i<n;i++){
				heap2[i] = heap[i+1];
			}
			heapSort(heap2, n);
			for (i=n-1;i>=0;i--){
				fprintf(out_f,"%d ",heap2[i]);
			}
			fprintf(out_f,"\n");
		}
	}
	finish = clock();
	duration = (double)(finish-start)/100000;
	printf("output written to hw2_result.txt.\n");
	printf("running time: %f seconds\n",duration);
	return 0;
}
