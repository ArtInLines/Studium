// hanoi.c Towers of hanoi
// TO DO: Extend the programm such that it creates a graphical output of the disks on the three rods
//        introduce a function display(), which is called from hanoi()
//        Use global or static variables to keep the status of the disk towers.

#include <stdio.h>
#include <stdlib.h>

void hanoi(int n, int start, int goal, int helper) {
   if (n > 0) {
      hanoi(n - 1, start, helper, goal);
      printf("move disk from %d to %d\n", start, goal);
      hanoi(n - 1, helper, goal, start);
      }
   }

int main() {
   int n;
   printf("How many disks? ");
   scanf("%d", &n);

   hanoi(n, 1, 2, 3);

   return EXIT_SUCCESS;
   }