/*
 *
 * Name        : Assignment2.c
 * Title	   : Assignment 2 - Student Registration System
 * Course      : CST8234 - C Language
 * Term        : Summer 2020
 * Author      : <<< Kunjesh_Aghera (aghe0001) >>>
 *	 	 	     <<< Vraj_Patel (pate0787) >>>
 * Version     :
 * Copyright   : Your copyright notice
 * Status:
 *	 	 Requirement #1: complete
 *	 	 Requirement #2: complete
 *	 	 Requirement #3: complete
 *	 	 Requirement #4: complete
 *	 	 Requirement #5: complete
 *	 	 Requirement #6: complete
 *	 	 Requirement #7: complete
 *	 	 Requirement #8: complete
 *	 	 Requirement #9: complete
 *	 	 Requirement #10: complete
 *	 	 Requirement #11: complete
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Node.h" // include Node.h header which is implement by us for using student list

/*
 Returns pointer to student with memory allocated to student
 */
static student_t* getNewStudentPointer(char *firstname, char *lastname) {
// allocate memory to student
	student_t *newstudent = (student_t*) malloc(sizeof(student_t));
	if (newstudent == NULL)
		return NULL;
// allocate memory to first and last names as their lengths
	newstudent->first_name = (char*) malloc(strlen(firstname) + 1);
	newstudent->last_name = (char*) malloc(strlen(lastname) + 1);
// copy names to student

	strcpy(newstudent->first_name, firstname);
	strcpy(newstudent->last_name, lastname);
// return student
	return newstudent;
}

int main() {
	//TODO: https://wiki.eclipse.org/CDT/User?FAQ#Eclipse_console_does_not_show_output_on_windows
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);
// head of the list
	node_t *head = NULL;
// each student
	student_t *student = NULL;
// first and last name character array to be read
	char firstname[256], lastname[256];

	printf("First, you will enter 3 student names that will be added to the start of the list\n");

	printf("Please enter first name for student 1: ");

	scanf("%s", firstname);

	printf("Please enter last name for student 1: ");

	scanf("%s", lastname);

	student = getNewStudentPointer(firstname, lastname);

	addToStart(&head, student);

	printf("Please enter first name for student 2: ");

	scanf("%s", firstname);

	printf("Please enter last name for student 2: ");

	scanf("%s", lastname);

	student = getNewStudentPointer(firstname, lastname);

	addToStart(&head, student);

	printf("Please enter first name for student 3: ");

	scanf("%s", firstname);

	printf("Please enter last name for student 3: ");

	scanf("%s", lastname);

	student = getNewStudentPointer(firstname, lastname);

	addToStart(&head, student);

	print_list(head);

	printf("Then, you will enter 3 student names that will be added to the end of the list\n");

	printf("Please enter first name for student 1: ");

	scanf("%s", firstname);

	printf("Please enter last name for student 1: ");

	scanf("%s", lastname);

	student = getNewStudentPointer(firstname, lastname);

	addToEnd(&head, student);

	printf("Please enter first name for student 2: ");

	scanf("%s", firstname);

	printf("Please enter last name for student 2: ");

	scanf("%s", lastname);

	student = getNewStudentPointer(firstname, lastname);

	addToEnd(&head, student);

	printf("Please enter first name for student 3: ");

	scanf("%s", firstname);

	printf("Please enter last name for student 3: ");

	scanf("%s", lastname);

	student = getNewStudentPointer(firstname, lastname);

	addToEnd(&head, student);

	print_list(head);

	printf("Then, you will remove the first 3 students from the list\n");
	removeFromStart(&head);
	removeFromStart(&head);
	removeFromStart(&head);

	print_list(head);

	printf("Then, you will remove the last 3 students from the list\n");
	removeLast(&head);
	removeLast(&head);
	removeLast(&head);

	print_list(head);

	printf("By now, your list should be empty, so you will enter 3 more students\n");

	printf("Please enter first name for student 1: ");

	scanf("%s", firstname);

	printf("Please enter last name for student 1: ");

	scanf("%s", lastname);

	student = getNewStudentPointer(firstname, lastname);

	addToEnd(&head, student);

	printf("Please enter first name for student 2: ");

	scanf("%s", firstname);

	printf("Please enter last name for student 2: ");

	scanf("%s", lastname);

	student = getNewStudentPointer(firstname, lastname);

	addToEnd(&head, student);

	printf("Please enter first name for student 3: ");

	scanf("%s", firstname);

	printf("Please enter last name for student 3: ");

	scanf("%s", lastname);

	student = getNewStudentPointer(firstname, lastname);

	addToEnd(&head, student);

	print_list(head);

	printf("Finally, you will delete the second student in the list\n");

	remove_by_index(&head, 2);

	print_list(head);

	printf("Program ended with exit code: 0");
	return 0;
}

