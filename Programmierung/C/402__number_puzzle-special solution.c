// number_puzzle.c 
// Write a number puzzle program by completing the TO DOs
// TO DO, optional: created an automatic, intelligent puzzle solver, which solves the puzzle without user intervention.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>

#define CNT 100

int puzzle[4][4];

// Do move. mv=0 right, 1=down, 2=left, 3=up
// checks for boundaries, returns 1 if move was valid, otherwise 0
int move(int mv)
{
    int i, j;    
    // Find empty field
    for(i=0; i<4; i++) {
        for(j=0; j<4; j++)
            if(puzzle[i][j]==-1) break;
        if(j<4 && puzzle[i][j]==-1) break;
    }

    // Do move and check for boundaries, returns 1 if move was valid, otherwise 0
    switch(mv) {
        case 0: if(i<3) { puzzle[i][j]=puzzle[i+1][j]; puzzle[i+1][j]=-1; return 1; }
                else return 0;
                // (Don't need break, because of return)
        case 2: if(i>0) { puzzle[i][j]=puzzle[i-1][j]; puzzle[i-1][j]=-1; return 1; }
                else return 0;
        case 1: if(j<3) { puzzle[i][j]=puzzle[i][j+1]; puzzle[i][j+1]=-1; return 1; }
                else return 0;
	    case 3: if(j>0) { puzzle[i][j]=puzzle[i][j-1]; puzzle[i][j-1]=-1; return 1; }
                else return 0;
    }
    return 0;
}

// Print puzzle
int output()
{
    int i, j;
    for(i=0; i<4; i++) {
        for(j=0; j<4; j++) {
            if(puzzle[i][j]==-1)
                printf("   ");
            else
                printf("%2d ", puzzle[i][j]+1);
        }
        printf("\n");
    }
}


int main()
{
    char sorted=0;       // This flag marks, if the field is sorted.  
    int i, j, mv, ret;
    int moves[CNT];

	srand(time(0));
    while(1) {
        // Set numbers in field
        for(i=0; i<4; i++)
            for(j=0; j<4; j++)
                puzzle[i][j]=i*4+j;
        puzzle[3][3]=-1;   // Mark empty field

        // Random shuffling
        for(i=0; i<CNT; i++) {
            do {
                mv=rand()%4;
                ret=move(mv);
            } while(!ret);
            moves[i]=mv^2;    // save inverse move: 0 becomes 2, 1<->3 etc. 
            if(i>0 && moves[i-1]==mv) i-=2;   // remove irrelevant "back-and-forth" moves
        }

		system("CLS");
        output();
        printf("Press enter to start\n");
        //getchar();
	    Sleep(5000);

	    // Automatic 'solver': playing shuffle sequence backwards
        for(i=CNT-1; i>=0; i--) {
            system("CLS");
            move(moves[i]);
            output();
			printf("Move: %d\n", "^<v>"[moves[i]]);
            for(j=0;j<50000000;j++); 	   
        }
		Sleep(5000);
        //getchar();
    }

}