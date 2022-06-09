
#include "../include/hostal.h"

hostal::hostal(string nombre, string direccion, int telefono){
    this->nombre = nombre;
    this->direcccion = direccion;
    this->telefono = telefono;
}

hostal::~hostal(){
    //Implementar

}

//Como obtiene un hostal su calificacion promedio?? En el disenio no aparece. El siguiente codigo recorre cada habitacion
DtHostal* hostal::getDatos(){
    int n, califs = 0;
    iter it = habitaciones.begin();

    while(it != habitaciones.end()){
        n += getCantidadCalificaciones(hab);    //Se explica sola
        califs += getSumaCalificaciones(hab);   //Se explica sola
        ++it;
    }
    int califProm = califs / n;
    return DtHostal(this->nombre, this->direcccion, califs/n);
}

//Mismo problema
DtHostalExt hostal::getDatosExt(){
    int n, califs = 0;
    list<DtResenia> l;
    iter it = habitaciones.begin();

    while(it != habitaciones.end()){
        n += getCantidadCalificaciones(*it);
        califs += getSumaCalificaciones(*it);
        l.merge(getDatosResenias(*it)); //getDatosResenias debe retornar una lista con las resenias asociadas a todas las estadias de hab
        ++it;
    }

    int califProm = califs / n;
    return DtHostalExt(this->nombre, this->direcccion, califs/n, l);
}

hostal::agregarHabitacionAHostal(habitacion hab){
    habitaciones.push_front(hab);
}

hostal::agregarEmpleadoAHostal(empleado e){
    empleados.push_front(e);
}

bool hostal::trabajaEmpleadoEnHostal(empleado e){
    if(!empleados.empty()){
        iterator it = empleados.begin();

        while(it != empleados.back() && getMail(*it) != getMail(e))
            ++it;

        return it == empleados.back();
    } else
        return false;
}


list<DtHabitacion> hostal::getInfoDeHabitaciones(){
    list<DtHabitacion> l;
    if(!habitaciones.empty()){
        iterator it = habitaciones.begin();

        while(it != habitaciones.back()) {
            l.push_back((*it).getDatos());
            it++;
        }
    }
    return l;
    */
}

//Precond: codigo es el codigo de una hab del hostal
habitacion hostal::getHabitacion(int codigo){
    iterator it = habitaciones.begin();
    while(it != habitaciones.end() && getCodigo(*it) != codigo)
        ++it;
    return *it;
}

list<DtReserva> hostal::getReservasNoCanceladas(string email){
    list<DtReserva> l;
    iterator it = habitaciones.begin();
    while(it != habitaciones.end()) {
        l.merge(getReservasAsociadas(email));
        ++it;
    }
    return l;
}

//Asumo que el telefono identifica a un hostal
bool hostal::esEsteHostal(hostal h){ //Boolean ¿? No me convence
    return telefono == getTelefono(h);
}

list<DtResenia> hostal::getReseñasSinResponder(){

}

hostal* hostal::getHostalSiTrabaja(empleado emp){

}

bool hostal::habitacionPerteneceAHostal(habitacion* hab){

}