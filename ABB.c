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

void PreOrden(){
    Recorrer(raiz);
}

void Recorrer(nodo *raiz){

    if(raiz != NULL){
        printf("%d\n",raiz->numero);
        Recorrer(raiz->izquierda);
        Recorrer(raiz->derecha);
    }
}

void Graficar(){
    if(raiz != NULL){
        char direccion[] = "ABB.dot";
        fd = fopen(direccion,"wt");

        if(fd == NULL){
            printf("\nError al crear el archivo'n");
            return;
        }

        //-------------- INICIO DEL CODIGO GRAPHVIZ -----------------
        char begin[] = "digraph G {\n";
        fputs(begin,fd);

        Generar_Grafo(raiz);

        fputs("}",fd);
        fclose(fd);

        system("dot -Tpng -O ABB.dot");
        system("xdg-open ABB.dot.png");

        //system("clear");
    }
}

void Generar_Grafo(nodo *raiz){
    if(raiz != NULL){
    char derecha[500]; char izquierda[500];
      if(raiz->izquierda != NULL){
      sprintf(izquierda,"\"%d\" -> \"%d\"\n",raiz->numero,raiz->izquierda->numero);
      fputs(izquierda,fd);
      }

      if(raiz->derecha != NULL){
        sprintf(derecha,"\"%d\" -> \"%d\"\n",raiz->numero,raiz->derecha->numero);
      fputs(derecha,fd);
      }

      Generar_Grafo(raiz->izquierda);
      Generar_Grafo(raiz->derecha);
    }

}











