#include <stdio.h>
// m�todo de busca de ocorrencias de um padr�o dentro de um texto, chamado KMP
// para isso vamos definir duas constantes, ser�o os tamanhos do texto, e do padr�o a ser comparado
#define MaxT 10 
#define MaxP 3
/*
o m�todo em quest�o possui duas fun��es, uma de pr�-processamento e a outra das compara��es em si 
o pr�-processamento possui um vetor auxiliar, onde guarda a quantidade de ocorrencias da um char dentro do pr�prio padr�o

o algoritmo KMP possui complexidade O(n) no pior caso, ou seja, � um algoritmo de complexidade linear
*/

//fun��o de pr�-processamento
int *p_processamento ( char *padrao ) {
    // variaveis:
    int i, j;
    int auxiliar[MaxP];
    // inicializa��es das variaveis:
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

//fun��o do KMP 
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



