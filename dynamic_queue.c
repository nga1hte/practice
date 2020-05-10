#include <stdio.h>
#include <stdlib.h>

typedef struct queue{
    int data;
    struct queue *next;
}queue;

queue *front = NULL;
queue *rear = NULL;

void enqueue(int data){
    queue *newData = (queue *) malloc(sizeof(queue));
    newData->data = data;
    newData->next = NULL;
    if(front == NULL && rear == NULL){
        front = rear = newData;
        return;
    }
    rear->next = newData;
    rear = newData;
}

void dequeue(){
    queue *temp = front;
    if(front == NULL ){
        printf("Queue is empty!");
        return;
    } 
    if(front == rear){
        front = rear = NULL;
    }else{
        front = front->next;
    }
    free(temp);
}

int isEmpty(){
    return (front == NULL);
}

int top(){
    if(!isEmpty())
        return front->data;
    return -1;
}

void printQ(){
    queue *temp = front;
    while(temp != NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main(){
    printf("empty: %d\n", isEmpty());
    enqueue(1); printQ();
    enqueue(2); printQ();
    enqueue(3); printQ();
    dequeue();printQ();
    printf("%d\n", top());
    return 0;

}
