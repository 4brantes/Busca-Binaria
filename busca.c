#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Definição da estrutura do TAD BuscaBinaria
typedef struct {
    int *array;
    int tamanho;
} BuscaBinaria;

// Função que cria o TAD BuscaBinaria
BuscaBinaria* criar_busca_binaria(int arr[], int tamanho) {
    BuscaBinaria *busca = (BuscaBinaria*)malloc(sizeof(BuscaBinaria));
    if (busca != NULL) {
        busca->tamanho = tamanho;
        busca->array = (int*)malloc(tamanho * sizeof(int));
        if (busca->array != NULL) {
            for (int i = 0; i < tamanho; i++) {
                busca->array[i] = arr[i];
            }
        }
    }
    return busca;
}

// Função que realiza a busca binária em um TAD BuscaBinaria
int busca_binaria(BuscaBinaria *busca, int elemento) {
    int esquerda = 0;
    int direita = busca->tamanho - 1;

    while (esquerda <= direita) {
        int meio = esquerda + (direita - esquerda) / 2;

        // Verifica se o elemento está no meio
        if (busca->array[meio] == elemento)
            return meio; // Elemento encontrado, retorna o índice

        // Se o elemento for maior, ignore a metade esquerda
        if (busca->array[meio] < elemento)
            esquerda = meio + 1;
        else
            // Se o elemento for menor, ignore a metade direita
            direita = meio - 1;
    }

    return -1; // Elemento não encontrado, retorna -1
}

// Função que libera a memória alocada para o TAD BuscaBinaria
void destruir_busca_binaria(BuscaBinaria *busca) {
    if (busca != NULL) {
        free(busca->array);
        free(busca);
    }
}

// Função principal para demonstrar o uso do TAD
int main() {
    // Inicializar o array
    int arr[] = {2, 3, 4, 10, 15, 20, 30, 40, 50, 60, 70, 80, 90, 100, 110, 120, 130, 140, 150, 160, 170, 180, 190, 200, 210, 220, 230, 240, 250, 260, 270, 280, 290, 300, 310, 320, 330, 340, 350, 360, 370, 380, 390, 400};
    int tamanho = sizeof(arr) / sizeof(arr[0]);

    // Cria o TAD BuscaBinaria
    BuscaBinaria *busca = criar_busca_binaria(arr, tamanho);
    if (busca == NULL) {
        printf("Falha ao criar o TAD BuscaBinaria\n");
        return -1;
    }

    // Define o elemento a ser buscado
    int elemento = 250;

    // Captura o tempo antes da execução da busca binária
    clock_t inicio = clock();

    // Realiza a busca binária usando o TAD
    int resultado = busca_binaria(busca, elemento);

    // Captura o tempo após a execução da busca binária
    clock_t fim = clock();

    // Calcula o tempo de execução em segundos
    double tempo_execucao = (double)(fim - inicio) / CLOCKS_PER_SEC;

    // Imprime o resultado da busca
    if (resultado != -1)
        printf("Elemento encontrado no índice %d\n", resultado);
    else
        printf("Elemento não encontrado\n");

    // Imprime o tempo de execução
    printf("Tempo de execução: %f segundos\n", tempo_execucao);

    // Libera a memória alocada para o TAD
    destruir_busca_binaria(busca);

    return 0;
}
