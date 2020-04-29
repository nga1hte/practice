#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct stack{
    char data;
    struct stack *next;
}stack;

stack *Top = NULL;

//Stack operations
stack *getStack(char data);
void push(char data);
char pop();
char top();
int isEmpty();

int perform(char o, char a, char b);
void evaluatePostfix(char *str);

int main(){
    char str[] = "2 2*2 2*+1+";
    evaluatePostfix(str);
    printf("%c\n", top());
    return 0;
}
int perform(char o, char a, char b){
    int result;
    switch(o){
        case '+':
            result = (a - '0') + (b - '0');
            break;
        case '*':
            result = (a - '0') * (b - '0');
            break;
        case '-':
            result = (a - '0') - (b - '0');
            break;
        case '/':
            result = (a - '0') / (b - '0');
            break;
    }
    return result;
}

void evaluatePostfix(char *str){
    int len = strlen(str);
    char op1, op2;
    int result;
    for(int i = 0; i < len; i++){
        switch(str[i]){
            case ' ':
                continue;
            case '*':
            case '+':
            case '-':
            case '/':
               op1 = pop();
               op2 = pop();
               result = perform(str[i], op1, op2); 
               push(result + '0');
               break;
            default:
                push(str[i]);
        }
    }
}

stack *getStack(char data){
    stack *newStack = (stack *) malloc(sizeof(stack));
    newStack->data = data;
    newStack->next = NULL;
    return newStack;
}

void push(char data){
    stack *newStack = getStack(data);
    newStack->next = Top;
    Top = newStack;
}

char pop(){
    if(Top == NULL){
        printf("Stack is empty!\n");
    }
    stack *newStack = Top->next;
    char data = Top->data;
    free(Top);
    Top = newStack;
    return data;
}

char top(){
    return Top->data;
}

int isEmpty(){
    if(Top == NULL) return 1;
    return 0;
}



