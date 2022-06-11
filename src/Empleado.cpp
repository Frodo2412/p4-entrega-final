//
// Created by guillermorey on 6/8/22.
//

#include "../include/Empleado.h"

Empleado::Empleado(string nombre, string mail, string password, DtCargo cargo) : Usuario(std::move(nombre),
                                                                                         std::move(mail),
                                                                                         std::move(password)) {
    this->cargo = cargo;
};

DtUsuario Empleado::getDatos() {
    return DtEmpleado(this->nombre, this->mail, this->cargo);
};

void Empleado::setCargo(DtCargo cargo) {
    this->cargo = cargo;
};

DtCargo Empleado::getCargo() {
    return this->cargo;
}
