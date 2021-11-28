#include <stdio.h>
#include <stdlib.h>

void main() {
    int a = 13;
    printf("%i\n", a);
    a = a / 2 * 4;
    printf("%i\n", a);
    a >>= 1;
    printf("%i\n", a);
    a = a * (int)1.3;
    printf("%i\n", a);
    a = (~a);
    printf("%i\n", a);
    a = a & 15;
    printf("%i\n", a);
    a = a > 5 ? a : -a;
    printf("%i\n", a);
    a = !a;
    printf("%i\n", a);
    }