#include <Arduino.h>

struct nodo {
    int dato;
    nodo *d;
    nodo *i;
    nodo *padre;
};

nodo *crear(int n, nodo *p) {
    nodo *nuevo = new nodo();
    nuevo->dato = n;
    nuevo->d = NULL;
    nuevo->i = NULL;
    nuevo->padre = p;
    return nuevo;
}

nodo *arbol = NULL;

void insertar(nodo *&arbol, int n, nodo *p) {
    if (arbol == NULL) {
        nodo *nuevo = crear(n, p);
        arbol = nuevo;
    } else {
        int x = arbol->dato;
        if (n < x) {
            insertar(arbol->i, n, arbol);
        } else if (n > x) {
            insertar(arbol->d, n, arbol);
        }
    }
}

void mostrar(nodo *arbol, int cont) {
    if (arbol == NULL) {
        return;
    } else {
        mostrar(arbol->d, cont + 1);
        for (int i = 0; i < cont; i++) {
            Serial.print("   ");
        }
        Serial.println(arbol->dato);
        mostrar(arbol->i, cont + 1);
    }
}

bool buscar(nodo *arbol, int n) {
    if (arbol == NULL) {
        return false;
    } else if (arbol->dato == n)
        return true;
    else if (arbol->dato > n)
        return buscar(arbol->i, n);
    else
        return buscar(arbol->d, n);
}

void pre(nodo *arbol) {
    if (arbol == NULL) {
        return;
    } else {
        Serial.print(arbol->dato);
        Serial.print(" - ");
        pre(arbol->i);
        pre(arbol->d);
    }
}

void in(nodo *arbol) {
    if (arbol == NULL) {
        return;
    } else {
        in(arbol->i);
        Serial.print(arbol->dato);
        Serial.print(" - ");
        in(arbol->d);
    }
}

void post(nodo *arbol) {
    if (arbol == NULL) {
        return;
    } else {
        post(arbol->i);
        post(arbol->d);
        Serial.print(arbol->dato);
        Serial.print(" - ");
    }
}

nodo *minimo(nodo *arbol) {
    if (arbol == NULL) {
        return NULL;
    }
    if (arbol->i) {
        return minimo(arbol->i);
    } else {
        return arbol;
    }
}

void reemplazar(nodo *a, nodo *b) {
    if (a->padre) {
        if (a->dato == a->padre->i->dato) {
            a->padre->i = b;
        } else if (a->dato == a->padre->d->dato) {
            a->padre->d = b;
        }
    }
    if (b) {
        b->padre = a->padre;
    }
}

void destruir(nodo *n) {
    n->i = NULL;
    n->d = NULL;
    n->padre = NULL;
    delete n;
}

void eliminarnodo(nodo *nodoeliminar) {
    if (nodoeliminar->d && nodoeliminar->i) {
        nodo *menor = minimo(nodoeliminar->d);
        nodoeliminar->dato = menor->dato;
        eliminarnodo(menor);
    } else if (nodoeliminar->i) {
        reemplazar(nodoeliminar, nodoeliminar->i);
        destruir(nodoeliminar);
    } else if (nodoeliminar->d) {
        reemplazar(nodoeliminar, nodoeliminar->d);
        destruir(nodoeliminar);
    } else {
        reemplazar(nodoeliminar, NULL);
        destruir(nodoeliminar);
    }
}

void eliminar(nodo *arbol, int n) {
    if (arbol == NULL) {
        return;
    } else if (arbol->dato > n)
        eliminar(arbol->i, n);
    else if (arbol->dato < n)
        eliminar(arbol->d, n);
    else
        eliminarnodo(arbol);
}

void setup() {
    Serial.begin(9600);

    int cant_nodos;
    Serial.println("Cantidad de nodos:");
    while (!Serial.available()) {
        
    }
    cant_nodos = Serial.parseInt();

    for (int i = 0; i < cant_nodos; i++) {
        int x;
        Serial.println("Digite el valor del nodo:");
        while (!Serial.available()) {
            
        }
        x = Serial.parseInt();
        insertar(arbol, x, NULL);
    }

    Serial.println("\nMostrando arbol:");
    mostrar(arbol, 0);

    int value;
    Serial.println("\nBuscar un número:");
    while (!Serial.available()) {
        
    }
    value = Serial.parseInt();

    bool f = buscar(arbol, value);
    if (f) {
        Serial.println("El número existe");
    } else {
        Serial.println("El número no existe");
    }

    Serial.println("Recorrido preorden:");
    pre(arbol);
    Serial.println();

    Serial.println("Recorrido inorden:");
    in(arbol);
    Serial.println();

    Serial.println("Recorrido postorden:");
    post(arbol);
    Serial.println();

    int e;
    Serial.println("Eliminar un nodo:");
    while (!Serial.available()) {
        
    }
    e = Serial.parseInt();
    eliminar(arbol, e);

    Serial.println("\nÁrbol después de eliminar:");
    mostrar(arbol, 0);
}

void loop() {
    
}