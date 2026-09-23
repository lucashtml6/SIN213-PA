#include "shell_sort.h"

void shellSort(int *vetor, int tamanho) {

    int i, j, h, aux;

    /* sequencia de incrementos de Knuth: 1, 4, 13, 40, 121, ...
       comeca no maior valor da sequencia que ainda serve para o tamanho */
    h = 1;

    while (h < tamanho / 3) {
        h = h * 3 + 1;
    }

    while (h >= 1) {

        /* insercao com passo h: compara elementos distantes h posicoes,
           em vez de vizinhos. Com h = 1 isto vira o proprio Insertion Sort */
        for (i = h; i < tamanho; i++) {

            aux = vetor[i];
            j = i;

            while (j >= h && vetor[j - h] > aux) {
                vetor[j] = vetor[j - h];
                j = j - h;
            }

            vetor[j] = aux;
        }

        h = h / 3;
    }
}
