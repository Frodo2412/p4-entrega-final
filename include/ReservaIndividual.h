
#ifndef P4_ENTREGA_FINAL_RESERVAINDIVIDUAL_H
#define P4_ENTREGA_FINAL_RESERVAINDIVIDUAL_H


#include "../datatypes/DtReservaIndividual.h"
#include "Reserva.h"

class ReservaIndividual : public Reserva {
public:
    ReservaIndividual(DtFecha checkIn, DtFecha checkOut, Huesped *huespedReservante, Habitacion *habitacion);

    DtReservaIndividual *getDatos() override;

    bool tieneHuespedAsociado(string email) override;

    int getCosto() override;

    Estadia *createEstadia(DtFecha checkIn) override;

};


#endif //P4_ENTREGA_FINAL_RESERVAINDIVIDUAL_H
