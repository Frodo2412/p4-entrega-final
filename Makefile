OBJETOS = src/Comentario.o src/ControllerFactory.o src/Empleado.o src/Estadia.o \
src/Habitacion.o src/Hostal.o src/HostalController.o \
src/Huesped.o src/NotificacionController.o src/Reloj.o \
src/Resenia.o src/Reserva.o src/ReservaController.o src/ReservaGrupal.o \
src/ReservaIndividual.o src/Usuario.o src/UsuarioController.o \
datatypes/DtHuesped.o datatypes/DtEmpleado.o datatypes/DtNotificacion.o datatypes/DtResenia.o datatypes/DtReserva.o \
datatypes/DtReservaGrupal.o datatypes/DtReservaIndividual.o datatypes/DtUsuario.o datatypes/DtFecha.o \
datatypes/DtHabitacion.o datatypes/DtHostal.o datatypes/DtEstadia.o datatypes/DtComentario.o \
datatypes/DtHostalExt.o



AUX = DtCargo.o DtEstado.o DtTipoReserva.o

OPCIONES = -g -Wall
CC = g++

FUENTES = main.cpp datatypes/DtCargo.h datatypes/DtEstado.h datatypes/DtTipoReserva.h \
datatypes/DtFecha.h datatypes/DtComentario.h datatypes/DtEmpleado.h datatypes/DtEstadia.h  \
datatypes/DtHabitacion.h datatypes/DtHostal.h datatypes/DtHostalExt.h \
datatypes/DtHuesped.h datatypes/DtNotificacion.h datatypes/DtResenia.h datatypes/DtReserva.h \
datatypes/DtReservaGrupal.h datatypes/DtReservaIndividual.h datatypes/DtUsuario.h \
datatypes/DtComentario.cpp datatypes/DtEmpleado.cpp datatypes/DtEstadia.cpp datatypes/DtFecha.cpp \
datatypes/DtHabitacion.cpp datatypes/DtHostal.cpp datatypes/DtHostalExt.cpp \
datatypes/DtHuesped.cpp datatypes/DtNotificacion.cpp datatypes/DtResenia.cpp datatypes/DtReserva.cpp \
datatypes/DtReservaGrupal.cpp datatypes/DtReservaIndividual.cpp datatypes/DtUsuario.cpp \
include/Comentario.h include/ControllerFactory.h include/Empleado.h include/Estadia.h \
include/Habitacion.h include/Hostal.h include/HostalController.h \
include/Huesped.h include/NotificacionController.h include/Observer.h include/Reloj.h \
include/Resenia.h include/Reserva.h include/ReservaController.h include/ReservaGrupal.h \
include/ReservaIndividual.h include/Usuario.h include/UsuarioController.h \
src/Comentario.cpp src/ControllerFactory.cpp src/Empleado.cpp src/Estadia.cpp \
src/Habitacion.cpp src/Hostal.cpp src/HostalController.cpp \
src/Huesped.cpp src/NotificacionController.cpp src/Reloj.cpp \
src/Resenia.cpp src/Reserva.cpp src/ReservaController.cpp src/ReservaGrupal.cpp \
src/ReservaIndividual.cpp src/Usuario.cpp src/UsuarioController.cpp \
infrastructure/IHostalController.h infrastructure/INotificacionController.h \
infrastructure/IReservaController.h infrastructure/IUsuarioController.h

EXTRA = IHostalController.o INotificacionController.o IReservaController.o IUsuarioController.o Observer.o

INTERFACES = IHostalController.o INotificacionController.o IReservaController.o IUsuarioController.o

FingVMB: $(OBJETOS) $(EXTRA) $(AUX) main.cpp Makefile
	$(CC) $(OPCIONES) -o FingVMB main.cpp $(OBJETOS)

OBJCONTROLLERFACTORY = src/UsuarioController.o src/ReservaController.o src/NotificacionController.o src/HostalController.o

ControllerFactory.o: src/ControllerFactory.cpp include/ControllerFactory.h $(OBJCONTROLLERFACTORY)
	$(CC) $(OPCIONES) -c -o ControllerFactory.o ControllerFactory.cpp $(OBJCONTROLLERFACTORY)


