// METODO DE ORDENAÇÃO MERGESORT
#include <stdio.h>
#define N 10

void intercalar (int v[N], int inicio, int meio, int fim);
void merge_sort(int v[N], int inicio, int fim);

int main () {

    int vetor[N] = {14,25,756,3,2,0,234,32,10,54};
    int ini = 0, fim = (N-1);
    merge_sort(vetor, ini, fim);
    
    for (int i = 0; i < N; i++ ) {
        printf("%d ", vetor[i]);
    }

    return 0;
}

void merge_sort(int v[N], int inicio, int fim) {
    if ( inicio < fim ) {
        int meio = (inicio+fim)/2;
        merge_sort(v, inicio, meio);
        merge_sort(v, meio + 1, fim);
        intercalar(v, inicio, fim, meio);
    }
}

void intercalar (int v[N], int inicio, int meio, int fim) {
    int i = inicio, j = meio+1, k = 0;
    int temp[N];
    while ( (i <= meio) || (j <= fim) ) {
        if ( (i = (meio + 1)) || (v[j] < v[i]) && (j != (fim + 1)) ) {
            temp[k] = v[j];
            j++;
            k++;
        } else {
            temp[k] = v[i];
            i++;
            k++;
        }
    }
    for (int i = inicio; i <= fim; i++) {
        v[i] = temp[i-inicio];
    }
}

