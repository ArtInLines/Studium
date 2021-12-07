/* Function_plotter.c
   This program uses pointers to functions, which are passed as arguments in function calls.

    TO DO 1: Have a look at the program and see how function pointers are used.
    TO DO 2: Extend the draw_function such that the range for x and y can be passed:
          Define a struct range, which provides values for min, max and step.
    TO DO 3: Extend the draw_function, such that two functions
             can be passed to the draw function and are shown in the same diagram.
          Use a NULL pointer to indicate that there is no second function to display.
    TO DO 4: Optional: Add more functions and a menu to flexibly choose
            which functions to show (use two function pointers).
*/

#include <math.h>
#include <stdio.h>


typedef struct {
   double min;
   double max;
   double step;
   } range;


// Display function 
void draw_function(double (*f)(double), range x_range, range y_range) {
   double x, y;

   for (y = y_range.max; y >= y_range.min; y -= y_range.step) {
      for (x = x_range.min; x < x_range.max; x += x_range.step) {
         printf("%c", ((*f)(x) >= y && (*f)(x) < y + y_range.step) ? '*' : ' ');
         // Dereferencing *-operator is optional:
         // f(x) would also work
         }
      printf("\n");
      }
   }


// Mathematical function to be displayed 
double my_function(double x) {
   return 0.5 * sin(x);
   }


// Asks user for range values
void get_range(range* ptr, char* name) {
   printf("Minimum for %s? ", name);
   scanf("%d", ptr->min);

   printf("Maximum for %s? ", name);
   scanf("%d", ptr->max);

   printf("Step for %s? ", name);
   scanf("%d", ptr->step);
   }


int main() {
   double (*fn_ptr)(double);     // Defines a variable pointing to a function
                                 // double some_function_name(double);
   fn_ptr = &my_function;        // & can be omitted
   // draw_function(fn_ptr);        // or directly: draw_function(my_function);

   // Define x_range, y_range
   range x, y;
   get_range(&x, "x");
   get_range(&y, "y");
   draw_function(fn_ptr, x, y);
   }
