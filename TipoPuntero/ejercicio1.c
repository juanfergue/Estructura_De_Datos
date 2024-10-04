#include <stdio.h>

int main(void){
    int *ptr;
    int num = 14;

    ptr = &num; //Hacemos que el puntero apunte a la misma dirrecion que num

    printf("(usando puntero ) Entero %d, Direccion de memoria %p\n", *ptr,ptr);
    printf("(usando variable) Entero %d, Direccion de memoria %p\n", num,&num);


    return 0;
}