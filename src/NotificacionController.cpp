
#include "NotificacionController.h"
#include <list>

list<DtEmpleado> NotificacionController::mostrarEmpleados() {
    UsuarioController *uc = UsuarioController::getInstance();
    return uc->getEmpleados();
}

void NotificacionController::suscribirANotificaciones(string email) {
    UsuarioController *uc = UsuarioController::getInstance();
    Empleado *e = uc->findEmpleado(email);
    agregarObserver(e);
}

list<DtNotificacion> NotificacionController::consultaDeNotificaciones(string email) {    //Cambio de tipo (no es void)
    /*
    auto it = observers.begin();

    while(it != observers.end() && it->first != email)
        it++;
    if(it != observers.end()){
        Empleado* e = it->second;   //getNotificaciones se implementa en Empleado, pero no puedo tratar al observer como empleado
        return e->getNotificaciones();
    }
    return {};
     */
    UsuarioController *uc = UsuarioController::getInstance();
    Empleado *e = uc->findEmpleado(email);
    return e->getNotificaciones();
}

void NotificacionController::eliminarSubscripcion(string email) {
    UsuarioController *uc = UsuarioController::getInstance();
    Empleado *e = uc->findEmpleado(email);
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
    UsuarioController *uc = UsuarioController::getInstance();
    Empleado *e = uc->getEmpleado(email);

    HostalController *ch = HostalController::getInstance();
    Hostal *h = ch->findHostal(e);  //Cambiar tipo de la op findHostal (no es void)

    return h->getReseniasSinResponder();
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
    Huesped *h = uc->findHuesped(mailAux);

    Reloj *clock = Reloj::getInstance();
    DtFecha fActual = clock->getFechaActual();

    auto c = new Resenia(calificacion, fActual, comentario);
    c->setEstadia(estadiaAux);
    c->setAutor(h);
    DtNotificacion dt = c->getNotificacion();
    estadiaAux->setResenia(c);
    resenias.push_back(c);

    for (auto &observer: observers) {
        observer->notify(dt);
    }
}


void NotificacionController::agregarObserver(Observer *observer) {
    observers.push_back(observer);
}


void NotificacionController::eliminarObserver(Observer *observer) {
    observers.remove(observer);
}

void NotificacionController::notifyObservers(DtNotificacion notif) {
    for (auto e: observers) e->notify(notif);
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