OBJHOSTALCONTROLLER =  IHostalController.o src/ReservaController.o src/UsuarioController.o

HostalController.o: src/HostalController.cpp include/HostalController.h $(OBJHOSTALCONTROLLER)
	$(CC) $(OPCIONES) -c -o HostalController.o HostalController.cpp $(OBJHOSTALCONTROLLER)


OBJNOTIFICACIONCONTROLLER = INotificacionController.o src/HostalController.o src/ReservaController.o src/UsuarioController.o

NotificacionController.o: src/NotificacionController.cpp include/NotificacionController.h $(OBJNOTIFICACIONCONTROLLER)
	$(CC) $(OPCIONES) -c -o NotificacionController.o NotificacionController.cpp $(OBJNOTIFICACIONCONTROLLER)


OBJRESERVACONTROLLER = IReservaController.o src/UsuarioController.o src/HostalController.o

ReservaController.o: src/ReservaController.cpp include/ReservaController.h $(OBJRESERVACONTROLLER)
	$(CC) $(OPCIONES) -c -o ReservaController.o ReservaController.cpp $(OBJRESERVACONTROLLER)


OBJUSUARIOCONTROLLER = IUsuarioController.o src/HostalController.o

UsuarioController.o: src/UsuarioController.cpp include/UsuarioController.h $(OBJUSUARIOCONTROLLER)
	$(CC) $(OPCIONES) -c -o UsuarioController.o UsuarioController.cpp $(OBJUSUARIOCONTROLLER)


#OBJIUSUARIOCONTROLLER = src/Huesped.o src/Empleado.o src/HostalController.o
#OBJIUSUARIOCONTROLLER = src/Huesped.o src/Empleado.o
OBJIUSUARIOCONTROLLER =

IUsuarioController.o: infrastructure/IUsuarioController.h $(OBJIUSUARIOCONTROLLER)
	$(CC) $(OPCIONES) -c -o IUsuarioController.o infrastructure/IUsuarioController.h $(OBJIUSUARIOCONTROLLER)


#OBJIRESERVACONTROLLER = src/Estadia.o src/Hostal.o src/Huesped.o src/Reloj.o \
# src/Resenia.o src/Reserva.o datatypes/DtEstadia.o src/Habitacion.o
 OBJIRESERVACONTROLLER =

IReservaController.o: infrastructure/IReservaController.h $(OBJIRESERVACONTROLLER)
	$(CC) $(OPCIONES) -c -o IReservaController.o infrastructure/IReservaController.h $(OBJIRESERVACONTROLLER)


#OBJINOTIFICACIONCONTROLLER = datatypes/DtNotificacion.o src/Estadia.o src/HostalController.o Observer.o \
#src/Reloj.o src/Resenia.o src/ReservaController.o src/UsuarioController.o
OBJINOTIFICACIONCONTROLLER =

INotificacionController.o: infrastructure/INotificacionController.h $(OBJINOTIFICACIONCONTROLLER)
	$(CC) $(OPCIONES) -c -o INotificacionController.o infrastructure/INotificacionController.h $(OBJINOTIFICACIONCONTROLLER)


#OBJIHOSTALCONTROLLER = datatypes/DtEmpleado.o src/Empleado.o src/Hostal.o src/Huesped.o src/Resenia.o
OBJIHOSTALCONTROLLER =

IHostalController.o: infrastructure/IHostalController.h $(OBJIHOSTALCONTROLLER)
	$(CC) $(OPCIONES) -c -o IHostalController.o infrastructure/IHostalController.h $(OBJIHOSTALCONTROLLER)


OBJRESERVAINDIVIDUAL = src/Reserva.o datatypes/DtReservaIndividual.o

ReservaIndividual.o: src/ReservaIndividual.cpp include/ReservaIndividual.h $(OBJRESERVAINDIVIDUAL)
	$(CC) $(OPCIONES) -c -o ReservaIndividual.o ReservaIndividual.cpp $(OBJRESERVAINDIVIDUAL)


