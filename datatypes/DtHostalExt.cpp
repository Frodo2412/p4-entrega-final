
#include "DtHostalExt.h"

DtHostalExt::DtHostalExt(string nombre, string direccion, int calificacionPromedio, list<DtResenia> resenias)
        : DtHostal(nombre, direccion, calificacionPromedio) {
    this->resenias = resenias;
}

list<DtResenia> DtHostalExt::getResenias() {
    return resenias;
}