/* Game of life
@author Valentin, Jakob, Marek, Leo, Yan
The "game of life" is an old and very simple approach of simulating evolution
A 2-dimensional field of cells is regarded with a cell being either empty/dead (0) or occupied/alive (1)
The intial state can be chosen e.g. manually or using some random operations.

The further evolution is governed by the following rules:

Every cell interacts with its eight neighbours, which are the cells that are directly horizontally, vertically, or diagonally adjacent.
At each step in time, the following transitions occur:
   1. Any live cell with fewer than two live neighbours dies, as if by needs caused by underpopulation.
   2. Any live cell with more than three live neighbours dies, as if by overcrowding.
   3. Any live cell with two or three live neighbours lives, unchanged, to the next generation.
   4. Any empty/dead cell with exactly three live neighbours cells will be populated with a living cell.

The initial pattern constitutes the 'seed' of the system. The first generation is created by applying the above rules simultaneously to every cell in the seed � births and deaths happen simultaneously, and the discrete moment at which this happens is sometimes called a tick. (In other words, each generation is a pure function of the one before.)  The rules continue to be applied repeatedly to create further generations.

see: http://en.wikipedia.org/wiki/Conway's_Game_of_Life
*/

// TO DO: Complete the programm such that it simulates the game of life. 
//        Do this as teamwork (e.g. in teams with 2 or 3) 
//        and benefit from the fact the functions can developed separately and then integrated into the final program.
// TODO optional 1: extend the program, such that it detects 'stable states', i.e. the system is oscillating between a few states. 
// TODO optional 2: let the program find a start state such that the system stays alive and unstable for as long as possible
// TODO optional 3: Create a flicker-free output: Do not print each character separately, but write the output into a string, which is printed all at once
// TODO optional 4: extend the program such that the content of the cells can be edited by the user. 

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>

#define HEIGHT 30
#define LENGTH 50

// Global 2-dim-array which contains the cells
char cells[HEIGHT][LENGTH];


// TO DO: initialize cells, set most to 0, some to 1 
void initialize_cells() {
   int i, j;
   srand(time(NULL));
   for (i = 0; i < HEIGHT; i++) {
      for (j = 0; j < LENGTH; j++) {
         if (rand() % 8) cells[i][j] = 0;
         else cells[i][j] = 1;
         }
      }
   }


// TO DO: Write output function to show the cells 
void display_cells() {
   int i, j;
   char out[HEIGHT * LENGTH + HEIGHT + 1];
   system("CLS"); // Clear screen - works (at least) on windows console.
   for (i = 0; i < HEIGHT; i++) {
      for (j = 0; j < LENGTH; j++) {
         if (!cells[i][j]) out[LENGTH * i + j] = ' ';
         else out[LENGTH * i + j] = '+';
         }
      out[LENGTH * (i + 1) - 1] = '\n';
      }
   printf("%s", out);
   }


// TO DO: Write a function to calculate the next evolution step
void evolution_step() {
   // TO DO: Use this array for the calculation of the next step
   char cells_helper[HEIGHT][LENGTH];
   int i, j, neighbours_count;

   // DEBUG:
   for (i = 0; i < HEIGHT; i++) {
      for (j = 0; j < LENGTH; j++) {
         // Get neighbour cells
         // If there is no cells on one side, it will default to 0 (to simulate that there is no cell)
         neighbours_count = i > 0 ? cells[i - 1][j] : 0;
         neighbours_count += j < LENGTH - 1 ? cells[i][j + 1] : 0;
         neighbours_count += i < HEIGHT - 1 ? cells[i + 1][j] : 0;
         neighbours_count += j > 0 ? cells[i][j - 1] : 0;

         // The usage of cells_helper assumes that every cell is supposed t be evaluated at the same time
         // Otherwise, cells_helper could practically be removed and replaced with cells
         if (cells[i][j]) {
            if (neighbours_count < 2 || neighbours_count > 3) cells_helper[i][j] = 0;
            else cells_helper[i][j] = 1;
            }
         else if (neighbours_count >= 3) cells_helper[i][j] = 1;
         else cells_helper[i][j] = 0;
         }
      }

   for (i = 0; i < HEIGHT; i++) for (j = 0; j < LENGTH; j++) cells[i][j] = cells_helper[i][j];
   }


// TO DO: Write a function that counts the occupied cells
int count_cells() {
   int count = 0, i, j;
   for (i = 0; i < HEIGHT; i++) for (j = 0; j < LENGTH; j++) count += cells[i][j];
   return count;
   }


// Main program
int main() {
   initialize_cells();

   while (1) {
      display_cells();

      // Leave loop if there are no more occupied cells
      if (count_cells() == 0) break;

      printf("Press enter");
      getchar();

      evolution_step();
      }
   }