OBJRESERVAGRUPAL = src/Reserva.o src/Huesped.o datatypes/DtReservaGrupal.o

ReservaGrupal.o: src/ReservaGrupal.cpp include/ReservaGrupal.h $(OBJRESERVAGRUPAL)
	$(CC) $(OPCIONES) -c -o ReservaGrupal.o ReservaGrupal.cpp $(OBJRESERVAGRUPAL)


OBJRESERVA = datatype/DtEstado.o datatype/DtReserva.o src/Estadia.o src/Habitacion.o src/Huesped.o

Reserva.o: src/Reserva.cpp include/Reserva.h $(OBJRESERVA)
	$(CC) $(OPCIONES) -c -o Reserva.o Reserva.cpp $(OBJRESERVA)


OBJRESENIA = src/Comentario.o datatypes/DtFecha.o datatypes/DtResenia.o datatypes/DtNotificacion.o \
src/Huesped.o src/Hostal.o

Resenia.o: src/Resenia.cpp include/Resenia.h $(OBJRESENIA)
	$(CC) $(OPCIONES) -c -o Resenia.o Resenia.cpp $(OBJRESENIA)


OBJESTADIA = src/Resenia.o src/Reserva.o src/Reloj.o Observer.o src/Habitacion.o datatypes/DtEstadia.o

Estadia.o: src/Estadia.cpp include/Estadia.h $(OBJESTADIA)
	$(CC) $(OPCIONES) -c -o Estadia.o Estadia.cpp $(OBJESTADIA)


OBJCOMENTARIO = src/Resenia.o datatypes/DtComentario.o

Comentario.o: src/Comentario.cpp include/Comentario.h $(OBJCOMENTARIO)
	$(CC) $(OPCIONES) -c -o Comentario.o src/Comentario.cpp $(OBJCOMENTARIO)


OBJHABITACION = src/Hostal.o src/Reserva.o datatypes/DtHabitacion.o datatypes/DtResenia.o datatypes/DtReserva.o

Habitacion.o: src/Habitacion.cpp include/Habitacion.h $(OBJHABITACION)
	$(CC) $(OPCIONES) -c -o Habitacion.o Habitacion.cpp $(OBJHABITACION)


OBJHOSTAL = src/Empleado.o src/Habitacion.o datatypes/DtHostalExt.o datatypes/DtResenia.o datatypes/DrReserva.o

Hostal.o: src/Hostal.cpp include/Hostal.h $(OBJHOSTAL)
	$(CC) $(OPCIONES) -c -o Hostal.o Hostal.cpp $(OBJHOSTAL)


OBJHUESPED = src/Reserva.o src/Usuario.o datatypes/DtHuesped.o

Huesped.o: src/Huesped.cpp include/Huesped.h $(OBJHUESPED)
	$(CC) $(OPCIONES) -c -o Huesped.o Huesped.cpp $(OBJHUESPED)

OBJEMPLEADO = datatypes/DtEmpleado.o Observer.o src/Usuario.o src/Hostal.o

Empleado.o: src/Empleado.cpp include/Empleado.h $(OBJEMPLEADO)
	$(CC) $(OPCIONES) -c -o Empleado.o Empleado.cpp $(OBJEMPLEADO)


OBJUSUARIO = datatypes/DtUsuario.h

Usuario.o: src/Usuario.cpp include/Usuario.h $(OBJUSUARIO)
	$(CC) $(OPCIONES) -c -o Usuario.o Usuario.cpp $(OBJUSUARIO)

OBJRELOJ = datatypes/DtFecha.o

Reloj.o: src/Reloj.cpp include/Reloj.h $(OBJRELOJ)
	$(CC) $(OPCIONES) -c -o Reloj.o Reloj.cpp $(OBJRELOJ)

#OBJOBSERVER = datatypes/DtNotificacion.o
OBJOBSERVER =

Observer.o: include/Observer.h $(OBJOBSERVER)
	$(CC) $(OPCIONES) -c -o Observer.o include/Observer.h $(OBJOBSERVER)

OBJDTRESERVAGRUPAL = datatypes/DtReserva.o datatypes/DtHuesped.o

