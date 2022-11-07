#include <stdio.h>
#include <stdlib.h>
// método de busca de ocorrencias de um padrão dentro de um texto, chamado KMP
// para isso vamos definir duas constantes, serão os tamanhos do texto, e do padrão a ser comparado
#define MaxT 10 
#define MaxP 6
/*
o método em questão possui duas funções, uma de pré-processamento e a outra das comparações em si 
o pré-processamento possui um vetor auxiliar, onde guarda a quantidade de ocorrencias da um char dentro do próprio padrão

o algoritmo KMP possui complexidade O(n) no pior caso, ou seja, é um algoritmo de complexidade linear
*/

//função de pré-processamento
int *p_processamento ( char *padrao, int n ) {
    // variaveis:
    int i, j;
    int *auxiliar = malloc(sizeof(int)*n);
    // inicializações das variaveis:
    j = -1;
    auxiliar[0] = j;
    // algoritmo:

    // for externo, percorre todo o vetor padrao
    for ( i = 1; i < MaxP; i++) {
        while ( (j > -1) && (padrao[j+1] != padrao[i]) ) {
            j = auxiliar[j];
        }
        if ( padrao[i] == padrao[j+1])
            j++;
        auxiliar[i] = j;
    }
    return auxiliar;
}

//função do KMP 
int kmp (char *texto, char *padrao, int t_p) {
    int *auxiliar, j;
    auxiliar = p_processamento(padrao, t_p);
    j = -1;
    for (int i = 0; i  < MaxT; i++ ) {
        while ( j > -1 && padrao[j+1] != texto[i] ) 
        {
            j = auxiliar[j];
        }
        if ( texto[i] == padrao[j+1])
            j++;
        if ( j == (MaxP-1))
            free(auxiliar);
            return (i-j);
    }
    free(auxiliar);
    return -1;
}

int main ( ) {

    char padrao[MaxP] = {'c','b','a','c','b','a'};
    int *auxiliar = p_processamento(padrao, MaxP);
    
    for ( int i = 0; i < MaxP; i++ ) {
        printf("%d ", auxiliar[i]);
    }

    return 0;
}


