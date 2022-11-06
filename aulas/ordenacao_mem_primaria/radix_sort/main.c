#include <stdio.h>
#define max 10

void radix (int *vetor, int n );

int main () {

    int vetor[10] = {14,6546,234,8,3456,234,7,8,3,534};
    radix(vetor, max);
    for ( int i = 0; i < 10; i++ ) {
        printf("%d -", vetor[i]);
    }

    return 0;
}

void radix (int *vetor, int n ) {
    int i, j, contador[10] = {0};
    for ( int i = 0; i < 10; i++ ) {
        printf("%d -", contador[i]);
    }

}