
#include "ReservaController.h"
#include "DtReservaIndividual.h"

Habitacion *ReservaController::getHabitacion() {
    return nullptr;
}

Huesped *ReservaController::getReservante() {
    return nullptr;
}

list<Huesped *> ReservaController::getInvitados() {
    return {};
}

Estadia *ReservaController::getEstadia() {
    return nullptr;
}

Resenia *ReservaController::getResenia(int idReserva) {
    return nullptr;
}

DtFecha ReservaController::getCheckIn() {
    return {};
}

DtFecha ReservaController::getCheckOut() {
    return {};
}

Hostal *ReservaController::getHostal() {
    return nullptr;
}

void ReservaController::elegirHuesped(string email) {
}

void ReservaController::elegirHuespedReservante(string email) {
}

void ReservaController::elegirHabitacion(int numero) {
}

void ReservaController::elegirTipoReserva(string reserva) {
}

list<DtHuesped> ReservaController::mostrarHuespedes() {
    return {};
}

DtEstadia ReservaController::mostrarInformacionEstadia() {
    return {"a", "b", 1, {}, {}, "c", 1};
}

list<DtReserva *> ReservaController::mostrarReservas() {
    return {};
}

list<DtHabitacion> ReservaController::mostrarHabitaciones() {
    return {};
}

void ReservaController::registrarEstadia(int idReserva) {
}

list<DtReserva *> ReservaController::mostrarReservasNoCanceladas(string email) {
    return {};
}

void ReservaController::finalizarReservasActivasDeUsuario(string email) {
}

list<DtEstadia> ReservaController::mostrarEstadiasFinalizadas(string email) {
    return {};
}

void ReservaController::cancelarReserva() {
}

void ReservaController::confirmarReserva() {
}

list<DtEstadia> ReservaController::listarEstadias() {
    return {};
}

list<DtReserva *> ReservaController::verCalificaciones() {
    return {};
}

DtReserva *ReservaController::verReserva() {
    return new DtReservaIndividual(0, DtFecha(), DtFecha(), Abierta, 0);
}

void ReservaController::especificarFechas(DtFecha checkIn, DtFecha checkOut) {
}

void ReservaController::elegirHostal(string nombre) {
}

list<DtHostal> ReservaController::mostrarHostales() {
    return {};
}

list<DtReserva *> ReservaController::informacionReservas() {
    return {};
}

void ReservaController::eliminarReserva(int codigoReserva) {
}

void ReservaController::cancelarBajaReserva() {
}

void ReservaController::confirmarBajaReserva() {
}

Estadia *ReservaController::findEstadia(int idReserva) {
    return nullptr;
}

ReservaController *ReservaController::getInstance() {
    return nullptr;
}

int ReservaController::getNextCodigoReserva() {
    currentIdReserva++;
    return currentIdReserva;
}
void ReservaController::seleccionarEstadia(int codigoReserva) {
    estadiaAux = reservas[codigoReserva]->getEstadia();
}
DtResenia ReservaController::verCalificacion() {
    return estadiaAux->getResenia()->getDatos();
}
