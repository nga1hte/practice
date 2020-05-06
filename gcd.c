#include <stdio.h>

int gcd(int a, int b){
    int big = (a >= b) ? a : b;
    int small = ( a <= b) ? a : b;
    
    while(small != 0){
        int remainder = big % small;
        big = small;
        small = remainder;
    }
    return big;
}

int main(){
    int ans = gcd(400, 124);
    printf("%d\n", ans);
    return 0;
}
