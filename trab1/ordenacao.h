#ifndef ORDENACAO_H_
#define ORDENACAO_H_

#define MAX_CHAR_NOME 50

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// A função getNome coloca um nome dentro da chamada
void getNome(char nome[]);

// Retorna o número do GRR
unsigned int getGRR();

// Escolhe um algoritmo de ordenação através de uma flag
void escolheSortAlg(int algCode, int vetor[], int tam);

// Escolhe um algoritmo de busca através de uma flag
void escolheSearchAlg(int algCode, int vetor[], int tam);

// Cria um vetor inverso
void writeReversedArray(int v[], int tam);

// Cria um vetor aleatorio
void writeRandomArray(int vetor[], int tam);

// Imprime o vetor
void readArray(int v[], int tam);

// Troca dois elementos de um vetor passados seus índices
void troca(int vetor[], int a, int b);

// Encontra o índice do menor elemento do vetor
int minimo(int vetor[], int tam, int *numComparacoes);

// Insere o último elemento do vetor na posição correta
int insere(int vetor[], int tam);

// Copia um vetor para outro
void copia_vetor(int v[], int u[], int tam);

// Ordena um vetor com duas metades ordenadas
int intercala(int vetor[], int tam, int m);

// Coloca todos os elementos menores ou iguais que o pivô à esquerda
// e todos os elementos maiores à direita
int particiona(int vetor[], int tam, int x, int *numComparacoes);

// Ordena um trio de nodos para construir um max heap
void maxHeapify(int vetor[], int tam, int index, int *numComparacoes);

// Percorre todos os nodos que não são folhas, chamando maxHeapify
void buildMaxHeap(int vetor[], int tam, int *numComparacoes);

//a busca sequencial é a busca ingênua
int buscaSequencial(int vetor[], int tam, int valor, int* numComparacoes);

// Busca binaria de elemento no vetor
int buscaBinaria(int vetor[], int tam, int valor, int* numComparacoes);

//Cada uma das funções ordena o vetor passado como parâmetro
//O retorno das funções de ordenação é o número de comparações
//entre elementos do vetor

int insertionSort(int vetor[], int tam);

int selectionSort(int vetor[], int tam);

int mergeSort(int vetor[], int tam);

int quickSort(int vetor[], int tam);

int heapSort(int vetor[], int tam);

#endif // ORDENACAO_H_