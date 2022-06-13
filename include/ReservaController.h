//
// Created by unzip on 09/06/22.
//

#ifndef P4_ENTREGA_FINAL_RESERVACONTROLLER_H
#define P4_ENTREGA_FINAL_RESERVACONTROLLER_H

#include "../infrastructure/IReservaController.h"

#include <list>
#include <map>
//Deberian estar todos los include desde la interfaz

//TODO: Implementar
class ReservaController : public IReservaController {
private:
    // la lista de estadias se borra aca
    map<int, Reserva *> reservas;
    //Capaz que usar el mismo int de reserva como "Key" de la lista de estadias
    map<int,Estadia *> estadias;
    Habitacion *habitacionAux;
    Huesped *huespedAux;
    Huesped *huespedReservanteAux;
    Estadia *estadiaAux;
    DtCargo tipoReservaAux;
    DtFecha checkInAux;
    DtFecha checkOutAux;
    Hostal *hostalAux;
    ReservaController *instance;
    int currentIdReserva = 0;
public:
    Habitacion *getHabitacion() override;

    Huesped *getReservante() override;

    //Capaz que es mejor que se devuelva un map? Sino esta bien que sea lista
    list<Huesped *> getInvitados() override;

    Estadia *getEstadia() override;

    Resenia *getResenia(int idReserva) override;

    DtFecha getCheckIn() override;

    DtFecha getCheckOut() override;

    Hostal *getHostal() override;

    void elegirHuesped(string email) override;

    void elegirHuespedReservante(string email) override;

    void elegirHabitacion(int numero) override;

    void elegirTipoReserva(string reserva) override;

    list<DtHuesped> mostrarHuespedes() override;

    list<DtEstadia> mostrarInformacionEstadia() override;

    list<DtReserva *> mostrarReservas() override;

    list<DtHabitacion> mostrarHabitaciones() override;

    void registrarEstadia(int idReserva) override;

    list<DtReserva *> mostrarReservasNoCanceladas(string email) override;

    void finalizarReservasActivasDeUsuario(string email) override;

    list<DtEstadia> mostrarEstadiasFinalizadas(string email) override;

    void cancelarReserva() override;

    list<DtEstadia> listarEstadias() override;

    list<DtReserva *> verCalificaciones() override;

    DtReserva *verReserva() override;

    void especificarFechas(DtFecha checkIn, DtFecha checkOut) override;

    void elegirHostal(string nombre) override;

    list<DtHostal> mostrarHostales() override;

    list<DtReserva *> informacionReservas() override;

    void eliminarReserva(int codigoReserva) override;

    void cancelarBajaReserva() override;

    void confirmarBajaReserva() override;

    Estadia *findEstadia(int idReserva) override;

    static ReservaController *getInstance();

    int getNextCodigoReserva();
};


#endif//P4_ENTREGA_FINAL_RESERVACONTROLLER_H
