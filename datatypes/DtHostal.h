
#ifndef P4_ENTREGA_FINAL_DTHOSTAL_H
#define P4_ENTREGA_FINAL_DTHOSTAL_H

#include <string>

using namespace std;

class DtHostal {
private:
    string nombre;
    string direccion;
    int calificacionPromedio;

public:
    DtHostal(string nombre, string direccion, int calificacionPromedio);


    string getNombre();

    string getDireccion();

    int getCalificacionProm() const;
};


#endif //P4_ENTREGA_FINAL_DTHOSTAL_H
