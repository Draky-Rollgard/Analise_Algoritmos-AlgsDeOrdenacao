#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 20
#define QUANT_EXEMPLOS 5

void numero_aleatorio(int v[], int n)
{
    for(int i = 0; i < n; i++)
    {
        v[i] = rand() % n;
    }
}

void saida(const char *nome_arquivo)
{
    FILE *arquivo_saida = fopen(nome_arquivo, "w");

    if (arquivo_saida == NULL)
    {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    for (int k = 0; k < QUANT_EXEMPLOS; k++)
    {
        int tamanho = rand() % N + 1;
        int v[N];

        numero_aleatorio(v, tamanho);

        fprintf(arquivo_saida, "%d ", tamanho);

        for (int i = 0; i < tamanho; i++) {
            fprintf(arquivo_saida, "%d ", v[i]);
        }

        fprintf(arquivo_saida, "\n");
    }

    fclose(arquivo_saida);
}

int main()
{
    srand(time(NULL));
    saida("testes.txt");

    return 0;
}