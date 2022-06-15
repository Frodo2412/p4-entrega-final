#include "Comentario.h"
#include "ControllerFactory.h"
#include "DtComentario.h"
#include "DtEmpleado.h"
#include "DtEstadia.h"
#include "DtFecha.h"
#include "DtHabitacion.h"
#include "DtHostal.h"
#include "DtHostalExt.h"
#include "DtHuesped.h"
#include "DtNotificacion.h"
#include "DtReserva.h"
#include "DtReservaGrupal.h"
#include "DtReservaIndividual.h"
#include "Empleado.h"
#include "Habitacion.h"
#include "Huesped.h"
#include "ReservaIndividual.h"

#include <iostream>

void printEstadias(list<DtEstadia> &estadias);
using namespace std;

void test_dt() {
    cout << " - DtFecha:" << endl;
    DtFecha fecha(1, 1, 1, 1901);
    cout << fecha << endl;

    cout << " - DtComentario:" << endl;
    DtComentario comentario("Hola Mundo");
    cout << comentario.getTexto() << endl;

    cout << " - DtEmpleado:" << endl;
    DtEmpleado empleado("Juan", "juan@gmail.com", DtCargo::Administracion);
    cout << empleado.getNombre() << endl;
    cout << empleado.getEmail() << endl;
    cout << empleado.getCargo() << endl;

    cout << " - DtEstadia:" << endl;
    DtEstadia estadia("Hostal", "juan@gmail.com", 1, DtFecha(1, 1, 1, 1901), DtFecha(1, 1, 1, 1901), "Promo", 1);
    cout << estadia.getHostal() << endl;
    cout << estadia.getHuesped() << endl;
    cout << estadia.getHabitacion() << endl;
    cout << estadia.getCheckIn() << endl;
    cout << estadia.getCheckOut() << endl;
    cout << estadia.getPromo() << endl;

    cout << " - DtHabitacion" << endl;
    DtHabitacion habitacion(1, 1, 1);
    cout << habitacion.getNumero() << endl;
    cout << habitacion.getCapacidad() << endl;
    cout << habitacion.getPrecio() << endl;

    cout << " - DtHostal" << endl;
    DtHostal hostal("Hostal", "El Viejo Pancho 1234", 3);
    cout << hostal.getNombre() << endl;
    cout << hostal.getDireccion() << endl;
    cout << hostal.getCalificacionProm() << endl;

    DtResenia resenia1(1, "Hola", "Juan", DtFecha(1, 1, 1, 1901), 1),
            resenia2(2, "Hola", "Juan", DtFecha(1, 1, 1, 1901), 1),
            resenia3(3, "Hola", "Juan", DtFecha(1, 1, 1, 1901), 1);
    list<DtResenia> resenias({resenia1, resenia2, resenia3});
    cout << " - DtHostalExt" << endl;
    DtHostalExt hostalExt("HostalExt", "El Viejo Pancho 1234", 3, resenias);
    cout << hostal.getNombre() << endl;
    cout << hostal.getDireccion() << endl;
    cout << hostal.getCalificacionProm() << endl;

    cout << " - DtHuesped:" << endl;
    DtHuesped huesped("Pedro", "pedro@gmail.com", true);
    cout << huesped.getNombre() << endl;
    cout << huesped.getEmail() << endl;
    cout << huesped.getEsFinger() << endl;

    cout << " - DtNotificacion:" << endl;
    DtNotificacion notificacion(1, DtFecha(1, 1, 1, 1901), "Estaba rica la torta", "Noo en que te sentaste", "Pedro");
    cout << notificacion.getCalificacion() << endl;
    cout << notificacion.getFecha() << endl;
    cout << notificacion.getResenia() << endl;
    cout << notificacion.getComentario() << endl;
    cout << notificacion.getAutor() << endl;

    cout << " - DtResenia:" << endl;
    DtResenia resenia(1, "Hola", "Juan", DtFecha(1, 1, 1, 1901), 1);
    cout << resenia.getCalificacion() << endl;
    cout << resenia.getResenia() << endl;
    cout << resenia.getComentario() << endl;
    cout << resenia.getFecha() << endl;

    //    cout << " - DtReserva:" << endl;
    //    DtReserva reserva(1, DtFecha(1, 1, 1, 1901), DtFecha(2, 1, 1, 1901), DtEstado::Abierta, 1);
    //    cout << reserva.getCodigo() << endl;
    //    cout << reserva.getCheckIn() << endl;
    //    cout << reserva.getCheckOut() << endl;
    //    cout << reserva.getEstado() << endl;
    //    cout << reserva.getCosto() << endl;
    // EN PRINCIPIO NO SE NECESITA

    cout << " - DtReservaGrupal:" << endl;
    DtReservaGrupal reservaGrupal(1, DtFecha(1, 1, 1, 1901), DtFecha(2, 1, 1, 1901), DtEstado::Abierta, 1, 1);
    cout << reservaGrupal.getCodigo() << endl;
    cout << reservaGrupal.getCheckIn() << endl;
    cout << reservaGrupal.getCheckOut() << endl;
    cout << reservaGrupal.getEstado() << endl;
    cout << reservaGrupal.getCosto() << endl;
    cout << reservaGrupal.getCantidadHuespedes() << endl;

    cout << " - DtReservaIndividual:" << endl;
    DtReservaIndividual reservaIndividual(1, DtFecha(1, 1, 1, 1901), DtFecha(2, 1, 1, 1901), DtEstado::Abierta, 1);
    cout << reservaIndividual.getCodigo() << endl;
    cout << reservaIndividual.getCheckIn() << endl;
    cout << reservaIndividual.getCheckOut() << endl;
    cout << reservaIndividual.getEstado() << endl;
    cout << reservaIndividual.getCosto() << endl;

    cout << " - DtUsuario:" << endl;
    DtUsuario usuario("Juan", "juan@gmail.com");
    cout << usuario << endl;

    cout << " - DtEmpleado:" << endl;
    DtEmpleado empleado1("DIEGO MARADONA", "diegol@gmail.com", DtCargo(1));
    cout << empleado1 << endl;

    cout << " - DtHuesped:" << endl;
    DtHuesped huesped1("DIEGO MARADONA", "diegol@gmail.com", true);
    cout << huesped1 << endl;
}

