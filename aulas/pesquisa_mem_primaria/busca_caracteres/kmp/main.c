#include <stdio.h>
#include <string.h>

#define M 6

void p_processamento ( char p[M] ) {
    int i = 1, j = 1, aux[0] = j;
    for (i = 1; i < (M-1); i++){
        while (j > -1 && p[j+1] > p[i]) {
            j = aux[j];
            if(p[i] == p[j]) {
                j++;
            }
            aux[i] = j;
        }
    }
}

void kmp ( ) {

}

int main () {


    return 0;
}