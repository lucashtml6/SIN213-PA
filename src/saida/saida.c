#include <stdio.h>

#include "saida.h"


void salvarTempo(char *algoritmo, char *instancia, int tamanho, double tempo) {

    char caminho[256];
    FILE *arquivo;

    sprintf(caminho, "%s/Arquivos de Tempo/%s/Tempo%s%d.txt",
            algoritmo, instancia, instancia, tamanho);

    arquivo = fopen(caminho, "w");

    fprintf(arquivo, "%d\n", tamanho);
    fprintf(arquivo, "%.6f\n", tempo);

    fclose(arquivo);

    printf("Tempo gravado : %s\n", caminho);
}


void salvarSaida(char *algoritmo, char *instancia, int tamanho, int *vetor) {

    char caminho[256];
    FILE *arquivo;
    int i;

    sprintf(caminho, "%s/Arquivos de Saida/%s/Saida%s%d.txt",
            algoritmo, instancia, instancia, tamanho);

    arquivo = fopen(caminho, "w");

    for (i = 0; i < tamanho; i++) {
        fprintf(arquivo, "%d\n", vetor[i]);
    }

    fclose(arquivo);

    printf("Saida gravada : %s\n", caminho);
}
