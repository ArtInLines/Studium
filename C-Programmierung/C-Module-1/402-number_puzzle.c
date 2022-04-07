/* number_puzzle.c
  Write a number puzzle program by completing the TO DOs
  TO DO 1: Initialize the puzzle, such that the numbers 1 to 15 are randomly distributed in the array.
           -1 should mark the empty field.
  TO DO 2: get key and move pieces accordingly (if keystroke is valid)
  TO DO 3: Check, if puzzle is in correct order -> set sorted=1
  TO DO 4: Create a more fancy output, e.g. by creating frames around the numbers
               (Use a special character e.g. a block rather than '*')
               (Also, mark the empty field rather than showing -1)

           *********************
           *  1 *  2 *  3 *  4 *
           *********************
           *  5 *  6 *  7 *  8 *
           *********************
           *  9 * 10 * 11 * 12 *
           *********************
           * 13 * 14 * 15 ******
           *********************

  TO DO 5, optional: created an automatic, intelligent puzzle solver, which solves the puzzle without user interaction.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
   int puzzle[4][4];
   char key;            // This holds the current key entered by the player.
   char sorted = 0;       // This flag marks, if the field is sorted.  
   int i, j, p, q, empty = 15, tmp;

   srand(time(NULL));


   /* Fill and Shuffle Array */
   for (i = 0; i < 4; i++) for (j = 0; j < 4; j++) puzzle[i][j] = ((i * 4 + j + 1) == 16 ? -1 : (i * 4 + j + 1));
   for (i = 0; i < 4; i++) {
      for (j = 0; j < 4; j++) {
         p = rand() % 4; q = rand() % 4;
         tmp = puzzle[i][j];
         puzzle[i][j] = puzzle[p][q];
         puzzle[p][q] = tmp;

         if (puzzle[i][j] == -1) empty = i * 4 + j;
         else if (puzzle[p][q] == 1) empty = p * 4 + q;
         }
      }


   /* Loop until player won the game */
   while (!sorted) {
      /* Print Output */
      for (i = 0; i < 4; i++) {
         for (j = 0; j < 4; j++) puzzle[i][j] == -1 ? printf(" * ") : printf("%2d ", puzzle[i][j]);
         printf("\n");
         }


      /* Get movement input */
   GET_CHAR_LOOP: do {
      printf("move into direction? (w-a-s-d for movement) ");
      key = getchar();
      /* putchar(key); */
      } while (key != 's' && key != 'a' && key != 'w' && key != 'd');


      /* React to the player's input */
      q = j = empty % 4; p = i = (empty - (empty % 4)) / 4;
      if (key == 'w' && i > 0) p = i - 1;
      else if (key == 'a' && j > 0) q = j - 1;
      else if (key == 'd' && j < 3) q = j + 1;
      else if (key == 's' && i < 3) p = i + 1;
      else { printf("Can't move outside the puzzle board\n"); goto GET_CHAR_LOOP; }
      puzzle[p][q] = puzzle[i][j];
      puzzle[i][j] = -1;
      empty = p * 4 + q;
      // printf("i: %i - j: %i - p: %i - q: %i -- puzzle[i][j]: %i - puzzle[p][q]: %i -- empty: %i\n", i, j, p, q, puzzle[i][j], puzzle[p][q], empty);


      /* Check if puzzle is finished */
      for (i = 0; i < 4; i++) {
         for (j = 0; j < 4; j++) {
            if (i == 3 && j == 3) sorted = 1;
            else {
               if (j == 4) { q = 0; p = i + 1; }
               else { p = i; q = j + 1; }
               if (puzzle[i][j] > puzzle[p][q] && puzzle[p][q] != -1) break;
               }
            }
         }
      }
   }