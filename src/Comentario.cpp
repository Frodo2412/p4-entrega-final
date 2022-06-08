//
// Created by unzip on 08/06/22.
//

#include "Comentario.h"

Comentario::Comentario(string txt) {
    texto = txt;
}

DtComentario Comentario::getDatos() {
    return DtComentario(texto);
}

void Comentario::setReseña(Resenia * nuevaResenia) {
    resenia = nuevaResenia;
}

string Comentario::getTexto() {
    return texto;
}

Resenia *Comentario::getResenia() {
    return resenia;
}
