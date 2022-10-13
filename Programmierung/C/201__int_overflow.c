/* check_int_overflow.c Check when integer numbers are overflowing */
// TO DO 1: complete the overflow detecion for other types 
// TO DO 2: extend this to unsigned integers 
// TO DO 3: stop counting after first overflow 
// TO DO 4: estimate how many operations are performed per second.
// TO DO 5 (optional): Use this program as benchmark for your CPU performance and compare it with other students' computers,
// TO DO 6 (optional): Check the CPU load when running the programm. What do you observe? 

#include <stdio.h>

int main() {
   char c, old_c;
   short s, old_s;
   int i, old_i;
   long l, old_l;

   c=s=i=l=0;

   while(1) {   
      old_c=c; old_s=s; old_i=i; old_l=l;
      c++; s++; i++; l++;
      if(old_c>c) printf("char  overflow %d -> %d \n", old_c, c);
      if(old_s>s) printf("short overflow %d -> %d \n", old_s, s);
      if(old_i>i) printf("int   overflow %d -> %d \n", old_i, i);
      if(old_l>l) printf("long  overflow %ld -> %ld \n", old_l, l);
   }
}
