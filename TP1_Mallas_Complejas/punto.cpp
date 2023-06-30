#include "punto.h"


//Constructor por defecto
Punto::Punto(){
    x = 0;
    y = 0;
}
//Constructor
Punto::Punto(int x_, int y_){
    x = x_;
    y = y_;
}
//Métodos para cargar y enviar los atributos
void Punto::Set_X(int x_){
    x = x_;
}

void Punto::Set_Y(int y_){
    y = y_;
}

int Punto::Get_X(){
    return x;
}

int Punto::Get_Y(){
    return y;
}
//Método que calcula la distancia
float Punto::Distancia(Punto* otro){
    return sqrt((this->x - otro->x)*(this->x - otro->x) + (this->y-otro->y)*(this->y-otro->y));
}
//Destructor de Punto (no hace nada), el cout está para visualizar la llamada.
Punto::~Punto(){
}