//void test_comentario() {
//    cout << " - Comentario:" << endl;
//    auto* huesped = new Huesped("carlos", "carlos@gmail.com", "contrasenia", false);
//    auto* estadia = new Estadia(DtFecha(1, 1, 1, 1901), huesped, new Reserva(DtFecha(1, 1, 1, 1901), DtFecha(1, 1, 2, 1901), huesped, new Habitacion(3, 3, 3)));
//    Resenia resenia(1, DtFecha(1, 1, 1, 1901), "bastante mala la verdad", estadia);
//    Comentario comentario("Hola");
//    //    Comentario comentario("Hola", &resenia);
//    cout << comentario.getTexto() << endl;
//    DtComentario comentarioDt = comentario.getDatos();
//    //    Resenia *resenia1 = comentario.getResenia();
//}

//TODO: faltan implementar cosas en estadia para el de arriba y para el de abajo
//void test_resenia() {
//    cout << " - Resenia:" << endl;
//    auto* huesped = new Huesped("carlos", "carlos@gmail.com", "contrasenia", false);
//    auto* estadia = new Estadia(DtFecha(1, 1, 1, 1901), huesped, new Reserva(DtFecha(1, 1, 1, 1901), DtFecha(1, 1, 2, 1901), huesped, new Habitacion(3, 3, 3)));
//    Resenia resenia(1, DtFecha(1, 1, 1, 1901), "bastante mala la verdad", estadia);
//    cout << resenia.getCalificacion() << endl;
//    cout << resenia.getFecha() << endl;
//    cout << resenia.getComentario() << endl;
//    auto *comentario = new Comentario("Hola");
//    //    auto *comentario = new Comentario("Hola", &resenia);
//    resenia.setComentario(comentario);
//}

// TODO: Cuando se implemente la reserva volver a activar el test
void test_usuario() {
    //    cout << " - Huesped:" << endl;
    //    Huesped usuario("Juan", "juan@gmail.com", "tuViejaEnTanga", true);
    //    cout << usuario.isMail("juan@gmail.com") << endl;
    //    cout << usuario.isMail("") << endl;
    //    auto *reserva = new ReservaIndividual();
    //    usuario.agregarReserva(reserva);
}

// TODO: Cuando se implemente hostal y reserva testear la habitacion
void test_habitacion() {
    //    cout << " - Habitacion:" << endl;
    //    Habitacion habitacion(1, 1, 1);
    //    Hostal hostal;
    //    habitacion.setHostal(&hostal);
    //    list<DtReserva> reservas = habitacion.getReservasAsociadas("juan@gmail.com");
}

//----------------------------------------------------------------------------------------------------------------------

