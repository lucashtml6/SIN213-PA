#include <stdio.h>
#include <stdlib.h>

#include "menu.h"

// função genérica para ler uma opção de menu. Devolve a opção lida.
int lerOpcao(int minimo, int maximo) {

    int opcao, c, lido;

    while (1) {
        printf("Opcao: ");

        lido = scanf("%d", &opcao);

        if (lido == 1 && opcao >= minimo && opcao <= maximo) {
            return opcao;
        }

        if (feof(stdin)) {
            exit(1);
        }

        c = getchar();

        while (c != '\n' && c != EOF) {
            c = getchar();
        }

        printf("Opcao invalida.\n\n");
    }
}


int menuAlgoritmo() {
    
    int opc_algoritmo;

    printf("\n");
    printf("Escolha o algoritmo:\n\n");
    printf("[1] Insertion Sort\n");
    printf("[2] Selection Sort\n");
    printf("[3] Bubble Sort\n");
    printf("[4] Shell Sort\n");
    printf("[0] Sair\n\n");

    opc_algoritmo = lerOpcao(0, 4);
    
    return opc_algoritmo;
}

int menuTamanho() {

    int tamanhos[6] = {10, 100, 1000, 10000, 100000, 1000000};
    int opc_tamanho;

    printf("\n");
    printf("Escolha o tamanho da entrada:\n\n");
    printf("[1] 10\n");
    printf("[2] 100\n");
    printf("[3] 1000\n");
    printf("[4] 10000\n");
    printf("[5] 100000\n");
    printf("[6] 1000000\n");
    printf("[0] Sair\n\n");

    opc_tamanho = lerOpcao(0, 6);

    if (opc_tamanho == 0) {
        return 0;
    }

    // ex: se o usuário digitar 1, devolve 10
    opc_tamanho = tamanhos[opc_tamanho - 1];

    return opc_tamanho;
}


char *menuInstancia() {
    int opc_instancia;
    char *instancias[3] = {"Crescente", "Decrescente", "Random"};

    printf("\n");
    printf("Escolha o tipo de instancia:\n\n");
    printf("[1] Crescente\n");
    printf("[2] Decrescente\n");
    printf("[3] Random\n");
    printf("[0] Sair\n\n");

    opc_instancia = lerOpcao(0, 3);

    if (opc_instancia == 0) {
        return NULL;
    }

    char *instancia = instancias[opc_instancia - 1];

    return instancia;
}

