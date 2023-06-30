#include "lista.h"

//******Método inicioliza la estructura de gestion con los punteros a NULL
//******y la cantidad a cero
Lista::Lista()
{   Inicio = nullptr;
    Actual = nullptr;
    Anterior = nullptr;
    Final = nullptr;
    cantidad = 0;
}

Lista::~Lista(){
    str_Nodo* suprimido;
    suprimido = Inicio;
    Inicio = Inicio->Get_str_SGT();
    Actual = Inicio;
    delete suprimido;
    cantidad--;
    suprimido = nullptr;
}


//******Método que inserta los nodos en la cabeza de la lista
void Lista::Insertar_Inicio(str_Nodo* Nuevo){
    if(cantidad != 0){
        Nuevo->Set_str_SGT(Inicio);
        Inicio = Nuevo;
        Actual = Nuevo;
        cantidad++;
    }else{
        Inicio = Nuevo;
        Final = Nuevo;
        Actual = Nuevo;
        cantidad++;
    }
}

//******Método que inserta por orden
void Lista::Insertar_Por_Orden(str_Nodo* Nuevo){
    int i = 0;
    Actual = Inicio;
    Anterior = Actual;
    if(cantidad != 0){
        for(; i < cantidad &&  Actual->Get_str_Punto()->Get_Y() - Nuevo->Get_str_Punto()->Get_Y() > 0; i++){
            Anterior = Actual;
            Actual = Actual->Get_str_SGT();

        }
        if(i == 0)Insertar_Inicio(Nuevo);
        else{
            Anterior->Set_str_SGT(Nuevo);
            Nuevo->Set_str_SGT(Actual);
            cantidad++;
        if(i == cantidad) Final = Nuevo;
    }
    }else Insertar_Inicio(Nuevo);
}

void Lista::Set_Inicio(str_Nodo* otro){Inicio = otro;}
void Lista::Set_Actual(str_Nodo* otro){Actual = otro;}
void Lista::Set_Anterior(str_Nodo* otro){Anterior = otro;}
void Lista::Set_Final(str_Nodo* otro){Final = otro;}

str_Nodo* Lista::Get_Inicio(){ return Inicio;}
str_Nodo* Lista::Get_Actual(){return Actual;}
str_Nodo* Lista::Get_Anterior(){return Anterior;}
str_Nodo* Lista::Get_Final(){return Final;}
int Lista::Get_Cantidad(){return cantidad;}


