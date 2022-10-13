/* operator priorities.c - investigate operator priorities */
/* 
   TO DO 1: Think about the expressions: What will be the output of the programm? 
            ...only then remove the last line und compile/run the program. Were your predictions correct?
   TO DO 2: With your neighbour: Exchange difficult expressions with each other
            - can you solve them without running the program?
            - use brackets to structure the expressions without changing their values
*/

#include <stdio.h>

int main()
{
   int a, b, c, d;
   int result;
   
   a=1; b=2; c=3; d=4;

   result=a-b-c;
   printf("result is %d\n", result);
    
   result=a<<b<<c;
   printf("result is %d\n", result);
   
   result=d/b/b;
   printf("result is %d\n", result);
   
   result=a>b? b>c? a : b : c;
   printf("result is %d\n", result);
    
   
   // don't-compile-this yet - read TO DO's first.
}