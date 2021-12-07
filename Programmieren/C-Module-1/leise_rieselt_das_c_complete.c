/* Leise rieselt das C! */ 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h>


#define SizeX 70
#define SizeY 30
#define FlockenCnt 100

int main() 
{
   char buf[SizeY*(SizeX+2)+1];
   int flocken[FlockenCnt][2];
   int level[SizeX];
   int x, y, i, cnt=0, sx=30, sy=SizeY-1;
   int txt=0;
   char snowman[5][10]={
       "    _    ",  
       "  _[_]_  ",
       "   (\")   ",
       "  ( : )  ",
       " (  :  ) " };
   char codes[5]={ 32, '_', 220, 178, 219 };

   int cursor=0;

   for(i=0; i<FlockenCnt; i++) {
	   flocken[i][0]=rand()%SizeX;
	   flocken[i][1]=rand()%SizeY;
   }
   for(x=0; x<SizeX; x++)
	   level[x]=0;

   // Endlosschleife
   while(1) {
      cursor=0;
      for(y = 0; y<SizeY; y++) {
         for(x = 0; x<SizeX; x++)
             buf[cursor++]=' ';  
         buf[cursor++]=10;
         buf[cursor++]=13;
      }
      buf[cursor]=0;

      for(i=0; i<FlockenCnt; i++) {
         buf[flocken[i][0]+(SizeX+2)*flocken[i][1]]='c'; // 248;
         flocken[i][1]=(flocken[i][1]+1)%SizeY;
         if(i>FlockenCnt*1/3) 
             flocken[i][0]=(flocken[i][0]+1)%SizeX;
         else if(i>FlockenCnt*2/3 && !(cnt&1))
             flocken[i][0]=(flocken[i][0]+SizeX-1)%SizeX;
         if(flocken[i][1]==SizeY-1) {
             level[flocken[i][0]]++;
             flocken[i][0]=rand()%SizeX;
         }
      }

      for(x = 0; x<SizeX; x++) {
         for(y = 0; y<level[x]/4; y++)
             buf[x+(SizeY-1-y)*(SizeX+2)]=codes[4];  
         buf[x+(SizeY-1-level[x]/4)*(SizeX+2)]=codes[level[x]%4];
      }

      sy=(level[sx]+level[sx+1]+level[sx-1])/12;
	  for(y=0; y<5; y++)
         for(x=0; x<9; x++)
            buf[sx-4+x+(-sy+SizeY-5+y)*(SizeX+2)]=snowman[y][x];
  
	  txt=(txt+1)%120;
	  memcpy(buf+2+(SizeX+2)*5,"Leise rieselt das C",txt<19? txt : 19); 
	  if(txt>50)
	  memcpy(buf+2+(SizeX+2)*7,"still und klar codiert tut's nicht weh...",txt-50<41? txt-50: 41); 
      system("CLS");
      printf(buf);
      cnt++;
      Sleep(200);
   }
}
