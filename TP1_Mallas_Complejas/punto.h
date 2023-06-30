#ifndef PUNTO_H
#define PUNTO_H
#include <iostream>
#include <cmath>
using namespace std;

//Esta clase representa un punto con coordenadas x y y

class Punto{
    //Atributos de la clase Punto
    int x;
    int y;
public:
    //Constructor por defecto
    Punto();
    //Constructor
    Punto(int, int);
    //Métodos para cargar y enviar los atributos
    void Set_X(int );
    void Set_Y(int );
    int Get_X();
    int Get_Y();
    //Mñetodo que calcula y envia la distancia entre dos puntos
    float Distancia(Punto*);
    //Destructor
    ~Punto();
};

#endif // PUNTO_H
