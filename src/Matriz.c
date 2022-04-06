
#include "Matriz.h"

void CriacaoMatriz(int nr_ordem, int **matriz)
{

    srand(time(NULL));
    for(int i=0; i < nr_ordem; i++){
        for(int j=0; j < nr_ordem; j++){
            matriz[i][j] = (rand() % 100);
        }
    }
}

void ImprimirMatriz(int nr_ordem, int **matriz)
{

    printf("\nA matriz gerada foi: \n");
    for (int i = 0; i < nr_ordem; i++){
            printf("\n");
            for (int j = 0; j < nr_ordem; j++)
            {
                printf("%d ", matriz[i][j]);
            }
        }
}

void PercorrendoMatriz(int nr_ordem, int **matriz)
{

    int i=0, j=0, soma_dos_valores=0;
    bool invalida_celula=false;
    soma_dos_valores+=matriz[i][j];
    matriz[i][j]=invalida_celula;

    while(i < nr_ordem && j < nr_ordem){
        if(i < nr_ordem-1 && j == 0){ //borda lateral esquerda
            if(matriz[i][j+1]>=matriz[i+1][j] && matriz[i][j+1]!=invalida_celula){
                soma_dos_valores+=matriz[i][j+1];
                matriz[i][j+1]=invalida_celula;
                j++;
            }
            else if(matriz[i+1][j]>=matriz[i][j+1] && matriz[i+1][j]!=invalida_celula){
                soma_dos_valores+=matriz[i+1][j];
                matriz[i+1][j]=invalida_celula;
                i++;
            }
        }
        else if(i==0 && j<nr_ordem-1){ //borda superior 
            if(matriz[i][j+1]>=matriz[i+1][j] && matriz[i][j+1]!=invalida_celula){
                soma_dos_valores+=matriz[i][j+1];
                matriz[i][j+1]=invalida_celula;
                j++;
            }
            else if(matriz[i + 1][j] >= matriz[i][j + 1] && matriz[i + 1][j] != invalida_celula)
            {
                soma_dos_valores += matriz[i + 1][j];
                matriz[i + 1][j] = invalida_celula;
                i++;
            }
        }
        else if(i==0 && j==nr_ordem){ //ponta da direita superior
            soma_dos_valores += matriz[i + 1][j];
            matriz[i + 1][j] = invalida_celula;
            i++;
        }
        else if(i<nr_ordem-1 && j==nr_ordem-1){ //borda lateral direita (sem ponta)
            if(matriz[i][j-1]>=matriz[i+1][j]&&matriz[i][j-1]!=invalida_celula){
                soma_dos_valores+=matriz[i][j-1];
                matriz[i][j-1]=invalida_celula;
                j--;
            }
            else if (matriz[i+1][j] >= matriz[i][j-1] && matriz[i+1][j] != invalida_celula){
                soma_dos_valores += matriz[i + 1][j];
                matriz[i + 1][j] = invalida_celula;
                i++;
            }
        }
        else if(i!=nr_ordem-1 && j!=nr_ordem-1){ //elementos que não estão na borda
            if (matriz[i][j + 1] > matriz[i + 1][j] && matriz[i][j + 1] > matriz[i][j - 1] && matriz[i][j + 1] != invalida_celula)
            {
                soma_dos_valores += matriz[i][j + 1];
                matriz[i][j + 1] = invalida_celula;
                j++;
            }
            else if (matriz[i + 1][j] >= matriz[i][j - 1] && matriz[i + 1][j] > matriz[i][j + 1] && matriz[i + 1][j] != invalida_celula)
            {
                soma_dos_valores += matriz[i + 1][j];
                matriz[i + 1][j] = invalida_celula;
                i++;
            }
            else if (matriz[i][j - 1] >= matriz[i + 1][j] && matriz[i][j - 1] > matriz[i][j+1] && matriz[i][j - 1] != invalida_celula)
            {
                soma_dos_valores += matriz[i][j - 1];
                matriz[i][j - 1] = invalida_celula;
                j--;
            }
        }
        else if(i==nr_ordem-1 && j<nr_ordem-1){
            soma_dos_valores += matriz[i][j + 1];
            matriz[i][j + 1] = invalida_celula;
            j++;
        }
        else if(i==nr_ordem-1 && j==nr_ordem-1){
            j++;
        }   
    }
    printf("\n\nA soma dos valores percorridos é: %d\n", soma_dos_valores);
}
