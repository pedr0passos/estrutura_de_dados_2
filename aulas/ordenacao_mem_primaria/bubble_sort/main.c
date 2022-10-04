#include <stdio.h>
#include <stdlib.h>

#define N 5

void pl() {
    printf("\n");
}

void ord(int vetor[N]) {
    
    int final = (N - 1), temp, quant_trocas = 1;

    pl();
    // while que vai fazer o for rodar quantas vezes for necessário para a ordenação do vetor...
    while (quant_trocas != 0 ) {
        //setando quant_trocas = 0, pois caso não exista mais nenhuma troca a ser feita, significa que o vetor foi ordenado OU já estava ordenado previamente...
        quant_trocas = 0;
        // for fazendo as trocas da direita do vetor até o inicio, portanto tem esse caminho: [<-][<-][<-][<-][<-][<-]...
        for ( int i = final; i >= 1; i-- ) {

            if (vetor[i-1] >= vetor[i]) {       // compara se o vetor da posição (i-1) é maior ou igual ao vetor em que o (i) está posicionado...
        
                // bloco de troca
                temp = vetor[i-1];
                vetor[i-1] = vetor[i];
                vetor[i] = temp;
                quant_trocas++;
        
            }
        
        }
    }    
    // a função faz o for ser repetido até o vetor ser ordenado, quando ele for ordenado não haverá mais comparações a serem verdadeiras, portanto irá sair do while.
}

int main () {

    int numeros[N] = {14,5,31,2,-5};
    ord(numeros);
    for (int i=0; i < N; i++ ) {
        printf("%d\t", numeros[i]);
    }

    return 0;
}