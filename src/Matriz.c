
#include "Matriz.h"

void CriarMatriz(const int nr_ordem, int matriz[nr_ordem][nr_ordem]){

    srand(time(NULL));
    for(int i=0; i < nr_ordem; i++){
        for(int j=0; j < nr_ordem; j++){
            matriz[i][j] = (rand() % 100);
        }
    }
}

void ImprimeMatriz(const int nr_ordem, int matriz[nr_ordem][nr_ordem]){

    printf("\nA matriz gerada foi: \n");
    for (int i = 0; i < nr_ordem; i++){
            printf("\n");
            for (int j = 0; j < nr_ordem; j++)
            {
                printf("%d ", matriz[i][j]);
            }
        }
}