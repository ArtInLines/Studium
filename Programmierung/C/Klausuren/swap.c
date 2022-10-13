#include <stdio.h>

void swap(int* a_pointer, int* b_pointer) {
    int tmp = a_pointer;
    printf("tmp: %d - a: %d - b: %d\n", tmp, *a_pointer, *b_pointer);
    *a_pointer = *b_pointer;
    printf("tmp: %d - a: %d - b: %d\n", tmp, *a_pointer, *b_pointer);
    *b_pointer = tmp;
    }

swapPointer(int** a, int** b) {
    int* tmp = *a;
    printf("tmp: %d - a: %d - b: %d\n", tmp, *a, *b);
    *a = *b;
    printf("tmp: %d - a: %d - b: %d\n", tmp, *a, *b);
    *b = tmp;
    printf("tmp: %d - a: %d - b: %d\n", tmp, *a, *b);
    }

int main() {
    int a, b;
    a = 5; b = 10;
    int* ap; int* bp;
    ap = &a; bp = &b;
    printf("ap: %d - bp: %d\n", ap, bp);
    /* swap(&a, &b);
    printf("a: %d - b: %d\n", a, b); */
    swapPointer(&ap, &bp);
    printf("a: %d - b: %d\n", a, b);
    printf("ap: %d - bp: %d\n", ap, bp);
    return 0;
    }