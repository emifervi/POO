#ifndef Comisionista_h_included
#define  Comisionista_h_included
#include "Empleado.h"
class Comisionista : public Empleado{
public:
    // Interfaz de constructores
    Comisionista();
    Comisionista(string n, string a, int iNomina, double sueldo, double ventas);
    
    // Interfaz metodo de modificacion.
    void setCantVendida(double ventas);

    // Interfaz metodo de acceso.
    double getCantVentida();

    // Metodos funcionales.
    double calcularPago();
    void mostrar();

private:
    double cantVendida;
};
/**
 * Constructor default.
 * Da valores predeterminados a los atributos del objeto.
 * Argumentos: ninguno.
 */
Comisionista::Comisionista() : Empleado(){
    cantVendida = 0;
}
/**
 * Constructor con parametros.
 * Permite al usuario crear un objeto con parametros predefinidos por él.
 * Argumentos: valores para crear objeto.
 */
Comisionista::Comisionista(string n, string a, int iNomina, double sueldo, double ventas) : Empleado(n, a, iNomina, sueldo){
    cantVendida = ventas;
}

/**
 * Metodo de modificacion de cantidad vendida
 * Argumentos: recibe las ventas.
 */
void Comisionista::setCantVendida(double ventas){
    cantVendida = ventas;
}

/**
 * Metodo de acceso a la cantidad de ventas.
 * Retornos: cantidad vendida.
 */
double Comisionista::getCantVentida(){
    return cantVendida;
}

/**
 * Metodo de calculo del pago para comisionista
 * Argumentos: ninguno.
 * Retornos: double representativo del pago del comisionista.
 */
double Comisionista::calcularPago(){
    if (cantVendida >= 15000 && cantVendida <= 35000){
        return sueldoBase * .06;
    }
    else if(cantVendida > 35000){
        return sueldoBase * .10;
    }
    else{
        return 0.0;
    }
}

/**
 * Metodo muestra
 * Argumentos: ninguno.
 * Retornos: ninguno.
 */
void Comisionista::mostrar(){
    cout << "Nomina: " << nomina << endl;
    cout << "Nombre: " << nombre << " " << apellido << endl;
    cout << "Sueldo Base: $" << sueldoBase << endl;
    cout << "Sueldo Por Comision $" << calcularPago() << endl;
    cout << "Sueldo Total: $" << sueldoBase + calcularPago() << endl;
}

#endif //  Comisionista_h_included
