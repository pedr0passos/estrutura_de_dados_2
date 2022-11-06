#include <stdio.h>
#define Max 10

int decrementa ( int number );
int calcula_h (int number , int tam_vetor );
void mediana ( int *v, int n );

void main () {

    int vetor[Max] = {7,9,2,10,3,6,4,1,5,8};
    mediana(vetor, Max);

}

int decrementa ( int number ) {
    return ( number = (number-1)/3);
}

int calcula_h (int number, int tam_vetor )
{
    while ( number < tam_vetor ) {
        number = number*3 + 1;
    }
    return number;

}

void mediana (int *v, int n) {

    //shellsort
    int i, j, h, auxiliar;
    h = 1;
    h = calcula_h( h, n);

    while ( h > 1 ) {

        h = decrementa(h);

        for ( i = h; i < n; i++) {

            auxiliar = v[i];
            j = i - h;

            while ( j>=0 && auxiliar < v[j] ) {
                v[j+h] = v[j];
                j = j - h;
            }

        v[j+h] = auxiliar;        

        }
    }
    for ( int i = 0; i < n ; i++ ) {
        printf("%d ", v[i]);
    }
    printf("\n");
    // fim do shellsort

    // calculando a mediana
    float mediana; int meio = (n-1)/2;
    if ( n%2 == 0 ) {   
        mediana = ((float)v[meio] + (float)v[meio+1]) / 2;
    } else {
        mediana = (float)v[meio];
    }

    printf("Mediana = %.1lf\n", mediana);

}