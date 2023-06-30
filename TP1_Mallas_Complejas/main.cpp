
//Realice el modelado de un sistema utilizando programación orientada a objetos
//de modo de representar puntos, superficies elementales y mallas complejas.
//Es de interés para las mallas elementales determinar su área
//y para las mallas complejas determinar la superficie total
//y la cantidad superficies elementales cuya superficie elemental es mayor a un valor.
//Utilice el modelo desarrollado en una aplicación de consola
//que genere una malla como la mostrada (Fig. 1) y presente por pantalla el valor
//de cada superficie elemental, el valor de la superficie completa de la malla
//y cuantas superficies elementales tienen un área mayor
// igual a un valor ingresado por el usuario.


#include <iostream>
#include <ctime>
#include <string>
#include "punto.h"
#include "str_nodo.h"
#include "lista.h"
#include "malla_elemental.h"
#include "malla_compleja.h"


using namespace std;


int Generar_Entero(){

    return rand()%10;
}

int main()
{
    cout << "Este programa genera una malla compleja y luego le pide al usuario que ingrese" << endl;
    cout <<"una superficie para determinar si la superficie de una o mas de las mallas"<< endl;
    cout <<"elementales supera o iguala la ingresada por el usuario." << endl;
    cout <<"Se muestra la superficie total de la malla compleja,"<< endl;
    cout <<"las superficies de las mallas elementales y cuantas superan el valor ingresado por Ud."<< endl<< endl<< endl;

    //Acá vamos a darle un marco a la malla compleja, solo para tener idea de donde esta inscripta

    cout << "La malla compleja esta confinada en un area rectangular de 10" << endl;
    cout << " por 10 unidades de longitud." << endl;

    //Ahora vamos a generar los puntos con los que se crean las mallas elementales
    //"cantidad_de_puntos" es la cantidad de puntos a generar

    srand(time(0));

    int cantidad_de_puntos = Generar_Entero();
    while(cantidad_de_puntos < 3)cantidad_de_puntos = Generar_Entero();

    //Ahora tendremos un conjunto de puntos con los que podmos formar multiples mallas elementales
    //Pero necesitamos saber qué relación hay entre ellos.

    Lista* Lista_ = new Lista();

    for(int i  = 0; i < cantidad_de_puntos; i++){
        Punto* un_Punto = new Punto(Generar_Entero(),Generar_Entero());
        str_Nodo* un_Nodo = new str_Nodo(un_Punto);
        //Y la relación es de orden: Se insertan ordenados de mayor a menor
        //respecto a la coordenada y
        Lista_->Insertar_Por_Orden(un_Nodo);
    }
    //Llevamos el puntero al inicio de la lista y mostramos los puntos ordenados
    Lista_->Set_Actual(Lista_->Get_Inicio() );
    for(int i = 0; i < Lista_->Get_Cantidad(); i++){
        cout << "Punto " << i << ": " << Lista_->Get_Actual()->Get_str_Punto()->Get_X() <<", "<< Lista_->Get_Actual()->Get_str_Punto()->Get_Y() << endl;
        Lista_->Set_Actual(Lista_->Get_Actual()->Get_str_SGT());
    }

    //Creamos un objeto de malla compleja
    cout << endl << "Malla compleja" << endl;

    Malla_Compleja una_malla_Compleja(Lista_);
    //Crea_Malla relaciona lo puntos de tres en tres siguiendo la lista enlazada
    //y evitando la superposición de mallas elementales
    una_malla_Compleja.Crea_Malla();

    //Mostramos las superficies de cada malla elemental
    for(int i = 0; i < Lista_->Get_Cantidad()-2; i++){
        cout << "Malla elemental " << i+1 << ", superficie " << una_malla_Compleja.Ver_Elementales(i) << endl;
    }
    //Mostramos la superficie de la malla compleja
    cout << endl << "Superficie de la malla compleja " << una_malla_Compleja.Superficie() << endl;
    //Interacutamos con el usuario según estipula el problema
    cout << "Ingrese una superficie para contraste con las de las mallas elementales:" << endl;
    string sup_ele_string;
    float sup_elemental = 0;
    int iguales_mayores = 0;
    cin >> sup_ele_string;
    if(isdigit(sup_ele_string[0]) || sup_ele_string[0] == '.'){
           sup_elemental = stof(sup_ele_string);
           for(int i = 0; i < Lista_->Get_Cantidad()-2; i++){
           if(sup_elemental <= una_malla_Compleja.Ver_Elementales(i))iguales_mayores++;
        }

         cout << "Las mallas elementales de superficie igual o mayor a la ingresada son: " <<iguales_mayores << endl;

    }


    //Borramos la lista
    delete Lista_;
    Lista_ = nullptr;

    return 0;
}
