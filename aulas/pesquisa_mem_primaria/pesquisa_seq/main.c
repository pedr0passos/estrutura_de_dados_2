#include <stdio.h>
#include <stdlib.h>
#define MAX 100

typedef struct {
    int x;
}registro;

typedef int indice;

typedef struct {
    registro item[MAX+1];
    indice n;
}tabela;

void inicia (tabela *t) {
    t->n = 0;
}

indice pesquisa (int x, tabela *t) {
    int i;
    t->item[0].x = x;
    i = t->n + 1;
    do {
        i--;
    } while ( t->item[i].x != x);
    return i;
}

void insere (registro reg, tabela *t ) {
    if ( t->n == MAX) {
        printf("Erro: Tabela Cheia\n");
    } else {
        t->n++;
        t->item[t->n] = reg;
    }
}

int main() {
    
    tabela *tab;
    registro numero;
    numero.x = 4;
    inicia(tab);
    insere(numero, tab);
    numero.x = 1;   
    insere(numero, tab);
    numero.x = 45;
    insere(numero, tab);
    numero.x = 2;
    printf("%d", pesquisa(4, tab));

    return 0;
}

