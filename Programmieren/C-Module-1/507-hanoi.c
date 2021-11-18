// hanoi.c Towers of hanoi
// TO DO: Extend the programm such that it creates a graphical output of the disks on the three rods
//        introduce a function display(), which is called from hanoi()
//        Use global or static variables to keep the status of the disk towers.

#include <stdio.h>
#include <stdlib.h>

// This Array stores always the lowest and highest disk-size for each rod
// This works, because hanoi() will never put a disk on another that isn't exactly one size higher
int rods[3][2] = { 0 };

void display(/* int disk, int start, int goal */) {
   static char res[24][25] = { 0 };
   static int rod_width = 24 / 3;
   int current_rod = 0;
   int disk_size = 0;
   int disk_amount = 0;

   for (int i = 0; i < 24; i++) {
      for (int j = 0; j < 24; j++) {
         current_rod = (j - (j % rod_width)) / rod_width;
         disk_amount = rods[current_rod][1] - rods[current_rod][0];

         disk_size = disk_amount + i - 24;
         if (disk_size >= 0) disk_size = rods[current_rod][0] + disk_size;

         printf("i: %i, j: %i, current_rod: %i, disk_size: %i, disk_amount: %i\n\n", i, j, current_rod, disk_size, disk_amount);

         if ((j % 4) * (-1) < disk_size) res[i][j] = '#';
         else if (j % 4 == 0 && j % 8 != 0) res[i][j] = '|';
         }
      res[i][25] = '\n';
      }
   res[24][25] = 0;

   printf("\n\n\n\n\n\n");
   // printf(res);
   }

void move_disk(int start, int goal) {
   start--; goal--; // Index starts at 0, but paremeters are entered at index-start at 1
   int current_disk = rods[start][0]; // Store the disk size only for display()

   for (int i = 0; i < 3; i++) printf("%i. Rod: %i - %i\n", i, rods[i][0], rods[i][1]);
   printf("\n\n");

   // Only one disk is on the starting rod -> No disk remains
   if (rods[start][0] == rods[start][1]) rods[start][0] = rods[start][1] = 0;
   // Otherwise -> The top disk on the rod must be one size higher than the last one
   else rods[start][0]++;

   if (rods[goal][1] == 0) { rods[goal][0]++; rods[goal][1]++; }
   else rods[goal][0]--;

   // display();

   for (int i = 0; i < 3; i++) printf("%i. Rod: %i - %i\n", i, rods[i][0], rods[i][1]);
   _sleep(/* 1000 * */ 100);
   }

void hanoi(int n, int start, int goal) {
   int helper = 3 - start - goal;
   if (n > 0) {
      move_disk(start, helper);
      hanoi(n - 1, start, helper);
      // printf("move disk from %d to %d\n", start, goal);
      move_disk(helper, goal);
      hanoi(n - 1, helper, goal);
      }
   }

int main() {
   int n;
   printf("How many disks? ");
   scanf("%d", &n);

   rods[0][0] = 1;
   rods[0][1] = n;

   hanoi(n, 1, 2);

   return EXIT_SUCCESS;
   }