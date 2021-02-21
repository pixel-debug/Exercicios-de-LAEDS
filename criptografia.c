#include <stdio.h>
#include <string.h>


void prints(int tam);
char* codificador(char* cripitografia);
void decodificador(char* vetor);

// aqui iremos codificar ao contrário
// espelhando e permutando
char* codificador(char* cripitografia){ 
    int j = 1;
    int k = 0;
    char aux2 =0;
    char aux = 0;
    for (int i = 0; i < strlen(cripitografia)/2; i=i+2){
        if( k % 2 == 0){
            aux = cripitografia[i];
            aux2 = cripitografia[i + 1];

            cripitografia[i] = cripitografia[strlen(cripitografia) - j];
            cripitografia[i + 1] = cripitografia[strlen(cripitografia) - j - 1];

            cripitografia[strlen(cripitografia) - j] = aux;
            cripitografia[strlen(cripitografia) - j - 1] = aux2; 
            j=j+2;
            k++;
        }       
        else{ //espelho dos que não trocam
            aux2 = cripitografia[i];
            cripitografia[i] = cripitografia[i + 1];
            cripitografia[i + 1] = aux2; 


            aux = cripitografia[strlen(cripitografia) - j ];
            cripitografia[strlen(cripitografia) - j] = cripitografia[strlen(cripitografia) -j - 1];
            cripitografia[strlen(cripitografia) -j - 1] = aux;  

            k++;
            j=j+2;
        } 
    }
 /*    printf("\n");

    for (int i = 0; i < strlen(cripitografia); i ++){
      printf("%c",cripitografia[i]);
    } 
    printf("\n");
   */ return cripitografia;
} 

// decodificando usando a tabela ASCII
void decodificador(char* vetor){
    
    for(int i = 0; i < strlen(vetor);i++){
        if(vetor[i] <= 69){
            vetor[i] = vetor[i] + 21; //16
        }
        else if(vetor[i] <= 90){
            vetor[i] = vetor[i] - 5;
        }
        else if(vetor[i] <= 101){
            vetor[i] = vetor[i] + 21;
        }
        else if(vetor[i] <= 122){
            vetor[i] = vetor[i] - 5;
        }
        else{
            vetor[i] = vetor[i] - 16;
        }
    }
    for(int i = 0; i < strlen(vetor);i++){
        if(vetor[i] == 56){
            if(!vetor[strlen(vetor)]){
                vetor[i] = 32;
            }
            else{
                vetor[i] = '\0';
            }
           
        }
    }
    prints(22);
    printf("\nMensagem decodificada:\n");
    prints(22);

    printf("\n%s\n", vetor);
}

void prints(int tam){
    for (int i = 0; i < tam; i ++){
      printf("-");
    } 
}


int main() {
    char arquivo[255];
    printf("Digite o nome do arquivo: ");
    scanf("%s", arquivo);
    
    FILE *fp;
    fp = fopen(arquivo,"r"); 
    if(!fp) {
        printf("Erro na abertura do arquivo.\n");
        return 0;
    }
    char vet[5000];
    for (int i = 0; i < 5000; i ++){
        vet[i] = '\0';
    }
    // Imprime conteudo do arquivo
    //while (!feof(fp) ) {
       // for(int i = 0; i < 5000; i++){
            fscanf(fp,"%s",vet);
        //}
   // }
   // printf("%d", strlen(vet));
    fclose(fp);
    printf("\n");

    prints(20);
    printf("\nMensagem codificada:\n");
    prints(20);
    printf("\n");

    for (int i = 0; i < strlen(vet); i ++){
      printf("%c",vet[i]);
    } 
    printf("\n");
    printf("\n");

    decodificador(codificador(vet));
}

