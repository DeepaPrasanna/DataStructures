// Inserting in an empty circular linked list
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};
/*
performs insertion when the list is empty
*/
void addToEmpty(struct Node **head_ref, int data) 
{ 
    // This function is only for empty list 
    if (*head_ref != NULL) 
    return; 

    // Creating a node dynamically. 
    struct Node *new_node = 
        (struct Node*)malloc(sizeof(struct Node)); 

    // Assigning the data. 
    new_node -> data = data; 

    // Note : list was empty. We link single node 
    // to itself. 
    new_node -> next = new_node; 
    *head_ref = new_node;
    // return last; 
} 

/*
traversing the nodes

*/
void printList(struct Node *head)
{
    struct Node *temp  = head;

    //if the list is empty, return
    if (head == NULL)
    {
        printf("List is empty");
        return;
    }
    int count = 0;
    //if the list is not empty, traverse
    do
    {
        printf("%d ", temp->data);
        temp = temp->next;
        count++;
    } while (temp != head);
    printf("\nThe no. of nodes are %d\n", count);
}

void main()
{
    //create a head pointer to mark the beginning of the List
    struct Node *head = NULL;

    //insert to an empty list
    addToEmpty(&head,7);

    //print the node values by traversing the Circular Linked List
    printList(head);

}