DtReservaGrupal.o: datatypes/DtReservaGrupal.cpp datatypes/DtReservaGrupal.h $(OBJDTRESERVAGRUPAL)
	$(CC) $(OPCIONES) -c -o DtReservaGrupal.o DtReservaGrupal.cpp $(OBJDTRESERVAGRUPAL)

OBJDTRESERVAINDIVIDUAL = datatypes/DtReserva.o

DtReservaIndividual.o: datatypes/DtReservaIndividual.cpp datatypes/DtReservaIndividual.h $(OBJDTRESERVAINDIVIDUAL)
	$(CC) $(OPCIONES) -c -o DtReservaIndividual.o DtReservaIndividual.cpp $(OBJDTRESERVAINDIVIDUAL)


OBJDTRESERVA = datatypes/DtEstado.o datatypes/DtFecha.o
#PROBAR SI NO ES NECESARIO METRER EL DIRECTORIO EN LOS DTTYPES (OSEA ESTA TRAABJANDO SOLO EN DATATYPES EN EL MISMO DIRECOTRIO)
DtReserva.o: datatypes/DtReserva.cpp datatypes/DtReserva.h $(OBJDTRESERVA)
	$(CC) $(OPCIONES) -c -o DtReserva.o DtReserva.cpp $(OBJDTRESERVA)

OBJDTHUESPED = datatypes/DtUsuario.o

DtHuesped.o: datatypes/DtHuesped.cpp datatypes/DtHuesped.h $(OBJDTHUESPED)
	$(CC) $(OPCIONES) -c -o DtHuesped.o DtHuesped.cpp $(OBJDTHUESPED)

OBJDTEMPLEADO = datatypes/DtUsuario.o datatypes/DtCargo.o

DtEmpleado.o: datatypes/DtEmpleado.cpp datatypes/DtEmpleado.h $(OBJDTEMPLEADO)
	$(CC) $(OPCIONES) -c -o DtEmpleado.o DtEmpleado.cpp $(OBJDTEMPLEADO)

OBJDTNOTIFICACION = datatypes/DtFecha.o

DtNotificacion.o: datatypes/DtNotificacion.cpp datatypes/DtNotificacion.h $(OBJDTNOTIFICACION)
	$(CC) $(OPCIONES) -c -o DtNotificacion.o DtNotificacion.cpp $(OBJDTNOTIFICACION)

DtEstadia.o: datatypes/DtEstadia.cpp datatypes/DtEstadia.h datatypes/DtFecha.o
	$(CC) $(OPCIONES) -c -o DtEstadia.o DtEstadia.cpp datatypes/DtFecha.o

OBJDTRESENIA = datatypes/DtFecha.o

DtResenia.o: datatypes/DtResenia.cpp datatypes/DtResenia.h $(OBJDTRESENIA)
	$(CC) $(OPCIONES) -c -o DtResenia.o DtResenia.cpp $(OBJDTRESENIA)

DtUsuario.o: datatypes/DtUsuario.cpp datatypes/DtUsuario.h
	$(CC) $(OPCIONES) -c -o DtUsuario.o DtUsuario.cpp

DtTipoReserva.o: datatypes/DtTipoReserva.h
	$(CC) $(OPCIONES) -c -o DtTipoReserva.o datatypes/DtTipoReserva.h

DtEstado.o: datatypes/DtEstado.h
	$(CC) $(OPCIONES) -c -o DtEstado.o datatypes/DtEstado.h

DtCargo.o: datatypes/DtCargo.h
	$(CC) $(OPCIONES) -c -o DtCargo.o datatypes/DtCargo.h

DtFecha.o: datatypes/DtFecha.cpp datatypes/DtFecha.h
	$(CC) $(OPCIONES) -c -o DtFecha.o DtFecha.cpp

clean:
	rm -f $(OBJETOS) $(AUX) $(EXTRA) FingVMB

rebuild:
	make clean
	make

entrega: $(FUENTES) Makefile
	rm -f 45_lab4.tar.gz
	tar -cvf 45_lab4.tar $(FUENTES) Makefile
	gzip 45_lab4.tar