#include <stdio.h>
#include <string.h>

int read(char* file, int matrix[][20], int vetor[]){
    FILE *fp;
    fp = fopen(file,"r"); 
    if(!fp) {
        printf("Erro na abertura do arquivo.\n");
        return 0;
    }
    // lendo o primeiro int do arquivo, que é o tamanho e colocando na matriz
    int tamanho = 0;
    fscanf(fp, "%d", &tamanho);
    
    
    int quebra = 0;
    int linha, coluna;
    int soma = 0;
    for(linha = 0; linha< tamanho; linha++){
        for(coluna =0; coluna < tamanho;coluna++){
            matrix[linha][coluna]= 0;
        }
    }
    // linha por linha do arquivo entra na matriz
    // a quebra funciona como um controlador para a altura da pilha
    // primeira camada quebra = 0
    // segunda camada quebra = 1 e por aí vai
    
    while(!feof(fp)){                           
        for (linha = 0; linha < tamanho; linha++) {
            for( coluna = 0; coluna < tamanho; coluna++){
                fscanf(fp, "%d", &matrix[linha][coluna]);
                if(quebra == coluna){
                    break;
                }
            }
            quebra++;
        }
        
    }
    fclose(fp);
    for(linha = 0; linha<tamanho;linha++){
        vetor[linha] = 0;
    }

    for(linha = 0; linha < tamanho; linha++){
        for(coluna = 0; coluna < tamanho; coluna++){
            vetor[linha] += matrix[linha][coluna];  //soma das linhas
        }
        
    }
    int aux[100] = {0};
    // soma dos elementos dos vetores
    // para que cada camada tenha a sua soma com a fileira de cima
    // primeira camada = soma d único elemento
    // segunda camada = soma de seus elementos com a camada de cima
    soma = 0;
    for(int i = 0; i < tamanho;i++){
        soma += vetor[i];
        aux[i] = soma;
    }
    aux[tamanho - 1] = 0;
    
    int melhor = 0;
    int numero =0;
    int maior = aux[0];
        for(linha = 1; linha < tamanho; linha++){
            for(coluna = 0; coluna < tamanho; coluna++){
                if(matrix[linha][coluna] != aux[0]){
                    melhor = aux[linha-1] + matrix[linha][coluna] ;     
                    if(melhor > maior){
                        maior = melhor;
                        numero = matrix[linha][coluna];
                    }
                }
                else{
                    maior = matrix[linha][coluna];
                }
            }  
        }
    
    if(matrix[0][0] > numero){ //se o primeiro numero for o maior
        numero = matrix[0][0];
    }
     //printf("%d ", numero);
    for(linha = 0; linha < tamanho; linha++){
        for(coluna = 0; coluna < tamanho; coluna++){
            if(matrix[linha][coluna] == numero){
                printf("Resposta: fileira %d, caixa %d.\n", linha +1, coluna +1);
            }
        }
    }
    return 0;
} 


int main() {
    int matriz[20][20];
    int vetor[20];
    char arquivo[255];
    printf("Digite o nome do arquivo de entrada: ");
    scanf("%s", arquivo);
    read(arquivo, matriz, vetor);
    
}