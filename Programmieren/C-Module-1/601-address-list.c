/* address_list.c */
// This program should be completed such that it maintains a list of students
// TO DO 1: Write a function inputStudent(int i), which allows the user to enter first name and last name and stores it at position i in the array.
// TO DO 2: Use a variable to count the number of students stored in the array.
// TO DO 3: Write a function printStudent(i), which prints student i stored in the array
// TO DO 4: Write functions addStudent(), for adding a student at the end of the array, and printAllStudents() for printing all students stored.
// TO DO 5: Write a function menu(), which allows the user to select one of the actions
//            - add Student
//            - print all students
//            - quit program
// TODO 6: Extend the student data and the corresponding functions with the gender male/female (using "enum").
// TODO 7: Create a structure for handling dates (day, month, year) and use it for birth date, date of enrollment etc. 
// TODO 8: Extend the program such it also handles address information (street, number, zip-code and city).
// TODO 9: optional: Add a function and menu item for deleting a selected student.
// TODO 10: optional: Add a function to sort the data according to given criteria

#include <stdio.h>


struct person
   {
   char first_name[30];
   char last_name[30];
   };

struct person students[100];

int globalStudentCounter = 0;

void printStudent(int i) {
   printf("\"%s %s\"\n", students[i].first_name, students[i].last_name);
   }

void printAllStudents() {
   for (int i = 0; i < globalStudentCounter; i++) printStudent(i);
   }

void addStudent() {
   printf("What is the student's first name? ");
   scanf("%s", &students[globalStudentCounter].first_name);
   printf("What is the student's last name? ");
   scanf("%s", &students[globalStudentCounter++].last_name);
   }

void menu() {
   char prompt[90] = "Press \"a\" to add a student, \"p\" to print all students or \"q\" to quit the pogram: ";
   char c = 0;
   while (1) {
      printf(prompt);
      do { scanf("%c", &c); } while (c == '\n');

      if (c == 'a') addStudent();
      else if (c == 'p') printAllStudents();
      else if (c == 'q') break;
      else /* if (c != '\n') */ printf("How difficult is it to type 'a', 'p', or 'q'???? Try again, dumbass!\n");
      }
   }

int main() {
   menu();

   return 0;
   }