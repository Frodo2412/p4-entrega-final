
#include "../datatypes/DtReservaIndividual.h"
#include "../include/ReservaController.h"
#include "../include/ReservaGrupal.h"
#include "../include/ReservaIndividual.h"

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
    try {
        UsuarioController *uc = UsuarioController::getInstance();
        huespedReservanteAux = uc->findHuesped(email);
    } catch (std::invalid_argument ex) {
        throw ex;
    }
}

void ReservaController::elegirHabitacion(int numero) {
    Hostal *h = getHostal();
    habitacionAux = h->getHabitacion(numero);
}

void ReservaController::elegirTipoReserva(string reserva) {
    tipoReservaAux = reserva;
}

list<DtHuesped*> ReservaController::mostrarHuespedes() {
    UsuarioController *uc = UsuarioController::getInstance();
    return uc->getHuespedes();
}

DtEstadia ReservaController::mostrarInformacionEstadia() {
    if (getEstadia() != nullptr)
        return getEstadia()->getDatos();
    else throw invalid_argument("La estadia seleccionada no existe");
}

list<DtReserva *> ReservaController::mostrarReservas() {
    list<DtReserva *> infoReservas;
    Hostal *h = getHostal();
    for (auto &it: reservas)
        if (it.second->checkIfSameHostal(h))
            infoReservas.push_back(it.second->getDatos());
    if (infoReservas.empty()) throw invalid_argument("No existen reservas en ese hostal.");
    return infoReservas;

}

list<DtHabitacion> ReservaController::mostrarHabitaciones() {
    Hostal *h = getHostal();
    return h->getInfoDeHabitaciones();
}

void ReservaController::registrarEstadia(int idReserva) {
    if (reservas.find(idReserva) == reservas.end())
        throw invalid_argument("No existen reservas con el codigo ingresado.");
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
        if (!it.second->hasResenia()) {
            if (it.second->getReserva()->getReservante()->getMail() == email)
                infoEstadias.push_back(it.second->getDatos());
        }
    if (infoEstadias.empty()) throw invalid_argument("No existen estadias finalizadas para este huesped.");
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
    habitacion->addReserva(reserva);
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
    if (infoReservas.empty()) throw invalid_argument(h->getNombre() + " no tiene reservas.");
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
    if (estadias.find(idReserva) == estadias.end())
        throw invalid_argument("No existe una reserva con codigo " + to_string(idReserva));
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
    if (reservas.find(codigoReserva) != reservas.end())
        estadiaAux = reservas[codigoReserva]->getEstadia();
    else
        throw invalid_argument("La reserva con el codigo seleccionado no existe.");
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

list<DtEstadia> ReservaController::listarEstadiasOfHostal() {
    list<DtEstadia> infoEstadias;
    for (auto &it: estadias)
        if (it.second->getDatos().getHostal() == hostalAux->getNombre())
            infoEstadias.push_back(it.second->getDatos());
    return infoEstadias;
}
