#include <stdio.h>

#define N 6


// h = h*3 + 1 

int d(int h) {
     return (h = (h-1)/3);
}

void imprime ( int *vetor ) {
    for (int i = 0; i < N; i++ ) {
        printf("%d ", vetor[i]);
    }
}

void shellsort(int v[], int n) {

    int i, j, h, auxiliar;
    
    h = 1; // iniciando o h como 1, o h é a quantidade de casas que se deve pular para fazer as comparações

    //laço que calcula o valor de h
    while (h < n) {
        h = h*3 + 1;
    }

    // laço principal 
    while ( h > 1 ) {
        h = d(h); // h = 4
        for (i = h; i < n; i++) {
            auxiliar = v[i];
            j = i - h;
            while ( j >= 0 && auxiliar < v[j] ) {
                v[j + h] = v[j];
                j -= h;
            }
            v[j+h] = auxiliar;
        }
    }
}

int main () {

    // vetor que vai ser ordenado
    int vetor[N] = {23,5,7,1,98,34};
    
    imprime(vetor);
    printf("\n");
    shellsort(vetor, N);
    imprime(vetor);
    printf("\n");

    return 0;
}