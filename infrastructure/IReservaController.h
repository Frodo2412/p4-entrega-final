//
// Created by unzip on 09/06/22.
//

#ifndef P4_ENTREGA_FINAL_IRESERVACONTROLLER_H
#define P4_ENTREGA_FINAL_IRESERVACONTROLLER_H


#include "DtEstadia.h"
#include "DtHabitacion.h"
#include "Estadia.h"
#include "Hostal.h"
#include "HostalController.h"
#include "Huesped.h"
#include "Reloj.h"
#include "Resenia.h"
#include "Reserva.h"
#include "UsuarioController.h"

#include <list>


class IReservaController {
public:
    virtual Habitacion *getHabitacion() = 0;

    virtual Huesped *getReservante() = 0;

    virtual list<Huesped *> getInvitados() = 0;

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

    virtual list<DtEstadia> mostrarInformacionEstadia() = 0;

    virtual list<DtReserva *> mostrarReservas() = 0;

    virtual list<DtHabitacion> mostrarHabitaciones() = 0;

    virtual void registrarEstadia(int idReserva) = 0;

    virtual list<DtReserva *> mostrarReservasNoCanceladas(string email) = 0;

    virtual void finalizarReservasActivasDeUsuario(string email) = 0;

    virtual list<DtEstadia> mostrarEstadiasFinalizadas(string email) = 0;

    virtual void cancelarReserva() = 0;

    virtual list<DtEstadia> listarEstadias() = 0;

    virtual list<DtReserva *> verCalificaciones() = 0;

    virtual DtReserva *verReserva() = 0;

    virtual void especificarFechas(DtFecha chekIn, DtFecha chekOut) = 0;

    virtual void elegirHostal(string nombre) = 0;

    virtual list<DtHostal> mostrarHostales() = 0;

    virtual list<DtReserva *> informacionReservas() = 0;

    virtual void eliminarReserva(int codigoReserva) = 0;

    virtual void cancelarBajaReserva() = 0;

    virtual void confirmarBajaReserva() = 0;

    virtual Estadia *findEstadia(int idReserva) = 0;
};

#endif//P4_ENTREGA_FINAL_IRESERVACONTROLLER_H