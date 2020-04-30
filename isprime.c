#include <stdio.h>
#include <math.h>

int isprime(int n){
    for(int i = 2; i <= sqrt(n); i++){
        if(n%i == 0)
            return 0;
    }
    return 1;
}

int main(){
    int n;
    printf("Please enter the number: ");
    scanf("%d", &n);

    if(isprime(n))
        printf("The number %d is prime.\n", n);
    else
        printf("The number %d is not prime.\n", n);
    
}
