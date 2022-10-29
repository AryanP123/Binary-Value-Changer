#include <stdio.h>
#include <stdlib.h>

struct node;
typedef struct node Node;

struct node
{
    int data;
    Node* next;
};

//declare your function here.
Node* reverse_linked_list(Node* head);
void print_list(Node* head);
void head_insert(Node** head , int num);
Node* list_sum(Node* head1, Node* head2);
void destroy_list(Node* head);

int main(int argc, char* argv[])
{
    //add up 189 + 11
    Node* head1 = NULL;
    Node* head2 = NULL;
    Node* head_sum = NULL;
    //create a list for the number 189
    head_insert(&head1, 9);
    head_insert(&head1, 8);
    head_insert(&head1, 1);
    //create a list for the number 11
    head_insert(&head2, 1);
    head_insert(&head2, 1);
    head_sum = list_sum(head1, head2);
    printf("The sum of ");
    print_list(head1);
    printf(" + ");
    print_list(head2);
    printf("\n");
    printf(" = ");
    print_list(head_sum);
    printf("\n");
    //clean up three lists
    destroy_list(head1); head1 = NULL;
    destroy_list(head2); head2 = NULL;
    destroy_list(head_sum); head_sum = NULL;
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

void print_list(Node* head){
    while(head != NULL){
        printf("%d", head->data);
        head = head->next;
    }
}

void head_insert(Node** head , int num){
    Node* temp;
    temp = (Node*)malloc(sizeof(Node));
    if(temp == NULL){
        printf("failed to allocated space for node with value %d", num);
        exit(1);
    }
    temp->data = num;
    temp->next = *head;
    *head = temp;
}

Node* list_sum(Node* head1, Node* head2){
    Node* list_sum = NULL;
    Node* temp_head = NULL;
    Node* temp;
    head1 = reverse_linked_list(head1);
    head2 = reverse_linked_list(head2);
    int i = 0, j = 0;
    temp = head1;
    while (temp != NULL){
        temp = temp->next;
        i++;
    }
    temp = head2;
    while (temp != NULL){
        temp = temp->next;
        j++;
    }
    if(i>=j){
        temp = head1;
        temp_head = head2;
    }else{
        temp = head2;
        temp_head = head1;
    }
    while(temp != NULL){
        head_insert(&list_sum, temp->data);
        temp = temp->next;
    }
    temp = NULL;
    while(list_sum != NULL){
        head_insert(&temp, list_sum->data);
        list_sum = list_sum->next;
    }
    i = 0;
    list_sum = NULL;
    while(temp != NULL){
        if(temp_head != NULL){
            temp->data = temp->data + temp_head->data;
        }
        if(temp->data > 9){
            temp->data = temp->data - 10;
            if(temp->next == NULL){
                head_insert(&list_sum, 1);
            }else{
                temp->next->data += 1;
            }
        }
        if(temp_head != NULL){
            temp_head = temp_head->next;
        }
        head_insert(&list_sum, temp->data);
        temp = temp->next;
    }

    head1 = reverse_linked_list(head1);
    head2 = reverse_linked_list(head2);
    return list_sum;
}

void destroy_list(Node* head){
    Node* temp;
    while(head != NULL){
        temp = head;
        head = head->next;
        free(temp);
    }
}
