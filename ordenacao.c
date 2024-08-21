#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Definição da estrutura do TAD OrdenacaoSelecao
typedef struct {
    int *array;
    int tamanho;
} OrdenacaoSelecao;

// Função que cria o TAD OrdenacaoSelecao
OrdenacaoSelecao* criar_ordenacao_selecao(int arr[], int tamanho) {
    OrdenacaoSelecao *ordenacao = (OrdenacaoSelecao*)malloc(sizeof(OrdenacaoSelecao));
    if (ordenacao != NULL) {
        ordenacao->tamanho = tamanho;
        ordenacao->array = (int*)malloc(tamanho * sizeof(int));
        if (ordenacao->array != NULL) {
            for (int i = 0; i < tamanho; i++) {
                ordenacao->array[i] = arr[i];
            }
        }
    }
    return ordenacao;
}

// Função para realizar a ordenação por seleção em um TAD OrdenacaoSelecao
void ordenacao_por_selecao(OrdenacaoSelecao *ordenacao) {
    int n = ordenacao->tamanho;
    int *arr = ordenacao->array;
    int i, j, min_idx;

    // Loop que percorre todo o array
    for (i = 0; i < n-1; i++) {
        // Suponha que o primeiro elemento do subarray não ordenado é o menor
        min_idx = i;

        // Loop interno para encontrar o menor elemento no subarray não ordenado
        for (j = i+1; j < n; j++) {
            // Se encontrar um elemento menor, atualiza min_idx
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }

        // Após encontrar o menor elemento, troca ele com o primeiro elemento do subarray não ordenado
        int temp = arr[min_idx];  // Armazena o valor do menor elemento encontrado
        arr[min_idx] = arr[i];    // Substitui o menor elemento pela posição inicial do subarray não ordenado
        arr[i] = temp;            // Coloca o valor armazenado na posição correta
    }
}

// Função para imprimir o array armazenado no TAD OrdenacaoSelecao
void print_array(OrdenacaoSelecao *ordenacao) {
    int *arr = ordenacao->array;
    int tamanho = ordenacao->tamanho;
    
    // Loop para percorrer e imprimir todos os elementos do array
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", arr[i]);  // Imprime o elemento atual seguido de um espaço
    }
    printf("\n");  // Imprime uma nova linha após todos os elementos terem sido impressos
}

// Função que libera a memória alocada para o TAD OrdenacaoSelecao
void destruir_ordenacao_selecao(OrdenacaoSelecao *ordenacao) {
    if (ordenacao != NULL) {
        free(ordenacao->array);
        free(ordenacao);
    }
}

// Função principal para demonstrar o uso do TAD
int main() {
    // Define e inicializa um array maior
    int arr[] = {64, 25, 12, 22, 11, 90, 55, 73, 30, 2, 18, 100, 45, 29, 85, 60, 44, 77, 33, 66, 88, 10, 95, 81, 5, 99};
    int tamanho = sizeof(arr) / sizeof(arr[0]);

    // Cria o TAD OrdenacaoSelecao
    OrdenacaoSelecao *ordenacao = criar_ordenacao_selecao(arr, tamanho);
    if (ordenacao == NULL) {
        printf("Falha ao criar o TAD OrdenacaoSelecao\n");
        return -1;
    }

    int num_execucoes = 10000;  // Número de vezes que o algoritmo será executado
    clock_t inicio = clock();

    // Executa a ordenação por seleção várias vezes usando o TAD
    for (int i = 0; i < num_execucoes; i++) {
        ordenacao_por_selecao(ordenacao);
    }

    clock_t fim = clock();
    double tempo_execucao = (double)(fim - inicio) / CLOCKS_PER_SEC / num_execucoes;

    printf("Array ordenado: \n");
    print_array(ordenacao);

    printf("Tempo médio de execução: %f segundos\n", tempo_execucao);

    // Libera a memória alocada para o TAD
    destruir_ordenacao_selecao(ordenacao);

    return 0;
}
