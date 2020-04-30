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
void pop();
char top();
int isEmpty();
int isOperator(char s);
int isOperand(char s);
char *infixToPostfix(char *str);
int hasHigherPre(char a, char b);
int getWeight(char a);

int main(){
    char str[100];
    scanf("%s", str);
    char *s = infixToPostfix(str);
    printf("%s\n", s);
    return 0;
}

int getWeight(char a){
    int weight = -1;
    switch(a){
        case '+':
        case '-':
            weight = 1;
            break;
        case '*':
        case '/':
            weight = 2;
            break;
        case '^':
            weight = 3;
    }
    return weight;
}

int hasHigherPre(char a, char b){
    int op1 = getWeight(a);
    int op2 = getWeight(b);
    if(op1 == op2) return 1;
    return (op1>op2);
}

char *infixToPostfix(char *str){
    int len = strlen(str);
    char *s = malloc(sizeof(char)*len);
    int i, k;
    for(i = 0, k = 0; i < len; i++){
        if(isOperand(str[i])){
            s[k] = str[i];
            k++;
        }else if(isOperator(str[i])){
             while(!isEmpty() && top() != '(' && hasHigherPre(top(), str[i])){
                  s[k] = top();
                  pop();
                  k++;
             }
             push(str[i]);
        }else if(str[i] == '('){
            push(str[i]);
        }else if(str[i] == ')'){
            while(!isEmpty() && top() != '('){
                s[k] = top();
                pop();
                k++;
            }
            pop();
        }

    }
    while(!isEmpty()){
        s[k] = top();
        pop();
        k++;
    }
    s[k] = '\0';
    return s;
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

int isOperand(char s){
    if(s >= '0' && s <= '9') return 1; 
    if(s >= 'a' && s <= 'z') return 1; 
    if(s >= 'A' && s <= 'Z') return 1; 
    return 0;
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

void pop(){
    if(Top == NULL){
        printf("Stack is empty!\n");
    }
    stack *newStack = Top->next;
    free(Top);
    Top = newStack;
}

char top(){
    return Top->data;
}

int isEmpty(){
    if(Top == NULL) return 1;
    return 0;
}



