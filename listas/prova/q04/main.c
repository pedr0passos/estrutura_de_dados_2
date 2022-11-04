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

/*void ordena_lista_1(descritor *lista) {
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

    ordenando o vetor e esvaziando a lista
    shellsort(vetor, tamanho);
    esvazia(lista);

    // colocando os valores do vetor dentro da nova lista
    for (int i = ((tamanho)-1); i >= 0; i--)
    {
        insere(lista, vetor[i]);
    }

}*/

/*void ordena_lista_2(descritor *lista) {

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

} */

void ordena_lista(descritor *lista) {

    int h = 1, i, j, auxiliar_troca;
    int tamanho = lista->num_elementos;
    
    while (h < tamanho)
    {
        h = h * 3 + 1;
    }

    no_lista *p;
    no_lista *q;

    while (h > 1) {
        h = (h - 1) / 3;
        printf("H: %d\n",h);
        i = 0 ;
        j = 0 ;
        p = lista->primeiro;

            printf("While 1\n");     

            do {
                p = p->proximo;
                i++;
            } while ( i < h );

            q = p;  

            printf("While 2\n");

            do {                
                q = q->anterior;
                j++;
            } while ( j < h);                     

            auxiliar_troca = p->informacao;

            while ( p != NULL || auxiliar_troca < q->informacao ) {

                printf("Informacao de p: %d\n", p->informacao); 
                printf("Informacao de q: %d\n", q->informacao);   

                    p->informacao = q->informacao;

                    printf("Trocou o %d pelo %d\n", p->informacao,q->informacao);
                    p = p->proximo;
                    q = q->proximo;                     

            }
            p->informacao = auxiliar_troca;
    } 
}


int main()
{
    setlocale(LC_ALL, "portuguese");

    descritor l;
    cria_lista(&l);

    insere(&l, 4);
    insere(&l, 10);
    insere(&l, 3);
    insere(&l, 6);
    insere(&l, 8);
    insere(&l, 1);



    printf("Lista 1: ");
    imprime(&l);
    ordena_lista(&l);
    printf("Lista Ordenada: ");
    imprime(&l);

    return 0;
}