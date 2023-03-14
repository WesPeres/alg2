#include <stdio.h>

// Cada presente possui um peso e um valor sentimental
struct presente {
    int valorSent;
    int peso;
};

void solucao(struct presente presentes[], int n, int pmax);
void gerarSubconjuntos(struct presente presentes[], int pmax, int n, int aux[], 
                      int sol[], int *valorSoma, int i);
int subconjuntoValido(struct presente presentes[], int pmax, int n, int aux[]);
void encherSaco(struct presente presentes[], int pmax, int n, int aux[], 
                      int sol[], int *valorSoma);
void copiarVetor(int v[], int u[], int tam);
void imprimirSolucao(int sol[], int n);

int main() {
    // Maximo de presentes
    int n;
    // Peso máximo suportado pelo saco
    int pmax;
    // Valor sentimental de cada presente
    struct presente presentes[n];
    // Lê as entradas
    scanf("%i", &n);
    scanf("%i", &pmax);
    for (int i = 0; i < n; i++) {
        scanf("%i", &(presentes[i].valorSent));
        scanf("%i", &(presentes[i].peso));
    }
    solucao(presentes, n, pmax);
}

// Verifica se sol[i] é 1 e, se sim, imprime o índice do presente
void imprimirSolucao(int sol[], int n) {
    int i;
    for (i = 0; i < n - 1; i++) {
        if (sol[i])
            printf("%i ",i + 1);
    }
    if (sol[i])
        printf("%i", i + 1);
    printf("\n");
}

void copiarVetor(int v[], int u[], int tam) {
    for (int i = 0; i < tam; i++) {
        v[i] = u[i];
    }
}

/* Soma o valor sentimental dos presentes que pertencem ao subconjunto
 * Se esse valor ultrapassa o maior valor já registrado, sobrecreve-se este valor
 * e salva o subconjunto (em binário) no vetor sol (solução) */
void encherSaco(struct presente presentes[], int pmax, int n, int aux[], 
                      int sol[], int *valorSoma) {
    int valorSent = 0;
    for (int i = 0; i < n; i++) {
        if (aux[i])
            valorSent += presentes[i].valorSent;
    }

    if (valorSent > *valorSoma) {
        copiarVetor(sol, aux, n);
        *valorSoma = valorSent;
    }
}       

/* Vai somando o peso dos presentes que pertencem ao conjunto (quando aux[i] é 1),
 * verificando, após cada soma, se o resultado é maior que o peso máximo
 * suportado pelo saco do papai noel. Se sim, faz o backtracking */
int subconjuntoValido(struct presente presentes[], int pmax, int n, int aux[]) {
    int peso = 0;
    for (int i = 0; i < n; i++) {
        if (aux[i]) {
            peso += presentes[i].peso;
            if (peso > pmax)
                return 0;
        }
    }

    return 1;
}

// Gera todos os conjuntos possíveis com os presentes
void gerarSubconjuntos(struct presente presentes[], int pmax, int n, int aux[], 
                      int sol[], int *valorSoma, int i) {
    if (i == n) {
        if (subconjuntoValido(presentes, pmax, n, aux))
            encherSaco(presentes, pmax, n, aux, sol, valorSoma);
        return;
    }
    aux[i] = 0;
    gerarSubconjuntos(presentes, pmax, n, aux, sol, valorSoma, i + 1);
    aux[i] = 1;
    gerarSubconjuntos(presentes, pmax, n, aux, sol, valorSoma, i + 1);
}

// Encontra a solução e imprime o resultado
void solucao(struct presente presentes[], int n, int pmax) {
    int aux[n];
    int sol[n];
    int valorSoma = 0;
    gerarSubconjuntos(presentes, pmax, n, aux, sol, &valorSoma, 0);
  
    imprimirSolucao(sol, n);
    printf("%i\n", valorSoma);
}