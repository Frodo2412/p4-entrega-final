
#include "DtComentario.h"

#include <utility>

using namespace std;

DtComentario::DtComentario(string texto) {
    this->texto = std::move(texto);
}

std::string DtComentario::getTexto() {
    return texto;
}