#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node{
	char command[10];
	struct node* next;
} QUEUE_NODE;

typedef struct{
	QUEUE_NODE* front;
	int count;
	QUEUE_NODE* rear;
} QUEUE;

int CheckCommand(char* command){
	if (strcmp(command,"help")==0 || strcmp(command,"dir")==0 || strcmp(command,"mkdir")==0 || strcmp(command,"cd")==0 || strcmp(command,"history")==0 || strcmp(command,"h")==0 || strcmp(command,"quit")==0 || strcmp(command,"q")==0){
		return 1;
	}
	return 0;
}

void EnqueueCommand(QUEUE* pQueue, char* dataIn){
	QUEUE_NODE* x = malloc(sizeof(QUEUE_NODE));
	strcpy(x->command, dataIn);
	x->next = NULL;
	if (pQueue->count==0){
		pQueue->front = x;
		pQueue->rear = x;
	}
	else{
		pQueue->rear->next = x;
		pQueue->rear = x;
	}
	pQueue->count++;
}

int DequeuePrint(QUEUE* pQueue, char* dataOut){
	if (pQueue->count == 0) return 0;
	QUEUE_NODE* x = malloc(sizeof(QUEUE_NODE));
	x = pQueue->front;
	strcpy(dataOut, x->command);
	pQueue->front = x->next;
	pQueue->count--;
	free(x);
	return 1;
}

int main(){
	char command[10];
	QUEUE* pQueue;
	pQueue = (QUEUE*)malloc(sizeof(QUEUE));
	char output[10];
	pQueue->front = NULL;
	pQueue->count = 0;
	pQueue->rear = NULL;
	while(1){
		printf(">>");
		scanf("%s",command);
		if (strcmp(command,"history")==0 || strcmp(command,"h")==0){
			while(1){
				if (DequeuePrint(pQueue,output)==0) break;
				printf(output);
				printf("\n");
			}
			EnqueueCommand(pQueue,command);
		}
		
		else if (strcmp(command,"quit")==0 || strcmp(command,"q")==0){
			while(1){
				if (DequeuePrint(pQueue,output)==0) break;
			}
			break;
		}
		else{
			if (CheckCommand(command)){
				printf("[Valid] %s\n",command);
				EnqueueCommand(pQueue,command);
			}
			else{
				printf("[Invalid]\n");
			}
		}
		
	}
	return 0;
}
