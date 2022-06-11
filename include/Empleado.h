
#ifndef P4_ENTREGA_FINAL_EMPLEADO_H
#define P4_ENTREGA_FINAL_EMPLEADO_H

#include "../datatypes/DtEmpleado.h"
#include "Usuario.h"

class Empleado : public Usuario {
private:
    DtCargo cargo;
public:
    Empleado(string nombre, string mail, string password, DtCargo cargo);
    void setCargo(DtCargo cargo);
    DtUsuario getDatos() override;
    DtEmpleado getDatosEmpleado();
    DtCargo getCargo();
};

#endif //P4_ENTREGA_FINAL_EMPLEADO_H
