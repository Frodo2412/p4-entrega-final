//
// Created by unzip on 09/06/22.
//

#ifndef P4_ENTREGA_FINAL_EMPLEADO_H
#define P4_ENTREGA_FINAL_EMPLEADO_H

#include "DtCargo.h"
#include "Hostal.h"
#include "Usuario.h"

//No deberia precisar mas clases que estas a menos de Dt


//TODO:Falta implementar
class Empleado : public Usuario {
DtCargo cargo;
public:
    Empleado(string nombre1, string mail1, string password1, string nombre, string mail, string password, DtCargo cargo);

    DtUsuario getDatos() override;

    DtCargo getCargo();

    DtCargo setCargo(DtCargo cargo);


};


#endif//P4_ENTREGA_FINAL_EMPLEADO_H
