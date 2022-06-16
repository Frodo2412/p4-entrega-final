
#ifndef P4_ENTREGA_FINAL_EMPLEADO_H
#define P4_ENTREGA_FINAL_EMPLEADO_H

#include "../datatypes/DtEmpleado.h"
#include "Observer.h"
#include "Usuario.h"
#include "Hostal.h"

#include <list>

class Empleado : public Usuario, public Observer {
private:
    DtCargo cargo;
    list<DtNotificacion> notificaciones;
public:
    Empleado(string nombre, string mail, string password, DtCargo cargo);

    void setCargo(DtCargo cargo);

    DtUsuario getDatos() override;

    DtEmpleado getDatosEmpleado();

    DtCargo getCargo();

    void notify(DtNotificacion notif) override;

    list<DtNotificacion> getNotificaciones();
};

#endif //P4_ENTREGA_FINAL_EMPLEADO_H
