#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *next;
    struct node *prev;
}node;

node *getNode(int data){
    node *newNode = (node *) malloc(sizeof(node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->next = NULL;
    return newNode;
}

void insertAtTail(node **head, int data){
    node *newNode = getNode(data);
    node *temp = *head;
    if(*head == NULL){
        *head = newNode;
        return;
    }
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
}

void insertAtHead(node **head, int data){
    node *newNode = getNode(data);
    node *temp = *head;
    if(*head == NULL){
        *head = newNode;
        return;
    }
    temp->prev = newNode;
    newNode->next = temp;
    *head = newNode;
}

void printList(node *start){
    while(start != NULL){
        printf("%d ", start->data);
        start = start->next;
    }
    printf("\n");
}

void printListR(node *start){
    while(start->next != NULL){
        start = start->next;
    }
    while(start != NULL){
        printf("%d ", start->data);
        start = start->prev;
    }
    printf("\n");
}

node *recur_reverse(node *current){

    node *temp = current->next;
    current->next = current->prev;
    current->prev = temp;

    if(current->prev == NULL)
        return current;

    return recur_reverse(current->prev);
    
}

void recursionR(node **head, node *current){
    node *temp = current->next;
    current->next = current->prev;
    current->prev = temp;
    if(current->prev == NULL){
        *head = current;
        return;
    }
    recursionR(head, current->prev);
}

void reverse(node **head){
    node *temp = NULL;
    node *current = *head;
    while(current != NULL){
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }
    *head = temp->prev;
}

int main(){
    node *head = NULL;
    for(int i = 0; i < 5; ){
        insertAtHead(&head, ++i);
    }
    printList(head);
    recursionR(&head, head);
    printList(head);
}
