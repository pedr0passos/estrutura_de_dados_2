#include <stdio.h>
#define Max 10

int d(int number);
int calcula_h(int number, int t);
void shellsort(int *v, int t );
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

void shellsort(int *v, int t ) {
    int i, j, h, aux;

    h = 1;

    h = calcula_h(h, t);

    while ( h > 1 ) {
        h = d(h);
        for ( i = h; i < t; i++ ) {
            aux = v[i];
            j = i-h;
            while  ( j >= 0 && aux < v[j] ) {
                v[j+h] = v[j];
                j = j - h;
            }
            if ( j != (i-h)) 
                v[j+h] = aux;
        }

    }
}




