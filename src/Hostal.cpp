#include "../include/Hostal.h"

Hostal::Hostal(string nombre, string direccion, int telefono){
    this->nombre = nombre;
    this->direccion = direccion;
    this->telefono = telefono;
}

Hostal::~Hostal(){
    //Implementar

}

//Como obtiene un Hostal su calificacion promedio?? En el disenio no aparece. El siguiente codigo recorre cada Habitacion
DtHostal Hostal::getDatos(){
    int n, califs = 0;
    list<Habitacion>::iterator it = habitaciones.begin();

    while(it != habitaciones.end()){
        n += (*it).getCantidadCalificaciones();    //Se explica sola
        califs += (*it).getSumaCalificaciones();   //Se explica sola
        ++it;
    }

    return DtHostal(this->nombre, this->direccion, califs/n);
}

//Mismo problema
DtHostalExt Hostal::getDatosExt(){
    int n, califs = 0;
    list<DtResenia> l;
    list<Habitacion>::iterator it = habitaciones.begin();

    while(it != habitaciones.end()){
        n += (*it).getCantidadCalificaciones();
        califs += (*it).getSumaCalificaciones();
        l.merge((*it).getDatosResenias()); //getDatosResenias debe retornar una lista con las resenias asociadas a todas las estadias de *it
        ++it;
    }

    return DtHostalExt(this->nombre, this->direccion, califs/n, l);
}


void Hostal::setNombre(string nombre){
    this->nombre = nombre;
}

void Hostal::setDireccion(string direccion){
    this->direccion = direccion;
}

void Hostal::setTelefono(int telefono){
    this->telefono = telefono;
}


string Hostal::getNombre(){
    return nombre;
}

string Hostal::getDireccion(){
    return direccion;
}

int Hostal::getTelefono(){
    return telefono;
}


void Hostal::agregarHabitacionAHostal(Habitacion hab){
    habitaciones.push_front(hab);
}

void Hostal::agregarEmpleadoAHostal(Empleado e){
    empleados.push_front(e);
}

bool Hostal::trabajaEmpleadoEnHostal(Empleado e){
    if(!empleados.empty()){
        list<Empleado>::iterator it = empleados.begin();

        while(it != empleados.end() && (*it).getMail() != e.getMail())
            ++it;

        return it == empleados.end();
    } else
        return false;
}


list<DtHabitacion> Hostal::getInfoDeHabitaciones(){
    list<DtHabitacion> l;
    if(!habitaciones.empty()){
        list<Habitacion>::iterator it;

        for(it = habitaciones.begin() ; it != habitaciones.end() ; ++it)
            l.push_back((*it).getDatos());
    }
    return l;
}

//Precond: codigo es el codigo de una hab del Hostal
Habitacion Hostal::getHabitacion(int codigo){
    list<Habitacion>::iterator it = habitaciones.begin();
    while(it != habitaciones.end() && (*it).getCodigo() != codigo)
        ++it;
    return *it;
}

list<DtReserva> Hostal::getReservasNoCanceladas(string email){
    list<DtReserva> l;
    list<Habitacion>::iterator it = habitaciones.begin();
    while(it != habitaciones.end()) {
        l.merge((*it).getReservasAsociadas(email));
        ++it;
    }
    return l;
}

//Asumo que el telefono identifica a un Hostal
bool Hostal::esEsteHostal(Hostal h){ //Boolean ¿? No me convence
    return telefono == h.getTelefono();
}

//Al DC le falta decir que el resultado es la concatenacion de todos sdr de habitaciones
list<DtResenia> Hostal::getReseniasSinResponder(){
    list<DtResenia> l;
    list<Habitacion>::iterator it = habitaciones.begin();
    while(it != habitaciones.end()) {
        l.merge((*it).getReseniasSinResponder());
        ++it;
    }
    return l;
}

//Esta op. pareceria no estar siendo usada en ningun DC
Hostal Hostal::getHostalSiTrabaja(Empleado emp){
    string nom = "";
    string dir = "";
    return Hostal(nom, dir, 0);
}


bool Hostal::habitacionPerteneceAHostal(Habitacion hab){
    if(!habitaciones.empty()){
        list<Habitacion>::iterator it = habitaciones.begin();

        while(it != habitaciones.end() && (*it).getNumero() != hab.getNumero())
            ++it;

        return it == habitaciones.end();
    } else
        return false;
}
