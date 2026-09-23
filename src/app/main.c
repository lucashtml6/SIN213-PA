#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "menu/menu.h"
#include "gerador/gerador.h"
#include "algoritmos/insertion_sort.h"
#include "algoritmos/selection_sort.h"
#include "algoritmos/bubble_sort.h"
#include "algoritmos/shell_sort.h"
#include "saida/saida.h"

int main() {

    int algoritmo, tamanho;
    char *instancia;
    int *vetor;
    clock_t inicio, fim;
    double tempo;

    srand(time(NULL));

    // o programa so termina quando o usuario escolher Sair no primeiro menu
    while (1) {

        algoritmo = menuAlgoritmo();
        // sai do programa
        if (algoritmo == 0) {
            break;
        }

        tamanho = menuTamanho();
        // sai do programa
        if (tamanho == 0) {
            break;
        }

        instancia = menuInstancia();
        // sai do programa
        if (instancia == NULL) {
            break;
        }

        // Insertion Sort
        if (algoritmo == 1) {

            printf("\n");
            printf("Algoritmo: Insertion Sort\n");
            printf("Tamanho: %d\n", tamanho);
            printf("Instancia : %s\n", instancia);

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

        // Selection Sort
        if (algoritmo == 2) {

            printf("\n");
            printf("Algoritmo: Selection Sort\n");
            printf("Tamanho: %d\n", tamanho);
            printf("Instancia : %s\n", instancia);

            vetor = gerarEntrada("Selection Sort", instancia, tamanho);

            printf("\nExecutando selection sort para entrada %d\n", tamanho);

            // o relogio envolve so a ordenacao: nada de geracao nem de gravacao
            inicio = clock();
            selectionSort(vetor, tamanho);
            fim = clock();

            tempo = (fim - inicio) / (double)CLOCKS_PER_SEC;

            printf("Tempo gasto   : %.6f s\n", tempo);

            salvarTempo("Selection Sort", instancia, tamanho, tempo);
            salvarSaida("Selection Sort", instancia, tamanho, vetor);

            free(vetor);
        }

        // Bubble Sort
        if (algoritmo == 3) {

            printf("\n");
            printf("Algoritmo: Bubble Sort\n");
            printf("Tamanho: %d\n", tamanho);
            printf("Instancia : %s\n", instancia);

            vetor = gerarEntrada("Bubble Sort", instancia, tamanho);

            printf("\nExecutando bubble sort para entrada %d\n", tamanho);

            // o relogio envolve so a ordenacao: nada de geracao nem de gravacao
            inicio = clock();
            bubbleSort(vetor, tamanho);
            fim = clock();

            tempo = (fim - inicio) / (double)CLOCKS_PER_SEC;

            printf("Tempo gasto   : %.6f s\n", tempo);

            salvarTempo("Bubble Sort", instancia, tamanho, tempo);
            salvarSaida("Bubble Sort", instancia, tamanho, vetor);

            free(vetor);
        }

        // Shell Sort
        if (algoritmo == 4) {

            printf("\n");
            printf("Algoritmo: Shell Sort\n");
            printf("Tamanho: %d\n", tamanho);
            printf("Instancia : %s\n", instancia);

            vetor = gerarEntrada("Shell Sort", instancia, tamanho);

            printf("\nExecutando shell sort para entrada %d\n", tamanho);

            // o relogio envolve so a ordenacao: nada de geracao nem de gravacao
            inicio = clock();
            shellSort(vetor, tamanho);
            fim = clock();

            tempo = (fim - inicio) / (double)CLOCKS_PER_SEC;

            printf("Tempo gasto   : %.6f s\n", tempo);

            salvarTempo("Shell Sort", instancia, tamanho, tempo);
            salvarSaida("Shell Sort", instancia, tamanho, vetor);

            free(vetor);
        }

        printf("\n------------------------------------------------------------\n");
    }

    printf("\nEncerrando.\n");

    return 0;
}
