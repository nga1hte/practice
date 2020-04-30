#include <stdio.h>
#include <math.h>

long long binary(int bin){
    long long n = 0;
    int i = 0;
    int rem = 0;
    while(bin > 0){
        rem = bin%2;
        n = n + pow(10, i) * rem;
        bin /= 2;
        i++;
    }
    return n;
}

int main(){
    long long n = binary(14);
    printf("%ld\n", n);
    return 0;
}
