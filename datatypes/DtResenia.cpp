//
// Created by User on 6/6/2022.
//

#include "DtResenia.h"

DtResenia::DtResenia(int calif, string rese, string coment, DtFecha* f){
    calificacion = calif;
    resenia = rese;
    comentario = coment;
    fecha = f;
}

int DtResenia::getCalificacion(){
    return calificacion;
}

string DtResenia::getResenia(){
    return resenia;
}

string DtResenia::getComentario(){
    return comentario;
}

DtFecha* DtResenia::getFecha(){
    return fecha;
}
