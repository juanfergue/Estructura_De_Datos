#include <stdio.h>

int main(void){

    int x = 10;
    int y = 20;
    int z[3];
    int *ptr;
    ptr = &x;
    y = *ptr;
    *ptr = 0;
    ptr = &z[0];

    return 0;
}

