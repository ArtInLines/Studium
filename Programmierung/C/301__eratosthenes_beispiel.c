/* prime sieve of Eratosthenes */

#include <stdio.h>

int main()
{
	char is_prime[1000];
    int max, i, j;
	
    printf("Calculate prim number up to?");
    scanf("%d", &max);

    if(max>=1000)
    {
        printf("Warning: Upper bound is set to 999.\n");
        max=999;
    }

    /* Initialize Array */    
    for(i=0; i<=max; i=i+1) 
        is_prime[i]=1;
	
    for (i = 2; i <= max; ++i)  {
        for (j= 2*i; j <= max; j=j+i)
            is_prime[j] = 0;
    }

    printf("Prime numbers are:\n");
    for(i=1; i<=max; i++)
        if(is_prime[i]>0)
            printf("%d ",i);
    printf("\n");
}