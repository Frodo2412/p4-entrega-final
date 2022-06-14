//
// Created by unzip on 09/06/22.
//

#ifndef P4_ENTREGA_FINAL_HOSTALCONTROLLER_H
#define P4_ENTREGA_FINAL_HOSTALCONTROLLER_H

#include "../infrastructure/IHostalController.h"

//TODO: Implementar
class HostalController : public IHostalController {
private:
    list<Hostal> hostales;
    list<Habitacion> habitaciones;
    Huesped *huespedAux;
    Empleado *empleadoAux;
    DtCargo cargoAux;
    Hostal *hostalAux;
    HostalController *instancia;

public:
    Empleado *getEmpleado() override;
    Hostal *getHostal() override;
    DtResenia getCalificacion() override;
    list<Hostal *> getHostales() override;
    list<DtHostal> mostrarHostales() override;
    list<DtResenia> masInformacionSobreHostal(string nombre) override;
    list<DtEmpleado> mostrarDesempleados() override;
    void cancelarContratoEmpleado() override;
    Empleado *seleccionarEmpleado(string email, DtCargo cargo) override;
    void altaHostal(string nombre, string direccion, int telefono) override;
    Hostal* findHostal(Empleado *empleado) override;
    void elegirHostal(string nombre) override;
    void cancelarAltaHabitacion() override;
    static HostalController* getInstance();
};


#endif//P4_ENTREGA_FINAL_HOSTALCONTROLLER_H
