#include <stdio.h>
#include <stdlib.h>

void ordenacao_contagem(int vetor[], int tamanho) 
{
    int valor_maximo = 0;                   //c1

    for (int i = 0; i < tamanho; i++)       //c2: inicialização
                                            //c3: teste = n+1 => c3*(n+1)
                                            //c4: passo = n
    {                                       
        if (vetor[i] > valor_maximo)        //c5: n*c5
        {                                   
            valor_maximo = vetor[i];        //c6: n*c6 (pior caso)
        }
    }

    int* vetor_contagem = (int*)calloc(valor_maximo + 1, sizeof(int));  //c7: c7*(k+1)

    for (int i = 0; i < tamanho; i++)       //c8: inicialização
                                            //c9: teste = n+1 => c9*(n+1)
                                            //c10: passo = n
    {
        vetor_contagem[vetor[i]]++;         //c11: n
    }

    for (int i = 1; i <= valor_maximo; i++) //c12: inicialização
                                            //c13: teste = k+1 => c13(k+1)
                                            //c14: passo = k
    {
        vetor_contagem[i] += vetor_contagem[i - 1];         //c15: k
    }

    int* resultado = (int*)malloc(tamanho * sizeof(int));   //c16: n

    for (int i = tamanho - 1; i >= 0; i--)                  //c17: inicialização
                                                            //c18: teste = n+1 => c18*(n+1)
                                                            //c19: passo = n
    {
        resultado[vetor_contagem[vetor[i]] - 1] = vetor[i]; //c20: n
        vetor_contagem[vetor[i]]--;                         //c21: n
    }

    for (int i = 0; i < tamanho; i++)       //c22: inicialização 
                                            //c23: teste = n+1 => c23*(n+1)
                                            //c24: passo = n
    {
        vetor[i] = resultado[i];            //c25: n
    }

    free(vetor_contagem);                   //c26
    free(resultado);                        //c27
}

/* ========= ANÁLISE DE COMPLEXIDADE ==========

    T(n,k) = c1 + (c2 + c3(n+1) + c4 n + c5 n + c6 n) + c7(k+1) + (c8 + c9(n+1) + c10 n + c11 n) +
            (c12 + c13(k+1) + c14k + c15k) + c16 n + (c17 + c18(n+1) + c19 n + c20 n + c21 n) + 
            (c22 + c23(n+1) + c24 n +c25 n) + c26 + c27

    O(n + k)
*/
