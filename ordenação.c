#include <stdio.h>

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
    // Define e inicializa o array
    int arr[] = {64, 25, 12, 22, 11};
    // Calcula o tamanho do array dividindo o tamanho total em bytes pelo tamanho de um elemento
    int tamanho = sizeof(arr) / sizeof(arr[0]);

    // Chama a função de ordenação por seleção
    ordenacao_por_selecao(arr, tamanho);

    // Imprime o array ordenado
    printf("Array ordenado: \n");
    printArray(arr, tamanho);

    return 0;  // Retorna 0 para indicar que o programa terminou com sucesso
}