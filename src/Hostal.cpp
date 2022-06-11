#include "../include/Hostal.h"

Hostal::Hostal(string nombre, string direccion, int telefono) {
    this->nombre = nombre;
    this->direccion = direccion;
    this->telefono = telefono;
}

//Como obtiene un Hostal su calificacion promedio?? En el disenio no aparece. El siguiente codigo recorre cada Habitacion
DtHostal Hostal::getDatos() {
    int calificaionPromedio = getCalificacionPromedio();
    return DtHostal(this->nombre, this->direccion, calificaionPromedio);
}

//Mismo problema
DtHostalExt Hostal::getDatosExt() {
    int calificaionPromedio = getCalificacionPromedio();
    list<DtResenia> resenias = getDatosReseniasDeHostal();
    return DtHostalExt(nombre, direccion, calificaionPromedio, resenias);
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
    habitaciones.push_front(hab);
}

void Hostal::agregarEmpleadoAHostal(Empleado *e) {
    empleados.push_front(e);
}

bool Hostal::trabajaEmpleadoEnHostal(Empleado *e) {
    if (!empleados.empty()) {
        auto it = empleados.begin();

        while (it != empleados.end() && ((*it)->getMail() != e->getMail()))
            ++it;

        return it == empleados.end();
    } else
        return false;
}


list<DtHabitacion> Hostal::getInfoDeHabitaciones() {
    list<DtHabitacion> l;
    if (!habitaciones.empty()) {
        list<Habitacion *>::iterator it;
        for (it = habitaciones.begin(); it != habitaciones.end(); ++it)
            l.push_back((*it)->getDatos());
    }
    return l;
}

//Precond: codigo es el codigo de una hab del Hostal
Habitacion *Hostal::getHabitacion(int codigo) {
    auto it = habitaciones.begin();
    while (it != habitaciones.end() && (*it)->getNumero() != codigo)
        ++it;
    return *it;
}

list<DtReserva *> Hostal::getReservasNoCanceladas(string email) {
    list<DtReserva *> l;
    auto it = habitaciones.begin();
    while (it != habitaciones.end()) {
        l.merge((*it)->getReservasAsociadas(email));
        ++it;
    }
    return l;
}

//Asumo que el telefono identifica a un Hostal
bool Hostal::esEsteHostal(Hostal *h) { //Boolean ¿? No me convence
    return telefono == h->getTelefono();
}

//Al DC le falta decir que el resultado es la concatenacion de todos sdr de habitaciones
list<DtResenia *> Hostal::getReseniasSinResponder() {
    list<DtResenia *> l;
//    auto it = habitaciones.begin();
//    while (it != habitaciones.end()) {
//        l.merge((*it)->getReseniasSinResponder());
//        ++it;
//    }
    return l;
}

// TODO: si no se usa en el hostal controller borrar
////Esta op. pareceria no estar siendo usada en ningun DC
//Hostal Hostal::getHostalSiTrabaja(Empleado* emp){
//    string nom = "";
//    string dir = "";
//    return Hostal(nom, dir, 0);
//}


bool Hostal::habitacionPerteneceAHostal(Habitacion *hab) {
    if (!habitaciones.empty()) {
        auto it = habitaciones.begin();

        while (it != habitaciones.end() && (*it)->getNumero() != hab->getNumero())
            ++it;

        return it == habitaciones.end();
    } else
        return false;
}

bool Hostal::operator==(Hostal hostal) {
    return false;
}

int Hostal::getCalificacionPromedio() {
    return 0;
}

list<DtResenia> Hostal::getDatosReseniasDeHostal() {
    return {};
}
