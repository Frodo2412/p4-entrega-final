//
// Created by unzip on 09/06/22.
//

#ifndef P4_ENTREGA_FINAL_USUARIOCONTROLLER_H
#define P4_ENTREGA_FINAL_USUARIOCONTROLLER_H

#include "../infrastructure/IUsuarioController.h"

//TODO: Implementar
class UsuarioController : public IUsuarioController {
private:
    list<Usuario *> usuarios;
    list<Empleado *> empleados;
    list<Huesped *> huespedes;
    Empleado *empleadoAux;
    Huesped *huespedAux;
    DtCargo cargoAux;
    string nombreAux;
    string emailAux;
    string passwordAux;
    bool esFingerAux;
    UsuarioController *instancia;

public:
    Empleado *getEmpleado(string email);
    DtEmpleado getDatos(Empleado *empleado);
    Empleado *getEmpleado();
    list<DtEmpleado> getEmpleados();
    list<DtHuesped> getHuespedes();
    Huesped *findHuesped(string email);
    list<DtUsuario> mostrarUsuarios();
    DtUsuario mostrarInformacionUsuario(string email);
    Empleado *findEmpleado(string email);
    void especificarEsFinger(bool esFinger);
    void especificarCargo(DtCargo cargo);
    void comenzarAltaUsuario(string nombre, string email, string password);
    void confirmarAltaUsuario();
    void cancelarAltaUsuario();
    void ingresarEmail(string email);
    static UsuarioController *getInstance();
};


#endif//P4_ENTREGA_FINAL_USUARIOCONTROLLER_H