DtCargo cargoDialog() {
    cout << "Ingrese cargo: " << endl;
    cout << "1. Adminstracion" << endl;
    cout << "2. Limpieza" << endl;
    cout << "3. Recepcion" << endl;
    cout << "4. Infraestructura" << endl;
    DtCargo cargo;
    int opcion;
    cin >> opcion;
    while (opcion != 1 && opcion != 2 && opcion != 3 && opcion != 4) {
        cout << "Opcion invalida, ingrese nuevamente: ";
        cin >> opcion;
    }
    switch (opcion) {
        case 1:
            cargo = DtCargo(1);
            break;
        case 2:
            cargo = DtCargo(2);
            break;
        case 3:
            cargo = DtCargo(3);
            break;
        case 4:
            cargo = DtCargo(4);
            break;
        default:
            break;
    }
    return cargo;
}

void printInterlineado() {
    cout << endl;
    cout << "----------------------------------------------------" << endl;
    cout << endl;
}

bool siNoDialog() {
    int opcion;
    cout << "1. Si" << endl;
    cout << "2. No" << endl;
    while (opcion != 1 && opcion != 2) {
        cout << "Opcion invalida, ingrese nuevamente: ";
        cin >> opcion;
    }
    return opcion == 1;
}

void printHostal(DtHostal &hostal) {
    cout << hostal.getNombre() << endl;
    cout << " - "
         << "Direccion: " << hostal.getDireccion() << endl;
    cout << " - "
         << "Calificacion promedio: " << hostal.getCalificacionProm() << endl;
}

void printResenia(DtResenia &resenia) {
    cout << "Calificacion: " << resenia.getCalificacion() << endl;
    cout << "Resenia: " << resenia.getResenia() << endl;
    cout << "Comentario: " << resenia.getComentario() << endl;
    cout << "Fecha: " << resenia.getFecha() << endl;
}

void printResenias(const list<DtResenia>& resenias) {
    for (DtResenia resenia: resenias) {
        printResenia(resenia);
    }
}


void printHostalExt(DtHostalExt &hostal) {
    printHostal(hostal);
    cout << "Sus resenias: " << endl;
    printResenias(hostal.getResenias());
}

void printHostales(list<DtHostal> &hostales) {
    for (auto hostal: hostales) {
        printHostal(hostal);
    }
}
void printNotificacion(DtNotificacion &notificacion) {
    cout << endl;
    cout << "Calificacion: " << notificacion.getCalificacion() << endl;
    cout << "Resenia: " << notificacion.getResenia() << endl;
    cout << "Comentario: " << notificacion.getComentario() << endl;
    cout << "Fecha: " << notificacion.getFecha() << endl;
    cout << "Autor: " << notificacion.getAutor() << endl;
}

void printNotificaciones(list<DtNotificacion> &notifaciones) {
    for (auto notificacion: notifaciones) {
        printNotificacion(notificacion);
    }
}

void printHabitaciones(list<DtHabitacion> &habitaciones) {
    for (auto habitacion: habitaciones) {
        cout << " - "
             << "Numero: " << habitacion.getNumero() << endl;
        cout << " - "
             << "Capacidad: " << habitacion.getCapacidad() << endl;
        cout << " - "
             << "Precio: " << habitacion.getPrecio() << endl;
    }
}

void mostrarElegirHostal_HostalController() {
    ControllerFactory *factory = ControllerFactory::getInstance();
    IHostalController *hostalController = factory->getHostalController();
    list<DtHostal> hostales = hostalController->mostrarHostales();
    cout << "Los Hostales disponibles son: " << endl;
    printHostales(hostales);
    cout << "Ingrese el nombre del Hostal que se desee: ";
    string nombre;
    cin >> nombre;
    hostalController->elegirHostal(nombre);
}

void mostrarElegirHostal_ReservaController() {
    ControllerFactory *factory = ControllerFactory::getInstance();
    IReservaController *reservaController = factory->getReservaController();
    list<DtHostal> hostales = reservaController->mostrarHostales();
    cout << "Los Hostales disponibles son: " << endl;
    printHostales(hostales);
    cout << "Ingrese el nombre del Hostal que se desee: ";
    string nombre;
    cin >> nombre;
    reservaController->elegirHostal(nombre);
}

void mostrarElegirHostal_NotificacionController() {
    ControllerFactory *factory = ControllerFactory::getInstance();
    INotificacionController *notificacionController = factory->getNotificacionController();
    list<DtHostal> hostales = notificacionController->mostrarHostales();
    cout << "Los Hostales disponibles son: " << endl;
    printHostales(hostales);
    cout << "Ingrese el nombre del Hostal que se desee: ";
    string nombre;
    cin >> nombre;
    notificacionController->elegirHostal(nombre);
}

