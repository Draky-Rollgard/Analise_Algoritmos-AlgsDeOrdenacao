#include <stdio.h>
#include <stdlib.h>

void ordenacao_contagem(int vetor[], int tamanho) {
    int valor_maximo = 0;

    // Encontrar o maior elemento do vetor
    for (int i = 0; i < tamanho; i++) {
        if (vetor[i] > valor_maximo) {
            valor_maximo = vetor[i];
        }
    }

    // Criar e inicializar o vetor de contagem
    int* vetor_contagem = (int*)calloc(valor_maximo + 1, sizeof(int));

    // Contar a frequência de cada elemento
    for (int i = 0; i < tamanho; i++) {
        vetor_contagem[vetor[i]]++;
    }

    // Calcular a soma prefixada (acumulada)
    for (int i = 1; i <= valor_maximo; i++) {
        vetor_contagem[i] += vetor_contagem[i - 1];
    }

    // Construir o vetor de saída ordenado
    int* resultado = (int*)malloc(tamanho * sizeof(int));
    for (int i = tamanho - 1; i >= 0; i--) {
        resultado[vetor_contagem[vetor[i]] - 1] = vetor[i];
        vetor_contagem[vetor[i]]--;
    }

    // Copiar os elementos ordenados de volta para o vetor original
    for (int i = 0; i < tamanho; i++) {
        vetor[i] = resultado[i];
    }

    // Liberar memória alocada dinamicamente
    free(vetor_contagem);
    free(resultado);
}

// Função principal
int main() {
    int vetor[] = {2, 5, 3, 0, 2, 3, 0, 3};
    int tamanho = sizeof(vetor) / sizeof(vetor[0]);

    // Ordenando o vetor
    ordenacao_contagem(vetor, tamanho);

    // Imprimindo o vetor ordenado
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", vetor[i]);
    }

    return 0;
}