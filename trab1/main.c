#include <stdbool.h>
#include "ordenacao.h"

#define MAX_VETOR 50000

int main(){
	char nome[MAX_CHAR_NOME];
	int numComp;
	// Valor a ser pesquisado na busca sequencial ou binária
	int valor;
	// Indice da posição do valor buscado
	int idxBusca;


	getNome(nome);
	printf("Trabalho de %s\n", nome);
	printf("GRR %u\n", getGRR());

	int *vetor = malloc(MAX_VETOR * sizeof(int));
	if (vetor == NULL) {
		printf("Falha fatal. Impossível alocar memoria.");
		return 1;
	}

	/* É passado como parâmetro dos algoritmos de busca e ordenação
	 * a fim de conservar o vetor original, não ordenado */
	int *copia = malloc(MAX_VETOR * sizeof(int));
	if (copia == NULL) {
		printf("Falha fatal. Impossível alocar memoria.");
		return 1;
	}
	
	/* Também é possível criar um vetor ordenado inversamente
	* através da função	writeReversedArray(vetor, MAX_VETOR); */
	// A função abaixo cria um vetor aleatório
	writeRandomArray(vetor, MAX_VETOR);
	// Cria cópia do vetor para poder recuperá-lo após ser ordenado
	copia_vetor(copia, vetor, MAX_VETOR);

	clock_t start, end;
	double total;

	printf("\nInsertion Sort:\n");
	start = clock();
	numComp = insertionSort(copia, MAX_VETOR);
	end = clock();
	total = ((double)end - start)/CLOCKS_PER_SEC;
	printf("Tempo total: %f\n", total);
	printf("Número de comparações: %i\n", numComp);

	copia_vetor(copia, vetor, MAX_VETOR);

	printf("\nSelection Sort:\n");
	start = clock();
	numComp = selectionSort(copia, MAX_VETOR);
	end = clock();
	total = ((double)end - start)/CLOCKS_PER_SEC;
	printf("Tempo total: %f\n", total);
	printf("Número de comparações: %i\n", numComp);

	copia_vetor(copia, vetor, MAX_VETOR);

	printf("\nMerge Sort:\n");
	start = clock();
	numComp = mergeSort(copia, MAX_VETOR);
	end = clock();
	total = ((double)end - start)/CLOCKS_PER_SEC;
	printf("Tempo total: %f\n", total);
	printf("Número de comparações: %i\n", numComp);

	copia_vetor(copia, vetor, MAX_VETOR);

	printf("\nQuick Sort:\n");
	start = clock();
	numComp = quickSort(copia, MAX_VETOR);
	end = clock();
	total = ((double)end - start)/CLOCKS_PER_SEC;
	printf("Tempo total: %f\n", total);
	printf("Número de comparações: %i\n", numComp);

	copia_vetor(copia, vetor, MAX_VETOR);

	printf("\nHeap Sort:\n");
	start = clock();
	numComp = heapSort(copia, MAX_VETOR);
	end = clock();
	total = ((double)end - start)/CLOCKS_PER_SEC;
	printf("Tempo total: %f\n", total);
	printf("Número de comparações: %i\n\n", numComp);

	readArray(copia, MAX_VETOR);

	numComp = 0;
	printf("\nBusca Sequencial:\n");
	printf("Digite o valor a ser inserido no vetor: ");
	scanf("%i", &valor);
	idxBusca = buscaSequencial(copia, MAX_VETOR, valor, &numComp);
	printf("%i deve ser inserido na posicao de indice %i\n", valor, idxBusca);
	printf("Número de comparações: %i\n", numComp);

	numComp = 0;
	printf("\nBusca Binária:\n");
	printf("Digite o valor a ser pesquisado no vetor: ");
	scanf("%i", &valor);
	idxBusca = buscaBinaria(copia, MAX_VETOR, valor, &numComp);
	if (idxBusca == -1)
		printf("%i não pertence ao vetor\n", valor);
	else
		printf("%i está na posição de índice %i\n", valor, idxBusca);
	printf("Número de comparações: %i\n", numComp);

	free(vetor);
	free(copia);

	return 0;
}
