#include "cola.h"
#include <stdio.h>

//#ifndef COLA_H // Evita la inclusión múltiple del archivo de encabezado
#define COLA_H

#include <stdbool.h>

/*struct Person
{
    char name[30];
    int age;
};

typedef struct Node *Queue;
struct Node
{
    struct Person * person;
    struct Node *next;
};


 * @brief Crea una nueva persona
 * @param name Nombre de la persona
 * @param age Edad de la persona
 * @return Puntero a la persona creada con memoria dinámica
 */
struct Person * createPerson(char *name, int age){
    struct Person 
}

/**
 * @brief Crea una cola vacía
 * @param queue Puntero a la cola
 */
void createQueue(Queue *ptrqueue);

/**
 * @brief Comprueba si la cola está vacía
 * @param queue Puntero a la cola
 * @return true si la cola está vacía, false en caso contrario
 */
bool isEmpty(Queue queue){
    return queue == NULL;
}

/**
 * @brief Comprueba el tamaño de la cola
 * @param queue Puntero a la cola
 * @return
 */
int size(Queue queue);

/**
 * @brief Añade un elemento al final de la cola
 * @param queue Puntero a la cola
 * @param person Puntero a persona a añadir
 */
void enqueue(Queue *ptrqueue, struct Person * person){
    if(isEmpty(*ptrqueue)){
        struct Node * nuevoNodo = (struct Node *)malloc(sizeof(struct Node));
        nuevoNodo->person = person;
        nuevoNodo->next = nuevoNodo;
        *ptrqueue = nuevoNodo;
    }
    else{
        struct Node * nuevoNodo = (struct Node *)malloc(sizeof(struct Node));
        nuevoNodo->person = person;
        nuevoNodo->next = (*ptrqueue)->next;
        (*ptrqueue)->next = nuevoNodo;
        
        *ptrqueue = nuevoNodo; //ultimo insertado
        //(*ptrqueue)->next //mas antiguo
    }
}

/**
 * @brief Elimina el primer elemento de la cola
 * @param queue Puntero a la cola
 */
void dequeue(Queue *ptrqueue){
     if(isEmpty(*ptrqueue)){
        Queue aux = (*ptrqueue)->next;

        
    }
}

/**
 * @brief Obtiene el primer elemento de la cola sin eliminarlo
 * @param queue Cola de la que se quiere obtener el primer elemento
 * @return Persona en la primera posición de la cola
 */
struct Person * first(Queue queue);

/**
 * @brief Limpia la cola
 * @param queue Puntero a la cola
 */
void clear(Queue *ptrqueue);

/**
 * @brief Muestra los elementos de la cola
 * @param queue Puntero a la cola
 */
void display(Queue queue);
