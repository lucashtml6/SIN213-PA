#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "menu/menu.h"
#include "gerador/gerador.h"
#include "algoritmos/algoritmos.h"
#include "saida/saida.h"

int main() {

    int algoritmo, tamanho;
    char *instancia;
    int *vetor;

    clock_t inicio, fim;
    double tempo;

    srand(time(NULL));

    algoritmo = menuAlgoritmo();

    // sai do programa
    if (algoritmo == 0) {
        return 0;
    }

    tamanho = menuTamanho();

    // sai do programa
    if (tamanho == 0) {
        return 0;
    }

    instancia = menuInstancia();

    // sai do programa
    if (instancia == NULL) {
        return 0;
    }

    printf("\n");
    printf("Algoritmo: Insertion Sort\n");
    printf("Tamanho: %d\n", tamanho);
    printf("Instancia : %s\n", instancia);

    // Insertion Sort
    if (algoritmo == 1) {
        vetor = gerarEntrada("Insertion Sort", instancia, tamanho);

        printf("\nExecutando insertion sort para entrada %d\n", tamanho);

        // o relogio envolve so a ordenacao: nada de geracao nem de gravacao
        inicio = clock();
        insertionSort(vetor, tamanho);
        fim = clock();

        tempo = (fim - inicio) / (double)CLOCKS_PER_SEC;

        printf("Tempo gasto   : %.6f s\n", tempo);

        salvarTempo("Insertion Sort", instancia, tamanho, tempo);
        salvarSaida("Insertion Sort", instancia, tamanho, vetor);

        free(vetor);
    }

    return 0;
}
