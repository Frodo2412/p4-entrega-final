
#ifndef P4_ENTREGA_FINAL_RESERVAGRUPAL_H
#define P4_ENTREGA_FINAL_RESERVAGRUPAL_H


#include "Reserva.h"
#include "Huesped.h"
#include "DtReservaGrupal.h"

class ReservaGrupal : public Reserva {
private:
    map<string ,Huesped *> huespedes;
public:
    bool tieneHuespedAsociado(string email) override;

    DtReservaGrupal *getDatos() override;

    int getCosto() override;

    virtual Estadia createEstadia(DtFecha checkIn) =0;

};


#endif //P4_ENTREGA_FINAL_RESERVAGRUPAL_H