void mostrarElegirHabitacion() {
    ControllerFactory *factory = ControllerFactory::getInstance();
    IReservaController *reservaController = factory->getReservaController();
    list<DtHabitacion> habitaciones = reservaController->mostrarHabitaciones();
    cout << "Las Habitaciones disponibles son: " << endl;
    printHabitaciones(habitaciones);
    cout << "Ingrese el numero de La Habitacion que se desee: ";
    int numero;
    cin >> numero;
    reservaController->elegirHabitacion(numero);
}

void altaUsuario() {
    ControllerFactory *factory = ControllerFactory::getInstance();
    IUsuarioController *usuarioController = factory->getUsuarioController();

    //Datos basicos del usuario
    string nombre, mail, contrasena;
    cout << "Ingrese nombre: ";
    cin >> nombre;
    cout << "Ingrese mail: ";
    cin >> mail;
    cout << "Ingrese contrasena: ";
    cin >> contrasena;
    usuarioController->comenzarAltaUsuario(nombre, mail, contrasena);

    //Eleccion de tipo de usuario
    cout << "Eliga que tipo de usurio desea registrar: " << endl;
    cout << "1. Huesped" << endl;
    cout << "2. Empleado" << endl;
    int opcion;
    cin >> opcion;
    while (opcion != 1 && opcion != 2) {
        cout << "Opcion invalida, ingrese nuevamente: ";
        cin >> opcion;
    }
    if (opcion == 1) {
        cout << "Es Finger?" << endl;
        bool esFinger = siNoDialog();
        usuarioController->especificarEsFinger(esFinger == 1);
    } else {
        DtCargo cargo = cargoDialog();
        usuarioController->especificarCargo(cargo);
    }

    //Verificar que no se repita el mail
    while (usuarioController->findUsuario(mail) != nullptr) {
        cout << "Usuario ya existe" << endl;
        cout << "Desea cancelar el alta?" << endl;
        bool isCancelada = siNoDialog();
        if (isCancelada) {
            usuarioController->cancelarAltaUsuario();
            return;
        } else {
            cout << "Ingrese nuevo mail: ";
            cin >> mail;
            usuarioController->ingresarEmail(mail);
        }
    }

    //Confirmacion de la operacion
    cout << "Todo esta correcto, desea confirmar el alta? (De lo contrario la cancelara)" << endl;
    bool isConfirmada = siNoDialog();
    if (isConfirmada) {
        usuarioController->confirmarAltaUsuario();
    } else {
        cout << "Alta cancelada" << endl;
        usuarioController->cancelarAltaUsuario();
    }
}

void altaHostal() {
    ControllerFactory *factory = ControllerFactory::getInstance();
    IHostalController *hostalController = factory->getHostalController();
    cout << "Ingrese nombre del Hostal: ";
    string nombre;
    cin >> nombre;
    cout << "Ingrese direccion del Hostal: ";
    string direccion;
    cin >> direccion;
    cout << "Ingrese telefono del Hostal: ";
    int telefono;
    cin >> telefono;
    hostalController->altaHostal(nombre, direccion, telefono);
}

void altaHabitacion() {
    ControllerFactory *factory = ControllerFactory::getInstance();
    IHostalController *hostalController = factory->getHostalController();
    mostrarElegirHostal_HostalController();
    cout << "Ingrese numero de habitacion: ";
    int numero;
    cin >> numero;
    cout << "Ingrese cantidad de camas: ";
    int cantidad;
    cin >> cantidad;
    cout << "Ingrese precio por noche: ";
    int precio;
    cin >> precio;
    hostalController->ingresarDatosHabitacion(numero, cantidad, precio);

    //Confirmacion de la operacion
    cout << "Todo esta correcto, desea confirmar el alta? (De lo contrario la cancelara)" << endl;
    bool isConfirmada = siNoDialog();
    if (isConfirmada) {
        hostalController->confirmarAltaHabitacion();
    } else {
        cout << "Alta cancelada" << endl;
        hostalController->cancelarAltaHabitacion();
    }
}
void asignarEmpleadoAHostal() {
    ControllerFactory *factory = ControllerFactory::getInstance();
    IHostalController *hostalController = factory->getHostalController();

    mostrarElegirHostal_HostalController();

    //Mostrar desempleados
    list<DtEmpleado> desempleados = hostalController->mostrarDesempleados();
    cout << "Los empleados disponibles son: " << endl;
    for (const auto &empleado: desempleados) {
        cout << empleado << endl;
    }

    cout << "Ingrese el email del empleado que se desee: ";
    string email;
    cin >> email;
    DtCargo cargo = cargoDialog();
    hostalController->seleccionarEmpleado(email, cargo);

    //Confirmacion de la operacion
    cout << "Todo esta correcto, desea confirmar la asignacion? (De lo contrario la cancelara)" << endl;
    bool isConfirmada = siNoDialog();
    if (isConfirmada) {
        hostalController->confirmarContratoEmpleado();
    } else {
        cout << "Asignacion cancelada" << endl;
        hostalController->cancelarContratoEmpleado();
    }
}

