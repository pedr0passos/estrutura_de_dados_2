#include <stdio.h>
#define Max 7

// buble sort que vai e volta
void b ( int *v, int n ) {
    int j, aux, inicio, fim;
    
    inicio = n-n;
    fim = (n-1);

    while ( inicio < fim ) {
        j = inicio;
        while ( j < fim ) {
            if ( v[j+1] < v[j] ) {
                aux = v[j];
                v[j] = v[j+1];
                v[j+1] = aux; 
            }
            j++;
        }
        while ( j > inicio ) {
            if ( v[j-1] > v[j] ) {
                aux = v[j];
                v[j] = v[j-1];
                v[j-1] = aux;
            }
            j--;
        }
        inicio++;
        fim--;
    }
}

// ordenacao por contagem
void o_contagem (int *v, int n ) {
    int max=0;
    int k;

    for ( int i = 0; i < n; i++ ) {
        if ( v[i] > max ) {
            max = v[i];
        }
    }

    int tamanho = max+1;
    int contador[tamanho];

    for (int i = 0; i < tamanho; i++ )
        contador[i] = 0;

    for ( int i = 0; i < n; i++ ) {
        contador[v[i]]++;
    }

    k = 0;
    for ( int i = 0; i < tamanho; i++ ) {
        
        for ( int j = 0; j < contador[i]; j++ ) {
            v[k] = i;
            k++;
        } 

    }

}

void par_impar (int *v, int n) {
    int trocado, i, j, aux, z;

    trocado = 1;
    z = 1;

    while ( z < n || trocado != 0 ) {
        trocado = 0;
        if ( (z%2) != 0 ) {
            for ( i = 0; i < n; i = i + 2) {
                if ( v[i] > v[i+1] ) {
                    aux = v[i];
                    v[i] = v[i+1];
                    v[i+1] = aux;
                    trocado = 1;
                }
            }
        } else {
            for ( i = 0; i < n; i = i + 2 ) {
                if ( v[i] > v[i+1] ) {
                    aux = v[i];
                    v[i] = v[i+1];
                    v[i+1] = aux;
                    trocado = 1;
                }
            }
        }
        z++;
    }
}

int main () {
    int vetor[Max] = {0,7,4,1,7,4,9};

    // bubblesort vai e volta
    b(vetor, Max);
    // for ( int i = 0; i < Max; i++ ) {
    //     printf("%d ", vetor[i]);
    // }
    int vetor2[Max] = {0,7,4,1,7,4,9};
    o_contagem(vetor2, Max);
    for ( int i = 0; i < Max; i++ ) {
        printf("%d ", vetor2[i]);
    }    
return 0;
}