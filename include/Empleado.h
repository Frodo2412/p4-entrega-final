//
// Created by guillermorey on 6/8/22.
//

#ifndef P4_ENTREGA_FINAL_EMPLEADO_H
#define P4_ENTREGA_FINAL_EMPLEADO_H

#include "../datatypes/DtEmpleado.h"
#include "Usuario.h"

class Empleado : public Usuario {
private:
    DtCargo cargo;
public:
    DtEmpleado getDatos();
    void setCargo(DtCargo cargo);
    Empleado create(string nombre, string email, DtCargo cargo);
};

#endif //P4_ENTREGA_FINAL_EMPLEADO_H
