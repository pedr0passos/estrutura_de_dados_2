#include <stdio.h>
#define N 8
#define max 10

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


    if (j > esquerda ) {
        quicksort(v, esquerda, j);
    }
        if (i < direita) {
        quicksort(v, i, direita);
    }

}

void heap_k ( int *v, int k, int i, int final) {

    int maiores[k];

    int y = 0;

    for ( i = (max-1)/2; i >= 0; i-- ) {

        int auxiliar = v[i], j;
        j = 2*i + 1;
        while ( j <= final ) {
            if ( j < final ) {
                if ( v[j] < v[j+1] ) {
                    j++;
                }
            }
            if ( auxiliar < v[j] ) {
                v[i] = v[j];
                i = j;
                j = i*2 + 1;
            } else {
                j = final+1;
            }
        }
        v[i] = auxiliar;

        for ( int i = 0; i < k; i++ ) {
            printf("%d ", maiores[i]);
        }
    }



}

int main () {

    // int vetor[N] = {5,1,6,7,423,75,43,0};
    // int algo[9] = {3,2,5,5,2,4,2,4,6};
    // int *i = 0, *j = 3;
    // part(algo, 0, 3, &i, &j);


    // for (int i = 0; i <= 9; i++ ) {
    //     printf("%d ", algo[i]);
    // }
    // int dir = (N-1);
    // int esq = (N-N);
    // quicksort(vetor, esq, dir);
    // for (int i = 0; i < N; i++ ) {
    //     printf("%d ", vetor[i]);
    // }

    int vetor[13] = {8,9,100,34,5,7,2,66,87,12,43,6, 71};
    heap_k(vetor, 5, 0, max-1);


}