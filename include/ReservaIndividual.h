
#ifndef P4_ENTREGA_FINAL_RESERVAINDIVIDUAL_H
#define P4_ENTREGA_FINAL_RESERVAINDIVIDUAL_H


#include "Reserva.h"

class ReservaIndividual : public Reserva {
public:
    bool tieneHuespedAsociado(string email) override;
};


#endif //P4_ENTREGA_FINAL_RESERVAINDIVIDUAL_H
