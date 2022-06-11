
#ifndef P4_ENTREGA_FINAL_HOSTAL_H
#define P4_ENTREGA_FINAL_HOSTAL_H

#include "Empleado.h"
#include "Habitacion.h"
#include "../datatypes/DtHostalExt.h"
#include "../datatypes/DtResenia.h"

#include <list>
//No deberian faltar includes a menos de Dts

class Habitacion;

class Empleado;

//TODO: Falta implementar
class Hostal {
private:
    string nombre;
    string direccion;
    int telefono;
    //    Set(Habitacion) habitaciones;
    //    Set(Empleado) empleados;
    int getCalificacionPromedio();
    list<DtResenia> getDatosReseniasDeHostal();
public:
    Hostal(string nombre, string direccion, int telefono);
    DtHostal getDatos();
    Habitacion * getHabitacion(int codigo);
    void agregarHabitacionAHostal(Habitacion * habitacion);
    void agregarEmpleadoAHostal(Empleado * empleado);
    void trabajaEmpleadoEnHostal(Empleado * empleado);
//    Set(DtHabitacion) getInfoDeHabitaciones();
    bool esEsteHostal(Hostal* otroHostal);
//    Set(DtReseña) getReseniasSinResponder();
    Hostal * getHostalSiTrabaja(Empleado * empleado);
    DtHostalExt getDatosExt();
    bool habitacionPerteneceAHostal(Habitacion * habitacion);
    bool operator==(Hostal hostal);
};


#endif//P4_ENTREGA_FINAL_HOSTAL_H
