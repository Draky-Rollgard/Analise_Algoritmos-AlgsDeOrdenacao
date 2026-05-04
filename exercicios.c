/* 
    == LISTA DE EXERCÍCIOS - ANÁLISE DE ALGORITMOS ==
             == LEONARDO ARAUJO ARMELIN ==
*/
#include <stdio.h>

//===================================================================================================================//

int q01(int n) {
    int i, j, count = 0;                           //c1 + c2 + c3
    int v[n];                                      //c4

    for (i = 0; i < n; i++) {                      //c5 + c6 (n + 1) + c7 n
        if (v[i] % 100 == 0) {                     //c8 n
            for (j = 0; j < n; j++) {              //c9 n + c10 n(n + 1) + c11 n^2
                count = count + j;                 //c12 n^2
            }
        }
    }
    return count;                                  //c13
}
/* 
  
  == MELHOR CASO ==
- Ocorre quando nenhum item do vetor é múltiplo de 100

Ω = c1 + c2 + c3 + c4 + c5 + c6(n+1) + c7n + c8n + c13
Ω = an + b
Ω(n)

   == PIOR CASO ==
- Ocorre quando todos os itens do vetor são múltiplos de 100

O = c1 + c2 + c3 + c4 + c5 + c6(n+1) + c7n + c8n + c9n + c10(n^2+1) + c11n^2 + c12n^2 + c13
O = an^2 + bn + c
O(n^2)

*/
//===================================================================================================================//

void q02(int n)
{
    for (int i = 2*n; i > 0; i--)                  //c1 + c2 (2n + 1) + c3 2n
    {
        for (int j = 0; j < i; j++)                //c4 2n + c5 2n (2n + 1) + c6 2n 2n
        {
        }
    }
}

/* 

  == MELHOR E PIOR CASO == 
Nessa análise, o melhor e pior caso são da mesma ordem

O = c1 + c2(2n+1) + c3(2n) + c4(2n) + c5(2n^2+1) + c6(4n^2)
O = an^2 + bn + c
O(n^2)
Ω(n^2)

*/
//===================================================================================================================//

void q03(int n)
{
    int i, j;                                      //c1 + c2
    // assuma n > 0

    for (i = 0; i < n; i++) {                      //c3 + c4 (n + 1) + c5 n
        j = n;                                     //c6 n
        if (i + j < 0) {                           //c7 n
            return;                                //c8
        }
        while (j > 0) {                            //c9 n log(n)
            j /= 2;                                //c10 n log(n)
        }
    }
}
/* 
  
  == MELHOR E PIOR CASO ==
Nessa análise, se n > 0, o melhor e o pior caso são da mesma ordem

O = c1 + c2 + c3 + c4(n+1) + c5n + c6n + c7n + c9(nlog(n)) + c10(nlog(n))
O(nlog(n))
Ω(nlog(n))

*/
//===================================================================================================================//

void q04(int n)
{
    int i, j;                                      //c1 + c2

    for (i = 1; i < n; i *= 2) {                   //c3 + c4 (log(n) + 1) + c5 log(n)
        for (j = 0; j < n; j++) {                  //c6 log(n) + c7 log(n)(n + 1) + c8 (nlog(n))
        }
    }
}
/* 
  
  == MELHOR E PIOR CASO ==
Nessa análise o melhor e o pior caso são da mesma ordem

O = c1 + c2 + c3 + c4(log(n)+1) + c5log(n) + c6log(n) + c7log(n)(n+1) + c8(nlog(n))
O(nlog(n))
Ω(nlog(n))

*/
//===================================================================================================================//

void q05(int n)
{
    int i, j;                                     //c1 + c2

    for (i = 0; i < n; i++) {                     //c3 + c4 (n + 1) + c5 n
        if (i == n - 1) {                         //c6 n 
            for (j = 0; j < n; j++) {             //c7 n + c8 (n + 1) + c9 n
            }
        }
    }
}
/* 
  
  == MELHOR E PIOR CASO ==
Nessa análise o melhor e o pior caso são da mesma ordem, pois o loop interno executa sempre na última iteração do externo

O = c1 + c2 + c3 + c4(n+1) + c5n + c6n + c7n + c8(n+1) + c9n
O(n)
Ω(n)

*/
//===================================================================================================================//

