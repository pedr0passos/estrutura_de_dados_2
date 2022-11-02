#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int comparador (const void *a, const void *b) {
    return ( *(int*)a - *(int*)b );
}

int main () {

    int vetor[10] = {14,6546,234,8,3456,234,7,8,3,534};
    qsort(vetor, 10, sizeof(int), comparador);
    for ( int i = 0; i < 10; i++ ) {
        printf("%d -", vetor[i]);
    }

    return 0;
}

