#include "ordenacao.h"

#include <string.h>
#include <math.h>

void getNome(char nome[]){
	strncpy(nome, "Wesley Peres de Freitas", MAX_CHAR_NOME);
	nome[MAX_CHAR_NOME-1] = '\0';
}

unsigned int getGRR(){
	return 20221235;
}

void escolheSearchAlg(int algCode, int vetor[], int tam) {
	clock_t start, end;
	double total;
	int valor;
	int idxBusca;
	int numComp = 0;

	if (algCode == 1) {
		printf("\nBusca Sequencial:\n");
		printf("Digite o valor a ser inserido no vetor: ");
		scanf("%i", &valor);
		start = clock();
		idxBusca = buscaSequencial(vetor, tam, valor, &numComp);
		end = clock();
		total = ((double)end - start)/CLOCKS_PER_SEC;
		printf("Tempo total: %f\n", total);
		printf("%i deve ser inserido na posicao de indice %i\n", valor, idxBusca);
		printf("Número de comparações: %i\n", numComp);
	}
	else if (algCode == 2) {
		printf("\nBusca Binária:\n");
		printf("Digite o valor a ser pesquisado no vetor: ");
		scanf("%i", &valor);
		start = clock();
		idxBusca = buscaBinaria(vetor, tam, valor, &numComp);
		end = clock();
		total = ((double)end - start)/CLOCKS_PER_SEC;
		printf("Tempo total: %f\n", total);
		if (idxBusca == - 1)
			printf("%i nao pertence ao vetor\n", valor);
		else
			printf("%i está na posição de índice %i\n", valor, idxBusca);
		printf("Número de comparações: %i\n", numComp);
	}
}

void escolheSortAlg(int algCode, int vetor[], int tam) {
	int numComp;
	clock_t start, end;//variáveis do tipo clock_t
	double total;

	if (algCode == 1) {
		printf("\nInsertion Sort:\n");
		start = clock();//start recebe o "ciclo" corrente
		numComp = insertionSort(vetor, tam);
		end = clock();//end recebe o "ciclo" corrente
		total = ((double)end - start)/CLOCKS_PER_SEC;
		readArray(vetor, tam);
		printf("Tempo total: %f\n", total);
		printf("Número de comparações: %i\n", numComp);
	}
	else if (algCode == 2) {
		printf("\nSelection Sort:\n");
		start = clock();
		numComp = selectionSort(vetor, tam);
		end = clock();
		total = ((double)end - start)/CLOCKS_PER_SEC;
		readArray(vetor, tam);
		printf("Tempo total: %f\n", total);
		printf("Número de comparações: %i\n", numComp);
	}
	else if(algCode == 3) {
		printf("\nMerge Sort:\n");
		start = clock();
		numComp = mergeSort(vetor, tam);
		end = clock();
		total = ((double)end - start)/CLOCKS_PER_SEC;
		readArray(vetor, tam);
		printf("Tempo total: %f\n", total);
		printf("Número de comparações: %i\n", numComp);
	}
	else if(algCode == 4) {
		printf("\nQuick Sort:\n");
		start = clock();
		numComp = quickSort(vetor, tam);
		end = clock();
		total = ((double)end - start)/CLOCKS_PER_SEC;
		readArray(vetor, tam);
		printf("Tempo total: %f\n", total);
		printf("Número de comparações: %i\n", numComp);
	}
	else if (algCode == 5) {
		printf("\nHeap Sort:\n");
		start = clock();
		numComp = heapSort(vetor, tam);
		end = clock();
		total = ((double)end - start)/CLOCKS_PER_SEC;
		readArray(vetor, tam);
		printf("Tempo total: %f\n", total);
		printf("Número de comparações: %i\n", numComp);
	}
}

void writeReversedArray(int vetor[], int tam) {
    for (int i = 0; i < tam; i++) {
        vetor[i] = tam - i;
    }
}

void writeRandomArray(int vetor[], int tam) {
	srand(time(NULL));
	for (int i = 0; i < tam; i++) {
		vetor[i] = rand() % 50000;
	}
}

void readArray(int vetor[], int tam) {
	int cont = 0;
	printf(" ");
	for (int i = 0; i < tam; i++) {
		printf("v[%i]=%i | ", i, vetor[i]);
		cont++;
		if (cont == 10) {
			printf("\n ");
			cont = 0;
		}
	}
	printf("\n");
}

void troca(int vetor[], int a, int b) {
	int aux = vetor[a];
	vetor[a] = vetor[b];
	vetor[b] = aux;
}

int minimo(int vetor[], int tam, int *numComparacoes) {
	if (tam <= 1)
		return 0;
	
	int m = minimo(vetor, tam - 1, numComparacoes);
	if (vetor[tam - 1] < vetor[m])
		m = tam - 1;
	*numComparacoes = *numComparacoes + 1;

	return m;
}

