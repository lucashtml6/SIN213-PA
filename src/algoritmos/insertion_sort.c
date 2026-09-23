#include "insertion_sort.h"

void insertionSort(int *vetor, int tamanho) {

    int i, j, aux;

    for (i = 1; i < tamanho; i++) {

        aux = vetor[i];
        j = i - 1;

        while (j >= 0 && vetor[j] > aux) {
            vetor[j + 1] = vetor[j];
            j--;
        }

        vetor[j + 1] = aux;
    }
}
