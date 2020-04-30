//Implementation of stack using arrays created in a struct
#include <stdio.h>
#include <stdlib.h>

typedef struct stack{
    int maxSize;
    int top;
    int *items;
}stack;

stack *newStack(int size){
    stack *ptr = (stack *) malloc(sizeof(stack));
    ptr->maxSize = size;
    ptr->top = -1;
    ptr->items = (int *)malloc(sizeof(int) * size);
    return ptr;
}

int size(stack *ptr){ return ptr->top+1; }
int isEmpty(stack *ptr){ return (ptr->top == -1);}
int isFull(stack *ptr){ return (ptr->top == ptr->maxSize - 1);}

void push(stack *ptr, int data){
    if(isFull(ptr)){
        printf("Stack is full!\n");
        return;
    }
    ptr->items[++ptr->top] = data;
}

int top(stack *ptr){
    if(isEmpty(ptr)){
        printf("Stack is empty!\n");
        return 0;
    }
    return ptr->items[ptr->top];
}

int pop(stack *ptr){
    if(isEmpty(ptr)){
        printf("Stack is empty!\n");
        return 0;
    }
    return ptr->items[ptr->top--];
}

int main(){
    stack *intStack = newStack(5);
    printf("Empty: %d\n", isEmpty(intStack));
    for(int i = 0; i < 5;){
        push(intStack, ++i);
    }
    printf("%d\n", top(intStack));
    printf("Full: %d\n", isFull(intStack));
    pop(intStack);
    printf("%d\n", top(intStack));
    printf("Full: %d\n", isFull(intStack));
    return 0;
}

