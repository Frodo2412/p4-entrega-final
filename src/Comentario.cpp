
#include "Comentario.h"

#include <utility>

Comentario::Comentario(string texto) {
    this->texto = std::move(texto);
}

string Comentario::getTexto() {
    return texto;
}

DtComentario Comentario::getDatos() {
    return DtComentario(texto);
}

Comentario::Comentario() = default;
