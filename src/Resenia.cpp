
#include "Resenia.h"
#include "DtNotificacion.h"

#include <utility>

Resenia::Resenia(int calificacion, DtFecha fecha, string comentario, Estadia* estadia) {
    this->calificacion = calificacion;
    this->fecha = fecha;
    this->comentario = std::move(comentario);
    this->maybeComentario = nullptr;
    this->maybeEstadia = estadia;
    this->autor = nullptr;
}

DtResenia Resenia::getDatos() {
    return {calificacion, comentario, maybeComentario->getTexto(), fecha, maybeEstadia->getReserva()->getCodigo()};
}

int Resenia::getCalificacion() const {
    return calificacion;
}

DtFecha Resenia::getFecha() {
    return fecha;
}

string Resenia::getComentario() {
    return comentario;
}

void Resenia::destruirAsociaciones() {
    delete this->maybeComentario;
}

void Resenia::setComentario(Comentario *respuesta) {
    this->maybeComentario = respuesta;
}

void Resenia::setEstadia(Estadia* estadia) {
    this->maybeEstadia = estadia;
}

bool Resenia::isComentada() {
    return maybeComentario != nullptr;
}

Resenia::~Resenia() {
    destruirAsociaciones();
}

Resenia::Resenia() = default;


void Resenia::setAutor(Huesped *aut) {
    autor = aut;
}

DtNotificacion Resenia::getNotificacion() {
    return {calificacion, fecha, comentario, maybeComentario->getTexto(), autor->getNombre()};
}

Estadia *Resenia::getEstadia() {
    return maybeEstadia;
}