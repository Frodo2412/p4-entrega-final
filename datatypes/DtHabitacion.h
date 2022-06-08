
#ifndef P4_ENTREGA_FINAL_DTHABITACION_H
#define P4_ENTREGA_FINAL_DTHABITACION_H


class DtHabitacion {
private:
    int numero;
    int capacidad;
    int precio; //Por noche

public:
    DtHabitacion(int numero, int capacidad, int precio);

    int getNumero() const;

    int getCapacidad() const;

    int getPrecio() const;
};


#endif //P4_ENTREGA_FINAL_DTHABITACION_H
