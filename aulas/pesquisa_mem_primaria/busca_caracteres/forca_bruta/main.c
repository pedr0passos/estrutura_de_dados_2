#include <stdio.h>
#include <stdlib.h>

void compara( char *texto, int tam_t, char *padrao, int tam_p) {
    int i,j;
    for ( i = 0; i <= (tam_t - tam_p); i++ ) {
        j = 0;
        while (j < tam_p && texto[i + j] == padrao[j]) {
            j++;
        }
        if ( j == tam_p ) {
            printf("encontrou\n");
        }
    }
}

int main() {

    int tamanho_t = 16, tamanho_p = 4;
    char text[tamanho_t];
    char pad[tamanho_p];
    scanf("%[^\n]", text);
    setbuf(stdin, NULL);
    scanf("%[^\n]", pad);
    setbuf(stdin, NULL);
    printf("leu\n");
    compara(text, tamanho_t, pad, tamanho_p);

    return 0;
}
