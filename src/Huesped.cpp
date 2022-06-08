
#include "Huesped.h"

#include <utility>

Huesped::Huesped(string nombre, string email, string password, bool esFinger) : Usuario(std::move(nombre),
                                                                                        std::move(email),
                                                                                        std::move(password)) {
    this->esFinger = esFinger;
    this->reservas = list<Reserva *>();
}

DtUsuario Huesped::getDatos() {
    return DtHuesped{nombre, mail, esFinger};
}

void Huesped::agregarReserva(Reserva *reserva) {
    this->reservas.push_back(reserva);
}

bool Huesped::isMail(const string& mail) {
    return this->mail == mail;
}

void Huesped::finalizarReservaActiva() {
    for (auto reserva: this->reservas)
        reserva->getEstadia()->finalizarActiva();
}

Huesped::~Huesped() {
    for (auto reserva: this->reservas)
        delete reserva;
}
