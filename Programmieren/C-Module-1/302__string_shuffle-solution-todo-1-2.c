/* Shuffles a string */
// TO DO 1: Extend the program such that spaces in the strings are not moved/shuffled.
// TO DO 2: Extend the program such that the first characters of names are not shuffled 
//          (a name may consist of several parts separated by spaces).

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
   char name[100], c;
   int i, p1, p2;

   printf("Please enter your name:\n");
   fgets(name, 100, stdin);   // To replace unsafe gets
   if(name[0] != 0) 
   	name[strlen(name)-1] = 0;   // truncate \n (which is added by fgets at the end of the input)

   i=0;
   while(i<10) 
   {
      p1=rand()%strlen(name);
      p2=rand()%strlen(name);
      if(p1 && p2 && name[p1]!=' ' && name[p2]!=' ' && name[p1-1]!=' ' && name[p2-1]!=' ') {
         c=name[p1];
         name[p1]=name[p2];
         name[p2]=c;
         printf("Hello %s\n", name);
         i++; // Nur bei Tausch Loopcounter erhöhen: Achtung ggf. Endlosschleife bei leerer Eingabe!
      }
   }
   getchar(); 
}