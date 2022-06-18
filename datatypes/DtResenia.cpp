
#include "DtResenia.h"

#include <utility>

DtResenia::DtResenia(int calificacion, string resenia, string comentario, DtFecha fecha, int codigo) {
    this->calificacion = calificacion;
    this->resenia = std::move(resenia);
    this->comentario = std::move(comentario);
    this->fecha = fecha;
    this->codigo = codigo;
}

DtResenia::DtResenia(int calificacion, string resenia, DtFecha fecha, int codigo) {
    this->calificacion = calificacion;
    this->resenia = std::move(resenia);
    this->fecha = fecha;
    this->codigo = codigo;
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
bool DtResenia::operator==(const DtResenia &rhs) const {
    return this->calificacion == rhs.calificacion &&
           this->resenia == rhs.resenia &&
           this->comentario == rhs.comentario &&
           this->fecha == rhs.fecha &&
           this->codigo == rhs.codigo;
    ;
}
int DtResenia::getCodigo() const {
    return codigo;
}
