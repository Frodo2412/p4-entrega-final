//
// Created by guillermorey on 6/8/22.
//

#include "../include/Empleado.h"

DtEmpleado Empleado::getDatos() {
    return DtEmpleado(this->nombre, this->mail, this->cargo);
};

void Empleado::setCargo(DtCargo cargo) {
    this->cargo = cargo;
};

Empleado Empleado::create(string nombre, string mail, DtCargo cargo) {
    this->nombre = nombre;
    this->mail = mail;
    this->cargo = cargo;
};