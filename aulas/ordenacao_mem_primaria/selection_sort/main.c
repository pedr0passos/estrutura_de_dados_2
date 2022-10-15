#include <stdio.h>
#define N 6

void selection_sort(int v[], int n) {
    int menor, auxiliar;
    for (int i = 0; i < n; i++ ) {
        menor = i;
        for (int j = i + 1; j < n; j++ ) {
            if ( v[j] < v[menor]) {
                menor = j;
            }
        }
        if ( i != menor) {
            auxiliar = v[i];
            v[i] = v[menor];
            v[menor] = auxiliar;
        }
    }
}

int main () {

    int vetor[N] = {5,1,9,3,6,2};
    selection_sort(vetor, N);
    for (int i = 0; i < N; i++ ) {
        printf("%d ", vetor[i]);
    }

    return 0;
}