void q06(int n)
{
    int i, j;                                     //c1 + c2

    for (i = 0; i < n; i++)                       //c3 + c4 (n + 1) + c5 n
    {
        for (j = i; j < i + n; j++)               //c6 n + c7 n(n + 1) + c8 n^2
        {
        }
    }
}
/* 
  
  == MELHOR E PIOR CASO ==
Nessa análise o melhor e o pior caso são da mesma ordem

O = c1 + c2 + c3 + c4(n+1) + c5n + c6n + c7n(n+1) + c8(n^2)
O(n^2)
Ω(n^2)

*/
//===================================================================================================================//

void q07(int n)
{
    int i, j;                                     //c1 + c2

    for (i = n; i > 0; i /= 2) {                  //c3 + c4 (log(n) + 1) + c5 log(n)
        for (j = i; j > 0; j /= 2) {              //c6 log(n) + c7 log(n)(log(n) + 1) + c8 (log(n)^2)
        }
    }
}
/* 
  
  == MELHOR E PIOR CASO ==
Nessa análise o melhor e o pior caso são da mesma ordem

O = c1 + c2 + c3 + c4(log(n)+1) + c5(log(n)) + c6(log(n)) + c7log(n)(log(n)+1) + c8(log(n)^2)
O(log(n)^2)
Ω(log(n)^2)

*/
//===================================================================================================================//

void q08(int n)
{ 
    int i, j;                                     //c1 + c2
 
    for (i = 0; i < n; i++) {                     //c3 + c4 (n + 1) + c5 n
        for (j = 0; j < i * i; j++) {             //c6 n + c7 n(n^2 + 1) + c8 n^3
        }
    }
}

/* 
  
  == MELHOR E PIOR CASO ==
Nessa análise o melhor e o pior caso são da mesma ordem

O = c1 + c2 + c3 + c4(n+1) + c5n + c6n + c7n(n^2+1) + c8n^3
O(n^3)
Ω(n^3)

*/
//===================================================================================================================//

void q09(int n)
{
    int *v = malloc(n * sizeof(int));             //c1

    for (int i = 0; i < n; i++) {                 //c2 + c3 (n + 1) + c4 n
        for (int j = 0; j < n; j++) {             //c5 n + c6 n(n + 1) + c7 (n^2)    
            v[i] += j;                            //c8 (n^2)
        }
    }

    free(v);                                      //c9
}
/* 
  
  == MELHOR E PIOR CASO ==
Nessa análise o melhor e o pior caso são da mesma ordem

O = c1 + c2 + c3(n+1) + c4n + c5n + c6(n^2+1) + c7(n^2) + c8(n^2) + c9
O(n^2)
Ω(n^2)

*/
//===================================================================================================================//

void q10(int n)
{
    int **m = malloc(n * sizeof(int*));           //c1

    for (int i = 0; i < n; i++) {                 //c2 + c3 (n + 1) + c4 n
        m[i] = malloc(n * sizeof(int));           //c5 n

        for (int j = 0; j < n; j++) {             //c6 n + c7 n(n + 1) + c8 n^2
            m[i][j] = i + j;                      //c9 n^2
        }
    }

    for (int i = 0; i < n; i++) {                 //c10 + c11 (n + 1) + c12 n
        free(m[i]);                               //c13 n
    }

    free(m);                                      //c14
}
/* 
  
  == MELHOR E PIOR CASO ==
Nessa análise o melhor e o pior caso são da mesma ordem

O = c1 + c2 + c3(n+1) + c4n + c5n + c6(n) + c7n(n+1) + c8(n^2) + c9(n^2) + c10 + c11(n+1) + c12n + c13n + c14
O(n^2)
Ω(n^2)

*/
//===================================================================================================================//

