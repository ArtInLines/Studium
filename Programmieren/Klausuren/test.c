#include <stdio.h>
#include <stdlib.h>

void main() {
    // Task 1
    // int a = 13;
    // printf("%i\n", a);
    // a = a / 2 * 4;
    // printf("%i\n", a);
    // a >>= 1;
    // printf("%i\n", a);
    // a = a * (int)1.3;
    // printf("%i\n", a);
    // a = (~a);
    // printf("%i\n", a);
    // a = a & 15;
    // printf("%i\n", a);
    // a = a > 5 ? a : -a;
    // printf("%i\n", a);
    // a = !a;
    // printf("%i\n", a);

    // Task 2 a)
    int row, i, j;
    for (row = 1; row <= 6; row++) {
        j = 0;
        for (i = 0; i < 50; i++) {
            if (i % row) printf("-");
            else { printf("%i", j % 10); j++; }
            }
        printf("\n");
        }
    }