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

void ajusta_numeros ( pagina *arvore, int numero ) {
    if ( arvore->chaves[numero].filho->numero_elementos < ordem  && arvore->numero_elementos <= 2*ordem  && arvore->numero_elementos > ordem ) {
        int aux = arvore->chaves[ordem].chave;
        int i = 0;
        while ( arvore->chaves[ordem].filho->chaves[i].chave < aux )
            i++;
        if ( i == 0 )
            arvore->chaves[ordem].filho->chaves;
    }
}

void cria_arvore_vazia ( pagina *arvore ) {
    arvore = NULL;
}

int vazia( pagina *arvore ) {
    return ( arvore == NULL );
}

void busca_elemento ( pagina *arvore, int buscado ) {

}

int acha_posicao( pagina *arvore, int valor, int posicao ) {
    while ( posicao < arvore->numero_elementos && valor > arvore->chaves[posicao].chave )
        posicao++;
    return posicao;
}

int overflow ( pagina *arvore ) {

}

informacao insere( pagina *arvore, int valor, int *altura ) {
    int i, j;
    informacao nova_info;
    pagina *nova_pagina;

    *altura=1;
    if (vazia(arvore)) {
        nova_info.chave = valor;
        nova_info.filho = NULL;
    } else {
        i = acha_posicao(arvore, valor, i);
        if ( arvore->chaves[i].chave == valor ) {
            *altura = 0;
            nova_info.chave = valor;
            nova_info.filho = NULL;
        } else {
            i--;
            if (i < 2*ordem) {
                if (i = -1)
                    nova_info = insere(arvore->pagina0, valor, altura);
                else 
                    if ( valor > arvore->chaves[i].chave )
                        nova_info = insere(arvore->chaves[i].filho, valor, altura);
                    else 
                        *altura = 0;
                if ( *altura == 1 ) {
                    for ( j = arvore->chaves; j > i+1; j-- )
                        arvore->chaves[j] = arvore->chaves[j-1];
                    arvore->chaves[j] = nova_info;
                    if ( arvore->numero_elementos < 2*ordem ) {
                        *altura = 0;
                        arvore->numero_elementos++;
                    } else {    // overflow
                        nova_pagina = (pagina*)malloc(sizeof(pagina));
                        nova_pagina->pagina0 = arvore->chaves[ordem].filho;
                        j = 0;
                        for ( i = ordem+1; i <= 2*ordem; i++ ) {
                            nova_pagina->chaves[j] = arvore->chaves[i];
                            j++;
                        }       
                        nova_info = arvore->chaves[ordem];                     
                    }
                }
            }
            
        }
    }

}