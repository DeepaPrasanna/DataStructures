// Inserting the nodes at the beginning of the Circular Linked List
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

/*
inserting the nodes at the beginning of the List

*/
void push(struct Node **head_ref, int new_data)
{
    //create a new node. Allocate the memory
    struct Node *new_node= (struct Node*)malloc(sizeof(struct Node));

    //a temporary variable
    struct Node *temp = *head_ref;

    //allocate data to the new node
    new_node->data = new_data;
    new_node->next = *head_ref; //whatever the head is pointing to
    
    if (*head_ref != NULL)
    {
        while(temp->next != *head_ref)
        {
            temp = temp->next;
        }
        temp->next = new_node;
    }
    else
    {
        new_node->next = new_node; 
    }
    *head_ref = new_node;
    
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
    //if the list is not empty, traverse
    do
    {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
    
}

void main()
{
    //create a head pointer to mark the beginning of the List
    struct Node *head = NULL;

    //inserting nodes at the beginning
    push(&head, 10);
    push(&head, 20);
    push(&head, 30);
    push(&head, 40);
    push(&head, 50);

    //print the node values by traversing the Circular Linked List
    printList(head);

}




