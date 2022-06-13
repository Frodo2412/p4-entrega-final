
#include "Resenia.h"

#include <utility>

Resenia::Resenia(int calificacion, DtFecha fecha, string comentario) {
    this->calificacion = calificacion;
    this->fecha = fecha;
    this->comentario = std::move(comentario);
    this->maybeComentario = nullptr;
//    this->maybeEstadia = nullptr;
}

DtResenia Resenia::getDatos() {
    return DtResenia(calificacion, comentario, maybeComentario->getTexto(), fecha);
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

//void Resenia::setEstadia(Estadia *estadia) {
//    this->maybeEstadia = estadia;
//}

bool Resenia::isComentada() {
    return maybeComentario != nullptr;
}

Resenia::~Resenia() {
    destruirAsociaciones();
}

Resenia::Resenia() = default;

