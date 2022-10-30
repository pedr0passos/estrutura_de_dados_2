#include <stdio.h>
// método de busca de ocorrencias de um padrão dentro de um texto, chamado KMP
// para isso vamos definir duas constantes, serão os tamanhos do texto, e do padrão a ser comparado
#define MaxT 10 
#define MaxP 3
/*
o método em questão possui duas funções, uma de pré-processamento e a outra das comparações em si 
o pré-processamento possui um vetor auxiliar, onde guarda a quantidade de ocorrencias da um char dentro do próprio padrão

o algoritmo KMP possui complexidade O(n) no pior caso, ou seja, é um algoritmo de complexidade linear
*/

//função de pré-processamento
int *p_processamento ( char *padrao ) {
    // variaveis:
    int i, j;
    int auxiliar[MaxP];
    // inicializações das variaveis:
    j = -1;
    auxiliar[0] = j;
    // algoritmo:

    // for externo, percorre todo o vetor padrao
    for ( i = 0; i < MaxP; i++) {
        while ( (j > -1) && (padrao[j+1] != padrao[i]) ) {
            j = auxiliar[j];
        }
        if ( padrao[i] == padrao[j-1])
            j++;
        auxiliar[i] = j;
    }
    return auxiliar;
}

//função do KMP 
int kmp (char *texto, char *padrao) {
    int *auxiliar, k;
    auxiliar = p_processamento(padrao);
    k = -1;
    for (int i = 0; i  < MaxT; i++ ) {
        while ( k > -1 && padrao[k+1] != texto[i] ) 
        {
            k = auxiliar[k];
        }
        if ( texto[i] == padrao[k+1])
            k++;
        if ( k == (MaxP-1))
            return (i-k);
    }
    return -1;
}



