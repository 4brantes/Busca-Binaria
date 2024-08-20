#include <stdio.h>
#include <time.h>

// Função para realizar a ordenação por seleção em um array
void ordenacao_por_selecao(int arr[], int n) {
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

// Função para imprimir o array
void printArray(int arr[], int tamanho) {
    // Loop para percorrer e imprimir todos os elementos do array
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", arr[i]);  // Imprime o elemento atual seguido de um espaço
    }
    printf("\n");  // Imprime uma nova linha após todos os elementos terem sido impressos
}

int main() {
    // Define e inicializa um array maior
    int arr[] = {64, 25, 12, 22, 11, 90, 55, 73, 30, 2, 18, 100, 45, 29, 85, 60, 44, 77, 33, 66, 88, 10, 95, 81, 5, 99};
    int tamanho = sizeof(arr) / sizeof(arr[0]);

    int num_execucoes = 10000;  // Número de vezes que o algoritmo será executado
    clock_t inicio = clock();

    // Executa a ordenação por seleção várias vezes
    for (int i = 0; i < num_execucoes; i++) {
        ordenacao_por_selecao(arr, tamanho);
    }

    clock_t fim = clock();
    double tempo_execucao = (double)(fim - inicio) / CLOCKS_PER_SEC / num_execucoes;

    printf("Array ordenado: \n");
    printArray(arr, tamanho);

    printf("Tempo médio de execução: %f segundos\n", tempo_execucao);

    return 0;
}
