#include <stdio.h>
#include <stdlib.h>

#define N 5

void pl() {
    printf("\n");
}

void ord(int vetor[N]) {
    
    int final = (N - 1), temp, quant_trocas = 1;

    pl();

    // for externo: come�a do final, e vai decrementando at� chegar em 1 
    for (int i = final; i >= 1; i-- ) {

        // for interno: come�a de 0 e vai acrescentando at� chegar no i, pois a cada vez que vc chama esse for o maior valor j� � colocado no seu valor correto
        for (int j = 0; j < i; j++ ) {

            // comparador:
            if (vetor[j] > vetor[j+1]) {

                // bloco de troca dos valores
                temp = vetor[j];
                vetor[j] = vetor[j+1];
                vetor[j+1] = temp;

            }

        }

    }

}

int main () {

    int numeros[N] = {14,5,31,2,-5};
    ord(numeros);
    for (int i=0; i < N; i++ ) {
        printf("%d\t", numeros[i]);
    }

    return 0;
}