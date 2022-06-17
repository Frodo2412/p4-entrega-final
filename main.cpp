//#include "include/Comentario.h"
#include "include/ControllerFactory.h"
//#include "datatypes/DtComentario.h"
//#include "datatypes/DtEmpleado.h"
//#include "datatypes/DtEstadia.h"
//#include "datatypes/DtFecha.h"
//#include "datatypes/DtHabitacion.h"
//#include "datatypes/DtHostal.h"
//#include "datatypes/DtHostalExt.h"
//#include "datatypes/DtHuesped.h"
//#include "datatypes/DtNotificacion.h"
//#include "datatypes/DtReserva.h"

#include <iostream>

using namespace std;

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
            cargo = DtCargo::Administracion;
            break;
        case 2:
            cargo = DtCargo::Limpieza;
            break;
        case 3:
            cargo = DtCargo::Recepcion;
            break;
        case 4:
            cargo = DtCargo::Infraestructura;
            break;
        default:
            cargo = DtCargo::PlaceHolder;
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
    cin >> opcion;
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

void printResenias(const list<DtResenia> &resenias) {
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
    for (auto hostal: hostales)
        printHostal(hostal);
}

void printNotificacion(DtNotificacion &notificacion) {
    cout << endl;
    cout << "Calificacion: " << notificacion.getCalificacion() << endl;
    cout << "Resenia: " << notificacion.getResenia() << endl;
    cout << "Comentario: " << notificacion.getComentario() << endl;
    cout << "Fecha: " << notificacion.getFecha() << endl;
    cout << "Autor: " << notificacion.getAutor() << endl;
}

void printNotificaciones(list<DtNotificacion> &notificaciones) {
    for (auto notificacion: notificaciones) {
        printNotificacion(notificacion);
    }
}

void printHabitaciones(list<DtHabitacion> &habitaciones) {
    for (auto habitacion: habitaciones)
        cout << habitacion;
}

void mostrarElegirHostal_HostalController() {
    ControllerFactory *factory = ControllerFactory::getInstance();
    IHostalController *hostalController = factory->getHostalController();

    list<DtHostal> hostales = hostalController->mostrarHostales();
    cout << "Los Hostales disponibles son: " << endl;
    printHostales(hostales);
    cout << "Ingrese el nombre del Hostal que se desee: ";
    string nombre;
    cin.ignore();
    getline(cin, nombre);
    try {
        hostalController->elegirHostal(nombre);
    } catch (invalid_argument &ex) {
        throw ex;
    }
}

void mostrarElegirHostal_ReservaController() {
    ControllerFactory *factory = ControllerFactory::getInstance();
    IReservaController *reservaController = factory->getReservaController();
    list<DtHostal> hostales = reservaController->mostrarHostales();
    cout << "Los Hostales disponibles son: " << endl;
    printHostales(hostales);
    cout << "Ingrese el nombre del Hostal que se desee: ";
    string nombre;
    cin.ignore();
    getline(cin, nombre);
    try {
        reservaController->elegirHostal(nombre);
    } catch (invalid_argument &ex) {
        throw ex;
    }
}

void mostrarElegirHostal_NotificacionController() {
    ControllerFactory *factory = ControllerFactory::getInstance();
    INotificacionController *notificacionController = factory->getNotificacionController();
    list<DtHostal> hostales = notificacionController->mostrarHostales();
    cout << "Los Hostales disponibles son: " << endl;
    printHostales(hostales);
    cout << "Ingrese el nombre del Hostal que se desee: ";
    string nombre;
    cin.ignore();
    getline(cin, nombre);
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
    cin.ignore();
    getline(cin, nombre);
    cout << "Ingrese mail: ";
    cin >> mail;
    cout << "Ingrese contrasena: ";
    cin >> contrasena;
    usuarioController->comenzarAltaUsuario(nombre, mail, contrasena);

    //Eleccion de tipo de usuario
    cout << "Elija que tipo de usuario desea registrar: " << endl;
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
    cin.ignore();
    getline(cin, nombre);
    cout << "Ingrese direccion del Hostal: ";
    string direccion;
    getline(cin, direccion);
    cout << "Ingrese telefono del Hostal: ";
    int telefono;
    cin >> telefono;
    try {
        hostalController->altaHostal(nombre, direccion, telefono);
    } catch (invalid_argument &ex) {
        cout << "Ya existe un hostal con ese nombre";
    }
}

void altaHabitacion() {
    ControllerFactory *factory = ControllerFactory::getInstance();
    IHostalController *hostalController = factory->getHostalController();
    try {
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
        hostalController->ingresarDatosHabitacion(numero, precio, cantidad);

        //Confirmacion de la operacion
        cout << "Todo esta correcto, desea confirmar el alta? (De lo contrario la cancelara)" << endl;
        bool isConfirmada = siNoDialog();
        if (isConfirmada) {
            hostalController->confirmarAltaHabitacion();
        } else {
            cout << "Alta cancelada" << endl;
            hostalController->cancelarAltaHabitacion();
        }
    } catch (invalid_argument &ex) {
        cout << ex.what() << endl;
        cout << "Intente nuevamente" << endl;
    }
}

