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
    // int row, i, j;
    // for (row = 1; row <= 6; row++) {
    //     j = 0;
    //     for (i = 0; i < 50; i++) {
    //         if (i % row) printf("-");
    //         else { printf("%i", j % 10); j++; }
    //         }
    //     printf("\n");
    //     }

    // Task 2 a) - Nachschreibeklausur:
    for (int i = 1; i <= 5; i++) {
        printf("%d", i);
        for (int j = i + 1; j < i + 9; j++) {
            printf("-");
            for (int k = 0; k <= j - i; k++) {
                printf("%d", j % 10);
                }
            }
        printf("\n");
        }

    // Alternatively (and probably easier to understand):
    printf("\n\n");
    for (int i = 0; i < 5; i++) {
        for (int j = 1; j < 10; j++) {
            if (j > 1) printf("-");
            for (int k = 0; k < j; k++) {
                printf("%d", (j + i) % 10);
                }
            }
        printf("\n");
        }


    // More tests to come
    // ...
    }