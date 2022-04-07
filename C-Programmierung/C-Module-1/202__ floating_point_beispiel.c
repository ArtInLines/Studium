/* floating_point.c Investigate the precision and borders of floating point numbers */
// TO DO 1: The program doesn't seem to stop. Maybe f and d should be increased faster? 
// TO DO 2: How does the 'limit behaviour' differ from integer numbers? 
// TO DO 3: Insert a comparison to check when the float and double values are different from each other 
//          print the difference

#include <stdio.h>

int main() {
   float f, old_f;
   double d, old_d, old_old_d;
   char show_float=1;
   
   f=d=1.;

   while(1) {   
      old_f=f;
      old_old_d=old_d; old_d=d;  
      f=f+1; 
	  d=(d+1)*(1.000005+20/d);  // play around with non-linear growth...

      if(old_f>=f && show_float) {
          printf("float limit (with precision 1) %f -> %f \n", old_f, f);
          show_float=0;
      }	  
	     
      if(old_d>=d) { 
          printf("double limit %lf -> %lf \n", old_old_d, old_d);
          break; /* exit from while-loop  */
      }

      // Also try: use identical counting f=f+1 and d=d+1 
      // and print if f and d have different values 
	  // if(f != d) printf("different precision %f %lf %lf \n", f, d, f-d);			  
   }
   getchar();     // Wait for key to avoid immediate closing of console
}
