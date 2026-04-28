#include <stdio.h>
#include <stdlib.h>

void ordenacao_contagem(int vetor[], int tamanho) 
{
    int valor_maximo = 0;


    for (int i = 0; i < tamanho; i++) 
    {
        if (vetor[i] > valor_maximo) 
        {
            valor_maximo = vetor[i];
        }
    }

    int* vetor_contagem = (int*)calloc(valor_maximo + 1, sizeof(int));

    for (int i = 0; i < tamanho; i++) 
    {
        vetor_contagem[vetor[i]]++;
    }

    for (int i = 1; i <= valor_maximo; i++) 
    {
        vetor_contagem[i] += vetor_contagem[i - 1];
    }

    int* resultado = (int*)malloc(tamanho * sizeof(int));

    for (int i = tamanho - 1; i >= 0; i--) 
    {
        resultado[vetor_contagem[vetor[i]] - 1] = vetor[i];
        vetor_contagem[vetor[i]]--;
    }

    for (int i = 0; i < tamanho; i++) 
    {
        vetor[i] = resultado[i];
    }

    free(vetor_contagem);
    free(resultado);
}


int main() 
{

    int tamanho = 0;

    printf("====================\nEscolha o tamanho:");

    scanf("%d", &tamanho);
    int *vetor = (int*)malloc(tamanho * sizeof(int));

    printf("\n====================\n");

    for (int i = 0; i < tamanho; i++)
    {
        scanf("%d", &vetor[i]);
    }

    ordenacao_contagem(vetor, tamanho);

    for (int i = 0; i < tamanho; i++) 
    {
        printf("%d ", vetor[i]);
    }

    return 0;
}