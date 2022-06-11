
#ifndef P4_ENTREGA_FINAL_RESERVA_H
#define P4_ENTREGA_FINAL_RESERVA_H


#include "DtEstado.h"
#include "DtReserva.h"
#include "Estadia.h"
#include "Habitacion.h"
#include "Huesped.h"

class Estadia;

class Huesped;

class Habitacion;

class Hostal;

class Resenia;

class Reserva {
protected:
    int codigo;
    DtFecha checkIn, checkOut;
    DtEstado estado;
    Huesped *huespedReservante;
    Habitacion *habitacion;
    Estadia *maybeEstadia;

    void setCodigoGenerado();

public:
    Reserva(DtFecha checkIn, DtFecha checkOut, Huesped *huespedReservante, Habitacion *habitacion);

    Estadia *getEstadia();

    virtual int getCosto() = 0;

    Huesped *getReservante();

    void setEstado(DtEstado estado);

    void setReservante(Huesped *huesped);

    void configReserva(Huesped *huespedReservante);

    virtual DtReserva *getDatos() = 0;

    Estadia createEstadia(DtFecha fecha);

    void finalizarReservaActiva();

    list<DtResenia> getReseniasSinResponder();

    Resenia *getResenia();

    bool checkIfSameHostal(Hostal hostal);

    Habitacion *getHabitacion();

    bool isReservaCancelada();

    virtual bool tieneHuespedAsociado(string basicString) = 0;

};


#endif//P4_ENTREGA_FINAL_RESERVA_H
