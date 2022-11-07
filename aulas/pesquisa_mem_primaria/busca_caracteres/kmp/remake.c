#include <stdio.h>
#include <stdlib.h>
// m�todo de busca de ocorrencias de um padr�o dentro de um texto, chamado KMP
// para isso vamos definir duas constantes, ser�o os tamanhos do texto, e do padr�o a ser comparado
#define MaxT 10 
#define MaxP 6
/*
o m�todo em quest�o possui duas fun��es, uma de pr�-processamento e a outra das compara��es em si 
o pr�-processamento possui um vetor auxiliar, onde guarda a quantidade de ocorrencias da um char dentro do pr�prio padr�o

o algoritmo KMP possui complexidade O(n) no pior caso, ou seja, � um algoritmo de complexidade linear
*/

//fun��o de pr�-processamento
int *p_processamento ( char *padrao, int n ) {
    // variaveis:
    int i, j;
    int *auxiliar = malloc(sizeof(int)*n);
    // inicializa��es das variaveis:
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

//fun��o do KMP 
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


