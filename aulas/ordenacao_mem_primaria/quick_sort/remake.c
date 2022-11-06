#include <stdio.h>
#define Max 35

void particao(int *v, int esquerda, int direita, int *i, int*j);
void quicksort(int *v, int esquerda, int direita);

void main () {

    int vetor[Max] = {5,1,8,9,34,2,0,3,3,6,-98,-1,10,67,12,11,41,22,98,55,120,117,51,-180,-62,34,29,1,1,3,7,-9,750,902,-100};
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

    pivo = v[(esquerda + direita)/2];
    
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