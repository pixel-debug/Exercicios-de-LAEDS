#include <stdio.h>
#include <stdlib.h>

int getPesoTamanho(FILE* fp){
    int pesoTamanho = 0;
    fscanf(fp, "%d", &pesoTamanho);
    return pesoTamanho;
}

int **read(FILE* fp, int tamanho){
    int ** matrix;
    matrix = malloc(sizeof(int*)*tamanho);
    for(int i = 0; i< tamanho; i++){
        matrix[i] = malloc(sizeof(int)*2);
        fscanf(fp, "%d %d", &matrix[i][0],&matrix[i][1]);
    }
    return matrix;
}

int *getResposta(FILE * fp, int tamanho){
    int* vet = malloc(sizeof(int)*tamanho);
    for(int i =0;i < tamanho;i++){
        fscanf(fp,"%d",&vet[i]);
    }
    return vet;
}

void printAPorraDaMatriz(int **matriz,int tamanho){
    for(int i = 0;i<tamanho;i++){
        for(int j = 0; j < 2; j++){
            printf(" %d ",matriz[i][j]);
        }
    }
}

int comparaVetorMatriz(int **matriz, int* vetor, int tamanho,int peso, int *pesoTotal, int *valorTotal){
    *pesoTotal = 0;
    *valorTotal = 0;
    for(int i = 0; i < tamanho; i ++){
        if(vetor[i] == 1){
            *pesoTotal+= matriz[i][0];
            *valorTotal+= matriz[i][1];
        }
    }
    if(*pesoTotal > peso){
        printf("Solucao inviavel.\n");
        return -1;
    }
}




int main(){
    int ** matrix;
    int * resposta;
    int tamanho, peso;
    int pesoTotal, valorTotal;

    FILE *fp;
    fp = fopen("texto.txt","r"); 
    if(!fp) {
        printf("Erro na abertura do arquivo.\n");
        return 0;
    }
    peso = getPesoTamanho(fp);
    tamanho = getPesoTamanho(fp);
    matrix = read(fp, tamanho);
    resposta = getResposta(fp,tamanho);
    pesoTotal = comparaVetorMatriz(matrix, resposta,tamanho, peso, &pesoTotal, &valorTotal);
    //printf(" %d %d \n", pesoTotal, valorTotal);
  //  printAPorraDaMatriz(matrix, tamanho);
    
    free(resposta);
    free(matrix);
}