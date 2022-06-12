#include "../include/Hostal.h"

#include <cmath>
#include <utility>

Hostal::Hostal(string nombreNuevo, string direccionNuevo, int telefonoNuevo) {
    nombre = std::move(nombreNuevo);
    direccion = std::move(direccionNuevo);
    telefono = telefonoNuevo;
}

//Como obtiene un Hostal su calificacion promedio?? En el disenio no aparece. El siguiente codigo recorre cada Habitacion
DtHostal Hostal::getDatos() {
    int calificaionPromedio = getCalificacionPromedio();
    return {this->nombre, this->direccion, calificaionPromedio};
}

//Mismo problema
DtHostalExt Hostal::getDatosExt() {
    int calificaionPromedio = getCalificacionPromedio();
    list<DtResenia> resenias = getDatosReseniasDeHostal();
    return {nombre, direccion, calificaionPromedio, resenias};
}

string Hostal::getDireccion() {
    return direccion;
}

int Hostal::getTelefono() {
    return telefono;
}

string Hostal::getNombre() {
    return nombre;
}


void Hostal::agregarHabitacionAHostal(Habitacion *hab) {
    habitaciones.insert(std::pair<int, Habitacion *>(hab->getNumero(), hab));
}

void Hostal::agregarEmpleadoAHostal(Empleado *e) {
    empleados.insert(std::pair<string, Empleado *>(e->getMail(), e));
}

bool Hostal::trabajaEmpleadoEnHostal(Empleado *e) {
    if (empleados.find(e->getMail()) == empleados.end()) {
        return false;
    } else {
        return true;
    }
}



list<DtHabitacion> Hostal::getInfoDeHabitaciones() {
    map<int, Habitacion *>::iterator itr;
    list<DtHabitacion> lista;
    for (itr = habitaciones.begin(); itr != habitaciones.end(); itr++) {
        lista.push_back(itr->second->getDatos());
    }
    return lista;
}

Habitacion *Hostal::getHabitacion(int numero) {
    return habitaciones[numero];
}

list<DtReserva *> Hostal::getReservasNoCanceladas(string email) {
    map<int, Habitacion *>::iterator itr;
    list<DtReserva *> lista;
    for (itr = habitaciones.begin(); itr != habitaciones.end(); itr++) {
        lista.splice(lista.end(), itr->second->getReservasAsociadas(email));
    }
    return lista;
}


bool Hostal::checkIfSameHostal(Hostal *otroHostal) {
    return nombre == otroHostal->getNombre();
}

//Al DC le falta decir que el resultado es la concatenacion de todos sdr de habitaciones
list<DtResenia> Hostal::getReseniasSinResponder() {
    map<int, Habitacion *>::iterator itrMap;
    list<DtResenia> lista;
    for (itrMap = habitaciones.begin(); itrMap != habitaciones.end(); itrMap++) {
        lista.splice(lista.end(), itrMap->second->getReseniasSinResponder());
    }
    return lista;
}

// TODO: si no se usa en el hostal controller borrar
////Esta op. pareceria no estar siendo usada en ningun DC
//Hostal Hostal::getHostalSiTrabaja(Empleado* emp){
//    string nom = "";
//    string dir = "";
//    return Hostal(nom, dir, 0);
//}


bool Hostal::habitacionPerteneceAHostal(Habitacion *hab) {
    if (habitaciones.find(hab->getNumero()) == habitaciones.end()) {
        return false;
    } else {
        return true;
    }
}

int Hostal::getCalificacionPromedio() {
    map<int, Habitacion *>::iterator itrMap;
    int calificacionPromedio = 0;
    for (itrMap = habitaciones.begin(); itrMap != habitaciones.end(); itrMap++) {
        calificacionPromedio += itrMap->second->getCalificacionPromedio();
    }
    return floor(calificacionPromedio / habitaciones.size());
}

list<DtResenia> Hostal::getDatosReseniasDeHostal() {
    map<int, Habitacion *>::iterator itrMap;
    list<DtResenia> lista;
    for (itrMap = habitaciones.begin(); itrMap != habitaciones.end(); itrMap++) {
        lista.splice(lista.end(), itrMap->second->getResenias());
    }
    return lista;
}
