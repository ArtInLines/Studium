/* Shuffles a string */
// Solution for TO DO 3: Extend the program such that two names can be entered and shuffling happens between these two 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
   char name[100], name2[100], c;
   int i, p1, p2;

   printf("Please enter your name:\n");   
   gets(name);   // Risk of buffer overflow!
   printf("Please enter your name:\n");
   gets(name2);   // Risk of buffer overflow!
   
   for(i=0; i<10; i++) 
   {
      p1=rand()%strlen(name);
      p2=rand()%strlen(name2);
      c=name[p1];
      name[p1]=name2[p2];
      name2[p2]=c; 
      printf("Hello %s and %s\n", name, name2);
   }

   getchar(); 
}