#include <stdio.h>
#include <stdlib.h>

struct node;
typedef struct node Node;

struct node
{
    int data;
    Node* next;
};

Node* reverse_linked_list(Node* head);


int main(int argc, char* argv[])
{
    Node* head = NULL;
    int i;
    Node* temp;

    //set up a test list with values 9->8->7->...->0
    for (i = 0; i < 10; i++)
    {
        temp = (Node*)malloc(sizeof(Node));
        if (temp == NULL)
        {
            printf("out of memory?\n");
            exit(1);
        }
        temp->data = i;
        temp->next = head;
        head = temp;
    }

    head = reverse_linked_list(head);
    //print the reversed list.
    temp = head;
    while (temp != NULL)
    {
        printf("%d\n", temp->data);
        temp = temp->next;
    }

    return 0;
}


Node* reverse_linked_list(Node* head){
    Node* previous = NULL;
    Node* next = head;
    while(head != NULL){
        next = next->next;
        head->next = previous;
        previous = head;
        head = next;
    }
    return previous;
}

