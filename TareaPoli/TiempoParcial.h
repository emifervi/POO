#ifndef TiempoParcial_h_included
#define TiempoParcial_h_included
#include "Empleado.h"
class TiempoParcial : public Empleado{
public:
    // Interfaz de constructores
    TiempoParcial();
    TiempoParcial(string n, string a, int iNomina, double sueldo, int hExtra);

    // Interfaz metodo de modificacion.
    void setHorasExtra(int hExtra);

    // Interfaz metodo de acceso.
    double getHorasExtra();

    // Metodos funcionales.
    double calcularPago();
    void mostrar();

private:
    int horasExtra;
};
/**
 * Constructor default.
 * Da valores predeterminados a los atributos del objeto.
 * Argumentos: ninguno.
 */
TiempoParcial::TiempoParcial() : Empleado(){
    horasExtra = 0;
}
/**
 * Constructor con parametros.
 * Permite al usuario crear un objeto con parametros predefinidos por él.
 * Argumentos: valores para crear objeto.
 */
TiempoParcial::TiempoParcial(string n, string a, int iNomina, double sueldo, int hExtra) : Empleado(n, a, iNomina, sueldo){
    horasExtra = hExtra;
}

/**
 * Metodo de modificacion de horas extra
 * Argumentos: recibe la cantidad de horas extra trabajadas
 */
void TiempoParcial::setHorasExtra(int hExtra){
    horasExtra = hExtra;
}

/**
 * Metodo de acceso de horas extra
 * Retornos: horas extra trabajadas.
 */
double TiempoParcial::getHorasExtra(){
    return horasExtra;
}

/**
 * Metodo de calculo del pago para comisionista
 * Argumentos: ninguno.
 * Retornos: double representativo del pago de los part timmers.
 */
double TiempoParcial::calcularPago(){
    return sueldoBase + (250 * horasExtra);
}

/**
 * Metodo muestra
 * Argumentos: ninguno.
 * Retornos: ninguno.
 */
void TiempoParcial::mostrar(){
    cout << "Nomina: " << nomina << endl;
    cout << "Nombre: " << nombre << " " << apellido << endl;
    cout << "Sueldo Base: $" << sueldoBase << endl;
    cout << "Horas extra trabajadas: " << horasExtra << endl;
    cout << "Monto por horas extra: $" << horasExtra * 250 << endl;
    cout << "Sueldo Total: $" << calcularPago() << endl;
}

#endif //  TiempoParcial_h_included
