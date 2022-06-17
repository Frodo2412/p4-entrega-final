
#ifndef P4_ENTREGA_FINAL_RESERVAGRUPAL_H
#define P4_ENTREGA_FINAL_RESERVAGRUPAL_H


#include "../datatypes/DtReservaGrupal.h"
#include "Reserva.h"
#include "Huesped.h"

class ReservaGrupal : public Reserva {
private:
    map<string, Huesped *> huespedes;
public:

    ReservaGrupal(DtFecha checkIn, DtFecha checkOut, Huesped *huespedReservante, Habitacion *habitacion,
                  map<string, Huesped *> invitados);

    bool tieneHuespedAsociado(string email) override;

    DtReservaGrupal *getDatos() override;

    int getCosto() override;

    Estadia *createEstadia(DtFecha checkIn) override;

};


#endif //P4_ENTREGA_FINAL_RESERVAGRUPAL_H
