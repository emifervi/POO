#pragma once

#include "CtaBanc.h"
class Chequera : public CtaBanc{
public:
    Chequera();
    Chequera(int n, int s, int c);
    int getComision();
    void setComision(int c);
    void muestra();
    bool retira(double cant);

private:
    int comision;
};

Chequera::Chequera() : CtaBanc(){
    comision = 0;
}

Chequera::Chequera(int n, int s, int c) : CtaBanc(n, s){
    comision = c;
}

void Chequera::setComision(int c){
    comision = c;
}

int Chequera::getComision(){
    return comision;
}

bool Chequera::retira(double cant){
    if(saldo - comision >= cant){
        saldo -= comision + cant;
        return true;
    }
    else{
        return false;
    }
}

void Chequera::muestra(){
    CtaBanc::mostrar();
    cout << " comision " << comision << endl;
}
