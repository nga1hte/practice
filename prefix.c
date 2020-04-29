#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct stack{
    int data;
    struct stack *next;
}stack;

stack *Top = NULL;

//Stack operations
stack *getStack(int data);
void push(int data);
int pop();
int top();
int isEmpty();
int perform(char o, int a, int b);
void evaluatePrefix(char *str);
int isOperator(char s);
int isNumeric(char s);

int main(){
    char str[100];
    scanf("%s", str);
    evaluatePrefix(str);
    printf("%d\n", top());
    return 0;
}

int isOperator(char s){
    switch(s){
        case '*':
        case '/':
        case '+':
        case '-':
            return 1;
        default:
            return 0;
    }
}

int isNumeric(char s){
    if(s >= '0' && s <= '9') return 1; 
    return 0;
}


int perform(char o, int a, int b){
    int result;
    switch(o){
        case '+':
            result = a + b;
            break;
        case '*':
            result = a * b;
            break;
        case '-':
            result = a - b;
            break;
        case '/':
            result = a / b;
            break;
        default:
            result = -1;
    }
    return result;
}

void evaluatePrefix(char *str){
    int len = strlen(str);
    int op1, op2;
    int result;
    for(int i = len - 1; i >= 0; i--){
        if(str[i] == ' ' || str[i] == ',') continue;
        else if(isOperator(str[i])){
               op1 = pop();
               op2 = pop();
               result = perform(str[i], op1, op2); 
               push(result);
        }else if(isNumeric(str[i])){
               int operand = 0;
               while(i >= 0 && isNumeric(str[i])){
                   operand = (operand * 10) + (str[i] - '0');
                   i--;
               }
               i++;
               push(operand);
        }
    }
}

stack *getStack(int data){
    stack *newStack = (stack *) malloc(sizeof(stack));
    newStack->data = data;
    newStack->next = NULL;
    return newStack;
}

void push(int data){
    stack *newStack = getStack(data);
    newStack->next = Top;
    Top = newStack;
}

int pop(){
    if(Top == NULL){
        printf("Stack is empty!\n");
    }
    stack *newStack = Top->next;
    int data = Top->data;
    free(Top);
    Top = newStack;
    return data;
}

int top(){
    return Top->data;
}

int isEmpty(){
    if(Top == NULL) return 1;
    return 0;
}



