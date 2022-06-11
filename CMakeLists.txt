cmake_minimum_required(VERSION 3.22)
project(p4_entrega_final)

set(CMAKE_CXX_STANDARD 14)

include_directories(datatypes)
include_directories(include)
include_directories(src)

add_executable(p4_entrega_final
        datatypes/DtComentario.cpp
        datatypes/DtComentario.h
        datatypes/DtCargo.h
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
        src/Empleado.cpp
        include/Empleado.h
        src/Habitacion.cpp
        include/Habitacion.h
        src/ReservaGrupal.cpp
        include/ReservaGrupal.h
        src/ReservaIndividual.cpp
        include/ReservaIndividual.h
        src/ReservaController.cpp
        include/ReservaController.h
        main.cpp src/UsuarioController.cpp include/UsuarioController.h src/HostalController.cpp include/HostalController.h infrastructure/IReservaController.h infrastructure/IHostalController.h infrastructure/IUsuarioController.h src/NotificacionController.cpp include/NotificacionController.h infrastructure/INotificacionController.h src/ControllerFactory.cpp include/ControllerFactory.h)
