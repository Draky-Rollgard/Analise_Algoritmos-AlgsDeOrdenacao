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

void arquivos_teste(const char *entrada, const char *saida) {
    FILE *arquivo_entrada = fopen(entrada, "r");
    FILE *arquivo_saida = fopen(saida, "w");

    if (arquivo_entrada == NULL || arquivo_saida == NULL) {
        printf("Erro ao abrir arquivos.\n");
        return;
    }

    int t;
    
    while (fscanf(arquivo_entrada, "%d", &t) != EOF) {
        int *vetor = (int*)malloc(t * sizeof(int));

        for (int i = 0; i < t; i++) {
            fscanf(arquivo_entrada, "%d", &vetor[i]);
        }

        ordenacao_contagem(vetor, t);

        for (int i = 0; i < t; i++) {
            fprintf(arquivo_saida, "%d ", vetor[i]);
        }
        fprintf(arquivo_saida, "\n");

        free(vetor);
    }

    fclose(arquivo_entrada);
    fclose(arquivo_saida);
}


int main() 
{
    /*
    Testes pre-processados
    int vetor[] = {2, 5, 3, 0, 2, 3, 0, 3};
    int tamanho = sizeof(vetor) / sizeof(vetor[0]);

    Testes via terminal
    int tamanho = 0;

    printf("====================\nEscolha o tamanho:");

    scanf("%d", &tamanho);
    int *vetor = (int*)malloc(tamanho * sizeof(int));

    printf("\n====================\n");
    

    for (int i = 0; i < tamanho; i++)
    {
        scanf("%d", &vetor[i]);
    }

    // Ordenando o vetor
    ordenacao_contagem(vetor, tamanho);

    // Imprimindo o vetor "ordenado"
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", vetor[i]);
    }
    */

    arquivos_teste("testes.txt", "saida.txt");
    printf("Tudo okay, veja o arquivo de saída em saida.txt\n");

    return 0;
}