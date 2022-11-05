#include <stdio.h>
#define Max 10

int d(int number);
int calcula_h(int number, int t);
void shellsort(int *vet, int tam );
void imprime(int *vetor, int t);

int main () {

    int v[Max];
    for (int i = 0; i < Max; i++ ) {
        v[i] = rand();
    }
    shellsort(v, Max);
    imprime(v, Max);

    return 0;
}

void imprime (int *vetor, int t ) {
    for ( int i = 0; i < t; i++ ) {
        printf("%d ", vetor[i]);
    }
}

int d(int number) {
    number = (number-1)/3;
    return number;
}

int calcula_h (int number, int t ) {
    while (number < t) {
        number = number*3+1;
    }
    return number;
}

void shellsort(int *vetor, int t ) {
    int i, j, h, menor;

    h = 1;

    h = calcula_h(h, t);
    h = d(h);

    while ( h > 1 ) {
        
        for ( i = h; i < t; i++ ) {

            menor = vetor[i];

            for ( j = (i-h); j >= 0; j = j - h ) {

                if ( menor < vetor[j] ) {
                    vetor[j+h] = vetor[j];
                    vetor[j] = menor;
                }

            }
        }

        h = d(h);
    }
}




