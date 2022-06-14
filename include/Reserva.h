
#ifndef P4_ENTREGA_FINAL_RESERVA_H
#define P4_ENTREGA_FINAL_RESERVA_H


#include "../datatypes/DtEstado.h"
#include "../datatypes/DtReserva.h"
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

    int getCodigo() const;

    Huesped *getReservante();

    bool hasReseniaSinResponder();

    bool hasResenia();

    void setEstado(DtEstado estado);

    void setReservante(Huesped *huesped);

    void configReserva(Huesped *huespedReservante);

    virtual DtReserva *getDatos() = 0;

    void finalizarReservaActiva();

    DtResenia getReseniaSinResponder();

    Resenia *getResenia();

    bool checkIfSameHostal(Hostal *hostal);

    Habitacion *getHabitacion();

    bool isReservaCancelada();

    virtual bool tieneHuespedAsociado(string email) = 0;

    DtEstado getEstado();

    virtual Estadia createEstadia(DtFecha checkIn) = 0;

};


#endif//P4_ENTREGA_FINAL_RESERVA_H
