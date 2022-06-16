
#include "ReservaController.h"
#include "DtReservaIndividual.h"
#include "ReservaGrupal.h"
#include "ReservaIndividual.h"

ReservaController *ReservaController::instance = nullptr;

Habitacion *ReservaController::getHabitacion() {
    return habitacionAux;
}

Huesped *ReservaController::getReservante() {
    return huespedReservanteAux;
}

map<string, Huesped *> ReservaController::getInvitados() {
    return invitadosAux;
}

Estadia *ReservaController::getEstadia() {
    return estadiaAux;
}

Resenia *ReservaController::getResenia(int idReserva) {
    return estadias[idReserva]->getResenia();
}

DtFecha ReservaController::getCheckIn() {
    return checkInAux;
}

DtFecha ReservaController::getCheckOut() {
    return checkOutAux;
}

Hostal *ReservaController::getHostal() {
    return hostalAux;
}

void ReservaController::elegirHuesped(string email) {
    UsuarioController *uc = UsuarioController::getInstance();
    Huesped *huesped = uc->findHuesped(email);
    invitadosAux.insert(pair<string, Huesped *>(huesped->getMail(), huesped));
}

void ReservaController::elegirHuespedReservante(string email) {
    UsuarioController *uc = UsuarioController::getInstance();
    huespedReservanteAux = uc->findHuesped(email);
}

void ReservaController::elegirHabitacion(int numero) {
    Hostal *h = getHostal();
    habitacionAux = h->getHabitacion(numero);
}

void ReservaController::elegirTipoReserva(string reserva) {
    tipoReservaAux = reserva;
}

list<DtHuesped> ReservaController::mostrarHuespedes() {
    UsuarioController *uc = UsuarioController::getInstance();
    return uc->getHuespedes();
}

DtEstadia ReservaController::mostrarInformacionEstadia() {
    return getEstadia()->getDatos();
}

list<DtReserva *> ReservaController::mostrarReservas() {
    list<DtReserva *> infoReservas;
    Hostal *h = getHostal();
    for (auto &it: reservas)
        if (it.second->checkIfSameHostal(h))
            infoReservas.push_back(it.second->getDatos());
    return infoReservas;

}

list<DtHabitacion> ReservaController::mostrarHabitaciones() {
    Hostal *h = getHostal();
    return h->getInfoDeHabitaciones();
}

void ReservaController::registrarEstadia(int idReserva) {
    Reloj *reloj = Reloj::getInstance();
    DtFecha fechaActual = reloj->getFechaActual();
    Reserva *reserva = reservas.find(idReserva)->second;
    Estadia *estadia = reserva->createEstadia(fechaActual);
    estadias.insert(pair<int, Estadia *>(idReserva, estadia));
    reserva->setEstado(DtEstado::Cerrada);
}

list<DtReserva *> ReservaController::mostrarReservasNoCanceladas(string email) {
    Hostal *h = getHostal();
    return h->getReservasNoCanceladas(email);
}

void ReservaController::finalizarReservasActivasDeUsuario(string email) {
    UsuarioController *uc = UsuarioController::getInstance();
    Huesped *huesped = uc->findHuesped(email);
    huesped->finalizarReservaActiva();
}

list<DtEstadia> ReservaController::mostrarEstadiasFinalizadas(string email) {
    list<DtEstadia> infoEstadias;
    for (auto &it: estadias)
        if (it.second->getReserva()->getReservante()->getMail() == email)
            infoEstadias.push_back(it.second->getDatos());
    return infoEstadias;
}

void ReservaController::cancelarReserva() {
    invitadosAux = {};
    huespedReservanteAux = nullptr;
    estadiaAux = nullptr;
    tipoReservaAux = "";
    checkInAux = {};
    checkOutAux = {};
    hostalAux = nullptr;
}

void ReservaController::confirmarReserva() {
    Habitacion *habitacion = getHabitacion();
    Huesped *reservante = getReservante();
    DtFecha checkIn = getCheckIn();
    DtFecha checkOut = getCheckOut();
    string tipoRes = getTipoReserva();
    Reserva *reserva;
    if (tipoRes == "Grupal") {
        map<string, Huesped *> huespedes = getInvitados();
        reserva = new ReservaGrupal(checkIn, checkOut, reservante, habitacion, huespedes);
        for (auto &it: invitadosAux)
            it.second->agregarReserva(reserva);
    } else reserva = new ReservaIndividual(checkIn, checkOut, reservante, habitacion);

    reserva->configReserva(reservante);
    reservante->agregarReserva(reserva);
    reservas.insert(pair<int, Reserva *>(reserva->getCodigo(), reserva));
}

list<DtEstadia> ReservaController::listarEstadias() {
    list<DtEstadia> infoEstadias;
    for (auto &it: estadias)
        infoEstadias.push_back(it.second->getDatos());
    return infoEstadias;
}

DtReserva *ReservaController::verReserva() {
    return getEstadia()->getDatosReserva();
}

void ReservaController::especificarFechas(DtFecha checkIn, DtFecha checkOut) {
    checkInAux = checkIn;
    checkOutAux = checkOut;
}

void ReservaController::elegirHostal(string nombre) {
    HostalController *ch = HostalController::getInstance();
    ch->elegirHostal(nombre);
    hostalAux = ch->getHostal();
}

list<DtHostal> ReservaController::mostrarHostales() {
    HostalController *hc = HostalController::getInstance();
    return hc->mostrarHostales();
}

list<DtReserva *> ReservaController::informacionReservas() {
    list<DtReserva *> infoReservas;
    Hostal *h = getHostal();
    for (auto &it: reservas)
        if (it.second->checkIfSameHostal(h))
            infoReservas.push_back(it.second->getDatos());
    return infoReservas;
}

void ReservaController::eliminarReserva(int codigoReserva) {
    reservaAux = reservas.find(codigoReserva)->second;
}

void ReservaController::cancelarBajaReserva() {
    hostalAux = nullptr;
}

void ReservaController::confirmarBajaReserva() {
    Reserva *res = getReserva();
    reservas.erase(res->getCodigo());
    delete res;
}

Estadia *ReservaController::findEstadia(int idReserva) {
    return estadias[idReserva];
}

ReservaController *ReservaController::getInstance() {
    if (instance == nullptr) instance = new ReservaController();
    return instance;
}

int ReservaController::getNextCodigoReserva() {
    currentIdReserva++;
    return currentIdReserva;
}

void ReservaController::seleccionarEstadia(int codigoReserva) {
    estadiaAux = reservas[codigoReserva]->getEstadia();
}

DtResenia ReservaController::verCalificacion() {
    return getEstadia()->getDatosResenia();
}

string ReservaController::getTipoReserva() {
    return tipoReservaAux;
}

ReservaController::~ReservaController() {
    for (auto &it: reservas)
        delete it.second;
    for (auto &it: estadias)
        delete it.second;
}

Reserva *ReservaController::getReserva() {
    return reservaAux;
}

ReservaController::ReservaController() {
    reservas = {};
    estadias = {};
    invitadosAux = {};
    habitacionAux = nullptr;
    huespedReservanteAux = nullptr;
    reservaAux = nullptr;
    estadiaAux = nullptr;
    hostalAux = nullptr;
    tipoReservaAux = "";
    checkInAux = {};
    checkOutAux = {};
}
