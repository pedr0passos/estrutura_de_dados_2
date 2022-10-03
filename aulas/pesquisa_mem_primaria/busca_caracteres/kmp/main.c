#include <stdio.h>
#include <string.h>

void kmp ( char text, char pattern, int m, int n) {
    if ( pattern == '\0' || n == 0 ) {
        printf("O Padrao tem tamanho 0\n");
    }
    if (text == '\0' || n > m ) {
        printf("Padrao nao encontrado\n");
    }
    
}

int main () {
    
    char text = "ABCABAABCABAC";
    char pattern = "CAB";

    return 0;
}