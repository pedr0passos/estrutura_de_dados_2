#include <stdio.h>
#include <locale.h>
#define Maxn 10

int pesquisa_sequencial( int *array, int chave );

int main() {
    
    setlocale(LC_ALL, "portuguese");

    int vetor[Maxn] = {10,5,23,7,8,2,88,5,32,47};
    int chave = 0;
    int inicializador = 1;
    while ( inicializador )
    {
        printf("Digite a chave para buscar: ");
        scanf("%d", &chave);
        if ( pesquisa_sequencial(vetor, chave) != -1 ) {
            printf("Encontrou!");
        } else {
            printf("Não Encontrou!");
        }
        printf("\nDeseja Continuar (1 - SIM | 0 - NÃO )?");
        scanf("%d", &inicializador);
        system("cls");
    }
    
    

    return 0;
}

int pesquisa_sequencial ( int *array, int chave ) {
    int i;
    for ( i = 0; i < Maxn; i++ ) {
        if ( array[i] == chave ) {
            return array[i];
        }
    }
    return -1;
}
