//
// Created by MontoroA on 6/6/2022.
//

#include "DtComentario.h"

DtComentario::DtComentario(std::string s){
    texto = s;
}

std::string DtComentario::getTexto(){
    return texto;
}