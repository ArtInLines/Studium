/* matrices - example solution*/
// TO DO 1: Extend the programm such that the result is printed
// TO DO 2: Extend the programm such that it also calculates the product of the two 3x3 matrices.
// TO DO 3: What happens when you make a mistake with the indices, e.g. read/write m1[3][0], m1[4][0], m1[0][4] etc.? 


#include <stdio.h>

int main()
{
   float m1[3][3]= { { 12, 5.3, 10.0 }, { 5, 10.2, -2 },  { 1, -1, 3 } };
   float m2[3][3]= { { 2.1, -3, 1.5 },  { 10, -12, 3.1 }, { 4, 8.2, -2 } };
   float sum[3][3];
   float prod[3][3];

   int i, j, k;

   
   for(i=0; i<3; i++)
      for(j=0; j<3; j++)
         sum[i][j]=m1[i][j]+m2[i][j];
   
   // DONE 2:
   for(i=0; i<3; i++)
	   for(j=0; j<3; j++)
		   for(prod[i][j]=k=0; k<3; k++)
			   prod[i][j] += m1[i][k] * m2[k][j];
   
   // DONE 1: i denotes the line, j the column of the matrix
   for(i=0; i<3; i++) {
      for(j=0; j<3; j++) 
		  printf("%6.1f ", m1[i][j]);
	  printf(i==1? "  *  ": "     ");
	  for(j=0; j<3; j++) 
		  printf("%6.1f ", m2[i][j]);
	  printf(i==1? "  =  ": "     ");
      for(j=0; j<3; j++) 
		  printf("%6.1f ", prod[i][j]);
	  printf("\n");
   }
   
   // DONE 3:
   printf("\nTODO 3: %6.1f, %6.1f, %6.1f\n",  m1[3][0], m1[4][0], m1[0][4]);
   getchar();
}