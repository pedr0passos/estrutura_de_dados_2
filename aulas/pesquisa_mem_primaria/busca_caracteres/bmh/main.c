#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 10
#define M 10
#define MAXCHAR 256

int bmh ( char t[N], char p[M] ) {
    int j, i, k;
    int tabela[MAXCHAR];

    for ( j = 0; j < MAXCHAR; j++ ) {
        tabela[j] = M;
    }
    for ( j = 1; j < M; j++ ) {
        tabela[p[j-1]] = M-j;
    }
    
    i = M;

    while ( i <= N ) {
        k = i;
        j = M;
        while (t[k-1] == p[j-1] && j > 0 ) {
            k--;
            j--;
        }
        if ( j == 0 ) {
            return k+1;
        }
        i = i + tabela[t[i-1]];
    }
    return -1;
}

int main () {

    char texto[N] = {'a','b','a','c','a','b','c','c','a','b','a','c','a','b','a','b','a','a','b','b'};
    char padrao[M] = {'a','b','a','c','a','b'};

    printf("%d", bmh(texto, padrao));

    return 0;
}