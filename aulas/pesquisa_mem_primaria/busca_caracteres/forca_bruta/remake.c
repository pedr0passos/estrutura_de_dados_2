#include <stdio.h>
// tamanhos de MaxP e MaxT
#define MaxT 10
#define MaxP 3
// regra : MaxT precisa ser maior que MaxP -> ( MaxT > MaxP )

// prototipo da funcao
int forca_bruta (char *texto, char *padrao);

int main () {


    return 0;
}

// função forca bruta
int forca_bruta (char *texto, char *padrao) {
    int i, j;
    int contador=0;
    for (i = 0; i < (MaxT-MaxP); i++) {
        j = 0;
        while ( j < MaxP && texto[i + j] == padrao[j] ) {
            j++;
            if ( j == MaxP ) {
                return i;
            }
        }
    }
}