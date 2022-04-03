#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include "Matriz.h"

int main(){

    int nr_ordem=0, matriz[TAM][TAM];

    printf("Informe o tamanho da matriz quadrada: ");
    scanf("%d", &nr_ordem);

    CriarMatriz(nr_ordem, matriz);
    ImprimeMatriz(nr_ordem, matriz); 
    PercorrerMatriz(nr_ordem, matriz);

    return 0;
}
