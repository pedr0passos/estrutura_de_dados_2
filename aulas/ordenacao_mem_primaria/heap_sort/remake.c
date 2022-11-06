#include <stdio.h>
#define Max 36

void criaheap (int *v, int i, int final);
void heapsort(int *v, int n);

int main () {

    int vetor[Max];
    
    for ( int i = 0; i < Max; i++ ) {
        vetor[i] = rand();
    }

    heapsort(vetor, Max);

    printf("\n");
    for (int i = 0; i < Max; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n\n");

    return 0;
}

void criaheap (int *v, int i, int final) {
    
    int j, auxiliar;
    
    auxiliar = v[i];
    j = (i)*2 + 1;
    // enquanto o j, que representa os filhos for menor ou igual ao final, tem que continuar verificando
    while ( j <= final ) {
        
        if ( j < final ) {
            if ( v[j] < v[j+1] ) {
                j++;
            }
        }
        if ( auxiliar < v[j] ) {
            v[i] = v[j];
            i = j;
            j = 2*i + 1;
        } else {
            j = final + 1;
        }
    }
    v[i] = auxiliar;
}

void heapsort(int *v, int n) {
    int final = (n-1);
    int meio = final/2;
    int aux;

    for (int i = meio; i>=0; i-- ) {
        criaheap(v, i, final);
    }

    for ( int i = final; i > 0; i--) {
        aux = v[0];
        v[0] = v[i];
        v[i] = aux;
        criaheap(v, 0, i-1);
    }
}

/*

aux = v[i];
j = j*2 + 1;
while ( j <= final ) {
    if ( j < final ) {
        if ( v[j] < v[j+1] ) {
            j++;
        }
    }
    if ( aux < v[j] ) {
        v[i] = v[j];
        i = j;
        j = j*2+1;
    }
    v[i] = aux;
}

for ( int i = meio; i >=0; i-- ) {
    criaheap(vetor, i, final);
}

for ( int i = final; i > 0 ; i-- ) {
    aux = v[0];
    v[0] = v[i];
    v[i] = aux;
    criaheap(vetor, 0, i-1);
}


*/