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
}

void insertAtHead(node **head, int data){
    node *newNode = getNode(data);
    node *temp = *head;
    newNode->next = *head;
    *head = newNode;
}

void printList(node *start){
    while(start != NULL){
        printf("%d ", start->data);
        start = start->next;
    }
    printf("\n");
}

int main(){
    node *head = NULL;
    for(int i = 0; i < 5; ){
        insertAtHead(&head, ++i);
    }
    printList(head);
}
