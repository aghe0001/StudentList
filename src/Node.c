#include <stdio.h>
#include <stdlib.h>
#include "Node.h" // include Node.h header for implementing all functions defined in it


/*
Prints all student names in the following format
LastName, firstName
*/
void print_list(node_t* head)
{
// continue loop until head becomes NULL
while(head != NULL){
    // check if student_ptr is not NULL
    if(head->student_ptr != NULL){
      printf("%s %s\n", head->student_ptr->last_name, head->student_ptr->first_name);
    }
    // goto next node in the list
    head = head->next;
}
}

/*
Adds a new node to the end of the list
*/
void addToEnd(node_t** head, student_t* student)
{
// if *head is NULL
if(*head == NULL){
    // add new node to the head
    // allocate memory to head
    *head = (node_t*)malloc(sizeof(node_t));
    // assign student to student_ptr
    (*head)->student_ptr = student;
    // set next pointer to NULL
    (*head)->next = NULL;
}else{
    // if head is not null
    node_t* temp = *head;
    // continue loop until next node beomes NULL
    while(temp->next != NULL){
      temp = temp->next;
    }
    // add newnode to the next node
    temp->next = (node_t*)malloc(sizeof(node_t));
    temp->next->student_ptr = student;
    temp->next->next = NULL;
}
}

/*
Adds new node to the beginning of the list
*/
void addToStart(node_t** head, student_t* student)
{
// if *head is NULL, see above function
if(*head == NULL){
    *head = (node_t*)malloc(sizeof(node_t));
    (*head)->student_ptr = student;
    (*head)->next = NULL;
}else{
    // create newnode by allocating memory to it
    node_t* newnode = (node_t*)malloc(sizeof(node_t));
    // assign student to student_ptr
    newnode->student_ptr = student;
    // set next of newnode to head
    newnode->next = *head;
    // and then set head points to newnode
    *head = newnode;
}
}

/*
Remove the first node from the list
*/
void removeFromStart(node_t** head)
{
// get head to the temporary variable
node_t* temp = *head;
// if head is NULL then return from function
if(*head == NULL)
    return;
// set head to next of head
*head = (*head)->next;
// delete temp (head)
free(temp);
}

/*
Remove the last node from the list
*/
void removeLast(node_t** head)
{
// temporary variable for looping through list
node_t* temp = *head;
// previous variable to store previous node as we loop through
node_t* prev = NULL;
// if head is NULL then return
if(*head == NULL)
    return;
// if next of head is NULL then delete head(temp) and return
if(temp->next == NULL){
    free(temp);
    *head = NULL;
    return;
}
// otherwise loop until next node of temp becomes NULL
while(temp->next != NULL){
    // get previous before moving to next node
    prev = temp;
    temp = temp->next;
}
// set previous of next to NULL
prev->next = NULL;
// and finally delete temp
free(temp);
}

/*
Remove a node by index
*/
void remove_by_index(node_t** head, int n)
{
// temporary variable for looping through list
node_t* temp = *head;
// previous variable to store previous node as we loop through
node_t* prev = NULL;
// if head(temp) is NULL then return
if(temp == NULL)
    return;
// if index is less than or equal to 0 then return
if(n <= 0)
    return;
// if index is 1, then there is only one element in the list
if(n == 1){
    // remove that element and return
    removeFromStart(&(*head));
    return;
}

// loop until temp becomes NULL
while(temp != NULL){
    // decrement index by 1
    n--;
    // if index becomes 0 the exit from loop
    if(n == 0){
      break;
    }else{
      // otherwise get previous and next node
      prev = temp;
      temp = temp->next;
    }
}

// if index is still not 0, then index is high than there are elements in the list
if(n != 0)
    return;

// if temp and its next is not null, means middle
// temp points to the node that needs to be deleted
if(temp != NULL && temp->next != NULL){
    // set next of prev to next of temp and delete temp
    prev->next = temp->next;
    free(temp);
// otherwise temp is the last element in the list
}else if(temp != NULL && temp->next == NULL){
    // delete next of previous
    free(prev->next);
    prev->next = NULL;
}
}
