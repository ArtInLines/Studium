/* pointers.c
  TO DO 1:  Extend/modify the address_list.c program such that the student data is not stored
            in a global but in local data structures in main.
  TO DO 2:  Use pointers/call by reference to pass student data to the different functions.
  TO DO 3:  use typedef to define a type for 'struct person' and use this type

  Some code snippets are given below.
*/

#include <stdio.h>


enum gender {
  male,
  female,
  nonBinary
  };

typedef struct {
  int day;
  int month;
  int year;
  } date;

typedef struct {
  char street[30];
  int number;
  int plz;
  char city[30];
  } address;

typedef struct {
  char first_name[30];
  char last_name[30];
  enum gender gender;
  date birthdate;
  date enrollmentDate;
  address address;
  } person;


void printStudent(person* student, int id) {
  printf("%d. \"%s %s\" (Geboren: %d.%d.%d). (%s %d, %s %d)\n", id, student->first_name, student->last_name, student->birthdate.day, student->birthdate.month, student->birthdate.year, student->address.street, student->address.number, student->address.city, student->address.plz);
  }


void printAllStudents(person* students, int limit) {
  int i;
  for (i = 0; i < limit; i++) printStudent(&students[i], i + 1);
  }


address getAddress() {
  address address;

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


date getDate(char* desc) {
  date date;
  int dateInt = 0;

  do {
    printf("Please enter the day of the %s? ", desc);
    scanf("%d", &dateInt);
    } while (dateInt < 1 || dateInt > 31);
    date.day = dateInt;

    do {
      printf("Please enter the month of the %s? ", desc);
      scanf("%d", &dateInt);
      } while (dateInt < 1 || dateInt > 12);
      date.month = dateInt;

      printf("Please enter the year of the %s? ", desc);
      scanf("%d", &dateInt);
      date.year = dateInt;

      return date;
  }


void makeStudent(person* student) {
  printf("What is the student's first name? ");
  scanf("%s", &student->first_name);

  printf("What is the student's last name? ");
  scanf("%s", &student->last_name);

GET_GENDER:;
  char c[10] = "";
  printf("What is the student's identified gender (m/f/nb)? ");
  scanf("%s", c);
  if (c[0] == 'm') student->gender = male;
  else if (c[0] == 'f') student->gender = female;
  else if (c[0] == 'n') student->gender = nonBinary;
  else goto GET_GENDER;

  student->birthdate = getDate("birthdate");
  student->enrollmentDate = getDate("date of enrollment");

  printf("What is the student's address?\n");
  student->address = getAddress();
  }


void deleteStudent(person* student) {
  person empty;
  *student = empty;
  }


void swap_people(person* a, person* b) {
  person tmp;
  tmp = *a;
  *a = *b;
  *b = tmp;
  }


void menu(person* students, int* i) {
  char prompt[] = "Press \"a\" to add a student, \"d\" to delete a student, \"p\" to print all students or \"q\" to quit the pogram: ";
  char c = 0;
  while (1) {
    printf(prompt);
    do { scanf("%c", &c); } while (c == '\n');

    if (c == 'a') {
      makeStudent(&students[*i]); // Shorter: makeStudent(&student+*i);
      *i = *i + 1;
      }
    else if (c == 'p') printAllStudents(students, *i);
    else if (c == 'd') {
      int id = i;
      printf("The student with which id, do you want to delete? ");
      scanf("%d", &id);
      deleteStudent(&students[id]);
      swap_people(&students[id], &students[*i]);
      *i = *i - 1;
      }
    else if (c == 'q') break;
    else /* if (c != '\n') */ printf("How difficult is it to type a single letter???? Try again, dumbass!\n");
    }
  }


void main() {
  person students[100];
  int studentCounter = 0;

  menu(students, &studentCounter);
  // print_student(&students[i]);
  // or simpler:
  // print_student(students+i);      // Note, that this addition of i to a pointer is special as it considers the size of type pointed to
  }




