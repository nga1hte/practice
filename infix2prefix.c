//Implementation of stack using arrays created in a struct
#include <stdio.h>
#include <stdlib.h>

typedef struct stack{
    int maxSize;
    int top;
    char *items;
}stack;

stack *newStack(int size){
    stack *ptr = (stack *) malloc(sizeof(stack));
    ptr->maxSize = size;
    ptr->top = -1;
    ptr->items = (char *)malloc(sizeof(char) * size);
    return ptr;
}

int size(stack *ptr){ return ptr->top+1; }
int isEmpty(stack *ptr){ return (ptr->top == -1);}
int isFull(stack *ptr){ return (ptr->top == ptr->maxSize - 1);}

void push(stack *ptr, char data){
    if(isFull(ptr)){
        printf("Stack is full!\n");
        return;
    }
    ptr->items[++ptr->top] = data;
}

char top(stack *ptr){
    if(isEmpty(ptr)){
        printf("Stack is empty!\n");
        return 0;
    }
    return ptr->items[ptr->top];
}

char pop(stack *ptr){
    if(isEmpty(ptr)){
        printf("Stack is empty!\n");
        return 0;
    }
    return ptr->items[ptr->top--];
}

int main(){
    stack *intStack = newStack(5);
    printf("Empty: %d\n", isEmpty(intStack));
    push(intStack, 'a');
    push(intStack, 'b');
    printf("%d\n", top(intStack));
    printf("Full: %d\n", isFull(intStack));
    pop(intStack);
    printf("%d\n", top(intStack));
    printf("Full: %d\n", isFull(intStack));
    return 0;
}

