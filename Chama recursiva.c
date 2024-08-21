#include <stdio.h>
#include <stdlib.h>

// Função de busca binária recursiva
int buscaBinariaRecursiva(int *vet, int chave, int inicio, int fim) {
    int meio;
    if (inicio <= fim) {
        meio = (inicio + fim) / 2;
        if (chave == vet[meio])
            return meio;
        else {
            if (chave < vet[meio])
                return buscaBinariaRecursiva(vet, chave, inicio, meio - 1);
            else
                return buscaBinariaRecursiva(vet, chave, meio + 1, fim);
        }
    }
    return -1; // elemento não encontrado
}

// Função de busca binária interativa
int buscaBinariaInterativa(int *vet, int chave, int fim) {
    int inicio = 0;
    int meio;

    while (inicio <= fim) {
        meio = (inicio + fim) / 2;
        if (chave == vet[meio])
            return meio;
        else {
            if (chave < vet[meio])
                fim = meio - 1;
            else
                inicio = meio + 1;
        }
    }
    return -1; // elemento não encontrado
}

int main() {
    int vet[20] = {10, 15, 18, 20, 22, 28, 30, 38, 45, 49, 58, 64, 68, 74, 78, 83, 89, 91, 93, 99};
    int valor, op;

    do {
        printf("Digite um valor a ser buscado: ");
        if (scanf("%d", &valor) != 1) {
            printf("Erro ao ler o valor. Por favor, tente novamente.\n");
            // Limpa o buffer de entrada para evitar loops infinitos
            while (getchar() != '\n');
            continue;
        }
        
        int resultado = buscaBinariaInterativa(vet, valor, 19);
        if (resultado != -1)
            printf("\nElemento encontrado no índice %d\n", resultado);
        else
            printf("\nElemento não encontrado\n");

        printf("\n0 - Sair\n1 - Nova busca\n");
        scanf("%d", &op);
    } while (op != 0);  // Correção na condição do loop

    return 0;
}
