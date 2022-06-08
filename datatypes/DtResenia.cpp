
#include "DtResenia.h"

#include <utility>

DtResenia::DtResenia(int calificacion, string resenia, string comentario, DtFecha fecha) {
    this->calificacion = calificacion;
    this->resenia = std::move(resenia);
    this->comentario = std::move(comentario);
    this->fecha = fecha;
}

int DtResenia::getCalificacion() const {
    return calificacion;
}

string DtResenia::getResenia() {
    return resenia;
}

string DtResenia::getComentario() {
    return comentario;
}

DtFecha DtResenia::getFecha() {
    return fecha;
}
