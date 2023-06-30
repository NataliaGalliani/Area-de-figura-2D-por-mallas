#ifndef MALLA_COMPLEJA_H
#define MALLA_COMPLEJA_H

#include "lista.h"
#include "malla_elemental.h"

//Una malla compleja es una agregación de mallas

class Malla_Compleja
{
    Lista* Lista_;
    Malla_Elemental* elementales;
    unsigned int cantidad;
    float *superficies;
    float superficie;

public:

    Malla_Compleja();
    Malla_Compleja(Lista*);
    void Crea_Malla();

    float Ver_Elementales(int);
    float Superficie();

    ~Malla_Compleja();
};

#endif // MALLA_COMPLEJA_H
