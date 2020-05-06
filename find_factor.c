#include <stdio.h>
#include <math.h>

int main(){
    int n;
    scanf("%d", &n);
    for(int i = 1;  i <= sqrt(n); i++){
        if(n%i == 0){
            if(i == sqrt(n))
                printf("%d ", i);
            else
                printf("%d %d ", i, n/i);
        }
    }
    printf("\n");
}
