#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
using namespace std;

double syntheticDiv(int deg, double x,  double arrConst[]){

    // Variables to store the result of evaluating the polynomial on a given X and its derivative.
    double residue, derivate;
    // Array to store the coefficients for the derivative.
    double arrDeriv[deg - 1];

    // Evaluate the polynomial on given X with synthetic division.
    for (int i = 0; i < deg; i++){
        // First number is not modified
        if ( i == 0){
            residue = arrConst[i];
            // Store the first number on the other array.
            arrDeriv[i] = residue;
        }
        else {
            // Last number doesn't get stored.
            if (i == deg - 1){
                residue  = (residue * x) + arrConst[i];
            }
            // The rest of the numbers are multiplied added and stored.
            else{
                residue = (residue * x) + arrConst[i];
                arrDeriv[i] = residue;
            }
        }
    }
    // When the residue is lesser than an error index, it returns the residue.
    if (residue <= .00001){
        return residue;
    }
    // If it's not lesser than the error evaluates the derivate through second synthetic division.
    else{
        for (int i = 0; i < deg - 1; i++){
            // First number not modified.
            if ( i == 0){
                derivate = arrDeriv[i];
            }
            // Rest of the numbers multiplied and added.
            else{
                derivate = (derivate * x) + arrDeriv[i];
            }
        }

        // Return the difference needed for Birge-Vieta estimation.
        return (residue / derivate);
    }
}

int main(){

    // Initiate seed for a random number.
    srand(unsigned (time(NULL)));

    // Variables to store the degree (provided by the user), the maximum number, and the number of iterations.
    int degree, iMax = 1000000000, iF = -1, roots, numIF;

    // Variables to store the result and the X of the function.
    double result, randX, epsilon;

    // Variable to chose if try another or not.
    char cOption;

    // Assign a random number between -1000000000 to 1000000000.
    randX = (double)rand() / (RAND_MAX + 1) + (-iMax) + (rand() % ((iMax*2) + 1));
    do{
        iF = -1;
        // Ask user for the degree of the polinomial and receive it.
        cout << "\nDe que grado es el polinomio ?\n";
        cin >> degree;
        cout << "Cual es el numero maximo de iteraciones? ";
        cin >> numIF;
        cout << "Cual es la tolerancia de error (epsilon)? ";
        cin >> epsilon;

        // Add one to the degree to compensate for term X^0 and declare array to store the coefficients.
        roots = degree;
        degree++;
        double arrCoefficients[degree];

        // Ask user to provide the coefficients one by one and store them in the array.
        cout << "Introduce por favor los coeficientes de tu polinomio\n";
        for (int i = 0; i < degree; i++){
            cout << "\n+ Introduce el coeficiente de grado " << degree - i - 1 << ": ";
            cin >> arrCoefficients[i];
        }
        do{
            do{
                // Call the synthetic division function passing the coefficients, degree and x as arguments.
                result = syntheticDiv(degree, randX, arrCoefficients);
                // update value of X and number of iterations.
                randX -= result;
                iF ++;

                // Check if it need another round.
            }while (abs(result) > epsilon);

            // Print the root and its evaluation.
            cout << "\nLa raiz es: " << randX << endl;
            cout << "Evaluada en: " << result << endl;

            // Reduce the degree of the polynomial evaluating with the root
            for(int i = 0; i < degree; i++){
                if(i == 0){
                    result = arrCoefficients[i];
                    arrCoefficients[i] = result;
                }
                else{
                    result = (result * randX) + arrCoefficients[i];
                    if (abs(result) <= .0001){
                        result = 0;
                    }
                    arrCoefficients[i] = result;
                }
            }

            // Update the degree of the polynomial and the number of roots found.
            degree--;
            roots--;
            if (roots == 0){
                iF = numIF;
            }
        }while (iF < numIF);

        cout << "\nQuiere probar otro polinomio ?";
        cin >> cOption;
    } while (cOption != 'n');

    return 0;
}
