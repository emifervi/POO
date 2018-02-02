#ifndef ROOM_H_INCLUDED
#define ROOM_H_INCLUDED

class Room{
private:
    // Private attributes.
    int capacity, signedUp, roomNum;
    string className;

public:
    // Constructor method.
    Room(int cap, string name, int room);
    // Access and modification methods.
    void setCapacity(int c);
    void setClassName(string n);
    void setSignedUp(int s);
    void setRoomNum(int r);
    int getCapacity();
    string getClassName();
    int getSignedUp();
    int getRoomNumber();
    void singStudents(int s);
};

// Constructor that takes the arguments given by user and starts signed up at 0;
Room::Room(int cap, string name, int room){
    capacity = cap;
    className = name;
    roomNum = room;
    signedUp = 0;
}

// Modification methods.
void Room::setCapacity(int c){
    capacity = c;
}
void Room::setClassName(string n){
    className = n;
}
void Room::setSignedUp(int s){
    signedUp = s;
}
void Room::setRoomNum(int r){
    roomNum = r;
}

// Access methods.
int Room::getCapacity(){
    return capacity;
}
string Room::getClassName(){
    return className;
}
int Room::getSignedUp(){
    return signedUp;
}
int Room::getRoomNumber(){
    return roomNum;
}

/*
 * Functional Methods.
 */

// Takes the amount of students provided by user and updates the value of the signed up students.
void Room::singStudents(int s){
        signedUp += s;
}



#endif // ROOM_H_INCLUDED
