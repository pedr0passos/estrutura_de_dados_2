#include <stdio.h>

typedef struct noLista {
    int p, l, c;
    struct no_lista  *proximo;
} no_lista;

typedef struct noTrie {
    no_lista *ocorrencia;
    struct noTrie *vetor[256];
}no_trie;

void cria_arvore (no_trie **t) {
    *t = NULL;
}

int vazia(no_trie **t) {
    return (*t == NULL);
}

no_trie *buscar (no_trie **t, char c ) {
    
}

no_trie *insere( no_trie**t, char c) {
    if ( vazia(*t)) {
        return NULL;
    } else {

    }
}

int main () {

    return 0;
}