void asignarEmpleadoAHostal() {
    ControllerFactory *factory = ControllerFactory::getInstance();
    IHostalController *hostalController = factory->getHostalController();
    try {
        mostrarElegirHostal_HostalController();

        //Mostrar desempleados
        list<DtEmpleado> desempleados = hostalController->mostrarDesempleados();
        cout << "Los empleados disponibles son: " << endl;
        for (const auto &empleado: desempleados)
            cout << empleado << endl;

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
    } catch (invalid_argument &ex) {
        cout << ex.what() << endl;
        cout << "Intente nuevamente" << endl;
    }
}

DtFecha fechaDialog() {
    cout << "Formato DD MM YYYY HH" << endl;
    int dia, mes, anio, hora;
    cin >> dia >> mes >> anio >> hora;
    try {
        return {hora, dia, mes, anio};
    } catch (invalid_argument &e) {
        cout << e.what() << endl;
        cout << "Intente nuevamente" << endl;
        return fechaDialog();
    }
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

    try {
        mostrarElegirHostal_ReservaController();

        cout << "Ingrese fecha de inicio: ";
        DtFecha inicio = fechaDialog();
        cout << "Ingrese fecha de fin: ";
        DtFecha fin = fechaDialog();
        reservaController->especificarFechas(inicio, fin);

        bool esGrupal = tipoReservaDialog();
        mostrarElegirHabitacion();
        list<DtHuesped> huespedes = reservaController->mostrarHuespedes();
        cout << "Los Huespedes disponibles son: " << endl;
        for (const auto &huesped: huespedes)
            cout << huesped << endl;
        cout << "Ingrese el email del huesped que esta realizando la Reserva: ";
        string email;
        cin >> email;

        reservaController->elegirHuespedReservante(email);
        if (esGrupal) {
            int hayNuevosHuespedes = 0;
            while (hayNuevosHuespedes != 2) {
                cout << "Desea agregar otro huesped? (1. Si, 2. No)" << endl;
                cin >> hayNuevosHuespedes;
                while (hayNuevosHuespedes != 1 && hayNuevosHuespedes != 2) {
                    cout << "Opcion invalida, ingrese nuevamente: ";
                    cin >> hayNuevosHuespedes;
                }
                if (hayNuevosHuespedes == 1) {
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
    } catch (invalid_argument &ex) {
        cout << ex.what() << endl;
        cout << "Intente nuevamente" << endl;
    }
}

void bajaReserva() {
    try {
        ControllerFactory *factory = ControllerFactory::getInstance();
        IReservaController *reservaController = factory->getReservaController();

        mostrarElegirHostal_ReservaController();

        list<DtReserva *> reservas = reservaController->informacionReservas();
        cout << "Las reservas disponibles son: " << endl;
        for (const auto &reserva: reservas) {
            cout << reserva << endl;
            delete reserva;
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
    } catch (invalid_argument &ex) {
        cout << ex.what() << endl;
        cout << "Intente nuevamente" << endl;
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
    try {
        ControllerFactory *factory = ControllerFactory::getInstance();
        IReservaController *reservaController = factory->getReservaController();

        mostrarElegirHostal_ReservaController();

        list<DtHuesped> huespedes = reservaController->mostrarHuespedes();
        cout << "Los Huespedes disponibles son: " << endl;
        for (const auto &huesped: huespedes)
            cout << huesped << endl;

        cout << "Ingrese el mail del huesped que desea registrar su estadia: " << endl;
        string email;
        cin >> email;

        list<DtReserva *> reservas = reservaController->mostrarReservasNoCanceladas(email);
        cout << "Para el Huesped indicado, las reservas disponibles para registra estadia son: " << endl;
        for (const auto &reserva: reservas) {
            cout << reserva << endl;
            delete reserva;
        }

        cout << "Ingrese el codigo de la reserva que desea registrar: " << endl;
        int numero;
        cin >> numero;

        reservaController->registrarEstadia(numero);
        cout << "Estadia registrada" << endl;
    } catch (invalid_argument &ex) {
        cout << ex.what() << endl;
        cout << "Intente nuevamente" << endl;
    }
}


void finalizarEstadia() {
    try {
        ControllerFactory *factory = ControllerFactory::getInstance();
        IReservaController *reservaController = factory->getReservaController();

        mostrarElegirHostal_ReservaController();

        list<DtHuesped> huespedes = reservaController->mostrarHuespedes();
        cout << "Los Huespedes disponibles son: " << endl;
        for (const auto &huesped: huespedes)
            cout << huesped << endl;

        cout << "Ingrese el mail del huesped que desea finalizar su estadia: " << endl;
        string email;
        cin >> email;

        reservaController->finalizarReservasActivasDeUsuario(email);
        cout << "Estadia finalizada" << endl;
    } catch (invalid_argument &ex) {
        cout << ex.what() << endl;
        cout << "Intente nuevamente" << endl;
    }
}

void printEstadias(list<DtEstadia> &estadias) {
    for (const DtEstadia &estadia: estadias)
        cout << estadia << endl;
}

void calificarEstadia() {
    try {
        ControllerFactory *factory = ControllerFactory::getInstance();
        INotificacionController *notificacionController = factory->getNotificacionController();

        mostrarElegirHostal_NotificacionController();

        list<DtHuesped> huespedes = notificacionController->mostrarHuespedes();
        cout << "Los Huespedes disponibles son: " << endl;
        for (const auto &huesped: huespedes)
            cout << huesped << endl;

        cout << "Ingrese el mail del huesped que desea calificar alguna de sus estadias: " << endl;
        string email;
        cin >> email;
        notificacionController->setMail(email);

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
        cin.ignore();
        getline(cin, resenia);
        notificacionController->ingresarCalificacion(calificacion, resenia);
    } catch (invalid_argument &ex) {
        cout << ex.what() << endl;
        cout << "Intente nuevamente" << endl;
    }
}

void comentarCalificacion() {
    try {
        ControllerFactory *factory = ControllerFactory::getInstance();
        INotificacionController *notificacionController = factory->getNotificacionController();

        list<DtEmpleado> empleados = notificacionController->mostrarEmpleados();
        cout << "Los empleados disponibles son: " << endl;
        for (const auto &empleado: empleados)
            cout << empleado << endl;

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
        } else cout << "No hay calificaciones disponibles para comentar" << endl;
    } catch (invalid_argument &ex) {
        cout << ex.what() << endl;
        cout << "Intente nuevamente" << endl;
    }
}

void consultaUsuario() {
    try {
        ControllerFactory *factory = ControllerFactory::getInstance();
        IUsuarioController *usuarioController = factory->getUsuarioController();

        list<DtUsuario> usuarios = usuarioController->mostrarUsuarios();
        cout << "Los usuarios registrados son: " << endl;
        for (const auto &usuario: usuarios)
            cout << usuario << endl;

        cout << "Ingrese el mail del usuario que desea consultar: " << endl;
        string email;
        cin >> email;
        DtUsuario usuario = usuarioController->mostrarInformacionUsuario(email);
        cout << "La informacion del usuario es: " << endl;
        cout << usuario << endl;

        cout << "Operacion finalizada" << endl;
    } catch (invalid_argument &ex) {
        cout << ex.what() << endl;
        cout << "Intente nuevamente" << endl;
    }
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

    try {
        mostrarElegirHostal_ReservaController();

        list<DtReserva *> reservas = reservaController->mostrarReservas();
        cout << "Las reservas disponibles son: " << endl;
        for (const auto &reserva: reservas) {
            cout << reserva << endl;
        }

        cout << endl;
        cout << "Operacion finalizada" << endl;
    } catch(invalid_argument &ex){
        cout << ex.what() << endl;
    }


}

void consultaEstadia() {
    ControllerFactory *factory = ControllerFactory::getInstance();
    IReservaController *reservaController = factory->getReservaController();

    try {
        mostrarElegirHostal_ReservaController();

        list<DtEstadia> estadias = reservaController->listarEstadias();
        cout << "Las estadias disponibles son: " << endl;
        printEstadias(estadias);

        cout << "Seleccione el codigo de la estadia que desea consultar: " << endl;
        int numero;
        cin >> numero;
        try {
            reservaController->seleccionarEstadia(numero);
            DtEstadia estadia = reservaController->mostrarInformacionEstadia();
            cout << "La informacion de la estadia es: " << endl;
            cout << estadia;

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
        }catch(invalid_argument &ex){
            cout << ex.what() << endl;
        }

    } catch(invalid_argument &ex){
        cout << ex.what() << endl;
    }

}

void subscribirseANotificaciones() {
    ControllerFactory *factory = ControllerFactory::getInstance();
    INotificacionController *notificacionController = factory->getNotificacionController();

    list<DtEmpleado> empleados = notificacionController->mostrarEmpleados();
    cout << "Los empleados disponibles son: " << endl;
    for (const auto &empleado: empleados) {
        cout << empleado << endl;
    }

    try {
        cout << "Ingrese el mail del empleado que desea subscribirse: " << endl;
        string email;
        cin >> email;
        notificacionController->suscribirANotificaciones(email);

        cout << endl;
        cout << "El empleado fue suscrito a las notificaciones" << endl;
    } catch(invalid_argument &ex){
        cout << ex.what() << endl;
    }
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

    try {
        list<DtNotificacion> notificaciones = notificacionController->consultaDeNotificaciones(email);
        cout << "Las notificaciones del empleado son: " << endl;
        printNotificaciones(notificaciones);

        cout << endl;
        cout << "Operacion finalizada" << endl;
    } catch (invalid_argument &ex) {
        cout << ex.what() << endl;
        cout << "Esto puede deberse, por otro lado, a que el empleado no este subscripto." << endl;
    }
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

    try {
        notificacionController->eliminarSubscripcion(email);
        cout << endl;
        cout << "El empleado no esta mas suscrito" << endl;
    } catch (invalid_argument &ex) {
        cout << ex.what() << endl;
        cout << "Esto puede deberse, por otro lado, a que el empleado no este subscripto." << endl;
    }
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
    mainApp();
    return 0;
}
