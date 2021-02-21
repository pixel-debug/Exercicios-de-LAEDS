#include <stdio.h>
#include <math.h>

int Digitos(int N){
  int cont = 1;
  if(N <= 9){
    return 1;
  }
  else{
    return (Digitos(N/10) + cont);
  }
}

int main(){
    int numero;
    printf("Digite um numero inteiro: ");
    scanf("%d", &numero);
    printf("Resultado: %d\n", Digitos(numero));
}


