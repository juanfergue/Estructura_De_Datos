#include<stdio.h>



int main(int argc, char const *argv[]){
    int tam_array;
    int array_enteros[50];

    printf("Cual es el tamaño del array(MAX 50): ");
    scanf("%i", &tam_array);
    int i = 0;
    int suma = 0;
    while(i < tam_array){
        printf("Numero %i", i);
        scanf("Numero: ",array_enteros[i]);
        suma+= array_enteros[i];
        i++;
    }
    int media = suma/tam_array;
    printf("La media del array es: %f" ,  media);

    return 0;
}