/* Chained list.c

   The (chained) list is a very important concept to manage sets of items dynamically:
   - The maximum number of elements does not need to be known in advance
   - Elements can have different sizes
   - Elements can be added and removed flexibly

   Key concepts of such a list are:
   - Each data item is stored in its own section of memory
   - There is a pointer to the first data item (or NULL, when the list is empty)
   - Each data item has a pointer to the next item in the list (or to NULL, if it's the last item in the list)

   The program below already contains some important definitions and functions.

   TO DO 1: Have a look at the program, get it running and try to understand how it works.
            - Print out pointer values to keep track of what the program does.
            - At what position is a new item added to the list (beginning or end?)
            DONE: Beginning
   TO DO 2: Extend main, such that more items are added to the list
   TO DO 3: Complete the function print_items to print for each item in the list:
            - the name, the address in memory and the address of its successor
            In addition, calculate the sum of all data payloads.
   TO DO 4: Write a function find_item(...) that searches the list for an item with a given guid.
   TO DO 5: (optional) Write a function delete_item(...) to delete an item from the list.
   TO DO 6: (optional) Experience 'Memory leaks':
            - Increase the size of the payload.
            - Change your delete function so that it does not free the memory correctly.
            - Add and remove items frequently in a big loop.
            - Use e.g. the task manager to see what happens with memory.
*/

#include <stdio.h>
#include <stdlib.h>

// itemType* for_each(itemType* list_start, void (*f)(itemType*));
// itemType* map(itemType* list_start, itemType* (*f)(itemType*, itemType*, int));
// itemType* find(itemType* list_start, int (*f)(itemType*, int));


// Data structure of the individual items in the list.
struct listElement {
    int guid;             // a unique id to identify the list item
    char name[128];       // a name to represent the item 
    unsigned char* data;  // arbitrary data 'payload'
    int size;             // size of data
    struct listElement* next_item;   // pointer to next item
    };

typedef struct listElement itemType;


// create_item:
// Creates and initializes a new item, or returns NULL, if it could not allocate memory.
itemType* create_item() {
    static int guid_ctr = 0;    // static counter to create unique ids
    itemType* ptr;

    ptr = malloc(sizeof(itemType));   // Allocate memory for the list item
    if (ptr != NULL) {
        ptr->guid = guid_ctr++;   // Generate a unique ID
        printf("Enter name: ");
        scanf("%s", ptr->name);  // Enter a name
        ptr->size = 1000;
        ptr->data = malloc(ptr->size * sizeof(unsigned char));  // Allocate some memory for a payload
        // TO DO: Have to check for NULL Pointer
        }
    return ptr;    // Return pointer to the new item
    }


// Insert_item:
// Inserts an existing item into the (potentially empty) list
void insert_item(itemType* new_item, itemType** list_ptr) {
    new_item->next_item = *list_ptr;   // Append existing list to new item
    *list_ptr = new_item;              // Set list_ptr to points to new item
    }



// print all items
void print_items(itemType* list_start) {
    itemType* item = list_start;
    while (item != NULL) {
        printf("%i: %s\n", item->guid, item->name);
        item = item->next_item;
        }
    }


// Finds an item with guid in the list 
itemType* find_item(int guid, itemType* list_start) {
    itemType* item = list_start;
    do {
        if (guid == item->guid) return item;
        item = item->next_item;
        } while (item->next_item != NULL);

        return NULL;
    }


// Deletes an item and returns the successor of the deleted item
// The chaining of the previous and next element has to be done 
// by the caller.
itemType* simple_delete_item(itemType* item) {
    itemType* next = item->next_item;
    free(item->data);
    free(item);
    return next;
    }


// Complete delete item
// Deletes item 'to_delete' from the 'list'
// return 0, if the item does not exist in the list, otherwise 1
int delete_item(itemType* to_delete, itemType** list_ptr) {
    itemType* current = *list_ptr;
    itemType* next = (*list_ptr)->next_item;

    if (*list_ptr != NULL) {
        if (*list_ptr == to_delete) {
            *list_ptr = simple_delete_item(to_delete);
            return 1;
            }

        while (next != NULL) {
            current = current->next_item;
            next = current->next_item;
            if (current == to_delete) {
                current->next_item = simple_delete_item(to_delete);
                return 1;
                }
            }
        }
    return 0;
    }


void del(itemType** list_ptr) {
    int id, res;
    printf("Enter the ID of the element, you wish to delete: ");
    scanf("%i", &id);

    itemType* to_del = find_item(id, *list_ptr);
    res = delete_item(to_del, list_ptr);

    if (res) printf("The item was successfully deleted!\n");
    else printf("Sorry, something went wrong, make sure you entered the right ID...");
    }


int main() {
    itemType* my_list = NULL;
    itemType* current;
    char c;
    int loop = 1;

    while (loop) {
        if (c != '\n') {
            printf("Press 'a' to add a new item, 'p' to print all items, 'd' to delete an item, or 'q' to quit: ");
            scanf("%c", &c);
            }

        switch (c)
            {
            case '\n':
                c = 0;
                break;

            case 'q':
                loop = 0;
                break;

            case 'a':
                current = create_item();
                insert_item(current, &my_list);
                break;

            case 'p':
                print_items(my_list);
                break;

            case 'd':
                del(&my_list);
                break;

            default:
                printf("Invalid character, try again dumbass!\n");
                break;
            }
        }
    }




//////////
//////////
// General purpose, functional methods:
//////////
//////////

// itemType* for_each(itemType* list_start, void (*f)(itemType*)) {
//     itemType* item = list_start;
//     do
//         {
//         (*f)(item);
//         item = item->next_item;
//         } while (item->next_item != NULL);
//         return list_start;
//     }


// itemType* map(itemType* list_start, itemType* (*f)(itemType*, itemType*, int)) {
//     itemType* item = list_start;
//     int i = 0;

//     do {
//         *item = *(*f)(item, item->next_item, i++);
//         item = item->next_item;
//         } while (item->next_item != NULL);

//         return list_start;
//     }


// itemType* find(itemType* list_start, int (*f)(itemType*, int)) {
//     itemType* item = list_start;
//     int i = 0;

//     do {
//         if ((*f)(item, i++)) return item;
//         item = item->next_item;
//         } while (item->next_item != NULL);

//         return NULL;
//     }
