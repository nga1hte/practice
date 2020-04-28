#include <stdio.h>
#include <stdlib.h>
#define MAX 101

int a[MAX];
int itop = -1;

void push(int x){
    if(itop == MAX - 1){
        printf("Error: Stack overflow!\n");
        return;
    }
    a[++itop] = x;
}

void pop(){
    if(itop == -1){
        printf("Error: Stack is empty!\n");
    }
    --itop;
}

int top(){
    return a[itop]; 
}

int isEmpty(){
    return (itop == -1);
}

int main(){
    pop();
    push(1);
    push(2);
    pop();
    push(3);
    printf("%d\n", top());
    printf("%s\n", (isEmpty() ? "true" : "false"));
}
