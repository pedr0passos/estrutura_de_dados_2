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

int vazia( descritor *lista ) {
    if ( lista->num_elementos == 0 ) {
        return 1;
    } else {
        return 0;
    }
}

void insere(descritor *lista, int valor)
{

    no_lista *novo_item = malloc(sizeof(no_lista));
    if (novo_item != NULL) {
        novo_item->informacao = valor;
        if ( !vazia(lista) ) {
            novo_item->proximo = lista->primeiro;
            novo_item->anterior = lista->primeiro->anterior;
            lista->primeiro->anterior = novo_item;
            lista->primeiro = novo_item;
        } else {
            novo_item->proximo = NULL;
            novo_item->anterior = NULL;
            lista->primeiro = novo_item;
            lista->ultimo = novo_item;
        }
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

void selection_sort(descritor *lista) {

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

void bub_sort ( descritor *lista ) {

    int auxiliar;
    no_lista *i, *j;

    for ( i = lista->ultimo ; i != lista->primeiro->proximo; i = i->anterior ) {
        
        for ( j = lista->primeiro ; j != i ; j = j->proximo ) {
            
            if ( j->informacao > j->proximo->informacao ) {
                auxiliar = j->informacao;
                j->informacao = j->proximo->informacao;
                j->proximo->informacao = auxiliar;
            }
        }
    }

}
 
void insertion_sort (descritor *lista ) {

    int auxiliar; no_lista *i, *j;

    for ( i = lista->primeiro->proximo; i != NULL; i = i->proximo ) {
        auxiliar = i->informacao;
        for ( j = i->anterior; j != NULL; j = j->anterior ) {
            if ( auxiliar < j->informacao ) {
                j->proximo->informacao = j->informacao;
                j->informacao = auxiliar;
            }
        }
    }

} 

void insertion_sort_w (descritor *lista) {

    int aux; no_lista *i, *j, *temp;

    for ( i = lista->primeiro->proximo; i != NULL; i = i->proximo ) {
        aux = i->informacao;
        j = i->anterior;
        while ( j != NULL && aux < j->informacao ) {           
            j->proximo->informacao = j->informacao;
            if ( j->anterior == NULL ) {
                temp = j;
            }            
            j = j->anterior;
        }
        if ( j == NULL ) {
            temp->informacao = aux;
        } else {
            j->proximo->informacao = aux;
        }
    }

}



int main() {
    setlocale(LC_ALL, "portuguese");

    descritor l;
    cria_lista(&l);

    insere(&l, 4);
    insere(&l, 1);
    insere(&l, 7);
    insere(&l, 6);
    insere(&l, -8);
    insere(&l, 10);

    printf("Lista: ");
    imprime(&l);

    insertion_sort(&l);
    printf("Lista Ordenada: ");
    imprime(&l);

    return 0;
}