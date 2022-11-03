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
            printf(" - ");
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

int d(int h)
{
    return (h = (h - 1) / 3);
}

void shellsort(int v[], int n)
{

    int i, j, h, auxiliar;

    h = 1; // iniciando o h como 1, o h é a quantidade de casas que se deve pular para fazer as comparações

    // laço que calcula o valor de h
    while (h < n)
    {
        h = h * 3 + 1;
    }

    // laço principal
    while (h > 1)
    {
        h = d(h); // h = 4
        for (i = h; i < n; i++)
        {
            auxiliar = v[i];
            j = i - h;
            while (j >= 0 && auxiliar < v[j])
            {
                v[j + h] = v[j];
                j -= h;
            }
            v[j + h] = auxiliar;
        }
    }
}

void ordena_lista_1(descritor *lista) {
    // criacao das variaveis necessárias
    int tamanho, i;
    tamanho = lista->num_elementos;
    i = 0;
    int vetor[tamanho];

    no_lista *p;
    // colocando as informações da lista, dentro do vetor
    for ( p = lista->primeiro; p != NULL; p = p->proximo) {
        vetor[i] = p->informacao;
        i++;
    }

    // ordenando o vetor e esvaziando a lista
    shellsort(vetor, tamanho);
    esvazia(lista);

    // colocando os valores do vetor dentro da nova lista
    for (int i = ((tamanho)-1); i >= 0; i--)
    {
        insere(lista, vetor[i]);
    }

}

void ordena_lista_2(descritor *lista) {

    // criacao das variaveis necessárias
    int tamanho, i;
    tamanho = lista->num_elementos;
    i = 0;
    int vetor[tamanho];

    // colocando as informações da lista, dentro do vetor
    no_lista *p = lista->primeiro;
    while (p != NULL) {
        no_lista *auxiliar = p;
        vetor[i] = auxiliar->informacao;
        p = auxiliar->proximo;
        remove_elemento(lista, auxiliar->informacao);
        i++;
    }

    // ordenando o vetor e criando a lista nova que será retornada no final da função
    shellsort(vetor, tamanho);

    // colocando os valores do vetor dentro da nova lista
    for (int i = ((tamanho)-1); i >= 0; i--) {
        insere(lista, vetor[i]);
    }

}

int main()
{
    setlocale(LC_ALL, "portuguese");

    descritor l;
    descritor l2;
    cria_lista(&l);
    cria_lista(&l2);

    insere(&l, 4);
    insere(&l, 1);
    insere(&l, 3);
    insere(&l, 7);
    insere(&l, 2);
    insere(&l, 5);
    insere(&l, 15);
    insere(&l, 22);
    insere(&l, 50);
    insere(&l, 6);
    printf("Lista 1: ");
    imprime(&l);

    insere(&l2, 4);
    insere(&l2, 1);
    insere(&l2, 3);
    insere(&l2, 7);
    insere(&l2, 2);
    insere(&l2, 5);
    insere(&l2, 15);
    insere(&l2, 22);
    insere(&l2, 50);
    insere(&l2, 6);
    printf("Lista 2: ");
    imprime(&l2);

    ordena_lista_1(&l2);
    ordena_lista_2(&l);
    printf("Lista 1 Ordenada: ");
    imprime(&l);
    printf("Lista 2 Ordenada: ");
    imprime(&l2);

    return 0;
}