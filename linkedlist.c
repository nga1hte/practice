#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *next;
}node;

node *getNode(int data){
    node *newNode = (node *) malloc(sizeof(node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

node *push(node *head,int data){
    if(head == NULL)
        head = getNode(data);
    else
        head->next = push(head->next, data);
    return head;
}

//iterative method
void deleteI(node *head, int data){
    if(head == NULL) return;
    node *prev = head;
    while(head != NULL){
        if(head->data == data){
            prev->next = head->next;
            free(head);
            return;
        }
        prev = head;
        head = head->next;
    }
}

node *delete(node *head, int data){
    if(head == NULL) return head;
    else if(head->data == data){
        node *tmp = head;
        head = head->next;
        free(tmp);
    }else head->next = delete(head->next, data);
    return head;

    
}

void print_list(node *head){
    if(head == NULL) return;
    printf("%d ", head->data);
    print_list(head->next);
}

int main(){
    node *head = NULL;
    print_list(head);
    head = push(head, 1);
    head = push(head, 2);
    head = push(head, 3);
    head = push(head, 4);
    print_list(head);
    printf("\n");
    head = delete(head, 4);
    print_list(head);
    printf("\n");
}
