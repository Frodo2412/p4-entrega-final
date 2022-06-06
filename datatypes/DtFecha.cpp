//
// Created by MontoroA on 6/6/2022.
//

#include "DtFecha.h"
#include <iostream>

DtFecha::DtFecha(int h, int d, int m, int a){
    if(h < 0 || h > 23)
        throw std::invalid_argument("Hora invalida");
    if(d < 0 || d > 30)
        throw std::invalid_argument("Dia invalido");
    if(m < 0 || 12 < m)
        throw std::invalid_argument("Mes invalido");
    if(a < 1901)
        throw std::invalid_argument("Anio invalido");
    hora = h;
    dia = d;
    mes = m;
    anio = a;
}

int DtFecha::getHora(){
    return hora;
}

int DtFecha::getDia(){
    return dia;
}

int DtFecha::getMes(){
    return mes;
}

int DtFecha::getAnio(){
    return anio;
}

int DtFecha::operator-(DtFecha* f){
    int f1 = this->dia + this->mes * 30 + this->anio * 365;
    int f2 = f->getDia() + f->getMes() * 30 + f->getAnio() * 365;

    return f1 - f2;
}

std::string DtFecha::format() {
    return std::to_string(this->dia) + "/" + std::to_string(this->mes) + "/" + std::to_string(this->anio) + ", " + std::to_string(this->hora) + "hrs";
}
