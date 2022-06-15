
#ifndef P4_ENTREGA_FINAL_ESTADIA_H
#define P4_ENTREGA_FINAL_ESTADIA_H

#include "Resenia.h"
#include "Reserva.h"
#include "Reloj.h"
#include "Observer.h"
#include "Habitacion.h"
#include "../datatypes/DtEstadia.h"

class Reserva;

class Resenia;

class Huesped;

class Habitacion;

class Estadia {
private:

    Resenia *maybeResenia;
    DtFecha checkIn;
    DtFecha checkOut;
    string promo;
    Reserva *reserva;
    map<string, Huesped *> huespedes;

public:
    Estadia(DtFecha checkIn, Huesped *reservante, map<string, Huesped *> invitados, Reserva *reserva);

    Estadia(DtFecha checkIn, Huesped *reservante, Reserva *reserva);

    DtEstadia getDatos();

    Reserva * getReserva();

    void finalizarActiva();

    Resenia *getResenia();

    bool hasResenia();

    bool hasReseniaSinResponder();

    bool isAbierta();

    void setCheckOut(DtFecha fecha);

    void setResenia(Resenia *resenia);

    void setReserva(Reserva *res);
};


#endif //P4_ENTREGA_FINAL_ESTADIA_H
