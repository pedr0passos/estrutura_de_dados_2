#include <stdio.h>
#define Maxn 10

int pesquisa_binaria( int *array, int chave);
int pesquisa_binaria_recursiva (int *array, int chave, int esquerda, int direita);

int main() {
    
    int vetor[Maxn] = {5,10,23,70,80,200,880,5000,32000,470000};
    int chave = 0;
    int inicializador = 1;
    while ( inicializador )
    {
        printf("Digite a chave para buscar: ");
        scanf("%d", &chave);
        if ( pesquisa_binaria_recursiva(vetor, chave, 0, Maxn-1) != -1 ) {
            printf("Encontrou!");
        } else {
            printf("Nao Encontrou!");
        }
        printf("\nDeseja Continuar (1 - SIM | 0 - NAO )?");
        scanf("%d", &inicializador);
        system("cls");
    }

    return 0;
}

int pesquisa_binaria (int *array, int chave) {
    int direita = (Maxn-1);
    int esquerda = 0;
    int meio = ((esquerda + direita)/2);
    while ( esquerda <= direita ) {
        printf("entrou\n");
        if ( array[meio] == chave ) {
            return 1;
        } else if ( chave > array[meio]) {
            esquerda = meio+1;
        } else {
            direita = meio-1;
        }
        meio = ((esquerda+direita)/2);
    }
    return -1;
}

int pesquisa_binaria_recursiva (int *array, int chave, int esquerda, int direita) {
    int meio = (esquerda+direita)/2;
    if ( esquerda > meio ) {
        return -1;
    } else {
        if ( array[meio] == chave ) {
            return 1;
        } else {
            if (chave > array[meio]){
                 pesquisa_binaria_recursiva(array, chave, meio+1, direita);
            } else {
                 pesquisa_binaria_recursiva(array, chave, esquerda, meio-1);
            }
        }
    }
}