int insere(int vetor[], int tam) {
	int numComparacoes = 0;
	int p = buscaSequencial(vetor, tam - 1, vetor[tam - 1], &numComparacoes);
	int i = tam - 1;
	while (i > p + 1) {
		troca(vetor, i, i - 1);
		i--;
	}
	return numComparacoes;
}

void copia_vetor(int v[], int u[], int tam) {
	for (int i = 0; i < tam; i++) {
		v[i] = u[i];
	}
}

int intercala(int vetor[], int tam, int m) {
	if (tam <= 1)
		return 0;
	
	int *aux = malloc(tam * sizeof(int));
	int numComparacoes = 0;
	int i = 0;
	int j = m + 1;
	for (int k = 0; k < tam; k++) {
		numComparacoes++;
		if ((j > tam - 1) || ((i <= m) && (vetor[i] <= vetor[j]))) {
			aux[k] = vetor[i];
			i++;
		}
		else {
			aux[k] = vetor[j];
			j++;
		}
	}
	copia_vetor(vetor, aux, tam);
	free(aux);
	
	return numComparacoes;
}

int particiona(int vetor[], int tam, int x, int *numComparacoes) {
	int m = -1;
	for (int i = 0; i < tam; i++) {
		if (vetor[i] <= x) {
			m++;
			troca(vetor, m, i);
		}
		*numComparacoes = *numComparacoes + 1;
	}

	return m;
}

void maxHeapify(int vetor[], int tam, int index, int *numComparacoes) {
    int largest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < tam && vetor[left] > vetor[index])
      largest = left;
  
    if (right < tam && vetor[right] > vetor[largest])
      largest = right;
  
	*numComparacoes = *numComparacoes + 2;
    if (largest != index) 
    {
      troca(vetor, index, largest);
      maxHeapify(vetor, tam, largest, numComparacoes);
    }
}

void buildMaxHeap(int vetor[], int tam, int *numComparacoes) {
	for (int i = tam / 2 - 1; i >= 0; i--) {
		maxHeapify(vetor, tam, i, numComparacoes);
	}
}

int buscaSequencial(int vetor[], int tam, int valor, int* numComparacoes){
	if (tam < 1)
		return - 1;

	*numComparacoes = *numComparacoes + 1;
	if (valor >= vetor[tam - 1])
		return tam - 1;

	return buscaSequencial(vetor, tam - 1, valor, numComparacoes);
}

int buscaBinaria(int vetor[], int tam, int valor, int* numComparacoes) {
	if (tam == 0)
		return -1;

	int m = (tam - 1) / 2;
	int indice;

	*numComparacoes = *numComparacoes + 1;
	if (vetor[m] == valor) {
		return m;
	}
	*numComparacoes = *numComparacoes + 1;
	if (vetor[m] > valor) {
		indice = buscaBinaria(vetor, m, valor, numComparacoes);
	}
	else {
		indice = buscaBinaria(vetor + m + 1, tam - m - 1, valor, numComparacoes);
        
        if (indice != -1)
		    indice = indice + m + 1;
	}

	return indice;
}

int insertionSort(int vetor[], int tam){	
	if (tam <= 1)
		return 0;
	
	int numComparacoes = insertionSort(vetor, tam - 1);
	return numComparacoes + insere(vetor, tam);
}

int selectionSort(int vetor[], int tam){
	if (tam <= 1)
		return 0;	

	int numComparacoes = 0;
	troca(vetor, 0, minimo(vetor, tam, &numComparacoes));
	return numComparacoes + selectionSort(vetor + 1, tam - 1);
}

int mergeSort(int vetor[], int tam) {
	if (tam <= 1)
		return 0;
	
	int m = (tam - 1) / 2;
	int comp1 = mergeSort(vetor, ceil((float)tam / 2));
	int comp2 = mergeSort(vetor + m + 1, floor((float)tam / 2));
	return comp1 + comp2 + intercala(vetor, tam, m);
}

int quickSort(int vetor[], int tam){
	if (tam <= 1)
		return 0;

	int numComparacoes = 0;
	int m = particiona(vetor, tam, vetor[tam - 1], &numComparacoes);
	numComparacoes = numComparacoes + quickSort(vetor, m);
	numComparacoes = numComparacoes + quickSort(vetor + m + 1, tam - m - 1);
	
	return numComparacoes;
}

int heapSort(int vetor[], int tam){
	int numComparacoes = 0;
	buildMaxHeap(vetor, tam, &numComparacoes);

	for (int i = tam - 1; i >= 0; i--) {
		troca(vetor, 0, i);
		tam = tam - 1;
		maxHeapify(vetor, tam, 0, &numComparacoes);
	}

	return numComparacoes;
}
