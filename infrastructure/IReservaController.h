
#ifndef P4_ENTREGA_FINAL_IRESERVACONTROLLER_H
#define P4_ENTREGA_FINAL_IRESERVACONTROLLER_H


#include "../datatypes/DtEstadia.h"
#include "../datatypes/DtHabitacion.h"
#include "../include/Estadia.h"
#include "../include/Hostal.h"
#include "../include/Huesped.h"
#include "../include/Reloj.h"
#include "../include/Resenia.h"
#include "../include/Reserva.h"


#include <list>


class IReservaController {
public:
    virtual Habitacion *getHabitacion() = 0;

    virtual Huesped *getReservante() = 0;

    virtual map<string, Huesped *> getInvitados() = 0;

    virtual Estadia *getEstadia() = 0;

    virtual Resenia *getResenia(int idReserva) = 0;

    virtual DtFecha getCheckIn() = 0;

    virtual DtFecha getCheckOut() = 0;

    virtual Hostal *getHostal() = 0;

    virtual void elegirHuesped(string email) = 0;

    virtual void elegirHuespedReservante(string email) = 0;

    virtual void elegirHabitacion(int numero) = 0;

    virtual void elegirTipoReserva(string reserva) = 0;

    virtual list<DtHuesped> mostrarHuespedes() = 0;

    virtual DtEstadia mostrarInformacionEstadia() = 0;

    virtual list<DtReserva *> mostrarReservas() = 0;

    virtual list<DtHabitacion> mostrarHabitaciones() = 0;

    virtual void registrarEstadia(int idReserva) = 0;

    virtual list<DtReserva *> mostrarReservasNoCanceladas(string email) = 0;

    virtual void finalizarReservasActivasDeUsuario(string email) = 0;

    virtual list<DtEstadia> mostrarEstadiasFinalizadas(string email) = 0;

    virtual void cancelarReserva() = 0;

    virtual list<DtEstadia> listarEstadias() = 0;

    virtual list<DtEstadia> listarEstadiasOfHostal() = 0;

    virtual DtReserva *verReserva() = 0;

    virtual void especificarFechas(DtFecha checkIn, DtFecha checkOut) = 0;

    virtual void elegirHostal(string nombre) = 0;

    virtual list<DtHostal> mostrarHostales() = 0;

    virtual list<DtReserva *> informacionReservas() = 0;

    virtual void eliminarReserva(int codigoReserva) = 0;

    virtual void cancelarBajaReserva() = 0;

    virtual void confirmarBajaReserva() = 0;

    virtual void confirmarReserva() = 0;

    virtual Estadia *findEstadia(int idReserva) = 0;

    virtual void seleccionarEstadia(int codigoReserva) = 0;

    virtual DtResenia verCalificacion() = 0;
};

#endif//P4_ENTREGA_FINAL_IRESERVACONTROLLER_H
