// A complete working C program to demonstrate deletion in singly 
// linked list
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next; 
};

void printList(struct Node *node)
{
    while(node != NULL)
    {
        printf("%d ,",node->data);
        node = node->next;
    }
    printf("\n");
}

void push(struct Node **head_ref, int new_data)
{
    //creating a new node and allocating memory
    struct Node *new_node = (struct Node*)malloc(sizeof(struct Node));

    new_node->data = new_data;
    //make the new node point to the current first node
    new_node->next = *head_ref;

    //make the head point to the new node
    *head_ref = new_node;

}

void deleteNode(struct Node **head_ref, int key)
{
    //store the head node in a temp field, and make a node named prev
    struct Node *temp, *prev;
    temp = *head_ref;

    //if head node itself holds the key to be deleted
    if (temp != NULL && temp->data == key)
    {
        //change the head
        *head_ref = temp->next;
        free(temp);
        return;
    }

    //iterate over the keys to find the key
    while (temp != NULL && temp->data != key)
    {
        prev = temp;
        temp = temp->next;
    }

    //if the key is not present
    if(temp == NULL)
    {
        return;
    }

    //unlink the node from the Linked List
    prev->next = temp->next;

    //delete the node
    free(temp);
}

void main()
{
    //head is initially not pointing to anything
    struct Node *head = NULL;

    //inserting values into the Linked List
    push(&head, 1);
    push(&head, 2);
    push(&head, 3);
    push(&head, 4);
    push(&head, 5);

    //print all the nodes in the linked list
    printList(head);

    //deleting a node of a particular key(data)
    deleteNode(&head, 3);

    //print all the nodes after the deletion
    printList(head);

}