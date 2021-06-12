#include <stdio.h>

typedef struct {
   int numerator;
   int denominator;
} FRACTION;

void getFr(FRACTION* pFr) {
   char tmp;
   printf("Write a fraction in the form of x/y: ");
   scanf("%d", &pFr->numerator);
   scanf("%c", &tmp);
   scanf("%d", &pFr->denominator);
}

int gcd(int a, int b) {
   if (a == 0) return b;
   else if (b == 0) return a;

   if (a % b == 0) return b;
   return gcd(b, a % b);
}

void addFr(FRACTION* pFr1, FRACTION* pFr2, FRACTION* pRes) {
   int x;
   
   pRes->denominator = pFr1->denominator * pFr2->denominator;
   pRes->numerator = pFr1->numerator * pFr2->denominator + pFr1->denominator * pFr2->numerator;
   x = gcd(pRes->denominator, pRes->numerator);
   pRes->numerator /= x; 
   pRes->denominator /= x;
}

void subFr(FRACTION* pFr1, FRACTION* pFr2, FRACTION* pRes) {
   int x;
   
   pRes->denominator = pFr1->denominator * pFr2->denominator;
   pRes->numerator = pFr1->numerator * pFr2->denominator - pFr1->denominator * pFr2->numerator;
   x = gcd(pRes->denominator, pRes->numerator);
   pRes->numerator /= x; 
   pRes->denominator /= x;
}

void mulFr(FRACTION* pFr1, FRACTION* pFr2, FRACTION* pRes) {
   int x;
   
   pRes->denominator = pFr1->denominator * pFr2->denominator;
   pRes->numerator = pFr1->numerator * pFr2->numerator;
   x = gcd(pRes->denominator, pRes->numerator);
   pRes->numerator /= x; 
   pRes->denominator /= x;
}

void divFr(FRACTION* pFr1, FRACTION* pFr2, FRACTION* pRes) {
   int x;
   
   pRes->denominator = pFr1->denominator * pFr2->numerator;
   pRes->numerator = pFr1->numerator * pFr2->denominator;
   x = gcd(pRes->denominator, pRes->numerator);
   pRes->numerator /= x; 
   pRes->denominator /= x;
}

void printFr(FRACTION* pFr1, FRACTION* pFr2, FRACTION* pRes, char op) {
   if (op == '+'){
   		printf("\nThe result of %d/%d + %d/%d is %d/%d\n", pFr1->numerator, pFr1->denominator, pFr2->numerator, pFr2->denominator, pRes->numerator, pRes->denominator);
   }
      
   else if (op == '-'){
   		printf("\nThe result of %d/%d - %d/%d is %d/%d\n", pFr1->numerator, pFr1->denominator, pFr2->numerator, pFr2->denominator, pRes->numerator, pRes->denominator);
   }
      
   else if (op == '*'){
   		printf("\nThe result of %d/%d * %d/%d is %d/%d\n", pFr1->numerator, pFr1->denominator, pFr2->numerator, pFr2->denominator, pRes->numerator, pRes->denominator);
   }
      
   else{
   		printf("\nThe result of %d/%d / %d/%d is %d/%d\n", pFr1->numerator, pFr1->denominator, pFr2->numerator, pFr2->denominator, pRes->numerator, pRes->denominator);
   }
}

int main(void) {
   FRACTION a, b, c;
   getFr(&a); 
   getFr(&b);
   addFr(&a, &b, &c);
   printFr(&a, &b, &c, '+');
   subFr(&a, &b, &c);
   printFr(&a, &b, &c, '-');
   mulFr(&a, &b, &c);
   printFr(&a, &b, &c, '*');
   divFr(&a, &b, &c);
   printFr(&a, &b, &c, '/');
   return 0;
}
