// A complete working C program to delete a node in a linked list 
// at a given position 
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
}Node;

void printList(Node *node)
{
    while(node != NULL)
    {
        printf("%d ,",node->data);
        node = node->next;
    }
    printf("\n");
}

void push(Node **head_ref, int new_data)
{
    //creating a new node and allocating memory
    Node *new_node = (Node*)malloc(sizeof(Node));

    new_node->data = new_data;
    //make the new node point to the current first node
    new_node->next = *head_ref;

    //make the head point to the new node
    *head_ref = new_node;

}
void deleteNode(Node **head_ref, int pos)
{
    //check if the Linked list is not empty
    if (*head_ref == NULL)
    {
        return;
    }
    //store the head node in a temp variable, and make a node named prev
    Node *temp = *head_ref, *prev;

    //if the node to be deleted is at the root, i.e pos = 0
    if (pos == 0)
    {
        *head_ref = temp->next; // change head
        free(temp);             //free the old head 
        return; 
    } 
    //find the prev node
    for (int i = 0;temp != NULL && i < pos;i++)
    {
        prev = temp;
        temp = temp->next;
    }
    //check if the position value is not greater the no. of nodes
    if (temp == NULL && temp->next == NULL)
    {
        return;
    }
    //make the prev node point to the next of the temp
    prev->next = temp->next;
    free(temp);

}
void main()
{
    //head is initially not pointing to anything
    Node *head = NULL;

    //inserting values into the Linked List
    push(&head, 1);
    push(&head, 2);
    push(&head, 3);
    push(&head, 4);
    push(&head, 5);

    //print all the nodes in the linked list
    printList(head);

    //deleting a node at a particular position. Here, at position 3
    deleteNode(&head, 3);

    //print all the nodes after the deletion
    printList(head);

}