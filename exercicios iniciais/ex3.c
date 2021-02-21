#include <stdio.h>
#include <math.h>

void dec2bin(int dec){
    int aux;
    if(dec/2 != 0){
        aux = dec/2;
        dec2bin(aux);
        printf("%d", dec%2);
        
    }
    else{
        printf("%d",dec%2);
        
    }
  
}

int main(){
    int numero;
    printf("Digite um numero inteiro: ");
    scanf("%d", &numero);
    dec2bin(numero);
}


