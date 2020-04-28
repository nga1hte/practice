#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *next;
}node;

node *head = NULL;

node *stack[10];
int top = -1;

node *getNode(int data){
    node *newNode = (node *) malloc(sizeof(node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertAtHead(int data){
    node *newNode = getNode(data);
    newNode->next = head;
    head = newNode;
}

void printList(){
    node *temp = head;
    while(temp != NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void push(node *x){
    stack[++top] = x;
}

void pop(){
    --top;
}

int isEmpty(){
    if(top == -1) return 1;
    return 0;
}

node *Top(){
    return stack[top];
}

void Reverse(){
    node *temp = head;
    while(temp->next != NULL){
        push(temp);
        temp = temp->next;
    }
    head = temp;
    while(!isEmpty()){
        temp->next = Top();
        temp = temp->next;
        pop();
    }
    temp->next = NULL;
}

int main(){
    for(int i = 5; i > 0; i--){
        insertAtHead(i);
    }
    printList();
    Reverse();
    printList();

    return 0;
}
