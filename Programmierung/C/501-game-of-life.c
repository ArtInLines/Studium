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

// DONE: Complete the programm such that it simulates the game of life. 
//        Do this as teamwork (e.g. in teams with 2 or 3) 
//        and benefit from the fact the functions can developed separately and then integrated into the final program.
// TODO optional 1: extend the program, such that it detects 'stable states', i.e. the system is oscillating between a few states. 
// TODO optional 2: let the program find a start state such that the system stays alive and unstable for as long as possible
// DONE optional 3: Create a flicker-free output: Do not print each character separately, but write the output into a string, which is printed all at once
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
void initialize_cells(int div) {
   int i, j;
   srand(time(NULL));
   for (i = 0; i < HEIGHT; i++) for (j = 0; j < LENGTH; j++) cells[i][j] = rand() % div ? 0 : 1;
   }


// TO DO: Write output function to show the cells 
void display_cells(char cell_char) {
   int i, j;
   char out[HEIGHT * LENGTH + HEIGHT + 1];
   for (i = 0; i < HEIGHT; i++) {
      for (j = 0; j < LENGTH; j++) {
         if (!cells[i][j]) out[LENGTH * i + j] = ' ';
         else out[LENGTH * i + j] = cell_char;
         }
      out[LENGTH * (i + 1) - 1] = '\n';
      }
   out[HEIGHT * LENGTH + HEIGHT + 1] = 0;
   system("CLS"); // Clear screen - works (at least) on windows console.
   printf(out);
   }


// TO DO: Write a function to calculate the next evolution step
void evolution_step(int hard_border) {
   // TO DO: Use this array for the calculation of the next step
   char cells_helper[HEIGHT][LENGTH];
   int i, j, neighbours_count;

   // DEBUG:
   for (i = 0; i < HEIGHT; i++) {
      for (j = 0; j < LENGTH; j++) {
         // Get neighbour cells
         if (hard_border) {
            // If there is no cells on one side, it will default to 0 (to simulate that there is no cell)
            neighbours_count = i > 0 ? cells[i - 1][j] : 0;
            neighbours_count += j < LENGTH - 1 ? cells[i][j + 1] : 0;
            neighbours_count += i < HEIGHT - 1 ? cells[i + 1][j] : 0;
            neighbours_count += j > 0 ? cells[i][j - 1] : 0;
            }
         else neighbours_count = cells[(HEIGHT + i - 1) % HEIGHT][j] + cells[(i + 1) % HEIGHT][j] + cells[i][(LENGTH + j - 1) % LENGTH] + cells[i][(j + 1) % LENGTH];

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
int main(int argc, char* argv[]) {
   // for (int i = 1; i < argc; i++) printf("%s\n", argv[i]);
   const int hard_border = argc > 1 && argv[1][0] == '-' && argv[1][1] == 'y' ? 1 : 0;
   const char cell_char = argc > 2 ? argv[2][1] : argc > 1 && !hard_border ? argv[1][1] : '+';

   const int div = 5;


   // printf("hard border: %i\n", hard_border);

   initialize_cells(5);

   while (1) {
      display_cells(cell_char);

      // Leave loop if there are no more occupied cells
      if (count_cells() == 0) break;

      printf("Press enter");
      getchar();

      evolution_step(hard_border);

      // printf("\n\n\n");
      // display_cells();
      }
   }