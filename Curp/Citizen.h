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
    string penDigit;
    string lastDigit;
public:
    Citizen();
    // Access and modification methods.
    void setFirstName(string fN);
    void setSecondName(string sN);
    void setLastName(string lN);
    void setMothersName(string sLN);
    void setYear(string y);
    void setMonth(string m);
    void setDay(string d);
    void setGender(string g);
    void setState(string s);
    void setCurp(string c);
    void setPenDigit(string pD);
    void setLastDigit(string lD);
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
    string getPenDigit();
    string getLastDigit();
    // Functional method.
    void fourInitials();
    void dateDigits();
    void genderChar();
    void stateInitials();
    void lastConsonants();
    void securityNum();
    void genLastDigit();
};

// Constructor
Citizen::Citizen(){
    firstName = "";
    secondName = "";
    lastName = "";
    mothersName = "";
    year = "";
    month = "";
    day = "";
    gender = "";
    state = "";
    curp = "";
}
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
void Citizen::setYear(string y){
    year = y;
}
/*
 * The function takes a string with the name of the month the person was born and checks which case it ism
 * then assigns the numeric value of the given month as the month variable.
 * Arguments: string passed by main.
 * Returns: none.
 */
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
/*
 * The function takes a string with the name of a birth place, then converts it to upper to eliminate case sensitive problems
 * after that check which birth place it is and assign key letters as the state variable.
 * Arguments: string from main.
 * Returns: none.
 */
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
void Citizen::setPenDigit(string pD){
    penDigit = pD;
}
void Citizen::setLastDigit(string lD){
    lastDigit = lD;
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
string Citizen::getPenDigit(){
    return penDigit;
}
string Citizen::getLastDigit(){
    return lastDigit;
}
/*
 * The function gets the first four initials of the CURP with the name, second name, last name and mothers name.
 * Arguments: none.
 * Returns: none, but modifies curp.
 */
void Citizen::fourInitials(){
    // Variables to be used by the function
    string key = "";
    int appearance = 0;
    bool flag = false;

    // Scans through the last name and gets the first letter and first vowel
    for (int i = 0; i < lastName.length() - 1; i++){
        if (i == 0){
            key += lastName[i];
        }
        else if ((lastName[i] == 'a' || lastName[i] == 'e' || lastName[i] == 'i' || lastName[i] == 'o' || lastName[i] == 'u') && appearance < 1){
            appearance ++;
            key += toupper(lastName[i]);
            flag = true;
        }
    }

    // If there are no vowel get X
    if (!flag){
        key += "X";
    }

    // If the person has no mothers name get X
    if (mothersName == ""){
        key += "X";
    }

    // Get mothers name first letter and attend the cases of María and José as first name without second name.
    else {
        key += mothersName[0];
    }

    if ((firstName == "José" || firstName == "María") && secondName != ""){
        key += secondName[0];
    }

    // First name different from José or María
    else{
        key += firstName[0];
    }

    // Add to curp.
    curp += key;
}
/*
 * The function gets the digits from the year, month and day and adds them to the curp.
 * Arguments: none.
 * Returns: none, but modifies curp.
 */
void Citizen::dateDigits(){
    // Variable to store the chars
    string digits = "";

    // Add the respective charts of the year, month and date to the digits string.
    digits += year[year.length() - 2];
    digits += year[year.length() - 1];
    digits += month;
    digits += day;

    // Add digits to curp.
    curp+= digits;
}

/*
 * The function checks the gender of the person and gets M for women and H for men.
 * Arguments: none.
 * Returns: none, but modifies curp.
 */
void Citizen::genderChar(){
    // Variables for the function
    string genChar;

    // Checks if they are feminine or masculine and assigns the respective character
    if (gender == "femenino"){
        genChar = "M";
    }
    else if (gender == "masculino"){
        genChar = "H";
    }

    // Adds the gender character to the curp.
    curp += genChar;
}
/*
 * The functions gets the initials from each state and adds them to the CURP.
 * Arguments: none.
 * Returns: none, but modifies curp.
 */
void Citizen::stateInitials(){
    // Variable for function.
    string initials = "";

    // Store initials and add them to the curp.
    initials += state;
    curp += initials;
}
/*
 * The functions get the internal consonants of the last name, mothers name, and first name and adds them to the curp.
 * Arguments: none.
 * Returns: none, but modifies curp.
 */
void Citizen::lastConsonants(){
    // Variables for the function.
    string consonants = "";
    int appearance = 0;
    bool flag = false;

    // Scans the last name for the first internal consonant, if there are no consonants add an X.
    for (int i = 1; i < lastName.length() - 1; i++){
        if (lastName[i] != 'a' && lastName[i] != 'e' && lastName[i] != 'i' && lastName[i] != 'o' && lastName[i] != 'u' && appearance <1){
            consonants += toupper(lastName[i]);
            appearance ++;
            flag = true;
        }
    }

    if (!flag){
        consonants += "X";
    }

    // If there is no mothers name add an X.
    if (mothersName == ""){
        consonants += "X";
    }

    // If there is a mothers name scan it for the first internal consonant, if there is none add X.
    else{
        appearance = 0;
        flag = false;
        for (int i = 1; i < mothersName.length() - 1; i++){
            if (mothersName[i] != 'a' && mothersName[i] != 'e' && mothersName[i] != 'i' && mothersName[i] != 'o' && mothersName[i] != 'u'
                && appearance < 1 ){
                    consonants += toupper(mothersName[i]);
                    appearance++;
                    flag = true;
                }
        }
        if (!flag){
            consonants += "X";
        }
    }

    // Scan first name for the first internal consonant, if there is none add X.
    appearance = 0;
    flag = false;
    for (int i = 1; i < firstName.length() - 1; i++){
        if (firstName[i] != 'a' && firstName[i] != 'e' && firstName[i] != 'i' && firstName[i] != 'o' && firstName[i] != 'u'
            && appearance < 1){
                consonants += toupper(firstName[i]);
                appearance ++;
                flag = true;
            }
    }
    if (!flag){
        consonants += "X";
    }

    // Add the last consonants to the curp.
    curp += consonants;
}
/*
 * The function takes an int as an arguments and uses stringstream library to convert into string.
 * Arguments: integer values.
 * Returns: integer turned int string.
 */
string itos (int i){
    // Variable to use stream string.
    stringstream ss;

    // Take the int as argument for string steam.
    ss << i;

    // Returns int as string
    return ss.str();
}
/*
 * The function scans a string and converts it into an integer.
 * Arguments: string with numbers inside.
 * Returns: numeric string turned into integer value.
 */
int stoi(string n){
    // Variable to store the values of each part of the numeric string.
    int num = 0;

    // Scan through string and convert into number subtracting the char '0' and multiplying by 10 to the nth.
    for (int i = 0; i < n.length(); i++){
        num += (n[i] - '0') * pow(10, n.length() - 1 - i);
    }

    // Return string turned into a number.
    return num;
}

/*
 * The function takes the penultimate digit and adds it to the curp.
 * Arguments: none.
 * Returns: none, but modifies curp.
 */
void Citizen::securityNum(){
    // Add penultimate digit to curp.
    curp += penDigit;
}

/*
 * The function takes the last digit and adds it to the curp.
 * Arguments: none.
 * Returns: none, but modifies curp.
 */
void Citizen::genLastDigit(){
    // Add last digit to curp;
    curp += lastDigit;
}
#endif // CITIZEN_H_INCLUDED