DtFecha fechaDialog() {
    int dia, mes, anio, hora;
    cout << "Ingrese dia: ";
    cin >> dia;
    cout << "Ingrese mes: ";
    cin >> mes;
    cout << "Ingrese anio: ";
    cin >> anio;
    cout << "Ingrese hora: ";
    cin >> hora;
    return {hora, dia, mes, anio};
}
bool tipoReservaDialog() {
    //Devuelve true si es Grupal
    cout << "Tipo de Reserva: " << endl;
    cout << "1. Grupal" << endl;
    cout << "2. Individual" << endl;
    int opcion;
    cin >> opcion;
    while (opcion != 1 && opcion != 2) {
        cout << "Opcion invalida, ingrese nuevamente: ";
        cin >> opcion;
    }
    return opcion == 1;
}
void realizarReserva() {
    ControllerFactory *factory = ControllerFactory::getInstance();
    IReservaController *reservaController = factory->getReservaController();

    mostrarElegirHostal_ReservaController();

    cout << "Ingrese fecha de inicio: ";
    fechaDialog();
    DtFecha inicio = fechaDialog();
    cout << "Ingrese fecha de fin: ";
    DtFecha fin = fechaDialog();
    reservaController->especificarFechas(inicio, fin);

    bool esGrupal = tipoReservaDialog();
    mostrarElegirHabitacion();
    list<DtHuesped> huespedes = reservaController->mostrarHuespedes();
    cout << "Los Huespedes disponibles son: " << endl;
    for (const auto &huesped: huespedes) {
        cout << huesped << endl;
    }
    cout << "Ingrese el email del huesped que esta realizando la Reserva: ";
    string email;
    cin >> email;
    reservaController->elegirHuespedReservante(email);
    if (esGrupal) {
        int hayNuevosHuepedes = 0;
        while (hayNuevosHuepedes != 2) {
            cout << "Desea agregar otro huesped? (1. Si, 2. No)" << endl;
            cin >> hayNuevosHuepedes;
            while (hayNuevosHuepedes != 1 && hayNuevosHuepedes != 2) {
                cout << "Opcion invalida, ingrese nuevamente: ";
                cin >> hayNuevosHuepedes;
            }
            if (hayNuevosHuepedes == 1) {
                cout << "Ingrese el email del huesped que desea agregar: ";
                cin >> email;
                reservaController->elegirHuesped(email);
            }
        }
    }
    //Confirmacion de la operacion
    cout << "Todo esta correcto, desea confirmar la reserva? (De lo contrario la cancelara)" << endl;
    bool isConfirmada = siNoDialog();
    if (isConfirmada) {
        reservaController->confirmarReserva();
    } else {
        cout << "Reserva cancelada" << endl;
        reservaController->cancelarReserva();
    }
}

void bajaReserva() {
    ControllerFactory *factory = ControllerFactory::getInstance();
    IReservaController *reservaController = factory->getReservaController();

    mostrarElegirHostal_ReservaController();

    list<DtReserva *> reservas = reservaController->informacionReservas();
    cout << "Las reservas disponibles son: " << endl;
    for (const auto &reserva: reservas) {
        cout << reserva << endl;
    }

    cout << "Ingrese el codigo de la reserva que desea dar de baja: ";
    int numero;
    cin >> numero;
    reservaController->eliminarReserva(numero);

    //Confirmacion de la operacion
    cout << "Todo esta correcto, desea confirmar la baja? (De lo contrario la cancelara)" << endl;
    bool isConfirmada = siNoDialog();
    if (isConfirmada) {
        reservaController->confirmarBajaReserva();
    } else {
        cout << "Baja cancelada" << endl;
        reservaController->cancelarBajaReserva();
    }
}

