#include <stdio.h>
#include <stdlib.h>

#define ordem 2
#define true 1 
#define false 0 

typedef struct no {
    int numero_elementos;
    struct no *pagina0;
    informacao chaves[2*ordem+1];
}pagina;

typedef struct pag {
    int chave;
    pagina *filho;
} informacao;

int main () {
    return false;
}

void cria_arvore_vazia ( no_arvore *arvore ) {
    arvore = NULL;
}

int vazia( no_arvore *arvore ) {
    return ( arvore == NULL );
}

void busca_elemento ( no_arvore *arvore, int buscado ) {

}

int acha_posicao( no_arvore *arvore, int valor, int posicao ) {
    while ( posicao < arvore->numero_elementos && valor > arvore->itens[posicao].chave )
        posicao++;
    return posicao;
}

int overflow ( no_arvore *arvore ) {

}

pagina insere( no_arvore *arvore, int valor, int *altura ) {
    int i, j;
    pagina nova_pagina;
    no_arvore *novo_no;

    *altura=1;
    if (vazia(arvore)) {
        nova_pagina.chave = valor;
        nova_pagina.filho = NULL;
    } else {
        i = acha_posicao(arvore, valor, i);
        if ( arvore->itens[i].chave == valor ) {
            *altura = 0;
            nova_pagina.chave = valor;
            nova_pagina.filho = NULL;
        } else {
            i--;
            if (i < 2*ordem) {
                if (i = -1)
                    nova_pagina = insere (arvore->pagina0, valor, altura);
                else 
                    if ( valor > arvore->itens[i].chave )
                        nova_pagina = insere(arvore->itens[i].filho, valor, altura);
                    else 
                        *altura = 0;
                if ( *altura == 1 ) {
                    for ( j = arvore->itens; j > i+1; j-- )
                        arvore->itens[j] = arvore->itens[j-1];
                    arvore->itens[j] = nova_pagina;
                    if ( arvore->numero_elementos < 2*ordem ) {
                        *altura = 0;
                        arvore->numero_elementos++;
                    } else {                                        // overflow
                        novo_no = (pagina*)malloc(sizeof(pagina));
                        novo_no->pagina0 = arvore->itens[ordem].filho;
                        j = 0;
                        for ( i = ordem+1; i <= 2*ordem; i++ ) {
                            novo_no->itens[j] = arvore->itens[i];
                            j++;
                        }       
                        nova_pagina = arvore->itens[ordem];                     
                    }
                }
            }
            
        }
    }

}