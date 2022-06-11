#ifndef P4_ENTREGA_FINAL_HOSTAL_H
#define P4_ENTREGA_FINAL_HOSTAL_H


#include "Habitacion.h"
#include "Empleado.h"
#include "../datatypes/DtHostal.h"
#include "../datatypes/DtHostalExt.h"
#include "../datatypes/DtHabitacion.h"

//No hables con extranios??
#include "../datatypes/DtReserva.h"
#include "../datatypes/DtResenia.h"

#include <string>
#include <list>

using std::string;

//Borrar, es para tener ref temprana
class Habitacion;

class Empleado;


class Hostal {
private:
    string nombre;
    string direccion;
    int telefono;

    list<Habitacion> habitaciones;
    list<Empleado> empleados;

private:
    Hostal(string nombre, string direccion, int telefono);

    ~Hostal();

    DtHostal getDatos();

    DtHostalExt getDatosExt();


    void setNombre(string nombre);

    void setDireccion(string direccion);

    void setTelefono(int telefono);

    string getNombre();

    string getDireccion();

    int getTelefono();


    void agregarHabitacionAHostal(Habitacion hab);

    void agregarEmpleadoAHostal(Empleado e);

    bool trabajaEmpleadoEnHostal(Empleado e);

    list<DtHabitacion> getInfoDeHabitaciones();

    Habitacion getHabitacion(int codigo);

    list<DtReserva> getReservasNoCanceladas(string email);

    bool esEsteHostal(Hostal h); //Boolean ¿? No me convence

    list<DtResenia> getReseniasSinResponder();

    Hostal getHostalSiTrabaja(Empleado emp);

    bool habitacionPerteneceAHostal(Habitacion hab);
};


#endif //P4_ENTREGA_FINAL_HOSTAL_H
