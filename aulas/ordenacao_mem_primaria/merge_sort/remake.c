#include <stdio.h>
#define Max 13

void intercala (int *v, int inicio, int meio, int final );
void mergesort(int *v, int inicio, int fim );

void main () {

    int vetor[Max] = {8,1,7,3,2,1,5,5,6,5,3,8,10};
    mergesort(vetor, 0, Max-1);
    for (int i = 0; i < Max; i++ ) {
        printf("%d ", vetor[i]);
    }
}

void mergesort(int *v, int inicio, int fim ) {
    if ( inicio < fim ) {
        int meio = (inicio+fim)/2;
        mergesort(v, inicio, meio);
        mergesort(v, meio+1, fim);
        intercala(v, inicio, meio, fim);
    }
}

void intercala (int *v, int inicio, int meio, int final ) {
    int auxiliar[Max], i, j, k;

    i = inicio;
    j = meio+1;
    k = 0;

    while ( i <= meio && j <= final ) {
    
        if ( v[i] < v[j] ) {
            auxiliar[k] = v[i];
            k++;
            i++;
        } else {
            auxiliar[k] = v[j];
            k++;
            j++;
        }
    }
    
    if (i > meio && j <= final ) {
        while ( j <= final ) {
            auxiliar[k] = v[j];
            j++;
            k++;
        }
    } 
    if ( j > final && i <= meio ) {
        while ( i <= meio ) {
            auxiliar[k] = v[i];
            i++;
            k++;
        }
    }

    for ( int x = inicio; x <= final; x++) {
        v[x] = auxiliar[x-inicio];
    }

}