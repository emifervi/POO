#include <iostream>
#include <string>
using namespace std;
#include "Empleado.h"
#include "Comisionista.h"
#include "TiempoParcial.h"

int main(){
    // Arreglo de empleados.
    Empleado *lista[4];
    // Variables a utilizar para crear objetos de apoyo.
    string nombre, apellido;
    int nomina, extra;
    double sueldo;
    
    for(int i = 0; i < 4; i++){
        // Se piden los datos del empleado.
        cout << "Dame el nombre del empleado\n";
        getline(cin, nombre);
        cout << "Dame el apellido del empleado\n";
        getline(cin, apellido);
        cout << "Introduce la nomina de " << nombre << "\n";
        cin >> nomina;
        cout << "Introduce el sueldo base de " << nombre << "\n";
        cin >> sueldo;
        // Caso de los comisionistas
        if (i < 2){
            cout << "Introduce el numero de ventas de " << nombre << "\n";
            cin >> extra;
            // Se crea un objeto con los datos obtenidos.
            Comisionista *comTemp = new Comisionista(nombre, apellido, nomina, sueldo, extra);
            // Se indexa el objeto al arreglo.
            lista[i] = comTemp;
        }
        // Caso de los part timmers
        else{
            cout << "Introduce el numero de horas extra trabajadas por " << nombre << "\n";
            cin >> extra;
            // Se crea un objeto con los datos obtenidos.
            TiempoParcial *parTemp = new TiempoParcial(nombre, apellido, nomina, sueldo, extra);
            // Se indexa el objeto al arreglo.
            lista[i] = parTemp;
        }
        cin.ignore();
    }
    
    for(int i = 0; i < 4; i++){
        cout << "========================================================================" << endl;
        lista[i]->mostrar();
        cout << "========================================================================" << endl;
    }

    return 0;
}