//
// Created by unzip on 09/06/22.
//

#ifndef P4_ENTREGA_FINAL_IUSUARIOCONTROLLER_H
#define P4_ENTREGA_FINAL_IUSUARIOCONTROLLER_H

#include "../include/Huesped.h"
#include "../include/Empleado.h"


#include <list>

class IUsuarioController {
public:
    virtual Usuario* findUsuario(string email) = 0;
    virtual list<DtEmpleado> getEmpleados() = 0;
    virtual Empleado* getEmpleado(string email) = 0;
    virtual list<DtEmpleado> getEmpleadosDesemplados(Hostal * hostal) = 0;
    virtual list<DtHuesped> getHuespedes() = 0;
    virtual Huesped* findHuesped(string email) = 0;
    virtual list<DtUsuario> mostrarUsuarios() = 0;
    virtual DtUsuario mostrarInformacionUsuario(string email) = 0;
    virtual Empleado* findEmpleado(string email) = 0;
    virtual void especificarEsFinger(bool esFinger) = 0;
    virtual void especificarCargo(DtCargo cargo) = 0;
    virtual void comenzarAltaUsuario(string nombre, string email, string password) = 0;
    virtual void confirmarAltaUsuario() = 0;
    virtual void cancelarAltaUsuario() = 0;
    virtual void ingresarEmail(string email) = 0;
};

#endif//P4_ENTREGA_FINAL_IUSUARIOCONTROLLER_H
