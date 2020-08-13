// C program to perform insertion in a linked list

#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node* next; //next is a pointer variable of node datatype
};


//print all the contents in the linkedlist
void printList(struct Node* head)
{
    while (head != NULL)
    {
        printf(" %d ", head->data);
        head=head->next;
    }
}

//inserting node at the beginning
void push (struct Node **head_ref, int data)
{
    //create a new node
    struct Node* new_node = (struct Node*)(malloc(sizeof(struct Node)));

    new_node->data = data;
    //making the  new node point to the current first node
    new_node->next = *head_ref;

    //making the head point to the new node
    *head_ref = new_node;
}

//inserting node at the end of the list
void append (struct Node **head_ref, int data)
{
    //create a new node to insert
    struct Node *new_node = (struct Node*)(malloc(sizeof(struct Node)));
    new_node->data = data;

    //making this node pointer to null
    new_node->next = NULL;

    /*Check if there exits nodes in the linked list.
     *If exists, make the current the last node point to the last node
     *If not, make the head point to the last node*/

    struct Node *last = *head_ref;
    if (last == NULL)
    {
        *head_ref = new_node;
        return;
    }
    while (last->next != NULL)
    {
        last = last->next;
    }
    last->next = new_node;
    return;

}

//inserting node after node
void insertAfter (struct Node* prev_node, int data)
{
    if (prev_node == NULL)
    {
        printf("The previous node cannot be null");
        return;
    }

    //allocate a new node
    struct Node* new_node = (struct Node*)(malloc(sizeof(struct Node)));

    new_node->data = data;

    //make next of new node as next of previous node
    new_node->next = prev_node->next;

    //move the next of previous node to new node
    prev_node->next = new_node;

    return;
}
int main(void)
{
    //creating three nodes
    struct Node* head = NULL;
    struct Node* first = NULL;
    struct Node* second = NULL;

    //allocate enough memory in the heap
    head = (struct Node*)(malloc(sizeof(struct Node)));
    first = (struct Node*)(malloc(sizeof(struct Node)));
    second = (struct Node*)(malloc(sizeof(struct Node)));

    //assigning data to the first node and linking it with the second
    head->data = 8;
    head->next = first;

    //assigning data to the second node and linking it with the third
    first->data = 18;
    first->next = second;

    //assigning data to the third node and making it as the last node
    second->data = 4;
    second->next = NULL;

    //inserting nodes at the beginning of the list
    push(&head, 24);

    //inserting nodes at the end of the list
    append(&head, 56);

    //inserting nodes after another node (here, after 2nd node)
    insertAfter (head->next, 50);

    //print the contents of the linked list from the start to the end
    printList(head);

    return 0;
}
