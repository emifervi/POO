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
    virtual double calculaPago() = 0;
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
 * No recibe argumentos.
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
 * Recibe los valores necesarios para crear el objeto.
 */
Empleado::Empleado(string n, string a, int iNomina, double sueldo){
    nombre = n;
    apellido = a;
    nomina = iNomina;
    sueldoBase = sueldo;
}

/**
 * Metodo de modificacion del nombre.
 */
void Empleado::setNombre(string n){
    nombre = n;
}
/**
 * Metodo de modificacion del apellido.
 */
void Empleado::setApellido(string a){
    apellido = a;
}
/**
 * Metodo de modificacion de la nomina.
 */
void Empleado::setNomina(int iNomina){
    nomina = nom;
}
/**
 * Metodo de modificacion del sueldo.
 */
void Empleado::setSueldo(double sueldo){
    sueldoBase = sueldo;
}

/**
 * Metodo de acceso al nombre.
 */
string Empleado::getNombre(){
    return nombre;
}
/**
 * Metodo de acceso al apellido.
 */
string Empleado::getApellido(){
    return apellido;
}
/**
 * Metodo de acceso a la nomina.
 */
int Empleado::getNomina(){
    return nomina;
}
/**
 * Metodo de acceso al sueldo.
 */
double Empleado::getSueldo(){
    return sueldoBase;
}

#endif //  Empleado_h_included
