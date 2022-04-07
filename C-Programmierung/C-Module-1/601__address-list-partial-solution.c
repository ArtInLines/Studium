/* address_list.c */
// This program should be completed such that it maintains a list of students
// TO DO 1: Write a function inputStudent(int i), which allows the user to enter first name and last name and stores it at position i in the array.
// TO DO 2: Use a variable to count the number of students stored in the array.
// TO DO 3: Write a function printStudent(i), which prints the students stored in the array
// TO DO 4: Write functions addStudent(), for adding a student at the end of the array, and printAllStudents() for printing all students stored.
// TO DO 5: Write a function menu(), which allows the user to select one of the actions
//            - add Student
//            - print all students
//            - Quit program
// TO DO 6: Extend the student data and the corresponding functions with the gender male/female (using "enum").
// TO DO 7: Create a structure for handling dates (day, month, year) and use it for birth date, date of enrollment etc. 
// TO DO 8: Extend the program such it also handles address information (street, number, zip-code and city).
// TO DO 9: optionally: Add a function and menu item for deleting a selected student.
// TO DO 10: Optionally: Add a function to sort the data according to given criteria

#include <stdio.h>

enum gender_enum
{
	male, female
};

struct person
{
   char first_name[30];
   char last_name[30];
   enum gender_enum gender;
};


struct person students[100];

int count;

void inputStudent(int i)
{
	char mf;
	printf("Student #%d\nVorname?",i);
	scanf("%s",students[i].first_name);
	printf("Nachname?");
	scanf("%s",students[i].last_name);
	do {
		printf("Geschlecht (m/w)?");
		scanf("\n%c", &mf);
		students[i].gender = mf=='m'? male : female;
	} while (mf != 'm' && mf != 'w');
}

void printStudent(int i)
{
	printf(students[i].gender == male ? "Herr" : "Frau");
	printf(" %s %s", students[i].first_name, students[i].last_name);
    printf("\n");
}

void printAllStudents()
{
   int i;
   for(i=0; i<count; i++)
      printStudent(i);
}

void addStudent()
{
   inputStudent(count++);
}

void menu()
{
    // TO DO ...
}

int main()
{
    count=0;
   
    addStudent();
    addStudent();
    addStudent();
    printAllStudents();
	getchar(); getchar();
}