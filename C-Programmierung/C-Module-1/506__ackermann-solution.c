// Ackermann: calculate the Ackermann function 
// The mathematical Ackermann function is defined as follows:
//
//    A(m,n) =   n+1              if m=0
//               A(m-1,1)         if m>0 and n==0
//               A(m-1, A(m,n-1)) if m>0 and n>0
//
// TO DO 1: Write a function that calculates the Ackermann function according to the definition above
// TO DO 2: Extend the function such that it counts the number of functions calls (use a global variable counter)
//          Print the function arguments and current count every x function calls. 
// TO DO 3: Count the amount of recursively called functions (which are not yet completed) and print them as well
// TO DO 4: Use static variables in ackermann for counting rather than global variables.
// TO DO 5: Optional: Visualize the current recursion depth with bars of ascii-characters: xxxxxxxxxxxxxxxxxx
// TO DO 6: Optional: Provide values m and n via the command line
//          Allow in addition the option '-v' (verbose), to switch on output of intermediate results

#include <stdio.h>

int ackermann(int m, int n)
{
   static long cnt=0;
   static long ackermaenner=0; 
   int v;

   cnt++;   
   ackermaenner++;
   if(cnt%5000000==0)
       printf("%ld Rechenschritte, %ld Ackermaenner, m=%d, n=%d\n", cnt, ackermaenner, m, n);
   
   if(m==0) v=n+1;
   else if(n==0) v=ackermann(m-1,1);
   else v=ackermann(m-1, ackermann(m,n-1));
   ackermaenner--;

   if(ackermaenner==0)
       printf("Ende: %ld Rechenschritte\n", cnt);

   return v;
}

int main( )
{

   // TODO: Übergabe der Werte über Kommandozeile
   // -v = verbose Ausgabe
   int n, m, result;

   printf("Value for m: ");
   scanf("%d", &m);
   printf("Value for n: ");
   scanf("%d", &n);

   result=ackermann(m,n);
   printf("Result=%d", result);
}