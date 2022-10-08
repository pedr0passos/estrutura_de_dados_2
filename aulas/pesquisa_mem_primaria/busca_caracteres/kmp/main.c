#include <stdio.h>
#include <string.h>

#define M 8
#define N 20

int *p_processamento ( char *p[M] ) {
    int i = 1, j = 1, aux[M];
    aux[0] = j;
    for (i = 1; i < M; i++){
        while (j > -1 && p[j+1] != p[i]) {
            j = aux[j];
        }
        if(p[i] == p[j+1]) {
            j++;
        }
        aux[i] = j;
    }
    return aux;
}

int kmp ( char t[N], char p[M] ) {
    int *aux = p_processamento(p[M]);
    int k = -1;
    for ( int i = 0; i < N; i++ ) {
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

    char texto[N] = {};
    char padrao[M] = {'a','b','c','d','a','b','c','a'};
    int *auxiliar = malloc(sizeof(int)*M);
    auxiliar = p_processamento(padrao);
    for(int i = 0; i < M; i++ ) {
        printf("%d\t", auxiliar[i]);
    }


    return 0;
}