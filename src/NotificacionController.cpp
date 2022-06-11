//
// Created by unzip on 09/06/22.
//

#include "NotificacionController.h"
list<DtEmpleado> NotificacionController::mostrarEmpleados() {
    return list<DtEmpleado>();
}
void NotificacionController::suscribirANotificaciones(string email) {
}
void NotificacionController::consultaDeNotificaciones(string email) {
}
void NotificacionController::eliminarSubscripcion(string email) {
}
void NotificacionController::notificar() {
}
Resenia *NotificacionController::getResenia() {
    return nullptr;
}
Estadia *NotificacionController::getEstadia() {
    return nullptr;
}
list<DtEstadia> NotificacionController::mostrarEstadiasFinalizadas(string email) {
    return list<DtEstadia>();
}
list<DtHostal> NotificacionController::mostrarHostales() {
    return list<DtHostal>();
}
list<DtResenia> NotificacionController::mostrarComentariosSinResponder(string email) {
    return list<DtResenia>();
}
void NotificacionController::elegirComentario(int idReserva) {
}
void NotificacionController::elegirHostal(string nombre) {
}
void NotificacionController::enviarComentario(string comentario) {
}
void NotificacionController::ingresarCalificacion(int calificacion, string comentario) {
}
void NotificacionController::agregarObserver(Observer *observer) {
}
void NotificacionController::eliminarObserver(Observer *observer) {
}
void NotificacionController::notifyObservers(DtNotificacion notif) {
}
NotificacionController *NotificacionController::getInstance() {
    return nullptr;
}
