//
// Created by User on 7/6/2022.
//

#ifndef P4_ENTREGA_FINAL_DTHABITACION_H
#define P4_ENTREGA_FINAL_DTHABITACION_H


class DtHabitacion{
private:
    int numero;
    int capacidad;
    int precio; //Por noche

public:
    DtHabitacion(int, int, int);
    ~DtHabitacion(){};

    int getNumero();
    int getCapacidad();
    int getPrecio();
};


#endif //P4_ENTREGA_FINAL_DTHABITACION_H
