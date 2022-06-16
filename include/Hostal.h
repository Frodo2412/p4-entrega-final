
#ifndef P4_ENTREGA_FINAL_HOSTAL_H
#define P4_ENTREGA_FINAL_HOSTAL_H

#include "../datatypes/DtHostalExt.h"
#include "../datatypes/DtResenia.h"
#include "../datatypes/DtReserva.h"
#include "Empleado.h"
#include "Habitacion.h"

#include <list>
#include <map>

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

    string getNombre();

    list<DtReserva *> getReservasNoCanceladas(const string &email);

    bool yaExisteHabitacion(int numero);

};


#endif//P4_ENTREGA_FINAL_HOSTAL_H
