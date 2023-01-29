#include <stdio.h>
#include <stdlib.h>

#define ordem 2
#define true 1
#define false 0

typedef struct _pagina *aponta_pagina;

typedef struct _dados {
    int chave;
    int id;
    aponta_pagina filho;
} dados;

typedef struct _pagina {
    int numero_elementos;
    dados informacoes[2*ordem+1];
    struct _pagina *pagina0;
} pagina;


// alguns rabiscos sobre a remocao:

/*

1 caso: se o elemento ESTIVER em uma folha e a folha mantiver 50% de ocupação se removida a chave, basta remove-la

- PARAMETROS:
int buscado;
pagina *p;

- PARTE DO CODIGO
int i = 0;
    if ( (p->numero_elementos)-1 >= ordem )
        while ( i < numero_elementos ) {
            if ( p->informacoes[i].chave == buscado )
                if ( i == numero_elementos - 1 )
                    p->numero_elementos--;
                else 
                    if ( i < numero_elementos - 1 && i > 0 )
                        while ( i < numero_elementos ) {
                            p->informacoes[i] = p->informacoes[i+1];
                            i++;
                        }
            else 
                i++;
        }

*/

int search(pagina *t, int k) {
    if ( t == NULL )
        return;
    else { 
        search(t->pagina0, k);
        int i = 0;
        while ( t->informacoes[i].id != k && i < t->numero_elementos )
            i++;
        if ( i != t->numero_elementos )
            return i;
        else 
            return;
    }
}


void ajusta ( pagina *p, int posicao ) {
    int i, j;
    pagina *aux;
    aux = p->informacoes[posicao].filho;

    if ( p->informacoes[posicao-1].filho->numero_elementos > ordem ) {
        i = aux->numero_elementos-1; 
        while ( i > 0 ) {
            aux->informacoes[i] = aux->informacoes[i-1];
            i--;
        }  
        aux->informacoes[i].chave = p->informacoes[posicao].chave;      
        p->informacoes[posicao].chave = p->informacoes[posicao-1].filho->informacoes[p->informacoes[posicao-1].filho->numero_elementos-1].chave;
        p->informacoes[posicao].filho->numero_elementos--;
        aux->numero_elementos++;
    }
}

dados insere ( pagina *p, int chave, int *h ) {
    int i, j;
    dados novo_dado;
    pagina *nova_pagina;

    *h = 1;
    if ( p == NULL ) {
        novo_dado.chave = chave;
        novo_dado.filho = NULL;
    } else {
        i = 0;
        while ( (i < p->numero_elementos ) && ( chave > p->informacoes[i].chave) )
            i++;
        if ( p->informacoes[i].chave == chave ) {
            *h = 0;
            novo_dado.chave = chave;
            novo_dado.filho = NULL;
        } else {
            i--;
            if ( i <= 2*ordem ) {
                if ( i == - 1 )
                    novo_dado = insere(p->pagina0, chave, h);
                else {
                    if ( chave > p->informacoes[i].chave )
                        novo_dado = insere(p->informacoes[i].filho, chave, h);
                    else 
                        *h = 0;
                }
                if ( *h == 1 ) {    
                    for ( j = p->numero_elementos; j > i+1; j--)
                        p->informacoes[j] = p->informacoes[j-1];
                    p->informacoes[j] = novo_dado;
                    if ( p->numero_elementos < 2*ordem ) {
                        *h = 0;
                        p->numero_elementos++;
                    } else {    // OVERFLOW
                        nova_pagina = malloc(sizeof(pagina));
                        nova_pagina->pagina0 = p->informacoes[ordem].filho;
                        j = 0;
                        for ( i = ordem+1; i <= 2*ordem; i++ ) {
                            nova_pagina->informacoes[j] = p->informacoes[i];
                            j++;
                        }
                        novo_dado = p->informacoes[ordem];
                        novo_dado.filho = nova_pagina;
                        p->numero_elementos = ordem;
                        nova_pagina->numero_elementos = ordem;
                        *h = 1;
                    }
                }
            }
        }
    }
    return novo_dado;
}

void insere_arvore( pagina **p, int chave ) {
    pagina *nova_pagina;
    dados info;
    int h;

    info = insere( *p, chave, &h );
    if ( h != 0 ) {
        nova_pagina = malloc(sizeof(pagina));
        nova_pagina->pagina0 = *p;
        nova_pagina->informacoes[0] = info;
        nova_pagina->numero_elementos = 1;
        *p = nova_pagina;
    }

}

void imprimeArvoreB(pagina *A){

  int i;

  if (A!=NULL){
    imprimeArvoreB(A->pagina0);
    for(i=0; i<A->numero_elementos;i++){
      printf("%d  \n",A->informacoes[i].chave);
      imprimeArvoreB(A->informacoes[i].filho);
    }
  }
}

int main () {

    pagina *arvore = NULL;
    
    insere_arvore(&arvore, 7);
    insere_arvore(&arvore, 17);
    insere_arvore(&arvore, 70);
    insere_arvore(&arvore, 13);
    imprimeArvoreB(arvore);

    return false;
}