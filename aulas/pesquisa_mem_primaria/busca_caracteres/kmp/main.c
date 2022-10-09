#include <stdio.h>
#include <string.h>

#define M 6
#define N 20

int *p_processamento ( char p[M] ) {
    int i = 1, j = -1;
    int *aux = malloc(sizeof(int)*M);
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
    int i;
    int *temp = p_processamento(p);
    int k = -1;
    for ( i = 0; i < N; i++ ) {
        while ( k > -1 && p[k+1] != t[i] ) {
            k = temp[k];
        }
        if (t[i] == p[k+1]) {
            k++;
        } 
        if (k == (M-1)) {
            free(temp);
            return (i-k);
        }
    }
    free(temp);
    return -1;
}

int main () {
    char texto[N] = {'a','b','a','c','a','a','c','c','a','b','a','c','a','b','a','b','a','a','b','b'};
    char padrao[M] = {'a','b','a','c','a','b'};

    printf("%d", kmp(texto, padrao));


    return 0;
}