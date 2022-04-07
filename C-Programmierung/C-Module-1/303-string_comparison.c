/* Compare two strings */
// TODO 1: This program does not always give the correct results. What is the problem? Correct it!
// TODO 2: Adapt the comparison such that it can be used for providing an ordering e.g. for phone books

#include <stdio.h>

int todo1();
int todo2();

int main() {
   todo2();
}

int todo2() {
   char s1[100], s2[100];
   int i, flag;
   
   printf("Please enter string 1:\n");
   gets(s1);
   printf("Please enter string 2:\n");
   gets(s2);
   
   flag=i=0;
   while(s1[i] != 0) {
      if (s2[i] == 0 || s2[i] < s1[i]) {
         printf("%s < %s", s2, s1);
         return 0;
      }
      else if (s2[i] > s1[i]) {
         printf("%s < %s", s1, s2);
         return 0;
      }
      i++;
   }
   printf("%s = %s", s1, s2);
}

int todo1() {
   char s1[100], s2[100];
   int i, flag;

   printf("Please enter string 1:\n");
   gets(s1);
   printf("Please enter string 2:\n");
   gets(s2);

   flag=0; i=0;
   while(s1[i]!=0 && s2[i]!=0) {
      // printf("i: %i - s1: %c - s2: %c\n", i, s1[i], s2[i]);
      if(s1[i]!=s2[i]) {
         flag=1;
         break;
      }
      i++;
   }
   if (s1[i]!=s2[i]) flag=1;
   if(flag)
      printf("Strings are different\n");
   else
      printf("Strings are equal\n");
}