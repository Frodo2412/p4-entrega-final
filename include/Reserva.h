
#ifndef P4_ENTREGA_FINAL_RESERVA_H
#define P4_ENTREGA_FINAL_RESERVA_H


#include "DtEstado.h"
#include "DtReserva.h"
#include "Estadia.h"
#include "Habitacion.h"
#include "Huesped.h"

//En teoria no deberia haber mas include excepto los DtTypes necessarios

class Estadia;

class Huesped;

class Reserva {
protected:
    Huesped *huespedReservante;
    DtEstado estado;
    Estadia *maybeEstadia;

public:
    virtual ~Reserva() = 0;

    Estadia *getEstadia();

    bool isReservaCancelada();

    virtual DtReserva getDatos() = 0;

    virtual bool tieneHuespedAsociado(string basicString) = 0;
};


#endif//P4_ENTREGA_FINAL_RESERVA_H
