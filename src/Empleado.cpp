//
// Created by unzip on 09/06/22.
//

#include "Empleado.h"
#include "DtEmpleado.h"

DtUsuario Empleado::getDatos() {
    return DtEmpleado(nombre, mail, cargo);
}
DtCargo Empleado::getCargo() {
    return Limpieza;
}
DtCargo Empleado::setCargo(DtCargo cargo) {
    return Limpieza;
}
Empleado::Empleado(string nombre1, string mail1, string password1, string nombre, string mail, string password, DtCargo cargo) : Usuario(nombre1,mail1,password1) {
}
