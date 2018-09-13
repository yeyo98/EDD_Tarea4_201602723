#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "ABB.h"

nodo* raiz = NULL;
char* cuerpo;
char contenido[1000];
FILE *fd;

void Insertar(){
    nodo*  nuevo = (nodo*)malloc(sizeof(nodo));
    printf("\nIngrese un numero: ");
    scanf(" %d", &nuevo->numero);
    raiz = Agregar_Dato(nuevo,raiz);
    nuevo = raiz;
}

nodo* Agregar_Dato(nodo* dato, nodo* raiz){
    if(raiz==NULL){
        raiz = dato;
    }else if(dato->numero < raiz->numero){
        nodo* izq;
        izq = Agregar_Dato(dato,raiz->izquierda);
        raiz->izquierda = izq;
    }else if(dato->numero > raiz->numero){
        nodo* der;
        der = Agregar_Dato(dato,raiz->derecha);
        raiz->derecha = der;
    }
    return raiz;
}




