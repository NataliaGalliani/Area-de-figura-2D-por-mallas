#ifndef STR_NODO_H
#define STR_NODO_H

#include "punto.h"

class str_Nodo
{
    Punto* str_Punto;
    str_Nodo* str_SGT;

public:
    str_Nodo();
    str_Nodo(Punto*);

    void Set_Punto(Punto*);
    void Set_str_SGT(str_Nodo*);

    Punto* Get_str_Punto();
    str_Nodo* Get_str_SGT();
    ~str_Nodo();
};

#endif // STR_NODO_H
