#include <stdio.h>
#include <stdlib.h>

typedef int IndexAmp;

typedef enum {
    Interno, Externo
}NodoTipo;

typedef struct PatNodo_str *Arvore;

typedef struct PadNodo_str {
    NodoTipo nt;
    union {
        struct {
            IndexAmp Index;
            Arvore Esq, Dir;
        }U0;
        int Chave[8];
    }UU;
}PatNodo;

typedef struct patricinha {
    int tipo_no;
    int posicao;
    char chave[8];
    struct noPatricia *esquerda;
    struct noPatricia *direita;
}no_pat;

no_pat inserir (no_pat *patricia, char chave_1[8], no_pat intermediario_retorna) {
    no_pat *novo = malloc(sizeof(no_pat)), *intermediario;
    novo->chave = chave_1;
    novo->tipo_no = 0;

    if ( (patricia) == NULL ) {

        novo->posicao = 0;
        (patricia) = novo;

    } else {

        int n = 0;
        if ((*patricia)->tipo_no == 0 ) {
            while ( n < 8 && patricia->chave[n] == chave_1[n] ) {
                n++;
            }
            if ( n < 8 ) {

                novo->tipo_no = 0;
                novo->esquerda = NULL;
                novo->direita = NULL;

                intermediario = malloc(sizeof(no_pat));
                intermediario->tipo_no = 1;
                intermediario->posicao = n;

                if ( chave_1[n] == 1 ) {
                    intermediario->direita = novo;
                } else {
                    intermediario->esquerda = novo;
                }

            }
        }


    }
}