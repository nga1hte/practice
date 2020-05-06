#include <stdio.h>
#include <math.h>

void prime_factor(int n){
    for(int i = 2; i <= sqrt(n); i++){
        if(n%i == 0){
            int count = 0;
            while(n%i == 0){
                n = n / i;
                count++;
            }
            printf("%d^%d ", i, count);
        }
    }
    if(n != 1) 
       printf("%d^%d ", n, 1);
    printf("\n");
}

int main(){
    prime_factor(44);
    return 0;
}
