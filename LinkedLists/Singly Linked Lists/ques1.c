// C program to create nodes in a linked list and traverse them (printing to the console the linked list)

#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node* next; //next is a pointer variable of node datatype
};

void printList(struct Node* head)
{
    while (head != NULL)
    {
        printf(" %d ", head->data);
        head=head->next;
    }
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

    //print the contents of the linked list from the start to the end
    printList(head);

    return 0;
}
