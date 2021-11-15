/* Game of life
The "game of life" is an old and very simple approach of simulating evolution 
A 2-dimensional field of cells is regarded, with a cell being either empty/dead (0) or occupied/alive (1)
The intial state can be chosen e.g. manually or using some random operations.

The further evolution is then governed by the following rules:

Every cell interacts with its eight neighbours, which are the cells that are directly horizontally, vertically, or diagonally adjacent. 
At each step in time, the following transitions occur:
   1. Any live cell with fewer than two live neighbours dies, as if by needs caused by underpopulation.
   2. Any live cell with more than three live neighbours dies, as if by overcrowding.
   3. Any live cell with two or three live neighbours lives, unchanged, to the next generation.
   4. Any empty/dead cell with exactly three live neighbours cells will be populated with a living cell.

The initial pattern constitutes the 'seed' of the system. The first generation is created by applying the above rules simultaneously to every cell in the seed — births and deaths happen simultaneously, and the discrete moment at which this happens is sometimes called a tick. (In other words, each generation is a pure function of the one before.) 
The rules continue to be applied repeatedly to create further generations.
 http://en.wikipedia.org/wiki/Conway's_Game_of_Life

 TO DO: Complete the programm such that it simulates the game of life 
 */

#include <stdio.h>
#include <stdlib.h>

// Global 2-dim-array which contains the cells
char cells[30][50];

// TO DO: initialize cells, set most to 0, some to 1 
void initialize_cells()
{
   int i, j;
   for(i=0; i<30; i++) 
      for(j=0; j<50; j++) 
         cells[i][j]=(rand()%50<10);
}

// TO DO: write output function to show the cells
void display_cells()
{
   int i, j;

   system("CLS"); // Clear screen (on windows console)
   for(i=0; i<30; i++) {
      for(j=0; j<50; j++) 
         printf("%c",cells[i][j]? 219:' ');
      printf("\n");
   }
}

// Function to calculate the next evolution step
void evolution_step()
{
   int i, j;
   // Use this array for the calculation of the next step
   char cells_helper[30][50];
   
   for(i=0; i<30; i++) {
      for(j=0; j<50; j++) {
		  int nb=cells[(i+30-1)%30][(j+50-1)%50]+
			     cells[(i+30)%30][(j+50-1)%50]+
			     cells[(i+30+1)%30][(j+50-1)%50]+
			     cells[(i+30-1)%30][(j+50)%50]+
			     cells[(i+30+1)%30][(j+50)%50]+
			     cells[(i+30-1)%30][(j+50+1)%50]+
			     cells[(i+30)%30][(j+50+1)%50]+
			     cells[(i+30+1)%30][(j+50+1)%50];
		  if(nb==2) cells_helper[i][j]=cells[i][j];
          else if(nb==3) cells_helper[i][j]=1;
		  else cells_helper[i][j]=0;
	  }
   }
   for(i=0; i<30; i++) 
      for(j=0; j<50; j++) 
		  cells[i][j]=cells_helper[i][j];
}

// Count the number of occupied cells
int count_cells()
{
   int i, j, cnt=0;

   for(i=0; i<30; i++) 
      for(j=0; j<50; j++) 
          cnt+=cells[i][j];
   return cnt;
}

// Main program
int main()
{
   initialize_cells();

   while(1) {
      display_cells();

	  // Leave loop if there are no more occupied cells
	  if(count_cells()==0) 
		  break;
      
      printf("Press enter");
	  getchar();

      evolution_step();
   }
}