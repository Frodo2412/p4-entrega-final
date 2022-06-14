
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
    map<string ,Huesped *> huespedes;
    Resenia *calificacion;
 //   Habitacion *hab;
public:
    Estadia(DtFecha checkIn,Huesped *reservante,    map<string ,Huesped *> invitados, Reserva *reserva);

    Estadia(DtFecha checkIn, Huesped *reservante, Reserva *reserva);

    DtEstadia getDatos();

    void finalizarActiva();

    Resenia *getResenia();

    bool hasResenia();

    bool hasReseniaSinResponder();

    void destruirAsociaciones();

    bool isAbierta();

    void setCheckOut(DtFecha fecha);

    Resenia setResenia(Resenia *r);

    void setReserva(Reserva *res);
};


#endif //P4_ENTREGA_FINAL_ESTADIA_H
