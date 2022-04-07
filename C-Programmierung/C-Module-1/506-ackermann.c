// Ackermann: calculate the Ackermann function 
// The mathematical Ackermann function is defined as follows:
//
//    A(m,n) =   n+1              if m=0
//               A(m-1,1)         if m>0 and n=0
//               A(m-1, A(m,n-1)) if m>0 and n>0
//
// TO DO 1: Write a function that calculates the Ackermann function according to the definition above
//          Test the program with very small values first!
// TO DO 2: Extend the function such that it counts the number of functions calls (use a global variable counter)
//          Print the function arguments and current count every x function calls. 
// TO DO 3: Count the amount of recursively called functions (which are not yet completed) and print them as well
// TO DO 4: Use static variables in ackermann for counting rather than global variables.
// TO DO 5: Optional: Visualize the current recursion depth with bars of ascii-characters: xxxxxxxxxxxxxxxxxx
// TO DO 6: Optional: Provide values m and n via the command line
//          Allow in addition the option '-v' (verbose), to switch on output of intermediate results

#include <stdio.h>

int printAckerman(int m, int n, int c1, int c2, int x, int v) {
   if (!v) {
      char str[100];
      for (int i = 0; i < 100; i++) str[i] = c2 > i ? 'x' : 0;
      // system("CLS");
      printf(str);
      printf("\n");
      }
   else if (!(c1 % x)) printf("%i.:  n: %i  m: %i  waiting for %i recursive calls...\n", c1, m, n, c2);
   }

int ackermann(int m, int n, int x, int v) {
   static int total_count = 0;
   static int unreturned_calls_count = 0;
   int res;

   total_count++;
   printAckerman(m, n, total_count, unreturned_calls_count, x, v);
   if (m == 0) {
      res = n + 1;
      }
   else if (n == 0) {
      unreturned_calls_count++;
      res = ackermann(m - 1, 1, x, v);
      unreturned_calls_count--;
      }
   else {
      unreturned_calls_count += 2;
      res = ackermann(m - 1, ackermann(m, n - 1, x, v), x, v);
      unreturned_calls_count -= 2;
      }

   printAckerman(m, n, total_count, unreturned_calls_count, x, v);
   if (unreturned_calls_count == 0) printf("Final function call after %i total calls. Result is: %i", total_count, res);

   return res;
   }

int main(int argc, char* argv[]) {
   int n, m, result, x; m = n = -1;
   int v = 0;

   for (int i = 1; i < argc; i++) {
      if (argv[i][0] == '-') {
         if (argv[i][1] == 'v') v = 1;
         else if (argv[i][1] == 'm' && argv[i][2] == '=') m = 1; // TODO: Figure out a way to convert cli argument to in
         else if (argv[i][1] == 'n' && argv[i][2] == '=') n = 1;
         }
      }

   while (m < 0) {
      printf("Value for m: ");
      scanf("%d", &m);
      }
   while (n < 0) {
      printf("Value for n: ");
      scanf("%d", &n);
      }
   if (v) {
      printf("Print current variables every x times: ");
      scanf("%d", &x);
      }

   result = ackermann(m, n, x, v);
   // printf("Result is: %i", result);
   }