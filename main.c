#include <stdio.h>

// Função que realiza a busca binária em um array
int busca_binaria(int arr[], int tamanho, int elemento) {
    int esquerda = 0;
    int direita = tamanho - 1;

    while (esquerda <= direita) {
        int meio = esquerda + (direita - esquerda) / 2;

        // Verifica se o elemento está no meio
        if (arr[meio] == elemento)
            return meio; // Elemento encontrado, retorna o índice

        // Se o elemento for maior, ignore a metade esquerda
        if (arr[meio] < elemento)
            esquerda = meio + 1;
        else
            // Se o elemento for menor, ignore a metade direita
            direita = meio - 1;
    }

    return -1; // Elemento não encontrado, retorna -1
}

int main() {
    // Inicializa o array e define o tamanho
    int arr[] = {2, 3, 4, 10, 40};
    int tamanho = sizeof(arr) / sizeof(arr[0]);

    // Define o elemento a ser buscado
    int elemento = 10;

    // Realiza a busca binária
    int resultado = busca_binaria(arr, tamanho, elemento);

    // Imprime o resultado da busca
    if (resultado != -1)
        printf("Elemento encontrado no índice %d\n", resultado);
    else
        printf("Elemento não encontrado\n");

    return 0;
}
