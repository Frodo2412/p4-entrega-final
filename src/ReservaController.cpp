//
// Created by unzip on 09/06/22.
//

#include "ReservaController.h"
Habitacion *ReservaController::getHabitacion() {
    return nullptr;
}
Huesped *ReservaController::getReservante() {
    return nullptr;
}
list<Huesped *> ReservaController::getInvitados() {
    return list<Huesped *>();
}
Estadia *ReservaController::getEstadia() {
    return nullptr;
}
Resenia *ReservaController::getResenia(int idReserva) {
    return nullptr;
}
DtFecha ReservaController::getCheckIn() {
    return DtFecha();
}
DtFecha ReservaController::getCheckOut() {
    return DtFecha();
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
    return list<DtHuesped>();
}
list<DtEstadia> ReservaController::mostrarInformacionEstadia() {
    return list<DtEstadia>();
}
list<DtReserva> ReservaController::mostrarReservas() {
    return list<DtReserva>();
}
list<DtHabitacion> ReservaController::mostrarHabitaciones() {
    return list<DtHabitacion>();
}
void ReservaController::registrarEstadia(int idReserva) {
}
list<DtReserva> ReservaController::mostrarReservasNoCanceladas(string email) {
    return list<DtReserva>();
}
void ReservaController::finalizarReservasActivasDeUsuario(string email) {
}
list<DtEstadia> ReservaController::mostrarEstadiasFinalizadas(string email) {
    return list<DtEstadia>();
}
void ReservaController::cancelarReserva() {
}
list<DtEstadia> ReservaController::listarEstadias() {
    return list<DtEstadia>();
}
list<DtReserva> ReservaController::verCalificaciones() {
    return list<DtReserva>();
}
DtReserva ReservaController::verReserva() {
    return DtReserva(0, DtFecha(), DtFecha(), Abierta, 0);
}
void ReservaController::especificarFechas(DtFecha chekIn, DtFecha chekOut) {
}
void ReservaController::elegirHostal(string nombre) {
}
list<DtHostal> ReservaController::mostrarHostales() {
    return list<DtHostal>();
}
list<DtReserva> ReservaController::informacionReservas() {
    return list<DtReserva>();
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
