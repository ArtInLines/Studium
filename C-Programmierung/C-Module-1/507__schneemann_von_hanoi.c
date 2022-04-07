// hanoi.c Towers of hanoi
// TO DO: Optional: Extend the programm such that it creates a graphical output of the disks on the three rods
//         introduce a function display(), which is called from hanoi()
//         Use global or static variables to keep the status of the disk towers.

#include <stdio.h>
#include <Windows.h>
#include <time.h>

#define MaxHeight 7

int stack[3][MaxHeight], height[3], n;

char turm[MaxHeight+1][14]={
	   "           ",
       "     _     ",  
       "   _[_]_   ",
       "    (\")    ",
       "   ( : )   ",
       "  (  :  )  ",
       " (   :   ) ",
       "(    :    )",};

void draw_stacks()
{
	int h, s;

	system("CLS");
	for(h=n-1; h>=0; h--) {
		for(s=0; s<3; s++) {
			if(height[s]>h) { 
				printf(turm[stack[s][h]]);
			}
			else printf(turm[0]);
		}
		printf("\n");
	}
}

void hanoi(int n, int start, int goal, int helper)
{
   if(n>0) {
      hanoi(n-1,start,helper,goal);
      stack[goal][height[goal]++]=stack[start][--height[start]];
	  draw_stacks();
	  printf("move disk from %d to %d\n", start, goal);
	  Sleep(500);
      hanoi(n-1,helper,goal,start);
   }
}

int main() 
{
   int i;
   printf("How many disks?");

   scanf("%d", &n);
  
   for(i=0; i<n; i++)
	   stack[0][i]=n-i;
   height[0]=n;
   height[1]=0;
   height[2]=0;

   while(1) {
       hanoi(n, 0, 1, 2);
       Sleep(3000);   // Nur Windows...
	   hanoi(n, 1, 2, 0);
       Sleep(3000);   // Nur Windows...
       hanoi(n, 2, 0, 1);
       Sleep(3000);   // Nur Windows...
   }
}