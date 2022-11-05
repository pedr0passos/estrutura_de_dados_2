#include <stdio.h>
#define N 10

void insertion_sort (int *vetor, int tamanho) {
    int i, j, auxiliar;
    for ( i = 1; i < tamanho; i++) {
        auxiliar = vetor[i];
        j = i - 1;
        while ( j >= 0 && auxiliar < vetor[j] ) {
            vetor[j+1] = vetor[j];
            j--;
        }
        vetor[j+1] = auxiliar;
    }
}

void insertion_sort_2(int *vetor, int tamanho) {
    int i, j, auxiliar;
    for ( i = 1; i < tamanho; i++) {
        auxiliar = vetor[i];
        for ( j = (i-1); j >= 0; j-- ) {
            if ( auxiliar < vetor[j] ) {
                vetor[j+1] = vetor[j];
                vetor[j+1] = auxiliar;
            }

        }
    }
}

/*
bub
insertion
shel
selection
heap
quick
*/

void print (int *vetor) {
    for ( int i = 0; i < N; i++ ) {
        printf("%d ", vetor[i]);
    }
}

int main () {

    int vetor[N] = {5,9,2,10,4,8,7,6,1,3};
    insertion_sort_2(vetor, N);
    print(vetor);

    return 0;
}