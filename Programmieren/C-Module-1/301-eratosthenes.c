/* prime sieve of Eratosthenes */
// TO DO 1: The program seems to work, but look carefully at the results -> There is a (typical) bug
// TO DO 2: Extend it such that the maximum number n to be calculated can be entered by the user
//          Use scanf("%d", &n)
// TO DO 3: What does this mean for the array? How should the program be adapted to work reliably? 

#include <stdio.h>

int main()
{
   unsigned int n;
   printf("Choose a maximum number: ");
   scanf("%d",&n);
   const int Max = n;
   char is_prime[Max];   // For full compatibility (C89, C90, C11) Array size has to be a constant!
   int i, j;
   
   /* Initialize Array */
   for(i=0; i<=Max; i++) 
      is_prime[i]=1;
	   
   for(i=2; i<Max; i++)  
      for(j=2*i; j<Max; j=j+i)
         is_prime[j] = 0;

   printf("Prime numbers are: ");
   for(i=2; i<=Max; i++)
      if(is_prime[i]>0)
         printf("%d ",i);  
}