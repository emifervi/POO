// Description: The program asks the user for a number of coordinates and then asks him to fill the coordinates after filling it,
// it calculates the minimum distances between points and which points are the closest ones.
// Author: Emilio Fernando Alonso Villa A00959385
// Date: 10 January 2018

#include <iostream>
#include <cmath>
using namespace std;

// Declare global variables.
int iRows, iX, iY, iSize;
double dGlobalMin;


// Function to let the user fill the coordinates array.
// Arguments: array with coordinates given by the user.
// Returns: no return.
void FillData(double fillData[][2]){

    cout << "Fill the in the coordinates first give the \"x\" coordinate, click space and then give the \"y\".\n";
    cout << "After that click \"enter\" to input the next set of coordinates.\n";

    for(iX = 0; iX < iRows; iX++){
        for (iY = 0; iY < 2; iY++){
            cin >> fillData[iX][iY];
        }
    }
}

// Calculates the size of an array to store the distance between N number of points.
// Arguments: the number of rows provided by the user.
// Return: size of the array which will store all the distances.
int arrSize(int numRows){

    int iSize = 0;

    for (iX = 1; iX < numRows; iX ++){
        iSize += iX;
    }

    return iSize;
}

// Function to calculate the distance between two points.
// Arguments: array with the coordinates provided by the user.
// Return: returns the distance between the points provided by the array.
double distanceP2P (double arrDistCoord[][2]){
    double dDist = sqrt( pow ((arrDistCoord[iY][0] - arrDistCoord[iX][0]), 2) +
                         pow ((arrDistCoord[iY][1] - arrDistCoord[iX][1]), 2));

    return dDist;
}

// Stores the distance between all points and gets the smallest one.
// Arguments: the array of coordinates provided by the user.
// Returns: the smallest distance between points.
double CalcDist(double arrCoords[][2]){

    double dArrDist[iSize], dMin;
    int iCounter = 0;

    for(iX = 0; iX < iRows; iX++){
        for (iY = 1 + iX; iY < 8; iY++){
            dArrDist[iCounter] = distanceP2P(arrCoords);
            iCounter ++;
        }
    }

    dMin = dArrDist[0];

    for (iX = 0; iX < iSize; iX++){
        if (dMin > dArrDist[iX]){
            dMin = dArrDist[iX];
        }
    }

    return dMin;
}

// Finds the coordinates that give the minimum distance.
// Arguments: array of coordinates given by the user and the minimum distance.
// Return: no return, prints set of coordinates with the smallest distance.
void FindCoords(double pointArray[][2], double dMinDist){

    double dDistances[iSize];
    int iCounter = 0;

    for(iX = 0; iX < iRows; iX++){
        for (iY = 1 + iX; iY < 8; iY++){
            dDistances[iCounter] = distanceP2P(pointArray);
            if (dDistances[iCounter] == dMinDist){
                cout << "The points: (" << pointArray[iY][0] << "," << pointArray[iY][1]
                     << ") and (" << pointArray[iX][0] << "," << pointArray[iX][1] << ")"
                     << " are the closest ones.";
                break;
            }
            iCounter ++;
        }
    }
}

// Main Function, starts the program and calls the rest of the functions.
int main(){
    do{
        cout << "How many pair of coordinates will you have?\n";
        cin >> iRows;
    }while (iRows <= 0);

    double arrCoordinates[iRows][2];

    FillData(arrCoordinates);
    iSize = arrSize(iRows);
    dGlobalMin = CalcDist(arrCoordinates);
    cout << "The minimum distance is: " << dGlobalMin << endl;
    FindCoords(arrCoordinates, dGlobalMin);

    return 0;
}
