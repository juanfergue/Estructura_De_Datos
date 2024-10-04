#include <stdio.h>
#include <stdlib.h>
#include <time.h> // Para srand y rand
int main(){
    int numElementos;
    //Entrada teclado
    printf("Ingrese el número de enteros que desea generar: ");
    scanf("%d", &numElementos);
    //Petición de memoria
    int *arrayEnteros = (int *)malloc(numElementos * sizeof(int));
    //No se puede conceder memoria, nos salimos
    if (arrayEnteros == NULL){
        perror("Error: No se pudo reservar memoria.\n"); // en caso de que no se pueda crear memoria
        exit(1);
    }
    srand(time(NULL)); // Semilla
    for (int i = 0; i < numElementos; i++){
        arrayEnteros[i] = rand() % (99 - 0 + 1);
    }
    printf("Array generado con %d elementos:\n", numElementos);
    for (int i = 0; i < numElementos; i++){
    printf("%d ", arrayEnteros[i]);
    }
    printf("\n");
    printf("Teclea enter para finalizar");
    getchar(); //Retorno anterior
    getchar();
    
    free(arrayEnteros);  //Liberamos la memoria del montículo
    return 0;
}