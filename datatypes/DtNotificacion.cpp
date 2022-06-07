//
// Created by MontoroA on 7/6/2022.
//

#include "DtNotificacion.h"

DtNotificacion::DtNotificacion(int calif, DtFecha* f, string res, string coment, string aut){
    calificacion = calif;
    fecha = f;
    resenia = res;
    comentario = coment;
    autor = aut;
}

int DtNotificacion::getCalificacion(){
    return calificacion;
}

DtFecha* DtNotificacion::getFecha(){
    return fecha;
}

string DtNotificacion::getResenia(){
    return resenia;
}

string DtNotificacion::getComentario(){
    return  comentario;
}

string DtNotificacion::getAutor(){
    return autor;
}