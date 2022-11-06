#include <stdio.h>
#define Max 5

void preenche(int *vetor, int n);
void b_insertionsort( int *v, int n);

int main () {

    int vetor[Max];
    preenche(vetor, Max);
    b_insertionsort(vetor, Max);
    printf("\n");
    for (int i = 0; i<Max; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n\n");

    return 0;
}

void preenche (int *vetor, int n) {
    for (int i = 0; i < n; i++) {
        vetor[i] = rand();
    }
}

void b_insertionsort(int *v, int n) {
    int auxiliar, i, j, esquerda, direita, meio;
    for (i = 1; i < n; i++) {
        auxiliar = v[i];
        esquerda = 0;
        direita = i;
        while ( esquerda < direita ) {
            meio = ( esquerda + direita )/ 2;
            if ( v[meio] <= auxiliar ) {
                esquerda = meio + 1;
            } else {
                direita = meio;
            }
        }
        for ( j = i; j > esquerda; j-- ) {
            v[j] = v[j-1];
        }
        v[direita] = auxiliar;        
    }
}

/*



for () {
    aux = v[i];
    esquerda = 0;
    direita = i;
    while ( esquerda < direita ) {
        if ( v[meio] <= aux ) {
            esquerda = meio + 1;
        } else {
            direita = meio;
        }
    }
    for ( j = i; j > esquerda; j-- ) {
        v[j] = v[j-1];
    }
    v[direita] = aux;
}
*/