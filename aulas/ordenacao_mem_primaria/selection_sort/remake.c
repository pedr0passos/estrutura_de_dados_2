#include <stdio.h>
#define Max 5

void selection_sort(int *v, int n);

int main () {

    int vetor[Max];
    
    for (int i = 0; i < Max; i++ ) {
        vetor[i] = rand();
    }
    
    selection_sort(vetor, Max);
    for (int i = 0; i < Max; i++ ) {
        printf("%d ", vetor[i]);
    }

    return 0;
}

void selection_sort(int *v, int n) {

    int i, j, menor, aux;
    j = 0;
    while ( j < n ) {
        menor = j;
        for ( i = j; i < n; i++ ) {
            if ( v[i] < v[menor] ) {
                menor = i;
            }
        }
        if ( i != j) {
            aux = v[menor];
            v[menor] = v[j];
            v[j] = aux; 
        }
        j++;
    }



    // for ( i = 0; i < n; i++ ) {
    //     menor = i;
    //     for ( j = i; j < n; j++) {
    //         if ( v[j] < v[menor] ) {
    //             menor = j;
    //         }
    //     }
    //     if ( i != j ) {
    //         aux = v[menor];
    //         v[menor] = v[i];
    //         v[i] = aux;
    //     }
    // }

    
}

// pego a posicao do menor, troco ele com o vetor[i]
