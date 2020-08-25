// A complete working C program to delete all the node in a linked list 
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
void deleteList(Node **head_ref)
{
    Node *current, *next;
    //set current node as head node
    current = *head_ref;
    //check if current node is not null
    if (current ==  NULL)
    {
        return;
    }
    while(current != NULL)
    {
        //set next as next of current node
        next = current->next;

        //free current node from memory
        free(current);

        //move the current node to next node
        current = next;
    }

    *head_ref = NULL;
    printf("All the nodes are deleted");
    
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
    deleteList(&head);

    //print all the nodes after the deletion
    printList(head);

}