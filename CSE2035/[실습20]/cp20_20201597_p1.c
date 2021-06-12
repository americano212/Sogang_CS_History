#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int data;
	struct node* next;
} QUEUE_NODE;

typedef struct{
	QUEUE_NODE* front;
	int count;
	QUEUE_NODE* rear;
} QUEUE;

void Exit(QUEUE* qu){
	QUEUE_NODE* x = malloc(sizeof(QUEUE_NODE));
	QUEUE_NODE* y = malloc(sizeof(QUEUE_NODE));
	y = qu->front;
	while(1){
		x = y;
		if (x->next==NULL){
			free(x);
			break;
		} 
		y = x->next;
		free(x);
	}
}
void Enqueue(QUEUE* qu){
	QUEUE_NODE* arr = malloc(sizeof(QUEUE_NODE));
	int n;
	printf("Input Data > ");
	scanf("%d",&n);
	arr->data = n;
	arr->next = NULL;
	
	if (qu->count==0){
		qu->front = arr;
		qu->rear = arr;
		qu->count += 1;
	}
	else{
		qu->rear->next = arr;
		qu->rear = arr;
		qu->count += 1;
	}
}
void PrintAll(QUEUE qu){
	QUEUE_NODE* x = malloc(sizeof(QUEUE_NODE));
	x = qu.front;
	while(1){
		printf("%d ",x->data);
		if (x->next==NULL) break;
		x = x->next;
	}
	printf("\n");
	printf("Queue Level : %d\n",qu.count);
}

void Dequeue(QUEUE* qu){
	QUEUE_NODE* x = malloc(sizeof(QUEUE_NODE));
	x = qu->front;
	if (qu->count == 1){
		qu->front = NULL;
		qu->rear = NULL;
		qu->count -= 1;
	}
	else{
		qu->front = qu->front->next;
		qu->count -= 1;
	}
	printf("Dequeue %d\n",x->data);
	free(x);
	
}


int main(){
	QUEUE* qu;
	qu = malloc(sizeof(QUEUE));
	qu->count=0;
	qu->front = NULL;
	qu->rear = NULL;
	printf("****** Menu ******\n");
	printf("* 0 : Exit       *\n");
	printf("* 1 : Enqueue    *\n");
	printf("* 2 : Dequeue    *\n");
	printf("* 3 : Print All  *\n");
	printf("******************\n");
	int check;
	while(1){
		printf("Select > ");
		scanf("%d",&check);
		if (check==0){
			Exit(qu);
			return 0;
		}
		if (check==1){
			Enqueue(qu);
		}
		if (check==2){
			Dequeue(qu);
		}
		if (check==3){
			PrintAll(*qu);
		}
	}
}
