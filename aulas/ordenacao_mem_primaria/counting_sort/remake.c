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

    int i, j, k, box[256];

    for ( int x = 0; x < 256; x++ ) {
        box[x] = 0;
    }

    for ( i = 0; i < tamanho; i++ ) {
        box[vetor[i]]++;
    }

    k = 0;
    for ( i = 0; i < 256; i++ ) {
        for ( j = 0; j < box[i]; j++ ) {
            vetor[k] = i;
            k++;
        }
    }


} 