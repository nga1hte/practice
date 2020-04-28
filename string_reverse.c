#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 50

char stack[MAX];
int top = -1;

void push(char x){
    stack[++top] = x;
}

void pop(){
    if(top == -1){
        printf("Stack is empty!\n");
        return;
    }
    --top;
}

char Top(){
    return stack[top];
}

int empty(){
    if(top == -1) return 0;
    return 1;
}

void Reverse(char *c, int n){
    for(int i = 0; i < n; i++)
        push(c[i]);
    for(int i = 0; i < n; i++){
        c[i] = Top();
        pop();
    }

    
}

int main(){
    char str[51];
    printf("Enter string:");
    scanf("%s", str);
    Reverse(str, strlen(str));
    printf("Output = %s\n", str);
}
