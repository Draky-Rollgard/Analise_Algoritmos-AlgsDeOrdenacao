#!/bin/bash
gcc Counting_Sort_code.c -o counting_sort

# Verificação
if [ $? -eq 0 ]; then
    echo "A Compilação foi um sucesso."
    echo "Executando programa..."
    ./counting_sort
else
    echo "Erro na compilação."
fi