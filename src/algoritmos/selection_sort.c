#include "selection_sort.h"

void selectionSort(int *vetor, int tamanho) {

    int i, j, menor, aux;

    for (i = 0; i < tamanho - 1; i++) {

        // procura o menor elemento do trecho que ainda nao foi ordenado
        menor = i;

        for (j = i + 1; j < tamanho; j++) {
            if (vetor[j] < vetor[menor]) {
                menor = j;
            }
        }

        // leva o menor para a posicao i
        aux = vetor[i];
        vetor[i] = vetor[menor];
        vetor[menor] = aux;
    }
}
