# Counting Sort

## Resumo

Proposto por Harold H. Seward, em 1954, o Counting Sort é um algoritmo de ordenação baseado na contagem da **frequência** de elementos. Em vez de comparar elementos, ele cria um array auxiliar para armazenar a frequência de cada valor e gerar a lista ordenada. 

Sua complexidade é O(n+k) - equivalente a O(n)- e esse algoritmo é especialmente performático para a ordenação de grandes vetores com poucos valores - pequena diferença entre valor máximo e mínimo.
Os elementos a serem ordenados são números inteiros pequenos, isto é, inteiros x onde x pertence à O(n).

## Funcionamento
- Contagem: Declaração de um array de contagem para armazenar as ocorrências dos elementos do array de entrada.
- Soma prefixada: Cálculo da soma prefixada em cada índice do array de contagem.
- Lista ordenada: a lista original é reconstituída de forma ordenada, percorrendo o vetor na ordem inversa e garantindo estabilidade.

## Aplicações de contagem Sort
Algoritmo comumente usado para os casos em que temos itens de alcance limitado. Assim como também é usado de sub-rotina em Radix Sort.
A ideia de classificar contagem é usada no Bucket Sort para dividir elementos em "baldes"

## Vantagens e desvantagens
| Vantagens | Right columns |
| ------------- |:-------------:|
| Tempo linear      | Ineficiencia p/ grandes intervalos     |
| Estabilidade      | Limitado     |
| In-place      | --     |

## Compilação e execução
Alternativas de compilação para Linux (gcc/clang) e Windows (MinGW/WSL):

Makefile:
```
make
make run
make clean
```

Shell Script (Linux):
```
chmod +x build.sh
./build.sh
```

Batch Script (Windows):
```
.\build.bat
```
