
#ifndef P4_ENTREGA_FINAL_RESERVACONTROLLER_H
#define P4_ENTREGA_FINAL_RESERVACONTROLLER_H

#include "../infrastructure/IReservaController.h"
#include "../include/HostalController.h"
#include "../include/UsuarioController.h"


#include <list>
#include <map>

class ReservaController : public IReservaController {
private:
    map<int, Reserva *> reservas;
    map<int, Estadia *> estadias;
    Habitacion *habitacionAux;
    map<string, Huesped *> invitadosAux;
    Huesped *huespedReservanteAux;
    Reserva *reservaAux;
    Estadia *estadiaAux;
    string tipoReservaAux;
    DtFecha checkInAux;
    DtFecha checkOutAux;
    Hostal *hostalAux;
    static ReservaController *instance;
    int currentIdReserva = 0;
public:

    ReservaController();

    ~ReservaController();

    Habitacion *getHabitacion() override;

    Huesped *getReservante() override;

    map<string, Huesped *> getInvitados() override;

    Estadia *getEstadia() override;

    Resenia *getResenia(int idReserva) override;

    DtFecha getCheckIn() override;

    DtFecha getCheckOut() override;

    Hostal *getHostal() override;

    void elegirHuesped(string email) override;

    void elegirHuespedReservante(string email) override;

    void elegirHabitacion(int numero) override;

    void elegirTipoReserva(string reserva) override;

    list<DtHuesped*> mostrarHuespedes() override;

    DtEstadia mostrarInformacionEstadia() override;

    list<DtReserva *> mostrarReservas() override;

    list<DtHabitacion> mostrarHabitaciones() override;

    void registrarEstadia(int idReserva) override;

    list<DtReserva *> mostrarReservasNoCanceladas(string email) override;

    void finalizarReservasActivasDeUsuario(string email) override;

    list<DtEstadia> mostrarEstadiasFinalizadas(string email) override;

    void cancelarReserva() override;

    void confirmarReserva() override;

    list<DtEstadia> listarEstadias() override;

    list<DtEstadia> listarEstadiasOfHostal() override;

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

    void seleccionarEstadia(int codigoReserva) override;

    DtResenia verCalificacion() override;

    string getTipoReserva();

    Reserva *getReserva();
};


#endif//P4_ENTREGA_FINAL_RESERVACONTROLLER_H
