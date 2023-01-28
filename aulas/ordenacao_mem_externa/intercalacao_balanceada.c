#include <stdio.h>
#include <stdlib.h>

// Função para dividir o conjunto de dados em partições
void partition(FILE *file, int pivot, int low, int high) {
    int i = low, j = high;
    int temp;
    fseek(file, sizeof(int) * low, SEEK_SET);
    while (i <= j) {
        while (i <= high && fread(&temp, sizeof(int), 1, file) && temp < pivot)
            i++;
        fseek(file, sizeof(int) * j, SEEK_SET);
        while (j >= low && fread(&temp, sizeof(int), 1, file) && temp > pivot)
            j--;
        if (i <= j) {
            fseek(file, sizeof(int) * i, SEEK_SET);
            fread(&temp, sizeof(int), 1, file);
            fseek(file, sizeof(int) * j, SEEK_SET);
            fread(&temp, sizeof(int), 1, file);
            fseek(file, sizeof(int) * i, SEEK_SET);
            fwrite(&temp, sizeof(int), 1, file);
            fseek(file, sizeof(int) * j, SEEK_SET);
            fwrite(&temp, sizeof(int), 1, file);
            i++;
            j--;
        }
    }
}

// Função recursiva para ordenar as partições
void quicksort_externo(FILE *file, int low, int high) {
    if (low < high) {
        int pivot;
        fseek(file, sizeof(int) * (low + high) / 2, SEEK_SET);
        fread(&pivot, sizeof(int), 1, file);
        partition(file, pivot, low, high);
        quicksort_externo(file, low, pivot - 1);
        quicksort_externo(file, pivot + 1, high);
    }
}

int main() {
    // Abra o arquivo de dados
    FILE *file = fopen("dados.txt", "rb+");

    // Obtenha o tamanho do arquivo
    fseek(file, 0, SEEK_END);
    int size = ftell(file) / sizeof(int);

    // Execute o quicksort externo
    quicksort_externo(file, 0, size - 1);

    // Feche o arquivo
    fclose(file);
    return 0;
}
