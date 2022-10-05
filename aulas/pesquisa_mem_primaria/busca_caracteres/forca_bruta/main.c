#include <stdio.h>
#include <stdlib.h>
// tamanho M é do texto, N é do padrão
#define N 10
#define M 3
// N tem que ser maior que M, portanto ( n > m )

int f_bruta (char t[N], char p[M] ) {
    int j;
    for (int i = 0; i < ( N - M ); i++ ) {
        j = 0;
        while ( (j < M) && t[i + j] = p[j] ) {
            j++;
            if ( j == M ) {
                return i;
            }
        }
        return 
    }
}

int main() {

    char texto[N];  //texto em que o padrao vai ser comparado
    char padrao[M]; //padrao para buscar dentro do texto, quantas vezes ele ocorre



    return 0;
}
