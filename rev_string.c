#include <stdio.h>
#include <string.h>

void Reverse(char *s){
    int i = 0;
    int j = strlen(s) - 1;
    while(i < j){
        char c = s[i];
        s[i] = s[j];
        s[j] = c;
        i++;
        j--;
    }

}

int main(){
    char str[20];
    printf("Enter string: ");
    scanf("%19s", str);
    Reverse(str);
    printf("Output: %s\n", str);

}
