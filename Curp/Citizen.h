#ifndef CITIZEN_H_INCLUDED
#define CITIZEN_H_INCLUDED

class Citizen{
private:
    // Class attributes.
    string firstName;
    string secondName;
    string lastName;
    string mothersName;
    string year;
    string month;
    string day;
    string gender;
    string state;
    string curp;

public:
    // Access and modification methods.
    void setFirstName(string fN);
    void setSecondName(string sN);
    void setLastName(string lN);
    void setMothersName(string sLN);
    void resetMothersName();
    void setYear(string y);
    void setMonth(string m);
    void setDay(string d);
    void setGender(string g);
    void setState(string s);
    void setCurp(string c);
    string getFirstName();
    string getSecondName();
    string getLastName();
    string getMothersName();
    string getYear();
    string getMonth();
    string getDay();
    string getGender();
    string getState();
    string getCurp();
    // Functional method.
    string generateCurp();
};

// Declaration and development of the methods.
void Citizen::setFirstName(string fN){
    firstName = fN;
}
void Citizen::setSecondName(string sN){
    secondName = sN;
}
void Citizen::setLastName(string lN){
    lastName = lN;
}
void Citizen::setMothersName(string sLN){
    mothersName = sLN;
}
void Citizen::resetMothersName(){
    mothersName = " ";
}
void Citizen::setYear(string y){
    year = y;
}
void Citizen::setMonth(string m){
    if(m == "enero"){
        month = "01";
    }
    if(m == "febrero"){
        month = "02";
    }
    if(m == "marzo"){
        month = "03";
    }
    if(m == "abril"){
        month = "04";
    }
    if(m == "mayo"){
        month = "05";
    }
    if(m == "junio"){
        month = "06";
    }
    if(m == "julio"){
        month = "07";
    }
    if(m == "agosto"){
        month = "08";
    }
    if(m == "septiembre"){
        month = "09";
    }
    if(m == "octubre"){
        month = "10";
    }
    if(m == "noviembre"){
        month = "11";
    }
    if(m == "diciembre"){
        month = "12";
    }
}
void Citizen::setDay(string d){
    day = d;
}
void Citizen::setGender(string g){
    gender = g;
}
void Citizen::setState(string st){
    string s = "";
    for (int i = 0; i < st.length(); i++){
        s += toupper(st[i]);
    }

    if (s == "AGUASCALIENTES"){
        state = "AS";
    }
    else if (s == "BAJA CALIFORNIA"){
        state = "BC";
    }
    else if (s == "BAJA CALIFORNIA SUR"){
        state = "BS";
    }
    else if (s == "CAMPECHE"){
        state = "CC";
    }
    else if (s == "COAHUILA"){
        state = "CL";
    }
    else if (s == "COLIMA"){
        state = "CM";
    }
    else if (s == "CHIAPAS"){
        state = "CS";
    }
    else if (s == "CHIHUAHUA"){
        state = "CH";
    }
    else if (s == "D.F."){
        state = "DF";
    }
    else if (s == "DURANGO"){
        state = "DG";
    }
    else if (s == "GUANAJUATO"){
        state = "GT";
    }
    else if (s == "GUERRERO"){
        state = "GR";
    }
    else if (s == "HIDALGO"){
        state = "HG";
    }
    else if (s == "JALISCO"){
        state = "JC";
    }
    else if (s == "MEXICO" || s == "ESTADO DE MEXICO"){
        state = "MC";
    }
    else if (s == "MICHOACAN"){
        state = "MN";
    }
    else if (s == "MORELOS"){
        state = "MS";
    }
    else if (s == "NAYARIT"){
        state = "NT";
    }
    else if (s == "NUEVO LEON"){
        state = "NL";
    }
    else if (s == "OAXACA"){
        state = "OC";
    }
    else if (s == "PUEBLA"){
        state = "PL";
    }
    else if (s == "QUERETARO"){
        state = "QT";
    }
    else if (s == "QUINTANA ROO"){
        state = "QR";
    }
    else if (s == "SAN LUIS POTOSI"){
        state = "SP";
    }
    else if (s == "SINALOA"){
        state = "SL";
    }
    else if (s == "SONORA"){
        state = "SR";
    }
    else if (s == "TABASCO"){
        state = "TC";
    }
    else if (s == "TAMAULIPAS"){
        state = "TS";
    }
    else if (s == "TLAXCALA"){
        state = "TL";
    }
    else if (s == "VERACRUZ"){
        state = "VZ";
    }
    else if (s == "YUCATAN"){
        state = "YN";
    }
    else if (s == "ZACATECAS"){
        state = "ZS";
    }
    else{
        state = "NE";
    }

}
void Citizen::setCurp(string c){
    curp = c;
}
string Citizen::getFirstName(){
    return firstName;
}
string Citizen::getSecondName(){
    return secondName;
}
string Citizen::getLastName(){
    return lastName;
}
string Citizen::getMothersName(){
    return mothersName;
}
string Citizen::getYear(){
    return year;
}
string Citizen::getMonth(){
    return month;
}
string Citizen::getDay(){
    return day;
}
string Citizen::getGender(){
    return gender;
}
string Citizen::getState(){
    return state;
}
string Citizen::getCurp(){
    return curp;
}
string Citizen::generateCurp(){
    string key = "";
    int appearance = 0;
    bool flag = false;

    for (int i = 0; i < lastName.length() - 1; i++){
        if (i == 0){
            key += lastName[i];
        }
        else if ((lastName[i] == 'a' || lastName[i] == 'e' || lastName[i] == 'i' || lastName[i] == 'o' || lastName[i] == 'u') && appearance < 1){
            appearance ++;https://docs.google.com/document/d/1u1Zq3T-fstKQoDMSTe85PKkbQMsu65w2Qcp8UIkSBuM/edit?usp=sharing
            key += toupper(lastName[i]);
            flag = true;
        }
    }

    if (!flag){
        key += "X";
    }

    if (mothersName == " "){
        key += "X";
    }
    else {
        key += mothersName[0];
    }

    if ((firstName == "José" || firstName == "María") && secondName != ""){
        key += secondName[0];
    }
    else{
        key += firstName[0];
    }

    key += year[year.length() -2];
    key += year[year.length() -1];
    key += month;
    key += day;

    if (gender == "masculino"){
        key += "H";
    }
    if (gender == "femenino"){
        key += "M";
    }

    key += state;
    appearance = 0;
    flag = false;
    for (int i = 1; i < lastName.length() - 1; i++){
        if (lastName[i] != 'a' && lastName[i] != 'e' && lastName[i] != 'i' && lastName[i] != 'o' && lastName[i] != 'u' && appearance < 1){
            key += toupper(lastName[i]);
            appearance++;
            flag = true;
        }
    }
    if (!flag){
        key += "X";
    }

    appearance = 0;
    flag = false;

    cout << mothersName << endl;
    for (int i = 1; i < mothersName.length() - 1; i++){
        if (lastName[i] != 'a' && mothersName[i] != 'e' && mothersName[i] != 'i' && mothersName[i] != 'o' && mothersName[i] != 'u' && appearance < 1){
            key += toupper(mothersName[i]);
            appearance++;
            flag = true;
        }
    }
    if (!flag){
        key += "X";
    }

    appearance = 0;
    flag = false;
    for (int i = 1; i < firstName.length() - 1; i++){
        if (firstName[i] != 'a' && firstName[i] != 'e' && firstName[i] != 'i' && firstName[i] != 'o' && firstName[i] != 'u' && appearance < 1){
            key += toupper(firstName[i]);
            appearance++;
            flag = true;
        }
    }
    if (!flag){
        key += "X";
    }
    return key;
}
#endif // CITIZEN_H_INCLUDED
