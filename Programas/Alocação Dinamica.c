/*Alocação dinamica de uma matriz, com valores já informados*/
#include <stdio.h>
#include <stdlib.h>

float** cria_matriz(int M, int N) {
    int i;
    float** matriz;

    matriz = (float**) malloc(M * sizeof(float*));

    if (matriz == NULL) {
        printf("Erro na alocação de memória. Saindo...\n");
        exit(1);
    }

    for (i = 0; i < M; i++) {
        matriz[i] = (float*) malloc(N * sizeof(float));

        if (matriz[i] == NULL) {
            printf("Erro na alocação de memória. Saindo...\n");
            exit(1);
        }
    }

    return matriz;
}

void libera_matriz(float** matriz, int M) {
    int i;

    if (matriz == NULL) {
        printf("Ponteiro nulo. Nada a liberar.\n");
        return;
    }

    for (i = 0; i < M; i++) {
        free(matriz[i]);
    }

    free(matriz);
}

int main() {
    int M = 3, N = 4;
    int i, j;
    float **matriz;

    matriz = cria_matriz(M, N);

    for (i = 0; i < M; i++) {
        for (j = 0; j < N; j++) {
            matriz[i][j] = (float) (i*N + j);
        }
    }

    for (i = 0; i < M; i++) {
        for (j = 0; j < N; j++) {
            printf("%.2f ", matriz[i][j]);
        }
        printf("\n");
    }

    libera_matriz(matriz, M);

    return 0;
}

