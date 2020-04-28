#include <stdio.h>
#include <string.h>

char stack[100];
int top = -1;

void push(char x){
    stack[++top] = x;
}

void pop(){
    if(top == -1)
        return;
    --top;
}

char Top(){
    return (char)stack[top];
}

int isEmpty(){
    if(top == -1) return 1;
    return 0;
}

int compare(char a, char b){
    if(a == '(' && b == ')') return 1;
    if(a == '{' && b == '}') return 1;
    if(a == '[' && b == ']') return 1;
    return 0;
}

int check_expression(char *s){
    int len = strlen(s);
    for(int i = 0; i < len; i++){
        switch(s[i]){
            case '(':
            case '[':
            case '{':
                push(s[i]);
                break;
            case ')':
            case ']':
            case '}':
                if(isEmpty() || !compare(Top(), s[i])) return 0;
                else pop();
                break;
        }
    }
    return isEmpty(); 
}

int main(){
    char expr[] = "{()]}";
    if(check_expression(expr)){
        printf("Correct!\n");
    }else{
        printf("Incorrect!\n");
    }
    return 0;
}
