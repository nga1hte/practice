#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *next;
}node;

node *head = NULL;

node *getNode(int data){
    node *newNode = (node *) malloc(sizeof(node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void Push(int data){
    node *newNode = getNode(data);
    newNode->next = head;
    head = newNode;
}

void Pop(){
    if(head == NULL){
        printf("Stack is empty\n");
        return;
    }
    node *temp = head->next;
    free(head);
    head = temp;
}

void Head(){
    printf("%d\n", head->data);
}

void isEmpty(){
    if(head == NULL)
        printf("It is empty\n");
    else
        printf("It is not empty\n");
}

int main(){
    isEmpty();
    Push(1);
    Push(2);
    Push(3);
    Head();
    Pop();
    Head();
}
