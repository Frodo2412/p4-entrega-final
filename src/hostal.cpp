#include "../include/hostal.h"

hostal::hostal(string nombre, string direccion, int telefono){
    this->nombre = nombre;
    this->direccion = direccion;
    this->telefono = telefono;
}

hostal::~hostal(){
    //Implementar

}

//Como obtiene un hostal su calificacion promedio?? En el disenio no aparece. El siguiente codigo recorre cada habitacion
DtHostal hostal::getDatos(){
    int n, califs = 0;
    list<habitacion>::iterator it = habitaciones.begin();

    while(it != habitaciones.end()){
        n += (*it).getCantidadCalificaciones();    //Se explica sola
        califs += (*it).getSumaCalificaciones();   //Se explica sola
        ++it;
    }

    return DtHostal(this->nombre, this->direccion, califs/n);
}

//Mismo problema
DtHostalExt hostal::getDatosExt(){
    int n, califs = 0;
    list<DtResenia> l;
    list<habitacion>::iterator it = habitaciones.begin();

    while(it != habitaciones.end()){
        n += (*it).getCantidadCalificaciones();
        califs += (*it).getSumaCalificaciones();
        l.merge((*it).getDatosResenias()); //getDatosResenias debe retornar una lista con las resenias asociadas a todas las estadias de *it
        ++it;
    }

    return DtHostalExt(this->nombre, this->direccion, califs/n, l);
}


void hostal::setNombre(string nombre){
    this->nombre = nombre;
}

void hostal::setDireccion(string direccion){
    this->direccion = direccion;
}

void hostal::setTelefono(int telefono){
    this->telefono = telefono;
}


string hostal::getNombre(){
    return nombre;
}

string hostal::getDireccion(){
    return direccion;
}

int hostal::getTelefono(){
    return telefono;
}


void hostal::agregarHabitacionAHostal(habitacion hab){
    habitaciones.push_front(hab);
}

void hostal::agregarEmpleadoAHostal(empleado e){
    empleados.push_front(e);
}

bool hostal::trabajaEmpleadoEnHostal(empleado e){
    if(!empleados.empty()){
        list<empleado>::iterator it = empleados.begin();

        while(it != empleados.end() && (*it).getMail() != e.getMail())
            ++it;

        return it == empleados.end();
    } else
        return false;
}


list<DtHabitacion> hostal::getInfoDeHabitaciones(){
    list<DtHabitacion> l;
    if(!habitaciones.empty()){
        list<habitacion>::iterator it;

        for(it = habitaciones.begin() ; it != habitaciones.end() ; ++it)
            l.push_back((*it).getDatos());
    }
    return l;
}

//Precond: codigo es el codigo de una hab del hostal
habitacion hostal::getHabitacion(int codigo){
    list<habitacion>::iterator it = habitaciones.begin();
    while(it != habitaciones.end() && (*it).getCodigo() != codigo)
        ++it;
    return *it;
}

list<DtReserva> hostal::getReservasNoCanceladas(string email){
    list<DtReserva> l;
    list<habitacion>::iterator it = habitaciones.begin();
    while(it != habitaciones.end()) {
        l.merge((*it).getReservasAsociadas(email));
        ++it;
    }
    return l;
}

//Asumo que el telefono identifica a un hostal
bool hostal::esEsteHostal(hostal h){ //Boolean ¿? No me convence
    return telefono == h.getTelefono();
}

//Al DC le falta decir que el resultado es la concatenacion de todos sdr de habitaciones
list<DtResenia> hostal::getReseniasSinResponder(){
    list<DtResenia> l;
    list<habitacion>::iterator it = habitaciones.begin();
    while(it != habitaciones.end()) {
        l.merge((*it).getReseniasSinResponder());
        ++it;
    }
    return l;
}

//Esta op. pareceria no estar siendo usada en ningun DC
hostal hostal::getHostalSiTrabaja(empleado emp){
    string nom = "";
    string dir = "";
    return hostal(nom, dir, 0);
}


bool hostal::habitacionPerteneceAHostal(habitacion hab){
    if(!habitaciones.empty()){
        list<habitacion>::iterator it = habitaciones.begin();

        while(it != habitaciones.end() && (*it).getNumero() != hab.getNumero())
            ++it;

        return it == habitaciones.end();
    } else
        return false;
}
