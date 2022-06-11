
#ifndef P4_ENTREGA_FINAL_HOSTAL_H
#define P4_ENTREGA_FINAL_HOSTAL_H

#include "Empleado.h"
#include "Habitacion.h"
#include "../datatypes/DtReserva.h"
#include "../datatypes/DtHostalExt.h"
#include "../datatypes/DtResenia.h"

#include <list>
//No deberian faltar includes a menos de Dts

class Habitacion;

class DtHabitacion;

class Empleado;

//TODO: Falta implementar
class Hostal {
private:
    string nombre;
    string direccion;
    int telefono;
    list<Habitacion *> habitaciones;
    list<Empleado *> empleados;

    int getCalificacionPromedio();

    list<DtResenia> getDatosReseniasDeHostal();

public:
    Hostal(string nombre, string direccion, int telefono);

    DtHostal getDatos();

    Habitacion *getHabitacion(int codigo);

    void agregarHabitacionAHostal(Habitacion *habitacion);

    void agregarEmpleadoAHostal(Empleado *empleado);

    bool trabajaEmpleadoEnHostal(Empleado *empleado);

    list<DtHabitacion> getInfoDeHabitaciones();

    bool esEsteHostal(Hostal *otroHostal);

    list<DtResenia *> getReseniasSinResponder();

//    Hostal *getHostalSiTrabaja(Empleado *empleado);

    DtHostalExt getDatosExt();

    bool habitacionPerteneceAHostal(Habitacion *habitacion);

    bool operator==(Hostal hostal);

    int getTelefono();

    string getDireccion();

    string getNombre();

    list<DtReserva *> getReservasNoCanceladas(string email);
};


#endif//P4_ENTREGA_FINAL_HOSTAL_H
