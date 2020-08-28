// Inserting the node in middle of two nodes in the Circular Linked List
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
void addAfter(struct Node *head, int data, int item) 
{ 
    //if the list is empty
    if(head == NULL)
    {
        return;
    }
    struct Node *temp, *p;
    p = head->next;
    do
    {   
        // when the data matches with the item
        if(p->data == item)
        {   
            // creating a temp node dynamically
            temp = (struct Node *)malloc(sizeof(struct Node));
            temp->data = data;
            temp->next = p->next;
            p->next = temp;

            //checking for the node from which it started traversing
            if(p == head)
            {   
                head = temp;
            }
            return;

        }
        p = p->next;
    }while(p != head->next);

    //this line is executed when it fails to match the serached data
    printf("The data is not present in the list");
    return;
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

    //inserting nodes at the beginning
    push(&head, 10);
    push(&head, 20);
    push(&head, 30);
    push(&head, 40);
    push(&head, 50);
    addAfter(head, 100, 10);
    
    

    //print the node values by traversing the Circular Linked List
    printList(head);

}




