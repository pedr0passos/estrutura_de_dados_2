#include <stdio.h>
#define N 10

void counting_sort(char *vetor, int tamanho);

int main () {

    char vet[N] = {'z','g','i','k','a','p','q','a','f','r'};
    counting_sort(vet, N);
    for (int i = 0; i < N; i++) {
        printf("%c - ", vet[i]);
    }

    return 0;
}

void counting_sort(char *vetor, int tamanho) {
    int i, j, k, caixas[256];

    for ( i = 0; i < 256; i++ ) {
        caixas[i] = 0;
    }
    
    for (i = 0; i < tamanho; i++) {
        caixas[vetor[i]]++;
    }

    k = 0;
    for (i = 0; i < 256; i++) {
        for (j = 0; j < caixas[i]; j++) {
            vetor[k] = i;
            k++;
        }
    }
} 

/*

int i, j, k, aux[256];

for ( i = 0; i < 256; i++ ) {
    aux[i] = 0;
}

for ( i = 0; i < max; i++ ) {
    aux[v[i]]++;
}

k = 0;
for ( i = 0; i < 256; i++ ) {
    for ( j = 0; j < caixas[i]; j++ ) {
        vetor[k] = i;
        k++;
    }
}

*/