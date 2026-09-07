#ifndef GERADOR_H
#define GERADOR_H

/* Gera o arquivo de entrada da combinacao escolhida no menu e devolve o vetor
   que foi gravado, para ser ordenado em seguida.
   O algoritmo entra como nome de pasta ("Insertion Sort"), entao a mesma
   funcao serve para qualquer algoritmo novo sem alteracao.
   O vetor e alocado com malloc: quem chama precisa dar free. */
int *gerarEntrada(char *algoritmo, char *instancia, int tamanho);

#endif
