#include <stdio.h>
#define N 8

void part(int *v, int esquerda, int direita, int *i, int *j) {
    int pivo, auxiliar;
    
    *i = esquerda;
    *j = direita;

    pivo = v[(esquerda + direita)/2];

    while ( *i <= *j ) {
        while (v[*i] < pivo && *i < direita ) {            
            (*i)++;
        }
        while (v[*j] > pivo && *j > esquerda ) {
            (*j)--;
        }
        if ( *i <= *j ) {
            auxiliar = v[*i];
            v[*i] = v[*j];
            v[*j] = auxiliar;
            (*i)++;
            (*j)--;
        }       
    }
}

void quicksort ( int *v, int esquerda, int direita ) {
    int i, j;
    part(v,esquerda,direita, &i, &j);
    if (i < direita) {
        quicksort(v, i, direita);
    }

    if (j > esquerda ) {
        quicksort(v, esquerda, j);
    }

}

int main () {

    int vetor[N] = {5,1,6,7,423,75,43,0};
    int dir = (N-1);
    int esq = (N-N);
    quicksort(vetor, 0, 7);
    for (int i = 0; i < N; i++ ) {
        printf("%d ", vetor[i]);
    }
}