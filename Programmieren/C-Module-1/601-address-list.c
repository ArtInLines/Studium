/* address_list.c */
// This program should be completed such that it maintains a list of students
// DONE 1: Write a function inputStudent(int i), which allows the user to enter first name and last name and stores it at position i in the array.
// DONE 2: Use a variable to count the number of students stored in the array.
// DONE 3: Write a function printStudent(i), which prints student i stored in the array
// DONE 4: Write functions addStudent(), for adding a student at the end of the array, and printAllStudents() for printing all students stored.
// DONE 5: Write a function menu(), which allows the user to select one of the actions
//            - add Student
//            - print all students
//            - quit program
// TO DO 6: Extend the student data and the corresponding functions with the gender male/female (using "enum").
// TO DO 7: Create a structure for handling dates (day, month, year) and use it for birth date, date of enrollment etc. 
// TO DO 8: Extend the program such it also handles address information (street, number, zip-code and city).
// TO DO 9: optional: Add a function and menu item for deleting a selected student.
// TODO 10: optional: Add a function to sort the data according to given criteria

#include <stdio.h>


enum gender {
   male,
   female,
   nonBinary
   };

struct date {
   int day;
   int month;
   int year;
   }

struct address {
   char street[30];
   int number;
   int plz;
   char city[30];
   }

struct person {
   char first_name[30];
   char last_name[30];
   enum gender gender;
   struct date birthdate;
   struct date enrollmentDate;
   struct address address;
   };

struct person students[100];
int globalStudentCounter = 0;


void printStudent(int i) {
   printf("%d. \"%s %s\"\n", i, students[i].first_name, students[i].last_name);
   }


void printAllStudents() {
   int i;
   for (i = 0; i < globalStudentCounter; i++) printStudent(i);
   }


struct address getAddress() {
   struct address address;

   printf("Street name? ");
   scanf("%s", &address.street);

   printf("House number? ");
   scanf("%d", &address.number);

   printf("City name? ");
   scanf("%s", &address.city);

   printf("PLZ / Zip-Code? ");
   scanf("%d", &address.plz);

   return address;
   }


struct date getDate(char* desc) {
   struct date date;
   int dateInt = 0;

   do {
      printf("Please enter the day of the %s", desc);
      scanf("%d", &dateInt);
      } while (date < 1 || date > 31);
      date.day = dateInt;

      do {
         printf("Please enter the month of the %s", desc);
         scanf("%d", &dateInt);
         } while (date < 1 || date > 12);
         date.month = dateInt;

         printf("Please enter the year of the %s", desc);
         scanf("%d", &dateInt);
         date.year = dateInt;

         return date;
   }


void addStudent() {
   printf("What is the student's first name? ");
   scanf("%s", &students[globalStudentCounter].first_name);

   printf("What is the student's last name? ");
   scanf("%s", &students[globalStudentCounter].last_name);

GET_GENDER:
   char c[10] = 0;
   printf("What is the student's identified gender (m/f/nb)? ");
   scanf("%s", c);
   if (c[0] == 'm') students[globalStudentCounter].gender = male;
   else if (c[0] == 'f') students[globalStudentCounter].gender = female;
   else if (c[0] == 'n') students[globalStudentCounter].gender = nonBinary;
   else goto GET_GENDER;

   students[globalStudentCounter].birthdate = getDate("birthdate");
   students[globalStudentCounter].enrollmentDate = getDate("date of enrollment");

   printf("What is the student's address?\n");
   students[globalStudentCounter].address = getAddress();

   globalStudentCounter++;
   }


void deleteStudent(int i) {
   if (i >= globalStudentCounter) return;

   students[i] = students[--globalStudentCounter];
   struct person empty;
   students[globalStudentCounter] = empty;
   }


void menu() {
   char prompt[90] = "Press \"a\" to add a student, \"d\" to delete a student, \"p\" to print all students or \"q\" to quit the pogram: ";
   char c = 0;
   while (1) {
      printf(prompt);
      do { scanf("%c", &c); } while (c == '\n');

      if (c == 'a') addStudent();
      else if (c == 'p') printAllStudents();
      else if (c == 'd') {
         int studentID = globalStudentCounter;
         printf("The student with which id, do you want to delete? ");
         scanf("%d", &studentID);
         deleteStudent(studentID);
         }
      else if (c == 'q') break;
      else /* if (c != '\n') */ printf("How difficult is it to type a single letter???? Try again, dumbass!\n");
      }
   }


int main() {
   menu();

   return 0;
   }