//
// Created by unzip on 09/06/22.
//

#ifndef P4_ENTREGA_FINAL_USUARIOCONTROLLER_H
#define P4_ENTREGA_FINAL_USUARIOCONTROLLER_H

#include "../infrastructure/IUsuarioController.h"

#include <map>


class UsuarioController : public IUsuarioController {
private:
    map<string, Usuario *> usuarios;
    map<string, Empleado *> empleados;
    map<string, Huesped *> huespedes;
    Empleado *empleadoAux;
    Huesped *huespedAux;
    DtCargo *cargoAux;
    string nombreAux;
    string emailAux;
    string passwordAux;
    bool esFingerAux;
    static UsuarioController *instancia;
    UsuarioController();

public:
    Empleado *getEmpleado(string email);
    list<DtEmpleado> getEmpleadosDesemplados(Hostal * hostal);
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
    ~UsuarioController();
    static UsuarioController *getInstance();

    //Agregada
    list<DtEmpleado> getEmpleados();
};


#endif//P4_ENTREGA_FINAL_USUARIOCONTROLLER_H
