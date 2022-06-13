//
// Created by unzip on 09/06/22.
//

#ifndef P4_ENTREGA_FINAL_HOSTALCONTROLLER_H
#define P4_ENTREGA_FINAL_HOSTALCONTROLLER_H

#include "../infrastructure/IHostalController.h"

//TODO: Implementar
class HostalController : public IHostalController {
private:
    map<string,Hostal*> hostales;
    map<int, Habitacion*> habitaciones;
    int numeroAux;
    int cantidadAux;
    int precioAux;
    Huesped *huespedAux;
    Empleado *empleadoAux;
    DtCargo cargoAux;
    Hostal *hostalAux;
    HostalController *instancia;

public:
    void ingresarDatosHabitacion(int numero, int cantidad, int precio);
    void confirmarAltaHabitacion();
    Empleado *getEmpleado() override;
    Hostal *getHostal() override;
    DtResenia getCalificacion() override;
    list<Hostal *> getHostales() override;
    list<DtHostal> mostrarHostales() override;
    list<DtResenia> masInformacionSobreHostal(string nombre) override;
    list<DtEmpleado> mostrarDesempleados() override;
    void cancelarContratoEmpleado() override;
    void seleccionarEmpleado(string email, DtCargo cargo) override;
    void altaHostal(string nombre, string direccion, int telefono) override;
    void findHostal(Empleado *empleado) override;
    void elegirHostal(string nombre) override;
    void cancelarAltaHabitacion() override;
    static HostalController* getInstance();
};


#endif//P4_ENTREGA_FINAL_HOSTALCONTROLLER_H
