// hanoi.c Towers of hanoi
// TO DO: Optional: Extend the programm such that it creates a graphical output of the disks on the three rods
//         introduce a function display(), which is called from hanoi()
//         Use global or static variables to keep the status of the disk towers.

#include <stdio.h>
#include <stdlib.h>

int stack[3][20], height[3];

void draw_stacks(int n)
{
	int h, s;

	system("CLS");
	for(h=n-1; h>=0; h--) {
		for(s=0; s<3; s++) {
			if(h<height[s]) { 
				printf("           "+stack[s][h]);
				printf("AAAAAAAAAAAAAAAA"+17-stack[s][h]*2);
				printf("           "+stack[s][h]);
			}
			else printf("                     ");
		}
		printf("\n");
	}
	for(h=0; h<1000000; h++);
}

void hanoi(int n, int start, int goal, int helper)
{
   if(n>0) {
      hanoi(n-1,start,helper,goal);
      printf("move disk from %d to %d\n", start, goal);
	  stack[goal][height[goal]++]=stack[start][--height[start]];
	  draw_stacks(n);
      hanoi(n-1,helper,goal,start);
   }
}

int main() 
{
   int i, n;

   printf("How many disks? (1-8)");
   scanf("%d", &n);
  
   for(i=0; i<n; i++)
	   stack[0][i]=n-i;
   height[0]=n;
   height[1]=height[2]=0;

   hanoi(n, 0, 1, 2);
   getchar();
}