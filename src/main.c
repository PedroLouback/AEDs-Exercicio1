#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Matriz.h"

int main(){

    int nr_ordem=0, matriz[TAM][TAM];

    printf("Informe o tamanho da matriz quadrada: ");
    scanf("%d", &nr_ordem);

    CriarMatriz(matriz, nr_ordem);
    ImprimeMatriz(matriz, nr_ordem); 

}
