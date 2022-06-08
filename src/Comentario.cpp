
#include "Comentario.h"

#include <utility>

Comentario::Comentario(string texto, Resenia *resenia) {
    this->texto = std::move(texto);
    this->resenia = resenia;
}

string Comentario::getTexto() {
    return texto;
}

Resenia *Comentario::getResenia() {
    return resenia;
}

DtComentario Comentario::getDatos() {
    return DtComentario(texto);
}

Comentario::Comentario() = default;
