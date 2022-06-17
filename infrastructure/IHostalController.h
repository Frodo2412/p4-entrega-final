//
// Created by unzip on 09/06/22.
//

#ifndef P4_ENTREGA_FINAL_IHOSTALCONTROLLER_H
#define P4_ENTREGA_FINAL_IHOSTALCONTROLLER_H

#include "../datatypes/DtEmpleado.h"
#include "../include/Empleado.h"
#include "../include/Hostal.h"
#include "../include/Huesped.h"
#include "../include/Resenia.h"


#include <list>
#include <vector>

class IHostalController {
public:
    virtual Empleado* getEmpleado() = 0;
    virtual Hostal* getHostal() = 0;
    virtual list<Hostal*> getHostales() = 0;
    virtual list<DtHostal> mostrarHostales() = 0;
    virtual list<DtResenia> masInformacionSobreHostal(string nombre) = 0;
    virtual list<DtEmpleado> mostrarDesempleados() = 0;
    virtual void cancelarContratoEmpleado() = 0;
    virtual void confirmarContratoEmpleado() = 0;
    virtual void seleccionarEmpleado(string email, DtCargo cargo) = 0;
    virtual void altaHostal(string nombre, string direccion, int telefono) = 0;
    virtual Hostal* findHostal(Empleado* empleado) = 0;
    virtual Hostal* findHostal(string nombre) = 0;
    virtual void elegirHostal(string nombre) = 0;
    virtual DtHostalExt informacionHostal() = 0;
    virtual list<DtHostal> mostrarTop3Hostales() = 0;
    virtual void ingresarDatosHabitacion(int num, int precio, int capacidad) = 0;
    virtual void cancelarAltaHabitacion() = 0;
    virtual void confirmarAltaHabitacion() = 0;
};

#endif//P4_ENTREGA_FINAL_IHOSTALCONTROLLER_H
