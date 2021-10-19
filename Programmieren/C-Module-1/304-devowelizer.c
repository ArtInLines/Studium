/* devowelizer / revowelizer 
 TO DO 1: Extend the program such that it replaces all vowels in the text with other vowels.
 TO DO 2: Extend the program such that the replacement vowel is chosen randomly.
          Hint: List the vowels in an additional array ...
                Use rand() to generate random numbers
 TO DO 3: Modify the program such that it removes all vowels (and shortens the text accordingly)
 TO DO 4 (optional): Write an encryption/decryption program which encodes texts by defining
         in a table how each character shall be replaced by another one. 
*/ 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int revowelizer();
int devowelizer();
int encrypter();

int main() {
   encrypter();
}

int revowelizer() {
   char Vowels[] = "AEIOU";
   int vowelsAmount = strlen(Vowels);
   char txt[1000];
   int i, j, k;

   printf("Please enter your text: ");
   gets(txt);

   i=0;
   while(txt[i] != 0)
   {
      // Loop through all vowels, to check if the current char is one of the vowels
      j=0;
      while (Vowels[j] != 0) {
         if (Vowels[j] == txt[i] || (Vowels[j]|32) == txt[i]) {
            // If the character is a vowel, randomly choose another vowel, that isn't the same
            do {
               k = rand() % vowelsAmount;
            } while (k == j);
            txt[i] = Vowels[k];
            break;
         }
         j++;
      }
      
      i++;
   }
   printf("%s", txt);
}

int devowelizer() {
   char Vowels[] = "AEIOU";
   int vowelsAmount = strlen(Vowels);
   char txt[1000];
   int i, j, vowelCounter;

   printf("Please enter your text: ");
   gets(txt);

   i=0; vowelCounter=0;
   while(txt[i] != 0)
   {  
      // Loop through all vowels, to check if the current char is one of the vowels
      j=0;
      while (Vowels[j] != 0) {
         if (Vowels[j] == txt[i] || (Vowels[j]|32) == txt[i]) {
            // If the character is a vowel, remove this character and move all further characters once up
            txt[i] = 0;
            vowelCounter++;
            break;
         }
         j++;
      }
      
      if (vowelCounter>0 && txt[i]!=0) {
         txt[i-vowelCounter] = txt[i];
         txt[i]=0;
      }
      
      i++;
   }
   printf("%s", txt);
}

int encrypter() {
   char tableTop[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
   char tableBot[] = "QWERTZUIOPASDFGHJKLYXCVBNM";
   
   int i, j;
   char txt[1000];
   printf("Please enter your text: ");
   gets(txt);
   
   i=0;
   while(txt[i] != 0) 
   {
      j=0;
      while(tableTop[j] != 0) {
         if (tableTop[j] == txt[i]) {
            txt[i] = tableBot[j];
            break;
         }
         else if ((tableTop[j] | 32) == txt[i]) {
            txt[i] = tableBot[j] | 32;
            break;
         }
         j++;
      }
      i++;
   }
   printf("%s", txt);
}