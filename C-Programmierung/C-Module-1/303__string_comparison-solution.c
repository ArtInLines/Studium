/* Compare two strings */
// TO DO 1: This program does not always give the correct results. What is the problem? Correct it!
// TO DO 2: Adapt the comparison such that it can be used for providing an ordering e.g. for phone books

#include <stdio.h>

int main()
{
   char s1[100], s2[100];
   int i, flag;

   printf("Please enter string 1:\n");
   gets(s1);     // Risk of buffer overflow!
   printf("Please enter string 2:\n");
   gets(s2);     // Risk of buffer overflow!

   for(flag=-1, i=0; flag<0; i++)
       if(!s1[i]) flag= s2[i]? 1 : 0;
       else if(!s2[i]) flag=2;
       else if((s1[i]|32)!=(s2[i]|32)) 
          flag = (s1[i]|32)<(s2[i]|32) ? 1 : 2;
 
   printf("String: %s %c %s\n", s1, "=<>"[flag], s2);

   /* Oder ausführlicher: */
   /* if(flag>0) 
      printf("String %s %c %s\n", s1, flag==1? '<':'>', s2);
   else
      printf("Strings are equal\n");
   */
}