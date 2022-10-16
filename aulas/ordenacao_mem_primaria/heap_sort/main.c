// ORDENAÇÃO HEAPSORT
#include <stdio.h>
#define N 10
/*

HEAP: é um vetor que simula uma árvore binária completa 
 - Todo elemento pai do vetor possui dois elementos como filhos
 - Cada posição do vetor passa a ser considerado pai de duas outras posições, chamadas filhos
 - Se o pai está na posição "i" então os filhos vão estar nas posições:

  {
    2*i + 1 -> Filho da Esquerda
    2*i + 2 -> Filho da Direita 
  }

*/ 

void cria_heap(int v[N], int i, int f);
void heap_sort(int v[N]);

int main () {

    int vetor[N] = {43,7,1,0,5,9,32,15,78,6};

    heap_sort(vetor);

    for (int i = 0; i < N; i++) {
        printf("%d ", vetor[i]);
    }

    return 0;
}

void cria_heap(int v[N], int i, int f) {
    int auxiliar = v[i], j;
    j = (i)*2+1;
    while ( j <= f ) {
        if ( j < f) {
            if (v[j] < v[j+1]) {
                j++;
            }
        }
        if (auxiliar < v[j]) {
            v[i] = v[j];
            i = j;
            j = 2*(i) + 1;
        } else {
            j = f+1;
        }
    }
    v[i] = auxiliar;
}

void heap_sort(int v[N]) {
    int i, auxiliar;
    for ( i = (N-1)/2; i >= 0; i--) {
        cria_heap(v, i, (N-1));    
    }
    for ( i = N-1; i > 0; i-- ) {
        auxiliar = v[0];
        v[0] = v[i];
        v[i] = auxiliar;
        cria_heap(v, 0, i-1);
    }
}