void consultarTop3Hostales() {
    ControllerFactory *factory = ControllerFactory::getInstance();
    IHostalController *hostalController = factory->getHostalController();

    list<DtHostal> hostales = hostalController->mostrarTop3Hostales();
    cout << "Los Top 3 hostales con mejor puntacion son: " << endl;
    printHostales(hostales);

    cout << "Desea ver las calificaciones de uno de los hostales? (1. Si, 2. No)" << endl;
    bool quieraInfo = siNoDialog();
    while (quieraInfo) {
        cout << "Ingrese el nombre del hostal: ";
        string nombre;
        cin >> nombre;
        list<DtResenia> resenias = hostalController->masInformacionSobreHostal(nombre);
        cout << "Las resenias del hostal " << nombre << " son: " << endl;
        printResenias(resenias);
        cout << endl;
        cout << "Desea ver las calificaciones de otro hostal? (1. Si, 2. No)" << endl;
        quieraInfo = siNoDialog();
    }
}

void registrarEstadia() {
    ControllerFactory *factory = ControllerFactory::getInstance();
    IReservaController *reservaController = factory->getReservaController();

    mostrarElegirHostal_ReservaController();

    cout << "Ingrese el mail del huesped que desea registrar su estadia: " << endl;
    string email;
    cin >> email;


    list<DtReserva *> reservas = reservaController->mostrarReservasNoCanceladas(email);
    cout << "Para el Huesped indicado, las reservas disponibles para registra estadia son: " << endl;
    for (const auto &reserva: reservas) {
        cout << reserva << endl;
    }

    cout << "Ingrese el codigo de la reserva que desea registrar: " << endl;
    int numero;
    cin >> numero;

    reservaController->registrarEstadia(numero);
    cout << "Estadia registrada" << endl;
}


void finalizarEstadia() {
    ControllerFactory *factory = ControllerFactory::getInstance();
    IReservaController *reservaController = factory->getReservaController();

    mostrarElegirHostal_ReservaController();

    cout << "Ingrese el mail del huesped que desea finalizar su estadia: " << endl;
    string email;
    cin >> email;

    reservaController->finalizarReservasActivasDeUsuario(email);
    cout << "Estadia finalizada" << endl;
}

void printEstadia(DtEstadia &estadia) {
    cout << "Codigo de estadia: " << estadia.getCodigo() << endl;
    cout << "Email del huesped: " << estadia.getHuesped() << endl;
    cout << "Numero de Habitacion: " << estadia.getHabitacion() << endl;
    cout << "Fecha de inicio: " << estadia.getCheckIn() << endl;
    cout << "Fecha de fin: " << estadia.getCheckOut() << endl;
}

void printEstadias(list<DtEstadia> &estadias) {
    for (DtEstadia estadia: estadias) {
        printEstadia(estadia);
    }
}

void calificarEstadia() {
    ControllerFactory *factory = ControllerFactory::getInstance();
    INotificacionController *notificacionController = factory->getNotificacionController();

    mostrarElegirHostal_NotificacionController();

    cout << "Ingrese el mail del huesped que desea calificar alguna de sus estadias: " << endl;
    string email;
    cin >> email;
    list<DtEstadia> estadias = notificacionController->mostrarEstadiasFinalizadas(email);
    cout << "Las estadias disponibles para calificar son: " << endl;
    printEstadias(estadias);

    cout << "Ingrese el codigo de la estadia que desea calificar: " << endl;
    int numero;
    cin >> numero;
    notificacionController->seleccionarEstadia(numero);

    cout << "Ingrese la calificacion: " << endl;
    int calificacion;
    cin >> calificacion;
    cout << "Ingrese la resenia: " << endl;
    string resenia;
    cin >> resenia;
    notificacionController->ingresarCalificacion(calificacion, resenia);
}

void comentarCalificacion() {
    ControllerFactory *factory = ControllerFactory::getInstance();
    INotificacionController *notificacionController = factory->getNotificacionController();

    cout << "Ingrese el mail del Empleado que desea comentar una calificacion: " << endl;
    string email;
    cin >> email;
    list<DtResenia> resenias = notificacionController->mostrarComentariosSinResponder(email);

    if (!resenias.empty()) {
        cout << "Las calificaciones disponibles para comentar son: " << endl;
        printResenias(resenias);
        cout << endl;
        cout << "Ingrese el codigo de la calificacion que desea comentar: " << endl;
        int numero;
        cin >> numero;
        notificacionController->elegirComentario(numero);
        cout << "Ingrese el comentario que desea darle a la calificacion: " << endl;
        string comentario;
        cin >> comentario;
        notificacionController->enviarComentario(comentario);
        cout << "Comentario enviado" << endl;
    } else {
        cout << "No hay calificaciones disponibles para comentar" << endl;
    }
}

