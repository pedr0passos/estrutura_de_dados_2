#include <stdio.h>
#define Max 5

void particao(int *v, int esquerda, int direita, int *i, int*j);
void quicksort(int *v, int esquerda, int direita);

void main () {

    int vetor[Max] = {5,1,8,9,34};
    quicksort(vetor, 0, Max-1);
    for (int i = 0; i < Max; i++ ) {
        printf("%d ", vetor[i]);
    }

}

void quicksort(int *v, int esquerda, int direita) {
    int i, j;
    particao(v,esquerda,direita, &i, &j);
    if ( i < direita ) {
        quicksort(v, i, direita);
    }
    if ( j > esquerda ) {
        quicksort(v, esquerda, j);
    }

}

void particao(int *v, int esquerda, int direita, int *i, int*j) {
    int aux, pivo;

    pivo = v[direita];
    
    *i = esquerda;
    *j = direita;
    
    while ( (*i) <= (*j) ) {
        while (v[*i] < pivo && (*i) < direita) {
            (*i)++;
        }
        while ( v[*j] > pivo && (*j) > esquerda ) {
            (*j)--;
        }
        if ( (*i) <= (*j) ) {
            aux = v[*i];
            v[*i] = v[*j];
            v[*j] = aux;
            (*i)++;
            (*j)--;
        }
    }
}

/*
particao ( int *v, int esquerda, int direita, *i, *j ) {
    int aux, pivo;
    pivo = v[(esq+dir)/2];

    while ( *i <= *j ) {
        while ( v[*i] < pivo && *i < direita ) {
            *i++;
        }
        while ( v[*j] > pivo && *j > esquerda ) {
            *j--;
        }
        if ( *i <= *j ) {
            aux = v[i];
            v[i] = v[j];
            v[j] = aux;
            i++;
            j--;
        }
    }
}

void quicksort (int vetor, int esquerda, int direita ) {
    int i , j;
    particao (vetor, esquerda, direita, &i, &j );
    if ( i < direita ) {
        quicksort(vetor, i, direita);
    }
    if ( j > esquerda ) {
        quicksort(vetor, esquerda, j);
    }
}
*/