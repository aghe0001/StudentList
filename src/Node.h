/*
 * Node.h
 *
 *  Created on: Aug 6, 2020
 *      Author: User
 */

#ifndef Node_h
#define Node_h

// student structure having first name & last name
struct student{
char* first_name;
char* last_name;
};

// define struct student to type student_t
typedef struct student student_t;

// Node structure having student_t pointer and next student pointer
// pointing to next Node
struct Node{
student_t *student_ptr;
struct Node* next;
};

// define struct Node to type node_t
typedef struct Node node_t;

/*
Prints all student names in the following format
LastName, firstName
*/
void print_list(node_t* head);

/*
Adds a new node to the end of the list
*/
void addToEnd(node_t** head, student_t* student);

/*
Adds new node to the beginning of the list
*/
void addToStart(node_t** head, student_t* student);

/*
Remove the first node from the list
*/
void removeFromStart(node_t** head);

/*
Remove the last node from the list
*/
void removeLast(node_t** head);

/*
Remove a node by index
*/
void remove_by_index(node_t** head, int n);

#endif
