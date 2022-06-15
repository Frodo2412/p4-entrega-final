
#ifndef P4_ENTREGA_FINAL_HOSTAL_H
#define P4_ENTREGA_FINAL_HOSTAL_H

#include "../datatypes/DtHostalExt.h"
#include "../datatypes/DtResenia.h"
#include "../datatypes/DtReserva.h"
#include "Empleado.h"
#include "Habitacion.h"

#include <list>
#include <map>
//No deberian faltar includes a menos de Dts

class Habitacion;

class DtHabitacion;

class Empleado;

class Hostal {
private:
    string nombre;
    string direccion;
    int telefono;
    map<int, Habitacion *> habitaciones;
    map<string, Empleado *> empleados;
public:

    list<DtResenia> getDatosReseniasDeHostal();

    int getCalificacionPromedio();

    Hostal(string nombre, string direccion, int telefono);

    DtHostal getDatos();

    Habitacion *getHabitacion(int numero);

    void agregarHabitacionAHostal(Habitacion *habitacion);

    void agregarEmpleadoAHostal(Empleado *empleado);

    bool trabajaEmpleadoEnHostal(Empleado *empleado);

    list<DtHabitacion> getInfoDeHabitaciones();

    bool checkIfSameHostal(Hostal *otroHostal);

    list<DtResenia> getReseniasSinResponder();

    DtHostalExt getDatosExt();

    bool habitacionPerteneceAHostal(Habitacion *habitacion);

    int getTelefono();

    string getDireccion();

    string getNombre();

    list<DtReserva *> getReservasNoCanceladas(string email);

    list<DtResenia> getResenias();
};


#endif//P4_ENTREGA_FINAL_HOSTAL_H
