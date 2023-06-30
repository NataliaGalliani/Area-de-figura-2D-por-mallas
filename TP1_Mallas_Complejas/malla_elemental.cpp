#include "malla_elemental.h"

//Constructor por defecto
Malla_Elemental::Malla_Elemental(){
    //Es necesario inicializar los punteros de vertices
    //para su posterior implementacion en la clase
    //Malla_Compleja que tiene un vector dinámico de mallas elementales
    Vertice_Uno = new(Punto);
    Vertice_Dos = new(Punto);
    Vertice_Tres = new(Punto);
    Arista_Uno = 0;
    Arista_Dos = 0;
    Arista_Tres = 0;
    semiperimetro = 0;
    superficie = 0;
}

//Constructor
Malla_Elemental::Malla_Elemental(Punto* uno, Punto* dos, Punto* tres){
    Vertice_Uno = uno;
    Vertice_Dos = dos;
    Vertice_Tres = tres;
    Arista_Uno = 0;
    Arista_Dos = 0;
    Arista_Tres = 0;
    semiperimetro = 0;
    superficie = 0;
}
void Malla_Elemental::Set_Vertice_UNO(Punto* uno){
    Vertice_Uno = uno;
}

void Malla_Elemental::Set_Vertice_DOS(Punto* dos){
    Vertice_Dos = dos;
}
void Malla_Elemental::Set_Vertice_TRES(Punto* tres){
    Vertice_Tres = tres;
}

void Malla_Elemental::Aristas(){
    Arista_Uno = Vertice_Uno->Distancia(Vertice_Dos);
    Arista_Dos = Vertice_Dos->Distancia(Vertice_Tres);
    Arista_Tres = Vertice_Tres->Distancia(Vertice_Uno);
}
void Malla_Elemental::Semiperimetro(){
    Aristas();
    semiperimetro = Arista_Uno*0.5+Arista_Dos*0.5+Arista_Tres*0.5;
}
//Verificamos que los puntos sean o no colineales
bool Malla_Elemental::Colineal(){
    //Si la suma de dos aristas es igual a la tercera
    //O si alguna arista es cero por ser la distancia entre dos puntos iguales...
    if(Arista_Uno + Arista_Dos == Arista_Tres || Arista_Uno + Arista_Tres == Arista_Dos || Arista_Dos + Arista_Tres == Arista_Uno ||Arista_Uno == 0 || Arista_Dos == 0 || Arista_Tres == 0)
        //...retorna false.
        return false;
    else return true;//En otro caso retorna true.
}

void Malla_Elemental::Superficie_Elemental(){
    //Si no es colineal...
    Semiperimetro();
    if(Colineal()){
        //...calcula la superficie y la guarda en el atributo...
        //Método de Heron
        superficie =  sqrt(semiperimetro*(semiperimetro-Arista_Uno)*(semiperimetro-Arista_Dos)*(semiperimetro-Arista_Tres));
    }
    else superficie = 0; // Si no, superficie es cero.
}

//Este método retorna el valor calculado de la superficie
float Malla_Elemental::Superficie(){
    Superficie_Elemental();
    return superficie;
}

Malla_Elemental::~Malla_Elemental(){
    delete Vertice_Uno;
    Vertice_Uno = nullptr;
    delete Vertice_Dos;
    Vertice_Dos = nullptr;
    delete Vertice_Tres;
    Vertice_Tres = nullptr;

}
