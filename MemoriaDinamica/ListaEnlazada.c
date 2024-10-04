#include <stdio.h>

typedef struct Node *ptrNode;
typedef struct Node{
    int data;
    ptrNode next;
}Node;

void IterarLista(ptrNode head){   
    int i = 0;
    while(head !=NULL) //mientras tenga siguiente avanza
    {
        printf("El valor es: %d en la posicion %d\n", head->data, i );
        i++;
        head = head->next;
    }
    
}
void insertarCabeza(ptrNode *ptrhead, int data){
    if(*ptrhead == NULL){ //en caso de que sea NULL
        (*ptrhead) = (ptrNode)malloc(sizeof(struct Node)); // crea el nodo en la dirrecion que apunta a ptrhead
        (*ptrhead)->data = data;
        (*ptrhead)->next = NULL;
    }else{
        ptrNode nuevo = (ptrNode)malloc(sizeof(struct Node));
        nuevo->next = (*ptrhead);
        (*ptrhead) = nuevo;
    }
}
void insertarCola(struct Node ** direccionHead, int dato){
  struct Node * nuevo = (struct Node *) malloc(sizeof(struct Node));
  if (nuevo==NULL){
    printf("No hay memoria disponible\n");
    exit(-1);
  }
  nuevo->data = dato;
  nuevo->next = NULL;

  if(direccionHead==NULL){
    *direccionHead=nuevo;
  }else{
    // Tengo al menos un elemento
    struct Node * iter = *direccionHead;
    while(iter->next!=NULL){ iter = iter->next;
    }
    iter->next=nuevo;
  }
}

bool eliminar( struct Node ** direccionHead, int data){
    bool res = false;
    if(*direccionHead != NULL){
        //Al menos un elemento
        if((*direccionHead)->next == NULL){
            if((*direccionHead)->data == data){
                free(*direccionHead);
                *direccionHead = NULL;
                res = true;
            }       
        }
    }else{
        struct Node * iter = *direccionHead; // iter apunta al primer elemento para partir de ese punto
        while(iter->next!=NULL && iter->next->data != data){  
            iter = iter->next;
        }
        if(iter->next != NULL){ //He encontrado el elemento que queria eliminar
            struct Node * aux = iter->next; //elemento que queremos eliminar
            iter->next = iter->next->next; //pasamos el iterador a que apunte al que apuntaba el que vamos a eliminar que es aux
            free(aux);
            res = true;
        }
        //Encontramos si iter->next es el que tiene el dato
        iter->next=nuevo;
    }
    

    return res;
}

void destruir(struct  Node ** direccionHead){
    struct Node * ant;
    while(*direccionHead != NULL){
        ant = *direccionHead;
        (*direccionHead) = (*direccionHead)->next;

        free(ant);
    }
}



int main(void){
    ptrNode head;
    head = (ptrNode)malloc(sizeof(struct Node));

    head->data = 3; // lo mismo que (*head).data = 3;
    head->next = (ptrNode)malloc(sizeof(struct Node));
    head->next->data = 7;
    head->next->next = (ptrNode)malloc(sizeof(struct Node));
    head->next->next->data = 9;
    head->next->next->next = NULL;
    IterarLista(head);
    return 0;
}

