#include <stdio.h>
#define N 5

void insertion_sort (int v[N]) {
    int i, j, auxiliar;

    for (int i = 1; i < N; i++) {
        auxiliar = v[i];
        j = (i-1);

        while ( (j>=0) && (auxiliar < v[j]) ) {
            v[j+1] = v[j];
            j--;
        }

        if ( j != (i-1) ) {
            v[j+1] = auxiliar;
        }

    }
}

void sla ( int v[N] ) {
    int auxiliar;
    for ( int i = 0; i < N; i++ ) {
        for ( int j = i; j < N; j++ ) {
            if ( v[i] < v[j] ) {
                auxiliar = v[i];
                v[i] = v[j];
                v[j] = v[i];
                printf("trocou\n");
            }
        }
    }
}

int main () {

    // 23 90 68 1 55 -> 23 90 

    int vetor[N] = {90,23,68,1,55};
    int vetor2[N] = {90,23,68,1,55};
    insertion_sort(vetor);
    printf("\n-------------\n");
    sla(vetor2);
    for ( int i = 0; i < N; i++ ) {
        printf("%d ", vetor[i]);
    }

    return 0;
}