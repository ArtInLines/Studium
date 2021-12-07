/* hexdump.c
   A Hexdump prints the content of some memory area in hexadecimal format.

   TO DO 1: Have a look at the following program. How does it work?
   TO DO 2: Extend the program such that it shows 16 bytes in a row and puts the memory address at the beginning
   TO DO 3: Add other data structures and show how they maintain their data
            (or copy the hexdump to your other programs and call it from there)
   TO DO 4: Use malloc to allocate memory and hexdump it.
   TO DO 5: What happens if you call hexdump with arbitrary numbers, e.g. hexdump(10000,10); Why?
   TO DO 6: What happens if you call hexdump("Hello",6); Why?
   TO DO 7: Do a hexdump(hexdump, 100). What might that mean? What happens if you try to change values in this address range?
   TO DO 8: Optional: Hexdumps often also show the memory content as ascii characters in an additional column.
            Extend the program accordingly.

*/

#include <math.h>
#include <stdio.h>

// Hexdump function 
void hexdump(void* adr, int length, int typeSize) {
   const int byte_amount = 16 < length ? 16 : length;
   int i, j, k;
   // Increment using char pointer (i.e. byte increments):      
   unsigned char* c_adr = adr;

   for (i = 0; i < length; i += byte_amount) {
      printf("%p:", *c_adr);
      for (j = 0; j < byte_amount / typeSize; j++) {
         printf(" ");
         for (k = 1; k <= typeSize; k++) {
            printf("%3x", *(c_adr + typeSize - k));
            }
         c_adr += typeSize;
         }
      printf("\n");
      }
   }

// Test code to call hexdump
int main() {
   enum gender {
      MALE,
      FEMALE,
      NON_BINARY
      };

   typedef struct {
      char name[100];
      int age;
      enum gender gender;
      } person;


   int a[] = { 1, 2, 3, 4, 5, -1, -2 };
   int myGender = MALE;
   person myPerson = { "Name 1", 18, myGender };
   person myPerson2 = { "Name 2", 20, FEMALE };
   person people[] = { myPerson, myPerson2 };

   void* ptr = malloc(100 * sizeof(char));

   printf("a:\n");
   hexdump(a, sizeof(a), sizeof(int));
   getchar();
   printf("myGender:\n");
   hexdump(&myGender, sizeof(myGender), sizeof(int));
   getchar();
   printf("myPerson:\n");
   hexdump(&myPerson, sizeof(myPerson), sizeof(int));
   getchar();
   printf("people:\n");
   hexdump(people, sizeof(people), sizeof(int));
   getchar();
   printf("malloc-ptr:\n");
   hexdump(ptr, 100, 1);
   getchar();
   printf("Hello:\n");
   hexdump("Hello", 6, sizeof(char));
   getchar();
   printf("hexdump:\n");
   hexdump(hexdump, 1000, 1);
   getchar();
   printf("arbitrary numbers:\n");
   hexdump(10000, 10, 1);
   getchar();
   }

