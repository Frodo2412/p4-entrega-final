
#include "../include/Huesped.h"

#include <utility>

Huesped::Huesped(string nombre, string email, string password, bool esFinger) : Usuario(std::move(nombre),
                                                                                        std::move(email),
                                                                                        std::move(password)) {
    this->esFinger = esFinger;
}

DtHuesped *Huesped::getDatos() {
    return new DtHuesped(nombre, mail, esFinger);
}

void Huesped::agregarReserva(Reserva *reserva) {
    reservas.insert(std::pair<int, Reserva *>(reserva->getCodigo(), reserva));
}

bool Huesped::isMail(const string &mail) {
    return this->mail == mail;
}

void Huesped::finalizarReservaActiva() {
    map<int, Reserva *>::iterator it;
    for (auto it: reservas)
        if (it.second->getEstadia() != nullptr)
            it.second->getEstadia()->finalizarActiva();
}

Huesped::~Huesped() {
    //No tiene sentido lo de abajo
//    for (auto reserva: this->reservas)
//        delete reserva;
}

DtHuesped Huesped::getDatosHuesped() {
    return {this->nombre, this->mail, this->esFinger};
}

bool Huesped::isFinger() {
    return esFinger;
}
