#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include "Matriz.h"

int main(){

    int i=0, nr_ordem=0, **matriz;

    printf("Informe o tamanho da matriz quadrada: ");
    scanf("%d", &nr_ordem);

    matriz = (int **)malloc(sizeof(int *) * nr_ordem);
    for(i=0; i<nr_ordem; i++){
        matriz[i] = (int *)malloc(sizeof(int) * nr_ordem);
    }

    MatrixMake(nr_ordem, matriz);
    MatrixPrint(nr_ordem, matriz);
    MatrixWalk(nr_ordem, matriz);

    return 0;
}