void consultaUsuario() {
    ControllerFactory *factory = ControllerFactory::getInstance();
    IUsuarioController *usuarioController = factory->getUsuarioController();

    list<DtUsuario> usuarios = usuarioController->mostrarUsuarios();
    cout << "Los usuarios registrados son: " << endl;
    for (const auto &usuario: usuarios) {
        cout << usuario << endl;
    }

    cout << "Ingrese el mail del usuario que desea consultar: " << endl;
    string email;
    cin >> email;
    DtUsuario usuario = usuarioController->mostrarInformacionUsuario(email);
    cout << "La informacion del usuario es: " << endl;
    cout << usuario << endl;

    cout << "Operacion finalizada" << endl;
}

void consultaHostal() {
    ControllerFactory *factory = ControllerFactory::getInstance();
    IHostalController *hostalController = factory->getHostalController();

    mostrarElegirHostal_HostalController();

    DtHostalExt hostal = hostalController->informacionHostal();
    cout << "La informacion del hostal es: " << endl;
    printHostalExt(hostal);

    cout << endl;
    cout << "Operacion finalizada" << endl;
}

void consultaReserva() {
    ControllerFactory *factory = ControllerFactory::getInstance();
    IReservaController *reservaController = factory->getReservaController();

    mostrarElegirHostal_ReservaController();

    list<DtReserva *> reservas = reservaController->mostrarReservas();
    cout << "Las reservas disponibles son: " << endl;
    for (const auto &reserva: reservas) {
        cout << reserva << endl;
    }

    cout << endl;
    cout << "Operacion finalizada" << endl;
}

void consultaEstadia() {
    ControllerFactory *factory = ControllerFactory::getInstance();
    IReservaController *reservaController = factory->getReservaController();

    mostrarElegirHostal_ReservaController();

    list<DtEstadia> estadias = reservaController->listarEstadias();
    cout << "Las estadias disponibles son: " << endl;
    printEstadias(estadias);

    cout << "Seleccione el codigo de la estadia que desea consultar: " << endl;
    int numero;
    cin >> numero;
    reservaController->seleccionarEstadia(numero);
    DtEstadia estadia = reservaController->mostrarInformacionEstadia();
    cout << "La informacion de la estadia es: " << endl;
    printEstadia(estadia);

    cout << "Desea ver la calificacion de la estadia? (1. Si / 2. No)" << endl;
    bool desea = siNoDialog();
    if (desea) {
        DtResenia resenia = reservaController->verCalificacion();
        cout << "La calificacion de la estadia es: " << endl;
        printResenia(resenia);
    }
    cout << "Desea ver la reserva de la estadia? (1. Si / 2. No)" << endl;
    desea = siNoDialog();
    if (desea) {
        DtReserva *reserva = reservaController->verReserva();
        cout << "La reserva de la estadia es: " << endl;
        cout << reserva << endl;
    }
    cout << endl;
    cout << "Operacion finalizada" << endl;
}

void subscribirseANotificaciones() {
    ControllerFactory *factory = ControllerFactory::getInstance();
    INotificacionController *notificacionController = factory->getNotificacionController();

    list<DtEmpleado> empleados = notificacionController->mostrarEmpleados();
    cout << "Los empleados disponibles son: " << endl;
    for (const auto &empleado: empleados) {
        cout << empleado << endl;
    }

    cout << "Ingrese el mail del empleado que desea subscribirse: " << endl;
    string email;
    cin >> email;
    notificacionController->suscribirANotificaciones(email);

    cout << endl;
    cout << "El empleado fue suscrito a las notificaciones" << endl;
}

void consultarNotificaciones() {
    ControllerFactory *factory = ControllerFactory::getInstance();
    INotificacionController *notificacionController = factory->getNotificacionController();

    list<DtEmpleado> empleados = notificacionController->mostrarEmpleados();
    cout << "Los empleados disponibles son: " << endl;
    for (const auto &empleado: empleados) {
        cout << empleado << endl;
    }

    cout << "Ingrese el mail del empleado que desea consultar: " << endl;
    string email;
    cin >> email;
    list<DtNotificacion> notificaciones = notificacionController->consultaDeNotificaciones(email);
    cout << "Las notificaciones del empleado son: " << endl;
    printNotificaciones(notificaciones);

    cout << endl;
    cout << "Operacion finalizada" << endl;
}


