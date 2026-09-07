#ifndef SAIDA_H
#define SAIDA_H

/* Gravam os resultados de uma execucao.
   O algoritmo entra como nome de pasta ("Insertion Sort"), entao as mesmas
   funcoes servem para qualquer algoritmo novo sem alteracao. */

void salvarTempo(char *algoritmo, char *instancia, int tamanho, double tempo);
void salvarSaida(char *algoritmo, char *instancia, int tamanho, int *vetor);

#endif
