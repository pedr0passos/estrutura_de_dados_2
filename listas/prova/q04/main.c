#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct no
{
    int informacao;
    struct no *proximo;
    struct no *anterior;
} no_lista;

typedef struct
{
    int num_elementos;
    no_lista *primeiro;
    no_lista *ultimo;
} descritor;

void cria_lista(descritor *lista)
{
    lista->num_elementos = 0;
    lista->primeiro = NULL;
    lista->ultimo = NULL;
}

int vazia(descritor *lista)
{
    if (lista->num_elementos == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void insere(descritor *lista, int valor)
{

    no_lista *novo_item = malloc(sizeof(no_lista));
    if (novo_item != NULL)
    {

        novo_item->informacao = valor;
        novo_item->proximo = lista->primeiro;
        novo_item->anterior = NULL;

        if (!vazia(lista))
        {
            lista->primeiro->anterior = novo_item;
        }

        lista->primeiro = novo_item;
        lista->num_elementos++;
    }
}

void imprime(descritor *l)
{

    no_lista *p;

    if (l->primeiro == NULL)
    {

        printf("Lista Vazia!");
    }
    else
    {

        for (p = l->primeiro; p != NULL; p = p->proximo)
        {

            printf("%d", p->informacao);
            printf(" ");
        }
        printf("\n");
    }
}

void esvazia(descritor *l)
{

    no_lista *p, *aux;

    for (p = l->primeiro; p != NULL; p = p->proximo)
    {

        aux = p->proximo;
        free(p);
    }

    l->num_elementos = 0;
    l->primeiro = NULL;
    l->ultimo = NULL;
}

void remove_elemento(descritor *l, int v)
{

    no_lista *p, *ant = NULL;

    for (p = l->primeiro; p != NULL && p->informacao != v; p = p->proximo)
    {

        ant = p;
    }

    if (ant == NULL)
    { // quando tem apenas 1 elemento

        l->primeiro = p->proximo;
        l->ultimo = NULL;
    }
    else
    { // quando tem mais de 1 elemento

        if (p == l->ultimo)
        { // quando é o ultimo elemento

            l->ultimo = ant;
        }

        ant->proximo = p->proximo;
    }

    l->num_elementos--;
    free(p);
}

void ordena_lista(descritor *lista) {

    int auxiliar;
    no_lista *p, *j, *menor;

    for ( p = lista->primeiro; p != NULL; p = p->proximo ) {
        menor = p;
        for ( j = p->proximo; j != NULL; j = j->proximo ) {
            if ( j->informacao < menor->informacao ) {
                menor = j;
            }
        }
        if ( menor != p ) {
            auxiliar = menor->informacao;
            menor->informacao = p->informacao;
            p->informacao = auxiliar;
        }
    }

} 

int main() {
    setlocale(LC_ALL, "portuguese");

    descritor l;
    cria_lista(&l);

    insere(&l, 4);
    insere(&l, 10);
    insere(&l, 3);
    insere(&l, 6);
    insere(&l, 8);
    insere(&l, 1);



    printf("Lista: ");
    imprime(&l);
    ordena_lista(&l);
    printf("Lista Ordenada: ");
    imprime(&l);

    return 0;
}