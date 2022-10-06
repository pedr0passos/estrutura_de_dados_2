#include <stdio.h>
#include <string.h>

#define M 4
#define N 20

int p_processamento ( char p[M] ) {
    int i = 1, j = 1, aux[M];
    aux[0] = j;
    for (i = 1; i < (M-1); i++){
        while (j > -1 && p[j+1] != p[i]) {
            j = aux[j];
        }
        if(p[i] == p[j]) {
            j++;
        }
        aux[i] = j;
    }
    return aux;
}

int kmp ( char t[N], char p[M] ) {
    int aux[M] = p_processamento(p[M]);
    int k = -1;
    for ( int i = 0; i < (N-1); i++ ) {
        while ( k > -1 && p[k+1] != t[i] ) {
            k = aux[k];
        }
        if (t[i] == p[k+1]) {
            k++;
        } 
        if (k == (M-1)) {
            return i-k;
        }
    }

}

int main () {

    char texto[N] = {'a','b','b','a','c','a','d','b','a','c','d','b','a','c','a','b','b','a','a','b'};
    char padrao[M] = {'a','b','b','a'};

    printf("%d\n", kmp(texto, padrao));


    return 0;
}