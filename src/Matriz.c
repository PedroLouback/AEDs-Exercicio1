
#include "Matriz.h"

void MatrixMake(const int nr_ordem, int **matriz)
{

    srand(time(NULL));
    for(int i=0; i < nr_ordem; i++){
        for(int j=0; j < nr_ordem; j++){
            matriz[i][j] = (rand() % 100);
        }
    }
}

void MatrixPrint(const int nr_ordem, int **matriz)
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

void MatrixWalk(const int nr_ordem, int **matriz)
{

    int i=0, j=0, soma_dos_valores=0;
    bool invalida_celula=false;
    soma_dos_valores+=matriz[i][j];
    matriz[i][j]=invalida_celula;

    while(i != nr_ordem && j != nr_ordem){
        if(i==0 && j==0){ //caso esteja no inicio
            if(matriz[i][j+1] >= matriz[i+1][j]){
                soma_dos_valores+=matriz[i][j+1];
                matriz[i][j+1]=invalida_celula;
                j++;
            }
            else{
                soma_dos_valores+=matriz[i+1][j];
                matriz[i+1][j]=invalida_celula;
                i++;
            }
        }
        if(i < nr_ordem-1 && j == 0){ //borda lateral esquerda
            if(matriz[i][j+1]>matriz[i+1][j] && matriz[i][j+1]!=invalida_celula){
                soma_dos_valores+=matriz[i][j+1];
                matriz[i][j+1]=invalida_celula;
                j++;
            }
            else{
                soma_dos_valores+=matriz[i+1][j];
                matriz[i+1][j]=invalida_celula;
                i++;
            }
        }
        else if(i==0 && j<nr_ordem-1){ //borda superior 
            if(matriz[i][j+1]>matriz[i+1][j] && matriz[i][j+1]!=invalida_celula){
                soma_dos_valores+=matriz[i][j+1];
                matriz[i][j+1]=invalida_celula;
                j++;
            }
            else{
                soma_dos_valores += matriz[i+1][j];
                matriz[i+1][j] = invalida_celula;
                i++;
            }
        }
        else if(i==0 && j==nr_ordem){ //ponta da direita superior
            soma_dos_valores += matriz[i + 1][j];
            matriz[i + 1][j] = invalida_celula;
            i++;
        }
        else if(i!=0 && i<nr_ordem-1 && j==nr_ordem){ //borda lateral direita (sem ponta)
            if(matriz[i][j-1]>matriz[i+1][j]&&matriz[i][j-1]!=invalida_celula){
                soma_dos_valores+=matriz[i][j-1];
                matriz[i][j-1]=invalida_celula;
                j--;
            }
            else if (matriz[i+1][j] > matriz[i][j-1] && matriz[i+1][j] != invalida_celula){
                soma_dos_valores += matriz[i + 1][j];
                matriz[i + 1][j] = invalida_celula;
                i++;
            }
        }
        else if(i!=0 && i!=nr_ordem && j!=nr_ordem && j!=0){ //elementos que não estão na borda
            if (matriz[i][j + 1] > matriz[i + 1][j] && matriz[i][j + 1] != invalida_celula)
            {
                soma_dos_valores += matriz[i][j + 1];
                matriz[i][j + 1] = invalida_celula;
                j++;
            }
            else if (matriz[i + 1][j] > matriz[i][j - 1] && matriz[i + 1][j] != invalida_celula)
            {
                soma_dos_valores += matriz[i + 1][j];
                matriz[i + 1][j] = invalida_celula;
                i++;
            }
            else if (matriz[i][j - 1] > matriz[i + 1][j] && matriz[i][j - 1] != invalida_celula)
            {
                soma_dos_valores += matriz[i][j - 1];
                matriz[i][j - 1] = invalida_celula;
                j--;
            }
        }
        else if(i==nr_ordem && j<nr_ordem){ // ultima linha exceto ultimo elemento
            soma_dos_valores += matriz[i][j + 1];
            matriz[i][j + 1] = invalida_celula;
            j++;
        }   
    }
    printf("\nA soma dos valores é: %d", soma_dos_valores);
}
