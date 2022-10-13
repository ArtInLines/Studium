// /* Shuffles a string */
// // TODO 1: Extend the program such that spaces in the strings are not moved/shuffled.
// // TODO 2: Extend the program such that the first characters of names are not shuffled 
// //          (a name may consist of several parts separated by spaces).
// // TODO 3: Extend the program such that two names can be entered and shuffling happens between these two 
// // TODO 4: How can a user make the program crash? What could be done against that problem?
      // 4: By inputting names with over 100 characters

/* Shuffles a string */
// TO DO 1: Extend the program such that spaces in the strings are not moved/shuffled.
// TO DO 2: Extend the program such that the first characters of names are not shuffled 
//          (a name may consist of several parts separated by spaces).
// TO DO 3: Extend the program such that two names can be entered and shuffling happens between these two 
// TO DO 4: How can a user make the program crash? What could be done against that problem?

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
   char name[100], anothername[100], c;
   int i, p1, p2;

   printf("Please enter your name:\n");
   gets(name);
   // Safer alternatives, with some issues -> lecture:
   // scanf("%99[^\n]", name);
   // fgets(name, 100, stdin);  // Read max. 99 chars + space for 0-byte

   printf("Please enter another name:\n");
   gets(anothername);

   for (i = 0; i < 10; i++) {
      p1 = rand() % strlen(name);
      p2 = rand() % strlen(anothername);

      while (name[p1] == ' ' || p1 == 0) p1 = rand() % strlen(name);
      while (anothername[p2] == ' ' || p2 == 0) p2 = rand() % strlen(anothername);

      c = name[p1];
      name[p1] = anothername[p2];
      anothername[p2] = c;
      printf("Hello %s\n%s\n", name, anothername);
   }
}

