
#include "DtEmpleado.h"

#include <utility>

DtEmpleado::DtEmpleado(string nombre, string email, DtCargo cargo) : DtUsuario(std::move(nombre), std::move(email)) {
    this->cargo = cargo;
}


DtCargo DtEmpleado::getCargo() {
    return cargo;
}
