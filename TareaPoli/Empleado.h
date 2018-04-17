#ifndef Empleado_h_included
#define Empleado_h_included
class Empleado
{
public:
    // Interfaz de constructores.
    Empleado();
    Empleado(string n, string a, int iNomina, double sueldo);

    // Interfaz de metodos de modificacion.
    void setNombre(string n);
    void setApellido(string a);
    void setNomina(int iNomina);
    void setSueldo(double sueldo);

    // Interfaz de metodos de acceso.
    string getNombre();
    string getApellido();
    int getNomina();
    double getSueldo();

    // Metodos virtuales puros.
    virtual double calcularPago() = 0;
    virtual void mostrar() = 0;

protected:
    // Atributos de la clase.
    string nombre, apellido;
    int nomina;
    double sueldoBase;

};

/**
 * Constructor default.
 * Da valores predeterminados a los atributos del objeto.
 * Argumentos: ninguno.
 */
Empleado::Empleado(){
    nombre = "";
    apellido = "";
    nomina = 0;
    sueldoBase = 0.0;
}
/**
 * Constructor con parametros.
 * Permite al usuario crear un objeto con parametros predefinidos por él.
 * Argumentos: valores para crear objeto.
 */
Empleado::Empleado(string n, string a, int iNomina, double sueldo){
    nombre = n;
    apellido = a;
    nomina = iNomina;
    sueldoBase = sueldo;
}

/**
 * Metodo de modificacion del nombre.
 * Argumentos: recibe el nombre.
 */
void Empleado::setNombre(string n){
    nombre = n;
}
/**
 * Metodo de modificacion del apellido.
 * Argumentos: recibe el apellido.
 */
void Empleado::setApellido(string a){
    apellido = a;
}
/**
 * Metodo de modificacion de la nomina.
 * Argumentos: recibe la nomina.
 */
void Empleado::setNomina(int iNomina){
    nomina = iNomina;
}
/**
 * Metodo de modificacion del sueldo.
 * Argumentos: recibe el sueldo.
 */
void Empleado::setSueldo(double sueldo){
    sueldoBase = sueldo;
}

/**
 * Metodo de acceso al nombre.
 * Retornos: nombre.
 */
string Empleado::getNombre(){
    return nombre;
}
/**
 * Metodo de acceso al apellido.
 * Retornos: apellido.
 */
string Empleado::getApellido(){
    return apellido;
}
/**
 * Metodo de acceso a la nomina.
 * Retornos: nomina.
 */
int Empleado::getNomina(){
    return nomina;
}
/**
 * Metodo de acceso al sueldo.
 * Retornos: sueldo base.
 */
double Empleado::getSueldo(){
    return sueldoBase;
}

#endif //  Empleado_h_included
