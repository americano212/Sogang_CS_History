#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct node* nptr;

typedef struct {
   int count;
   nptr link;
}STACK;


typedef struct node {
   int data;
   nptr link;
} STACK_NODE;

void Push(STACK *stk, char c) {
   STACK_NODE* arr = malloc(sizeof(STACK_NODE));
   arr->link = stk->link;
   arr->data = c;
   stk->link = arr;
   stk->count++;
}


int Pop(STACK *stk, char c) {
   if (stk->link == NULL) {
      return -1;
   }
   STACK_NODE* x = stk;
   while (1) {
      if (x->link->link == NULL) break;
      x = x->link;
   }
   free(x->link);
   x->link = NULL;
}

int main() {
   char s[101];
   STACK* pStack;
   pStack = malloc(sizeof(STACK));
   pStack->link = NULL;
   pStack->count = 0;
   scanf("%s", s);
   int i;
   for (i = 0; i<strlen(s); i++) {
      if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
         Push(pStack, s[i]);
      }
      else if (s[i] == ')' || s[i] == ']' || s[i] == '}') {
         if (Pop(pStack, s[i])<0) {
            printf("Unmatched Parentheses!\n");
            return 0;
         }
      }
   }
   if (Pop(pStack, s[i])<0) {
      printf("Matched Parentheses!\n");
   }
   else {
      printf("Unmatched Parentheses!\n");
   }
}
