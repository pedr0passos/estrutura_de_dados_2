#include <stdio.h>
#define N 10

// funcao que faz a busca binaria...
int busca_binaria(int v[N], int x) {
    // variaveis de controle, inicio recebe o posicao inicial do vetor, que � zero. Fim recebe o final, sendo ela a quantidade de termos que existem - 1, o meio criamos para ser utilizado dentro do while.
    int inicio=0,fim = N-1, meio;
    // enquanto ( inicio foi menor ou igual ao final, vai ficar verificando os maiores e menores necess�rios )
    while ( inicio <= fim ) {
        // calculando o meio
        meio = (inicio + fim)/2;

        if ( x > v[meio] ) {            // se o numero que estou buscando, � maior que o meio, seguiremos para direita
            inicio = meio + 1;          // portanto moveremos o inicio, e n�o o final, para a posicao do meio + 1, pois o meio j� foi verificado
        } else if ( x < v[meio] ) {     // se o numero que estou buscando, � menor que o meio, seguiremos para esquerda
            fim = meio - 1;             // portanto moveremos o final, e nao o inicio, para a posicao do meio - 1.
        } else {                        
            return meio;                // quando encontrar significa que o x == v[meio], portanto coloquei um return da posicao meio, e n�o o numero, porem poderia colocar "return v[meio]"
        }
    }
}

int main () {

    int vetor[N] = {2,15,17,30,32,34,40,50,80,90}, n_buscado = 32;
    printf("O numero %d esta na posicao %d", n_buscado, busca_binaria(vetor, n_buscado));
    
    return 0;
}