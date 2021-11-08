// Switch case: Order your burger...
// TODO 1: Replace the if-statements with switch case and add a default case for invalid input
// TODO 2: Add support for extra-large and fish burgers
// TODO 3: Extend the program such that is executed in a loop, which can be aborted by entering 'q' as size
// TODO 4: If there is a much longer list of options: How can long if-else-chains / switch-case-statements be avoided?
    // ANSWER: By using arrays
// TODO 5: Optional: Any further ideas for additional sizes and options?

#include <stdio.h>

int main() {
    char size, specials;
    int height;
    float price;

    while (1) {
        printf("Which size you want your burger (s=small, m=medium, l=large, x=extra-large)? - Presss 'q' to exit ");
        scanf(" %c", &size);
        if (size == 'q') break;
        printf("Any specials (r=regular: beef, v=veggie, c=cheese, f=fish)?");
        scanf(" %c", &specials);

        switch (size)
            {
            case 's':
                height = 1;
                price = 2.5f;
                break;

            case 'm':
                height = 2;
                price = 3.5f;
                break;

            case 'l':
                height = 4;
                price = 5.9f;
                break;

            case 'x':
                height = 6;
                price = 7.5f;
                break;

            default:
                printf("Invalid input\n");
                continue;
            }

        printf("\n\n.-\"\"\"\"-.\n");
        while (height--) {
            switch (specials)
                {
                case 'c':
                    printf(" ------ \n");
                    break;

                case 'v':
                    printf("(xxxxxx)\n");
                    break;

                case 'f':
                    printf("_ffffff_\n");
                    break;

                default:
                    printf("(mmmmmm)\n");
                    break;
                }
            }
        printf("\\______/\n");
        printf("\n\n%.2f Euro - Enjoy!\n", price);
        }
    }