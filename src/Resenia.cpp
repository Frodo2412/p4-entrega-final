
#include "../include/Resenia.h"

#include <utility>

Resenia::Resenia(int calificacion, DtFecha fecha, string comentario, Estadia *estadia) {
    this->calificacion = calificacion;
    this->fecha = fecha;
    this->comentario = std::move(comentario);
    this->maybeComentario = nullptr;
    this->maybeEstadia = estadia;
    this->autor = nullptr;
}

DtResenia Resenia::getDatos() {
//    return {calificacion, comentario, maybeComentario->getTexto(), fecha, maybeEstadia->getReserva()->getCodigo()};
    if (maybeComentario == nullptr)
        return DtResenia(calificacion, comentario, fecha,
                         maybeEstadia->getReserva()->getCodigo());
    else
        return DtResenia(calificacion, comentario, maybeComentario->getTexto(), fecha,
                         maybeEstadia->getReserva()->getCodigo());
}

void Resenia::destruirAsociaciones() {
    delete this->maybeComentario;
}

void Resenia::setComentario(Comentario *respuesta) {
    this->maybeComentario = respuesta;
}

bool Resenia::isComentada() {
    return maybeComentario != nullptr;
}

Resenia::~Resenia() {
    destruirAsociaciones();
}

Resenia::Resenia() = default;


void Resenia::setAutor(Huesped *pAutor) {
    autor = pAutor;
}

DtNotificacion Resenia::getNotificacion() {
    string respuesta;
    if (maybeComentario != nullptr) respuesta = maybeComentario->getTexto();
    return {calificacion, fecha, comentario, respuesta, autor->getNombre()};
}

Estadia *Resenia::getEstadia() {
    return maybeEstadia;
}