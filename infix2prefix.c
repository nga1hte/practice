//Implementation of stack using arrays created in a struct
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

char bracket(char a){
    if(a == '(') return ')';
    if(a == ')') return '(';
    if(a == '{') return '}';
    if(a == '}') return '{';
    if(a == '[') return ']';
    if(a == ']') return '[';
    return a;
}

void reverseString(char *s){
    int i = 0;
    int j = strlen(s) - 1;
    while(i < j){
        char tmp = bracket(s[i]);
        s[i] = bracket(s[j]);
        s[j] = tmp;
        i++;
        j--;
    }
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
    }
    return weight;
}

int hasHigherPre(char a, char b){
    int op1 = getWeight(a);
    int op2 = getWeight(b);
    if(op1 == op2) return 1;
    return (op1 > op2);
}

int isOperand(char s){
    if(s >= '0' && s <= '9') return 1;
    if(s >= 'a' && s <= 'z') return 1;
    if(s >= 'A' && s <= 'Z') return 1;
    return 0;
}

int isOperator(char s){
    switch(s){
        case '*':
        case '+':
        case '/':
        case '-':
            return 1;
        default:
            return 0;
    }
}

char *infixToPrefix(char *str, stack **newAddr){
    int len = strlen(str);
    stack *charStack = *newAddr;
    char *s = malloc(sizeof(s) * len);
    int i, k;
    for(i = 0, k = 0; i < len; i++){
        if(isOperand(str[i])){
            s[k] = str[i];
            k++;
        }else if(isOperator(str[i])){
            while(!isEmpty(charStack) && top(charStack) != '(' && hasHigherPre(top(charStack), str[i])){
                s[k] = top(charStack);
                pop(charStack);
                k++;
            }
            push(charStack, str[i]);
        }else if(str[i] == '('){
            push(charStack, str[i]);
        }else if(str[i] == ')'){
            while(!isEmpty(charStack) && top(charStack) != '('){
                s[k] = top(charStack);
                pop(charStack);
                k++;
            }
            pop(charStack);
        }
    }
    while(!isEmpty(charStack)){
        s[k] = top(charStack);
        pop(charStack);
        k++;
    }
    s[k] = '\0';
    return s;
}




int main(){
    stack *charStack = newStack(10);
    char str[20]; 
    scanf("%s", str);
    reverseString(str);
    char *result = infixToPrefix(str, &charStack);
    reverseString(result);
    printf("%s\n", result);
    return 0;
}

