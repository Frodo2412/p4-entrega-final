//
// Created by unzip on 09/06/22.
//

#ifndef P4_ENTREGA_FINAL_IHOSTALCONTROLLER_H
#define P4_ENTREGA_FINAL_IHOSTALCONTROLLER_H

#include "DtEmpleado.h"
#include "Empleado.h"
#include "Hostal.h"
#include "Huesped.h"
#include "Resenia.h"
#include "ReservaController.h"
#include "UsuarioController.h"

#include <list>
#include <map>


class IHostalController {
public:
    virtual void ingresarDatosHabitacion(int numero, int cantidad, int precio) = 0;
    virtual void confirmarAltaHabitacion() = 0;
    virtual void confirmarContratoEmpleado() = 0;
    virtual Empleado* getEmpleado() = 0;
    virtual Hostal* getHostal() = 0;
    virtual DtResenia getCalificacion() = 0;
    virtual list<Hostal*> getHostales() = 0;
    virtual list<DtHostal> mostrarHostales() = 0;
    virtual list<DtResenia> masInformacionSobreHostal(string nombre) = 0;
    virtual list<DtHostal> mostrarTop3Hostales() = 0;
    virtual list<DtEmpleado> mostrarDesempleados() = 0;
    virtual void cancelarContratoEmpleado() = 0;
    virtual void seleccionarEmpleado(string email, DtCargo cargo) = 0;
    virtual void altaHostal(string nombre, string direccion, int telefono) = 0;
    virtual Hostal* findHostal(Empleado* empleado) = 0;
    virtual void elegirHostal(string nombre) = 0;
    virtual void cancelarAltaHabitacion() = 0;
    virtual DtHostalExt informacionHostal() = 0;
};

#endif//P4_ENTREGA_FINAL_IHOSTALCONTROLLER_H
