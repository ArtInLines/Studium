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

int main()
{
    char txt[1000];
    int i, j;

    printf("Please enter your text:");
    gets(txt);   // Risk of buffer overflow!

    // Efficient solution for removing vowels:
    i=j=0;
    do 
    {
        // skip vowels with j counter
        while(txt[j]=='a' || txt[j]=='e' || txt[j]=='i' || txt[j]=='o' || txt[j]=='u' ||
              txt[j]=='A' || txt[j]=='E' || txt[j]=='I' || txt[j]=='O' || txt[j]=='U')
            j++;
        // copy char from position j to position i, thus skipping vowels (j >= i)
        txt[i++]=txt[j++];
    } while(txt[i-1]);   // -1, because also zero byte needs to be copied.
    
    printf("%s", txt);
}