/* Leise rieselt das C ! */

#include <stdio.h>
#include <stdlib.h>

#define SizeX 70
#define SizeY 40

int main() 
{
   char buf[SizeY*(SizeX+2)+1];
   int flocken[100][2]; 
   int x, y, flockenCnt=100, i, level=50;

   int cursor=0;

   for(i=0; i<flockenCnt; i++) {
	   flocken[i][0]=rand()%SizeX;
	   flocken[i][1]=rand()%SizeY;
   }

   while(1) {
      cursor=0;
      for(y = 0; y<SizeY-level/100; y++) {
         for(x = 0; x<SizeX; x++)
            buf[cursor++]=' ';  
		 buf[cursor++]=10;
		 buf[cursor++]=13;
      }
      buf[cursor]=0;

      for(i=0; i<flockenCnt; i++) {
         buf[flocken[i][0]+(SizeX+2)*flocken[i][1]]='*';
         flocken[i][1]=(flocken[i][1]+1)%SizeY;
         if(i>flockenCnt*3/4) {
            if(!(level%2))
               flocken[i][0]=(flocken[i][0]+1)%SizeX;
         }
         else if(i>flockenCnt/2 && !(level%2))
            flocken[i][0]=(flocken[i][0]+SizeX-1)%SizeX;
      }
      system("CLS");
      printf(buf);
      level++;
      for(i=0; i<20000000; i++);
   }
}