void q11(int LIN, int COL)
{
    int **p = (int**) malloc(LIN*sizeof(int));                     //c1
    int i, j;                                                      //c2 + c3

    int matriz[LIN][COL];                                          //c4

    for (i=LIN-1; i>=0; i--) {                                     //c5 + c6 (LIN + 1) + c7 LIN
        p[i] = (int*) malloc(COL*sizeof(int));                     //c8 LIN
        for (j=0; j<COL; j++) {                                    //c9 LIN + c10 LIN(COL + 1 ) + c11 (LIN COL)
            p[i][j] = 10*(i+1) + (j+1);                            //c12 (LIN COL)
            matriz[i][j] = p[i][j];                                //c13 (LIN COL)
        }
    }

    for (i=LIN-1; i>=0; i--) {                                     //c14 + c15 (LIN + 1) + c16 LIN          
        free(p[i]);                                                //c17 LIN
        p[i] = NULL;                                               //c18 LIN
    }

    free(p);                                                       //c19
    p = NULL;                                                      //c20
}
/* 
  
  == MELHOR E PIOR CASO ==
Nessa análise o melhor e o pior caso são da mesma ordem

O = c1 + c2 + c3 + c4 + c5 + c6(LIN+1) + c7(LIN) + c8LIN + c9LIN + c10LIN(COL+1) + c11(LIN*COL) + c12(LIN*COL)
+ c13(LIN*COL) + c14 + c15(LIN+1) + c16LIN + c17LIN + c18LIN + c19 + c20
O(n*m)
Ω(n*m)

*/
//===================================================================================================================//

void q12(int n)
{
    int i = 1, count = 0;                   //c1 + c2
    while (i < n) {                         //c3 (log(n) + 1)
        i *= 3;                             //c4 log(n) 
        count++;                            //c5 log(n)
    }
}
/* 
  
  == MELHOR E PIOR CASO ==
Nessa análise o melhor e o pior caso são da mesma ordem

O = c1 + c2 + c3(log(n)+1) + c4(log(n)) + c5(log(n))
O(log(n))
Ω(log(n))

*/
//===================================================================================================================//

void q13(int n)
{
    int *v = malloc(n * sizeof(int));       //c1 + c2
    for (int i = 0; i < n; i++) {           //c3 + c4 (n + 1) + c5 n
        v[i] = 0;                           //c6 n
        int j = 1;                          //c7 n
            
        while (j < n) {                     //c8 n(log(n) + 1) 
            j *= 2;                         //c9 n(log(n))
        }
    }
    free(v);                                //c10
}
/* 
  
  == MELHOR E PIOR CASO ==
Nessa análise o melhor e o pior caso são da mesma ordem

O = c1 + c2 + c3 + c4(n+1) + c5n + c6n + c7n + c8n(log(n)+1) + c9n(log(n)) + c10
O(nlog(n))
Ω(nlog(n))

*/
//===================================================================================================================//

void q14(int n)
{
    int *v = malloc(n * sizeof(int));      //c1 + c2
    int i = 0;                             //c3
    while (i < n) {                        //loop infinito
        v[i] = i;                          
        i += i;                            
        if (i > 0) {                      
            i += i;                        
        }
    }
    free(v);                               //c9
}
/* 
  
  == MELHOR E PIOR CASO ==
Nesse algoritmo o loop roda infinitamente até o processo ser interrompido a força, uma vez que a condição (i < n)
sempre é satisfeita. Nesse caso, não temos complexidade de melhor e pior caso finita.

*/
//===================================================================================================================//

void q15(int n)
{
    int i;                                 //c1
    for (i = 0; i < n; i++) {              //c2 + c3 (n + 1) + c4 n
        if (i % 2 == 0) {                  //c5 n
            continue;                      //c6 n
        } else {                           //c7 n
            break;                         //c8
        }
    }
}
/* 
  
  == MELHOR E PIOR CASO ==
Nessa análise o melhor e o pior caso são da mesma ordem, pois o laço quebrará na terceira iteração quando i = 3.

O(1)
Ω(1)

*/
//===================================================================================================================//

void q16(int n)
{
    int i, sum = 0;                       //c1 + c2
    for (i = 0; i < n; i++) {             //c3 + c4 (n + 1) + c6 n
        sum += i;                         //c7 n
        if (sum > 10) {                   //c8 n
            break;                        //c9
        }
    }
}
/* 
  
  == MELHOR E PIOR CASO ==
Nessa análise o melhor e o pior caso são da mesma ordem, pois o laço quebra após 5 iterações.

O(1)
Ω(1)

*/
//===================================================================================================================//