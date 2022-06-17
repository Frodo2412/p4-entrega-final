
#ifndef P4_ENTREGA_FINAL_HOSTALCONTROLLER_H
#define P4_ENTREGA_FINAL_HOSTALCONTROLLER_H

#include "../infrastructure/IHostalController.h"
#include "../include/ReservaController.h"
#include "../include/UsuarioController.h"

class HostalController : public IHostalController {
private:
    map<string, Hostal *> hostales;
    Empleado *empleadoAux;
    DtCargo cargoAux;
    Hostal *hostalAux;
    int num;
    int precio;
    int capacidad;
    static HostalController *instancia;

    HostalController();

public:
    Empleado *getEmpleado() override;

    Hostal *getHostal() override;

    list<Hostal *> getHostales() override;

    list <DtHostal> mostrarHostales() override;

    list <DtResenia> masInformacionSobreHostal(string nombre) override;

    list <DtEmpleado> mostrarDesempleados() override;

    void cancelarContratoEmpleado() override;

    void confirmarContratoEmpleado() override;

    void seleccionarEmpleado(string email, DtCargo cargo) override;

    void altaHostal(string nombre, string direccion, int telefono) override;

    Hostal *findHostal(Empleado *empleado) override;

    void elegirHostal(string nombre) override;

    list <DtHostal> mostrarTop3Hostales() override;

    DtHostalExt informacionHostal() override;

    void ingresarDatosHabitacion(int numero, int precioPorNoche, int capacidadMaxima);

    void cancelarAltaHabitacion();

    void confirmarAltaHabitacion();

    ~HostalController();

    static HostalController *getInstance();
};


#endif//P4_ENTREGA_FINAL_HOSTALCONTROLLER_H
