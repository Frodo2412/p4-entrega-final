
#include "DtNotificacion.h"

DtNotificacion::DtNotificacion(int calificacion, DtFecha fecha, string resenia, string comentario, string autor) {
    this->calificacion = calificacion;
    this->fecha = fecha;
    this->resenia = resenia;
    this->comentario = comentario;
    this->autor = autor;
}

int DtNotificacion::getCalificacion() {
    return calificacion;
}

DtFecha DtNotificacion::getFecha() {
    return fecha;
}

string DtNotificacion::getResenia() {
    return resenia;
}

string DtNotificacion::getComentario() {
    return comentario;
}

string DtNotificacion::getAutor() {
    return autor;
}