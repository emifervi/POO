#pragma once

class Cuadratica
{
public:
    Cuadratica();
    Cuadratica(int, int, int);
    void muestra();

    //sobre carga del operador + utilizando función miembro
    Cuadratica operator + (Cuadratica sumando);
    //sobre carga del operador * utilizando función miembro.
    Cuadratica operator * (int multiplicando);
    //sobre carga del operador == utilizando función miembro.
    bool operator == (Cuadratica arg);

    //sobre carga del operador - utilizando función amiga
    friend Cuadratica operator - (Cuadratica a, Cuadratica b);
    //sobre carga del operador += utilizando función amiga
    friend void operator += (Cuadratica &a, Cuadratica b);
    //sobre carga del operador ++ utilizando función amiga
    friend Cuadratica operator ++ (Cuadratica &a, int);
    //sobre carga de operador << utilizando función amiga
    friend ostream& operator << (ostream &os, Cuadratica a);
    // sobre carga de operador >> utilizando funcion amiga
    friend istream& operator >> (istream &is, Cuadratica &a);

    double evalua(double n);

private:
    int iCoefA, iCoefB, iCoefC;
};

Cuadratica::Cuadratica(){
    iCoefA = 0;
    iCoefB = 0;
    iCoefC = 0;
}

Cuadratica::Cuadratica(int iA, int iB, int iC){
    iCoefA = iA;
    iCoefB = iB;
    iCoefC = iC;
}

void Cuadratica::muestra(){
    if (iCoefA != 0){
        cout << iCoefA;
        cout << "x^2 ";
    }
 
    if (iCoefB != 0){
        if (iCoefB > 0)
        cout << " + ";
        cout << iCoefB;
        cout << "x ";
    }
 
    if (iCoefC != 0){
        if (iCoefC > 0)
        cout << " + ";
        cout << iCoefC;
    }
    cout << endl;
}

Cuadratica Cuadratica::operator + (Cuadratica sumando){
    Cuadratica resultado;
    resultado.iCoefA = iCoefA + sumando.iCoefA;
    resultado.iCoefB = iCoefB + sumando.iCoefB;
    resultado.iCoefC = iCoefC + sumando.iCoefC;

    return resultado;
}

Cuadratica operator - (Cuadratica a, Cuadratica b){
    Cuadratica res;
    res.iCoefA = a.iCoefA - b.iCoefA;
    res.iCoefB = a.iCoefB - b.iCoefB;
    res.iCoefC = a.iCoefC - b.iCoefC;

    return res;
}

Cuadratica Cuadratica::operator * (int multiplicando){
    Cuadratica res;
    res.iCoefA = iCoefA * multiplicando;
    res.iCoefB = iCoefB * multiplicando;
    res.iCoefC = iCoefC * multiplicando;

    return res;
}

void operator += (Cuadratica &a, Cuadratica b){
    a.iCoefA = a.iCoefA + b.iCoefA;
    a.iCoefB = a.iCoefB + b.iCoefB;
    a.iCoefC = a.iCoefC + b.iCoefC;
}

bool Cuadratica::operator == (Cuadratica arg){
    if(iCoefA == arg.iCoefA && iCoefB == arg.iCoefB && iCoefC == arg.iCoefC)
        return true;
    
    else
        return false;
}

Cuadratica operator ++ (Cuadratica &a, int){
    a.iCoefC++;
    Cuadratica nueva;
    nueva.iCoefA = a.iCoefA;
    nueva.iCoefB = a.iCoefB;
    nueva.iCoefC = a.iCoefC;
    return nueva;
}


ostream& operator << (ostream &os, Cuadratica a){
    if (a.iCoefA != 0){
        os << a.iCoefA;
        os << "x^2 ";
    }
 
    if (a.iCoefB != 0){
        if (a.iCoefB > 0)
        os << " + ";
        os << a.iCoefB;
        os << "x ";
    }
 
    if (a.iCoefC != 0){
        if (a.iCoefC > 0)
        os << " + ";
        os << a.iCoefC;
    }
    os << endl;

    return os;
}

istream& operator >> (istream &is, Cuadratica &a){
    is >> a.iCoefA;
    is >> a.iCoefB;
    is >> a.iCoefC;

    return is;
}

double Cuadratica::evalua(double n){
    return iCoefA * n * n + iCoefB * n + iCoefC;
}