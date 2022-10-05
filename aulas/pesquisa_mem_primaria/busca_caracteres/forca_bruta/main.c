#include <stdio.h>
#include <stdlib.h>
// tamanho M é do texto, N é do padrão
#define N 20
#define M 6
// N tem que ser maior que M, portanto ( n > m )

int f_bruta (char t[N], char p[M] ) {
    int j;
    for (int i = 0; i < ( N - M ); i++ ) {
        j = 0;
        while ( j < M && t[i + j] == p[j] ) {
            j++;
            if ( j == M ) {
                return i;
            }
        }
    }
    return -1;
}

int main() {

    char texto[N] = {'a','b','a','c','a','a','b','a','c','c','a','b','a','c','a','b','a','a','b','b'};  //texto em que o padrao vai ser comparado
    char padrao[M] = {'a','b','a','c','a','b'};//padrao para buscar dentro do texto, quantas vezes ele ocorre

    printf("Padrão Ocorre na Posição: %d\n", f_bruta(texto,padrao));


    return 0;
}
