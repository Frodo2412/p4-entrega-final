cmake_minimum_required(VERSION 3.22)
project(p4_entrega_final)

set(CMAKE_CXX_STANDARD 14)

include_directories(datatypes)
include_directories(include)

add_executable(p4_entrega_final
        datatypes/DtCargo.h
        datatypes/DtComentario.cpp
        datatypes/DtComentario.h
        datatypes/DtEmpleado.cpp
        datatypes/DtEmpleado.h
        datatypes/DtEstadia.cpp
        datatypes/DtEstadia.h
        datatypes/DtEstado.h
        datatypes/DtFecha.cpp
        datatypes/DtFecha.h
        datatypes/DtReservaGrupal.cpp
        datatypes/DtReservaGrupal.h
        datatypes/DtHabitacion.cpp
        datatypes/DtHabitacion.h
        datatypes/DtHostal.cpp
        datatypes/DtHostal.h
        datatypes/DtHostalExt.cpp
        datatypes/DtHostalExt.h
        datatypes/DtHuesped.cpp
        datatypes/DtHuesped.h
        datatypes/DtReservaIndividual.cpp
        datatypes/DtReservaIndividual.h
        datatypes/DtNotificacion.cpp
        datatypes/DtNotificacion.h
        datatypes/DtResenia.cpp
        datatypes/DtResenia.h
        datatypes/DtReserva.cpp
        datatypes/DtReserva.h
        datatypes/DtUsuario.cpp
        datatypes/DtUsuario.h
        include/Hostal.h
        src/Hostal.cpp
        include/Comentario.h
        src/Comentario.cpp
        include/Resenia.h
        src/Resenia.cpp
        include/Reloj.h
        src/Reloj.cpp
        include/Usuario.h
        src/Usuario.cpp
        include/Huesped.h
        src/Huesped.cpp
        include/Estadia.h
        src/Estadia.cpp
        include/Reserva.h
        src/Reserva.cpp
        include/Observer.h

        main.cpp)
