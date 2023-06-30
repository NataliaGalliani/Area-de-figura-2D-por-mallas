#include "str_nodo.h"

str_Nodo::str_Nodo(){
    str_Punto = nullptr;
    str_SGT = nullptr;
}
//******Método que carga el item e inicializa el str_SGT a NULL
str_Nodo::str_Nodo(Punto* un_Punto){
    str_Punto = un_Punto;
    str_SGT = nullptr;
}

void str_Nodo::Set_str_SGT(str_Nodo* str_SGT_){
    str_SGT = str_SGT_;
}
Punto* str_Nodo::Get_str_Punto(){
    return str_Punto;
}
str_Nodo* str_Nodo::Get_str_SGT(){
    return str_SGT;
}
str_Nodo::~str_Nodo(){
    str_Punto = nullptr;
    str_SGT = nullptr;
}
