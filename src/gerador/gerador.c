#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "gerador.h"

/* rand() aqui vai so ate 32767 (RAND_MAX do MinGW), faixa pequena demais para
   sortear posicoes de um vetor de 1.000.000. Junta dois sorteios de 15 bits. */
static int aleatorio(int limite) {

    long r = ((long)(rand() & 0x7FFF) << 15) | (rand() & 0x7FFF);

    return (int)(r % limite);
}


static void preencherVetor(int *vetor, int tamanho, char *instancia) {

    int i, j, aux;

    // crescente: sempre executa, mesmo que a instancia seja decrescente ou random
    for (i = 0; i < tamanho; i++) {
        vetor[i] = i + 1;
    }

    // decrescente: inverte o vetor crescente
    if (strcmp(instancia, "Decrescente") == 0) {

        for (i = 0; i < tamanho / 2; i++) { // tamanho / 2 para nao inverter de novo
            aux = vetor[i];
            vetor[i] = vetor[tamanho - 1 - i];
            vetor[tamanho - 1 - i] = aux;
        }

    // random
    } else if (strcmp(instancia, "Random") == 0) {

        /* Fisher-Yates: percorre de tras para frente trocando cada posicao
           com uma sorteada entre as que ainda nao passaram. */
        for (i = tamanho - 1; i > 0; i--) {

            j = aleatorio(i + 1);

            aux = vetor[i];
            vetor[i] = vetor[j];
            vetor[j] = aux;
        }
    }
}

/* Grava o arquivo em:
     <algoritmo>/Arquivos de Entrada/<instancia>/Entrada<instancia><tamanho>.txt
   Primeira linha: o tamanho da instancia. Depois, um numero por linha.
   Devolve o vetor gerado; o free fica por conta de quem chamou. */
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
