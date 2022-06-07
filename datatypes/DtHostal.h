//
// Created by User on 7/6/2022.
//

#ifndef P4_ENTREGA_FINAL_DTHOSTAL_H
#define P4_ENTREGA_FINAL_DTHOSTAL_H

#include <string>

using std::string;

class DtHostal {
private:
    string nombre;
    string direccion;
    int calificacionProm;

public:
    DtHostal(string, string, int);
    ~DtHostal(){};

    string getNombre();
    string getDireccion();
    int getCalificacionProm();
};


#endif //P4_ENTREGA_FINAL_DTHOSTAL_H
