#include "algoritmos.h"

/* Insertion Sort - versao tradicional (InsertionSort_versao1)

   Percorre o vetor da segunda posicao em diante. A cada passo, o trecho a
   esquerda de i ja esta ordenado; guarda-se vetor[i] em aux e abre-se espaco
   para ele empurrando para a direita todo mundo que for maior. */
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
