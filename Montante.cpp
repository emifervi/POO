#include <iostream>
#include <vector>
using namespace std;

void fillData(vector < vector<double> >& mat, int eq, int var){
	double coef;
	for (int i = 0; i < eq; i++){

		// Vector de filas para pasarselo al vector de vectores.
		vector<double> row;

		// Se pide al usuario el valor de las variables con su indice y la ecuación a la que pertenecen.
		for (int j = 0; j < var; j++){
			if (j == var - 1){
				cout << "Valor de b en la ecuacion " << i + 1 << endl;
			}
			else{
				cout << "Coeficiente de la variable " << j + 1 << " en la ecuacion " << i + 1 << endl;
			}
			cin >> coef;

			// Se pasa el coeficiente al vector unitario.
			row.push_back(coef);
		}
		// Se pasa el vector con los coeficientes como fila al vector de vectores.
		mat.push_back(row);
	}
}

void dispData(vector < vector<double> >& mat, int eq, int var){
	for( int i = 0; i < eq; i++){
		for (int j = 0; j < var; j++){
			cout << mat[i][j] << " ";
		}
		cout << endl;
	}
}


int main(){
	// Variables a utilizar para guardar info.
	int eq, var, count = 0;
	//double coef;

	// Pide el nunmero de ecuaciones y variable a utilizar en el sistema y valida que sean iguales.
	do{
		// Si es la primera vez que se hace el input, es directo, si no, se imprime el mensaje de error.
		if (count > 0){
			cout << "Error, numero de ecuaciones y variables debe ser igual" << endl;
		}
		cout << "Cuantas equaciones se van a utilizar ?" << endl;
		cin >> eq;
		cout << "Cuantas variables ?" << endl;
		cin >> var;

		count++;
	}while (eq != var);

	// Eq = filas
	// Var = columnas;

	// Se actualiza el valor de las variables para crear espacio para un los resultados en la matriz aumentada.
	var++;

	// Vector de vectores para crear "arreglo" bidimensional.
	vector< vector<double> > matrix;

	fillData(matrix, eq, var);
	dispData(matrix, eq, var);

	return 0;
}

