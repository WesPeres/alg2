#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>

#include "ordenacao.h"

#define MAX_VETOR 50000

int main(){
	char nome[MAX_CHAR_NOME];
	int tamVetor;
	/* Codigo utilizado para verificar a escolha do vetor inverso
	 * ou do vetor aleatório */
	int vetCode;
	// Codigo utilizado para verificar a escolha do algoritmo
	int algCode;
	/* Utilizado para verificar se o vetor foi ordenado antes de
	 * utilizar algum algoritmo de busca */
	bool ordenado;

	getNome(nome);
	printf("Trabalho de %s\n", nome);
	printf("GRR %u\n", getGRR());

	do {
		printf("Digite o tamanho do vetor (entre 0 e 50000): ");
		scanf("%i", &tamVetor);
	} while (tamVetor < 0 || tamVetor > MAX_VETOR);

	int *vetor = malloc(tamVetor * sizeof(int));
	if (vetor == NULL) {
		printf("Falha fatal. Impossivel alocar memoria.");
		return 1;
	}

	/* eh passado como parametro dos algoritmos de busca e ordenação
	 * a fim de conservar o vetor original, nao ordenado */
	int *copia = malloc(tamVetor * sizeof(int));
	if (copia == NULL) {
		printf("Falha fatal. Impossivel alocar memoria.");
		return 1;
	}

	do {
		printf("Digite 1 se deseja criar um vetor inverso. Ex: [3, 2, 1]\n");
		printf("Digite 2 se deseja criar um vetor aleatório. Ex: [2, 5, 1]\n");
		scanf("%i", &vetCode);
	} while (vetCode != 1 && vetCode != 2);
	
	if (vetCode == 1)
		writeReversedArray(vetor, tamVetor);
	else
		writeRandomArray(vetor, tamVetor);

	readArray(vetor, tamVetor);

	ordenado = false;
	do {
		printf("\nInsira 1 para Insertion Sort\n");
		printf("Insira 2 para Selection Sort\n");
		printf("Insira 3 para Merge Sort\n");
		printf("Insira 4 para Quick Sort\n");
		printf("Insira 5 para Heap Sort\n");
		printf("Insira 0 para algoritmos de busca \n");
		scanf("%i", &algCode);
					
		if (algCode >= 1 && algCode <= 5) {
			copia_vetor(copia, vetor, tamVetor);
			escolheSortAlg(algCode, copia, tamVetor);
			ordenado = true;
		}
		else if (algCode == 0 && !ordenado) {
			printf("Voce precisa escolher um algoritmo de ordenacao "
					"antes de utilizar um algoritmo de busca\n\n");
		}
	} while (algCode != 0 || !ordenado) ;

	do {
		printf("\nInsira 1 para Busca Sequencial\n");
		printf("Insira 2 para Busca Binaria\n");
		printf("Insira 0 para sair\n");
		scanf("%i", &algCode);

		escolheSearchAlg(algCode, copia, tamVetor);
	} while (algCode != 0);

	free(vetor);
	free(copia);

	return 0;
}
