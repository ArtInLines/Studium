/* Variables and memory
  have a look the variables in your previous programs, e.g. address_list.c

  TO DO 1: Use sizeof to determine how much memory different types require in memory.
  TO DO 2: Also consider arrays, structs, enums and unions.
  TO DO 3: Use & to determine the addresses of different variables in memory.
  TO DO 4: Can you see a difference of addresses for local and global variables? DONE: Global Variables are stored at far lower addresses
  TO DO 5: How are variables sorted in memory (increasing or decreasing addresses)? - DONE: Decreasing
  TODO 6: What about addresses of local variables in recursive functions (e.g. hanoi.c)?
  TO DO 7: Can you find int variables stored at uneven addresses? How do you judge the result?
  // DONE: Internatl Exception sh*t
  TO DO 8: What is the size of the following struct? Why? Can it be reduced?
  // DONE: Size is 16 bytes. Could be reduced via bitfields to use only 10 bytes.
*/


#include <stdio.h>

typedef struct {
  char a;
  int b;
  char c;
  int d;
  } test;

enum my_enum {
  enabled,
  disabled
  };

union my_union
  {
  int i;
  short s;
  };

const int GlobalInt = 4;

void main() {
  test my_test;
  union my_union num;
  num.i = -5;
  num.s = 5;

  char c; int i; short s; double d; long l; unsigned int u;
  printf("char: %d, unsigned int: %d, int: %d, short: %d, double: %d, long: %d\n", sizeof(c), sizeof(u), sizeof(i), sizeof(s), sizeof(d), sizeof(l));

  int intarr[4]; long longarr[4]; char str[] = "Test";
  printf("int array: %d, long array: %d, 'Test'-string: %d, test struct: %d, test union: %d\n", sizeof(intarr), sizeof(longarr), sizeof(str), sizeof(my_test), sizeof(num));

  printf("\nLocations of:\nGlobal Int: %d - %p\nUnion Num: %d - %p\nLocal Int: %d -%p\nLocal Short: %d - %p\nLocal Double: %d - %p\n\n", &GlobalInt, &GlobalInt, &num, &num, &i, &i, &s, &s, &d, &d);
  }