#include "malla_compleja.h"

Malla_Compleja::Malla_Compleja(){
    Lista_ = nullptr;
    elementales = nullptr;
    superficies =  nullptr;
    superficie = 0;
    cantidad = 0;
}
Malla_Compleja::Malla_Compleja(Lista* uno){
    cantidad = 0;
    superficie = 0;
    Lista_ = uno;
    cantidad = Lista_->Get_Cantidad()-2;
    elementales = new Malla_Elemental[cantidad];
    superficies =  new float[cantidad];
}

void Malla_Compleja::Crea_Malla(){

    //Tenemos dos clases de triangulos, los que se comportn bien, aux_BD = true
    //y los que no, aux_BD = false
    //La diferencia radica en que los primeros se forman uniendo los punto
    //en zig-zag: tomo el primero, voy a la derecha (o la izquierda) para el siguiente
    //y voy para la izquierda (o derecha) para tomar el tercero. Esto me asegura que
    //las mallas elementales no se superpongan.
    //Los puntos que siempre crecen (o decrecen) en x, van a generar mallas
    //elementales que se terminan solapando.

    bool aux_BD = true;
    //Para evitar estos solapamientos, voy a guardar el primer vértice en aux_UNO
    //cuando aux_BD sea false
    //Y lo voy a usar como vértice en la siguiente malla elemental, en lugar de
    //usar el punto que me hace superposición de triángulos
    Punto* aux_UNO = new Punto;

    //Voy al inicio de la lista
    Lista_->Set_Actual(Lista_->Get_Inicio());

    //Cargo los tres primeros puntos para los vértices V_UNO, V_DOS, V_TRES
    Lista_->Set_Anterior(Lista_->Get_Actual());
    Punto* V_UNO = Lista_->Get_Anterior()->Get_str_Punto();
    aux_UNO = V_UNO;
    Lista_->Set_Actual(Lista_->Get_Actual()->Get_str_SGT());
    Punto* V_DOS = Lista_->Get_Actual()->Get_str_Punto();
    Lista_->Set_Anterior(Lista_->Get_Actual()->Get_str_SGT());
    Punto* V_TRES = Lista_->Get_Anterior()->Get_str_Punto();

    //"derecha" e "izquierda" son booleanas que me permiten saber si voy por el
    //buen camino, en zig-zag, o no
    bool izquierda = (V_UNO->Get_X() > V_DOS->Get_X()) && (V_DOS->Get_X() < V_TRES->Get_X());
    bool derecha = (V_UNO->Get_X() < V_DOS->Get_X()) && (V_DOS->Get_X() > V_TRES->Get_X());

    //Como anticipamos, si voy en zig-zag, aux_BD = true
    if(derecha || izquierda){
        aux_BD = true;
     }else{
        //si no, aux_BD = false
        aux_BD = false;
    }

    //La primer malla puede ser kosher o no,
    //no importa porque no se superpone con nada
    //Armo la primera malla
    elementales[0].Set_Vertice_UNO(aux_UNO);
    elementales[0].Set_Vertice_DOS(V_DOS);
    elementales[0].Set_Vertice_TRES(V_TRES);

    //Calculo el área
    superficies[0] = elementales[0].Superficie();
    //Lo sumo al área de la malla compleja
    superficie += superficies[0];

    //Ahora vamos a hacer lo mismo con el resto de los puntos
    for(int i = 1; i < Lista_->Get_Cantidad()-2; i++){

        Lista_->Set_Anterior(Lista_->Get_Actual());
        V_UNO = Lista_->Get_Anterior()->Get_str_Punto();
        if(aux_BD != false ){
            aux_UNO = V_UNO;
        }
        Lista_->Set_Actual(Lista_->Get_Actual()->Get_str_SGT());
        V_DOS = Lista_->Get_Actual()->Get_str_Punto();
        Lista_->Set_Anterior(Lista_->Get_Actual()->Get_str_SGT());
        V_TRES = Lista_->Get_Anterior()->Get_str_Punto();

        derecha = (V_UNO->Get_X() > V_DOS->Get_X()) && (V_DOS->Get_X() < V_TRES->Get_X());
        izquierda = (V_UNO->Get_X() < V_DOS->Get_X()) && (V_DOS->Get_X() > V_TRES->Get_X());

        if(derecha || izquierda){
            aux_BD = false;
        }else{
            aux_BD = true;
        }

        elementales[i].Set_Vertice_UNO(aux_UNO);
        elementales[i].Set_Vertice_DOS(V_DOS);
        elementales[i].Set_Vertice_TRES(V_TRES);

          superficies[i] = elementales[i].Superficie();

        superficie +=  superficies[i];

    }
}

//Este método `permite ver la superficie de cada malla elemental de la compleja
float Malla_Compleja::Ver_Elementales(int i){
    return superficies[i];
}

//Este método permite ver la superficie total.
float Malla_Compleja::Superficie(){
    return superficie;
}

Malla_Compleja::~Malla_Compleja(){
}
