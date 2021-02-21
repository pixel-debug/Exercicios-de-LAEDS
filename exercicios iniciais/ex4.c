#include <stdio.h>
#include <math.h>

int mult(int base, int exp){
    if(base == 1 || exp <= 0 ){
        return 1;
    }
    else{
        return (base*mult(base,exp-1));
    }
}

int main(){
    int expo,base;
    printf("Digite a base e o expoente inteiros: ");
    scanf("%d %d", &base, &expo);
    printf("Resultado: %d\n", mult(base,expo));
}


