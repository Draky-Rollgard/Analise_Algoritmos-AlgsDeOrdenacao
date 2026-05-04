#include <stdio.h>
#include <stdlib.h>

void ordenacao_contagem(int vetor[], int tamanho) {
    int valor_maximo = 0;                                    // c1

    // Encontrar o maior elemento do vetor
    for (int i = 0; i < tamanho; i++) {                      // c2 + c3(n-1) + c4 n
        if (vetor[i] > valor_maximo) {                       // c5 n
            valor_maximo = vetor[i];                         // c6 n (pior caso)
        }
    }

    // Criar e inicializar o vetor de contagem
    int* vetor_contagem = (int*)calloc(valor_maximo + 1, sizeof(int)); // c7(k+1)

    // Contar a frequência de cada elemento
    for (int i = 0; i < tamanho; i++) {                     // c8 + c9(n-1) + c10 n
        vetor_contagem[vetor[i]]++;                         // c11 n
    }

    // Calcular a soma prefixada (acumulada)
    for (int i = 1; i <= valor_maximo; i++) {               // c12 + c13(k-1) + c14 k
        vetor_contagem[i] += vetor_contagem[i - 1];         // c15 k
    }

    // Construir o vetor de saída ordenado
    int* resultado = (int*)malloc(tamanho * sizeof(int));   // c16 n
    for (int i = tamanho - 1; i >= 0; i--) {                // c17 + c18(n-1) + c19 n
        resultado[vetor_contagem[vetor[i]] - 1] = vetor[i]; // c20 n
        vetor_contagem[vetor[i]]--;                         // c21 n
    }

    // Copiar os elementos ordenados de volta para o vetor original
    for (int i = 0; i < tamanho; i++) {                     // c22 + c23(n-1) + c24 n
        vetor[i] = resultado[i];                            // c25 n
    }

    // Liberar memória alocada dinamicamente
    free(vetor_contagem);                                   // c26
    free(resultado);                                        // c27
}

/* ========= ANÁLISE DE COMPLEXIDADE ==========

    T(n,k) = c1 + (c2 + c3(n−1) + c4 n + c5 n + c6 n) + c7(k+1) + (c8 + c9(n−1) + c10 n + c11 n) +
            (c12 + c13(k−1) + c14k + c15k) + c16 n + (c17 + c18(n−1) + c19 n + c20 n + c21 n) + 
            (c22 + c23(n−1) + c24 n +c25 n) + c26 + c27

    O(n + k)
*/

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
    // Manipulação de arquivos

    arquivos_teste("testes.txt", "saida.txt");
    printf("Tudo okay, veja o arquivo de saída em saida.txt\n");

    return 0;
}