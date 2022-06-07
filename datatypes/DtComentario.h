//
// Created by MontoroA on 6/6/2022.
//

#ifndef P4_ENTREGA_FINAL_DTCOMENTARIO_H
#define P4_ENTREGA_FINAL_DTCOMENTARIO_H

#include <string>

class DtComentario {
private:
    std::string texto;

public:
    DtComentario(std::string);
    ~DtComentario(){};  //Hace falta eliminar el string?

    std::string getTexto();
};


#endif //P4_ENTREGA_FINAL_DTCOMENTARIO_H
