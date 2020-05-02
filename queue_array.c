#include <stdio.h>
#include <stdlib.h>

typedef struct queue{
    int front;
    int rear;
    int *data;
    int maxSize;
}queue;

int isEmpty(queue *q){
    return (q->front == -1  && q->rear == -1);
}

int isFull(queue *q){
    return ((q->rear + 1) % q->maxSize == q->front);
}

void enQueue(queue *q, int data){
    if(isFull(q)){
        printf("Queue is already full!\n");
        return;
    }
    else if(isEmpty(q)){
        q->front = 0;
        q->rear = 0;
    }else{
        q->rear = ((q->rear) + 1) % q->maxSize;
    }
    q->data[q->rear] = data;
}

int deQueue(queue *q){
    int data = q->data[q->front];
    if(isEmpty(q)){
        printf("Queue is already empty!\n");
        return -1;
    }else if(q->front == q->rear){
        q->front = -1;
        q->rear = -1;
    }else{
        q->front = (q->front) + 1 % q->maxSize;;
    }
    return data;
}

int Front(queue *q){
    if(isEmpty(q)){
        printf("Queue is empty!\n");
        return -1;
    }
    return q->data[q->front];
}

queue *createQueue(int max){
    queue *newStack = (queue *) malloc(sizeof(queue));
    newStack->front = -1;
    newStack->rear = -1;
    newStack->maxSize = max;
    newStack->data = (int *) malloc(sizeof(int)*max);
    return newStack;
}

int main(){
    queue *q = createQueue(10);
    for(int i = 0; i < 10;)
        enQueue(q, ++i);
    while(!isEmpty(q)){
        printf("%d ", Front(q));
        deQueue(q);
    }
    printf("\n");

    free(q);
    return 0;


}
