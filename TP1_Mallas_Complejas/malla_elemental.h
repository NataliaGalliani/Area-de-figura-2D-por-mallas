#ifndef MALLA_ELEMENTAL_H
#define MALLA_ELEMENTAL_H

#include "punto.h"

//Esta clase representa una malla elemental, un triangulo

class Malla_Elemental
{
    //La superficie elemental tiene tres puntos,
    //dos aristas nos permiten calcular la superficie
    Punto* Vertice_Tres;
    Punto* Vertice_Uno;
    Punto* Vertice_Dos;
    float Arista_Uno;
    float Arista_Dos;
    float Arista_Tres;
    float semiperimetro;
    float superficie;
    //Si los puntos son colineales no se puede calcular el area
    void Aristas();
    bool Colineal();
    void Semiperimetro();
    void Superficie_Elemental();
public:
    //Constructor por defecto
    Malla_Elemental();
    //Constructor
    Malla_Elemental(Punto*, Punto*, Punto*);

    void Set_Vertice_UNO(Punto*);
    void Set_Vertice_DOS(Punto*);
    void Set_Vertice_TRES(Punto*);
    //Destructor
    ~Malla_Elemental();

    float Superficie();

};

#endif // MALLA_ELEMENTAL_H
