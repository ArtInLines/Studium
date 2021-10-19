/* ascii_table.c Draw a table of all asci characters */
/* TO DO 1: Extend the program to suppress special characters which derange the table 
   TO DO 2: Find out, which ASCII character is the beep 
            and (OPTIONAL...:) write a program which produces 'beep-music' 
            (use large loops to produce pauses between beeps.) */

#include <stdio.h>

int main()
{
   int i, j;
   unsigned char c;
   for(i = 0; i<256; i+=16) 
   {
      printf("%3d ",i);  
      for(j = 0; j<16; j++) {
         c=i+j;
         
         printf("%c",c);
      }
      printf("\n");
   }
   getchar();
}


