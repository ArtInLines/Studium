/* ascii_art.c */
/* TO DO 1: Can you explain why a circle is displayed?
   TO DO 2: Play around with the operators to create beautiful ascii art 
            - use different arithmetics
            - use different comparisons
            - use different characters (e.g. more than two) */

#include <stdio.h>
#include <math.h>

int pyramid();
int diagonal();

int main() 
{
   diagonal();
   printf("\n\n\n\n");
   pyramid();
   
   return 0;
   
   int x, y, v;

   for(y=0; y<30; y=y+1) {
      for(x=0; x<30; x=x+1) {
	      v=(pow(x-15, 2)+pow(y-15, 2));          
         if(v>60) printf(" ");
         else printf("o");
      }
      printf("\n");
   }
}

int diagonal() {
   int x, y, v;
   int width = 40;
   int height = 20;
   
   for (y=0; y<height; y++) {
      for (x=0; x<width; x++) {
         v=x+2*y;
         if (v<width || v<2*height) printf(" ");
         else printf("/");
      }
      printf("\n");
   }
}

int pyramid() {
   int x, y, v;
   
   for (y=0; y<16; y++) {
      for (x=0; x<30; x++) {
         v=pow(x-15, 2) - pow(y, 2);
         if(v<=0) printf("o");
         else printf(" ");
      }
      printf("\n");
   }
}
