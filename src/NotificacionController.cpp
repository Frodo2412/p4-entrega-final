
#include "../include/NotificacionController.h"
#include <list>
#include <algorithm>

list<DtEmpleado *> NotificacionController::mostrarEmpleados() {
    UsuarioController *uc = UsuarioController::getInstance();
    return uc->getEmpleados();
}

void NotificacionController::suscribirANotificaciones(string email) {
    UsuarioController *uc = UsuarioController::getInstance();
    Empleado *e = uc->findEmpleado(email);
    agregarObserver(e);
}

list<DtNotificacion> NotificacionController::consultaDeNotificaciones(string email) {    //Cambio de tipo (no es void)
    UsuarioController *uc = UsuarioController::getInstance();
    Empleado *e = uc->findEmpleado(email);
    if (std::find(observers.begin(), observers.end(), e) == observers.end())
        throw invalid_argument("El empleado ingresado no tiene suscripciones activas.");
    return e->getNotificaciones();
}

void NotificacionController::eliminarSubscripcion(string email) {
    UsuarioController *uc = UsuarioController::getInstance();
    Empleado *e = uc->findEmpleado(email);
    if (std::find(observers.begin(), observers.end(), e) == observers.end())
        throw invalid_argument("El empleado ingresado no tiene suscripciones activas.");
    eliminarObserver(e);
}

void NotificacionController::notificar(DtNotificacion notif) {
    for (auto e: observers) e->notify(notif);
}

Resenia *NotificacionController::getResenia() {
    return reseniaAux;
}

Estadia *NotificacionController::getEstadia() {
    return estadiaAux;
}

list<DtEstadia> NotificacionController::mostrarEstadiasFinalizadas(string email) {
    ReservaController *rc = ReservaController::getInstance();
    return rc->mostrarEstadiasFinalizadas(email);

}

list<DtHostal> NotificacionController::mostrarHostales() {
    HostalController *ch = HostalController::getInstance();
    return ch->mostrarHostales();
}

list<DtResenia> NotificacionController::mostrarComentariosSinResponder(string email) {
    UsuarioController *usuarioController = UsuarioController::getInstance();
    Empleado *empleados = usuarioController->getEmpleado(email);

    HostalController *hostalController = HostalController::getInstance();
    Hostal *hostal = hostalController->findHostal(empleados);  //Cambiar tipo de la op findHostal (no es void)

    return hostal->getReseniasSinResponder();
}


void NotificacionController::elegirComentario(int idReserva) {
    ReservaController *rc = ReservaController::getInstance();
    reseniaAux = rc->getResenia(idReserva);
}

void NotificacionController::elegirHostal(string nombre) {
    HostalController *ch = HostalController::getInstance();
    ch->elegirHostal(nombre);
    hostalAux = ch->getHostal();
}

void NotificacionController::enviarComentario(string comentario) {
    auto com = new Comentario(comentario);
    reseniaAux->setComentario(com);
    reseniaAux = nullptr;
}

void NotificacionController::ingresarCalificacion(int calificacion, string comentario) {
    UsuarioController *uc = UsuarioController::getInstance();
    Huesped *huesped = uc->findHuesped(mailAux);

    Reloj *clock = Reloj::getInstance();
    DtFecha fechaActual = clock->getFechaActual();

    auto resenia = new Resenia(calificacion, fechaActual, comentario, estadiaAux);
    resenia->setAutor(huesped);
    DtNotificacion notificacion = resenia->getNotificacion();
    estadiaAux->setResenia(resenia);
    resenias.push_back(resenia);

    notifyObservers(notificacion);
}


void NotificacionController::agregarObserver(Observer *observer) {
    observers.push_back(observer);
}


void NotificacionController::eliminarObserver(Observer *observer) {
    observers.remove(observer);
}

void NotificacionController::notifyObservers(DtNotificacion notificacion) {
    for (auto observer: observers) observer->notify(notificacion);
}

NotificacionController *NotificacionController::instancia = nullptr;

NotificacionController *NotificacionController::getInstance() {
    if (instancia == nullptr) {
        instancia = new NotificacionController();
    }
    return instancia;
}

void NotificacionController::seleccionarEstadia(int codigoReserva) {
    ReservaController *rc = ReservaController::getInstance();
    estadiaAux = rc->findEstadia(codigoReserva);
}

list<DtHuesped *> NotificacionController::mostrarHuespedes() {
    UsuarioController *uc = UsuarioController::getInstance();
    return uc->getHuespedes();
}

void NotificacionController::setMail(string email) {
    mailAux = email;
}
