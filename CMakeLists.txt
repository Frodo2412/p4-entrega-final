cmake_minimum_required(VERSION 3.13)

project(p4-entrega-final)

set(CMAKE_CXX_STANDARD 14)

add_executable(cmake_testapp main.cpp
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
        include/Hostal.h)
