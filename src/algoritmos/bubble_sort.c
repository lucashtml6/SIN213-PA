#include "bubble_sort.h"

void bubbleSort(int *vetor, int tamanho) {

    int i, j, aux;

    for (i = 0; i < tamanho - 1; i++) {

        /* a cada passagem, o maior elemento que ainda restava sobe ate o
           fim do trecho nao ordenado; por isso o limite diminui de 1 */
        for (j = 0; j < tamanho - 1 - i; j++) {

            if (vetor[j] > vetor[j + 1]) {
                aux = vetor[j];
                vetor[j] = vetor[j + 1];
                vetor[j + 1] = aux;
            }
        }
    }
}
