//
// Created by User on 7/6/2022.
//

#include "DtHabitacion.h"

DtHabitacion::DtHabitacion(int numero, int capacidad, int precio){
    this->numero = numero;
    this->capacidad = capacidad;
    this->precio = precio;
}

int DtHabitacion::getNumero(){
    return numero;
}

int DtHabitacion::getCapacidad(){
    return capacidad;
}

int DtHabitacion::getPrecio(){
    return precio;
}