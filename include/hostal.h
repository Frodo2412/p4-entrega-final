#ifndef P4_ENTREGA_FINAL_HOSTAL_H
#define P4_ENTREGA_FINAL_HOSTAL_H

#include "habitacion.h"
#include "empleado.h"
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
class habitacion;
class empleado;


class hostal {
private:
    string nombre;
    string direcccion;
    int telefono;

   list<habitacion> habitaciones;
   list<empleado> empleados;

private:
    hostal(string nombre, string direccion, int telefono);

    ~hostal();

    DtHostal getDatos();

    DtHostalExt getDatosExt();

    setNombre(string nombre);

    setMail(string mail);

    setTelefono(int telefono);

    getNombre(string nombre);

    getMail(string mail);

    getTelefono(int telefono);


    agregarHabitacionAHostal(habitacion* hab);

    agregarEmpleadoAHostal(empleado* e);

    bool trabajaEmpleadoEnHostal(empleado e);

    list<habitacion> getInfoDeHabitaciones();

    habitacion* getHabitacion(int codigo);

    list<DtReserva> getReservasNoCanceladas(string email);

    bool esEsteHostal(hostal h); //Boolean ¿? No me convence

    list<DtResenia> getReseniasSinResponder();

    hostal* getHostalSiTrabaja(empleado emp);

    bool habitacionPerteneceAHostal(habitacion hab);
};


#endif //P4_ENTREGA_FINAL_HOSTAL_H
