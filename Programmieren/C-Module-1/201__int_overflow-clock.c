/* check_int_overflow.c Check when integer numbers are overflowing */
// TO DO 1: complete the overflow detecion for other types 
// TO DO 2: extend this to unsigned integers 
// TO DO 3: stop counting after first overflow 
// TO DO 4: estimate how many operations are performed per second.
// TO DO 5 (optional): Use this program as benchmark for your CPU performance and compare it with other students' computers,
// TO DO 6 (optional): Check the CPU load when running the programm. What do you observe? 

#include <stdio.h>
#include <time.h>

int main() 
{
   char c, old_c;
   short s, old_s;
   int i, old_i;
   long l, old_l;
   int done=0;

   clock_t t1, t2;

   c=s=i=l=0;

   t1=clock();

   while(done<4) {   
      old_c=c; old_s=s; old_i=i; old_l=l;
      c=c+1; s=s+1; i=i+1; l=l+1;
      if(old_c>c && done<1) { printf("char  overflow %d -> %d \n", old_c, c); done=1; }
      if(old_s>s && done<2) { printf("short overflow %d -> %d \n", old_s, s); done=2; }
      if(old_i>i && done<3) { printf("int   overflow %d -> %d \n", old_i, i); done=3; }
      if(old_l>l && done<4) { printf("long overflow %ld -> %ld \n", old_l, l); done=4; }
   }
    t2=clock();

   printf("%g seconds\n", (double)(t2-t1) / CLOCKS_PER_SEC);
	getchar();
}
