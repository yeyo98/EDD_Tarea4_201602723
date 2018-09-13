#ifndef ABB
#define ABB

typedef struct nodo{
    int numero;
    //nodo* padre;
    struct nodo* izquierda;
    struct nodo* derecha;
}nodo;

void Insertar(void);
nodo* Agregar_Dato(nodo* dato, nodo* raiz);
void PreOrden(void);
void Recorrer(nodo* raiz);
void Graficar(void);
void Generar_Grafo(nodo *raiz);

#endif
