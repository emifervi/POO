#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(){
    ifstream inFile;
    ofstream grupo1, grupo2, grupo3;
    string studentInfo;

    inFile.open("SemanaI.txt");
    grupo1.open("Grupo1.txt");
    grupo1 << "**** Grupo 1 ****" << endl;

    grupo2.open("Grupo2.txt");
    grupo2 << "**** Grupo 2 ****" << endl;

    grupo3.open("Grupo3.txt");
    grupo3 << "**** Grupo 3 ****" << endl;

    while (!inFile.eof()){
        getline(inFile, studentInfo);
        if (studentInfo[studentInfo.length() - 1] == '1'){
            studentInfo.erase(studentInfo.length() - 1);
            grupo1 << studentInfo << endl;
        }
        if (studentInfo[studentInfo.length() - 1] == '2'){
            studentInfo.erase(studentInfo.length() - 1);
            grupo2 << studentInfo << endl;
        }
        if (studentInfo[studentInfo.length() - 1] == '3'){
            studentInfo.erase(studentInfo.length() - 1);
            grupo3 << studentInfo << endl;
        }
    }

    return 0;
}
