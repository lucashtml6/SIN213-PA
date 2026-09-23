#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "gerador.h"

static int aleatorio(int limite) {

    long parteAlta, parteBaixa, sorteio, posicao;

    parteAlta = rand() & 0x7FFF;
    parteBaixa = rand() & 0x7FFF;

    sorteio = (parteAlta << 15) | parteBaixa;

    posicao = sorteio % limite;

    return (int)posicao;
}


static void preencherVetor(int *vetor, int tamanho, char *instancia) {

    int i, j, aux;

    // crescente: sempre executa, mesmo que a instancia seja decrescente ou random
    for (i = 0; i < tamanho; i++) {
        vetor[i] = i + 1;
    }

    // decrescente: inverte o vetor crescente
    if (strcmp(instancia, "Decrescente") == 0) {

        for (i = 0; i < tamanho / 2; i++) {
            aux = vetor[i];
            vetor[i] = vetor[tamanho - 1 - i];
            vetor[tamanho - 1 - i] = aux;
        }

    // random
    } else if (strcmp(instancia, "Random") == 0) {

        for (i = tamanho - 1; i > 0; i--) {

            j = aleatorio(i + 1);

            aux = vetor[i];
            vetor[i] = vetor[j];
            vetor[j] = aux;
        }
    }
}


int *gerarEntrada(char *algoritmo, char *instancia, int tamanho) {

    char caminho[256];
    FILE *arquivo;
    int *vetor;
    int i;

    sprintf(caminho, "%s/Arquivos de Entrada/%s/Entrada%s%d.txt",
            algoritmo, instancia, instancia, tamanho);

    vetor = (int *) malloc(tamanho * sizeof(int));

    preencherVetor(vetor, tamanho, instancia);

    arquivo = fopen(caminho, "w");

    fprintf(arquivo, "%d\n", tamanho);

    for (i = 0; i < tamanho; i++) {
        fprintf(arquivo, "%d\n", vetor[i]);
    }

    fclose(arquivo);

    printf("\nArquivo gerado: %s\n", caminho);

    return vetor;
}
