#ifndef LISTA_H
#define LISTA_H


#include "str_nodo.h"

class Lista
{
    str_Nodo* Inicio;
    str_Nodo* Actual;
    str_Nodo* Anterior;
    str_Nodo* Final;
    int cantidad;

public:
    //Inicializo a NULL o cero
     Lista();

     //Inserta los nodos en la cabeza de la lista
     void Insertar_Inicio(str_Nodo*);
     //Inserto el punto generado en orden respecto de las x's
     void Insertar_Por_Orden(str_Nodo*);

     void Set_Inicio(str_Nodo*);
     void Set_Actual(str_Nodo*);
     void Set_Anterior(str_Nodo*);
     void Set_Final(str_Nodo*);

     str_Nodo* Get_Inicio();
     str_Nodo* Get_Actual();
     str_Nodo* Get_Anterior();
     str_Nodo* Get_Final();
     int Get_Cantidad();


    //Libero la memoria
     ~Lista();
};

#endif // LISTA_H