void eliminarSubscripcion() {
    ControllerFactory *factory = ControllerFactory::getInstance();
    INotificacionController *notificacionController = factory->getNotificacionController();

    list<DtEmpleado> empleados = notificacionController->mostrarEmpleados();
    cout << "Los empleados disponibles son: " << endl;
    for (const auto &empleado: empleados) {
        cout << empleado << endl;
    }

    cout << "Ingrese el mail del empleado que desea eliminar su subscripcion: " << endl;
    string email;
    cin >> email;
    notificacionController->eliminarSubscripcion(email);

    cout << endl;
    cout << "El empleado no esta mas suscrito" << endl;
}

void modificarFechaDelSistema() {
    Reloj *reloj = Reloj::getInstance();
    cout << "Ingrese la nueva fecha del sistema: " << endl;
    DtFecha fecha = fechaDialog();
    reloj->modificarFechaDeSistema(fecha.getAnio(), fecha.getMes(), fecha.getDia(), fecha.getHora());
}

void printOpciones() {
    cout << "Eliga el numero de la opcion que desea realizar:" << endl;
    cout << "1 - Alta de Usuario" << endl;
    cout << "2 - Alta de Hostal" << endl;
    cout << "3 - Alta de Habitacion" << endl;
    cout << "4 - Asignar Empleado a Hostal" << endl;
    cout << "5 - Realizar Reserva" << endl;
    cout << "6 - Baja de Reserva" << endl;
    cout << "7 - Consultar TOP 3 de Hostales" << endl;
    cout << "8 - Registrar Estadia" << endl;
    cout << "9 - Finalizar Estadia" << endl;
    cout << "10 - Calificar Estadia" << endl;
    cout << "11 - Comentar Calificacion" << endl;
    cout << "12 - Consulta de Usuario" << endl;
    cout << "13 - Consulta de Hostal" << endl;
    cout << "14 - Consulta de Reserva" << endl;
    cout << "15 - Consulta de Estadia" << endl;
    cout << "16 - Subscribirse a Notificaciones" << endl;
    cout << "17 - Consultar Notificaciones" << endl;
    cout << "18 - Eliminar Subscripcion" << endl;
    cout << "19 - Modificar Fecha del Sistema" << endl;
    cout << "20 - Salir" << endl;
}

void mainApp() {
    cout << "Bienvenido al sistema de gestion de hoteleria FING" << endl;
    int opcion = 0;
    while (opcion != 20) {
        if (opcion != 20) {
            printOpciones();
            cin >> opcion;
        }
        switch (opcion) {
            case 1:
                altaUsuario();
                printInterlineado();
                break;
            case 2:
                altaHostal();
                printInterlineado();
                break;
            case 3:
                altaHabitacion();
                printInterlineado();
                break;
            case 4:
                asignarEmpleadoAHostal();
                printInterlineado();
                break;
            case 5:
                realizarReserva();
                printInterlineado();
                break;
            case 6:
                bajaReserva();
                printInterlineado();
                break;
            case 7:
                consultarTop3Hostales();
                printInterlineado();
                break;
            case 8:
                registrarEstadia();
                printInterlineado();
                break;
            case 9:
                finalizarEstadia();
                printInterlineado();
                break;
            case 10:
                calificarEstadia();
                printInterlineado();
                break;
            case 11:
                comentarCalificacion();
                printInterlineado();
                break;
            case 12:
                consultaUsuario();
                printInterlineado();
                break;
            case 13:
                consultaHostal();
                printInterlineado();
                break;
            case 14:
                consultaReserva();
                printInterlineado();
                break;
            case 15:
                consultaEstadia();
                printInterlineado();
                break;
            case 16:
                subscribirseANotificaciones();
                printInterlineado();
                break;
            case 17:
                consultarNotificaciones();
                printInterlineado();
                break;
            case 18:
                eliminarSubscripcion();
                printInterlineado();
                break;
            case 19:
                modificarFechaDelSistema();
                printInterlineado();
                break;
            case 20:
                cout << "Gracias por utilizar el sistema de gestion de hoteleria FING" << endl;
                break;
            default:
                cout << "Opcion incorrecta" << endl;
                cout << "Por favor, ingrese una opcion valida" << endl;
                printInterlineado();
                break;
        }
    }
}

int main() {
    //    test_dt();
    //    test_comentario();
    //    test_resenia();
    //    test_usuario();

    mainApp();
    return 0;
}
