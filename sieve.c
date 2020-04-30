#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void findPrime(int n){
    int *primes = (int *) malloc(sizeof(int)*(n+1));
    for(int i = 0; i <= n; i++)
        primes[i] = 1;
    primes[0] = 0;
    primes[1] = 0;

    for(int i = 2; i <= sqrt(n); i++){
        if(primes[i] == 1){
            for(int j = 2; j*i <= n; j++)
                primes[i*j] = 0;
        }
    }

    for(int i = 0; i <= n; i++){
        if(primes[i] == 1){
            printf("%d ", i);
        }
    }
    printf("\n");
}

int main(){
    int n;
    scanf("%d", &n);
    findPrime(n);
}
