/**
  * The program allows the user to give a class room a name, a room number where the class will be taken, a capacity of students and allows the user to sign up students for the class.
  * Author: Emilio Fernando Alonso Villa A00959385.
  * Date: January 31st, 2018
  */

#include <iostream>
#include <string>
using namespace std;
// Declare header for class to be used.
#include "Room.h"

int main()
{
    // Declare variables.
    string name;
    int roomNum, capacity, students = 0;
    char cOption;

    // Receive input for name, room number and capacity and pass it to the object of class Room.
    cout << "+ What's the name of the class?\n";
    getline(cin, name);
    cout << "\n+ In which room?\n";
    cin >> roomNum;
    cout << "\n+ How many students can sign up for this class ?\n";
    cin >> capacity;

    // Declare object of class room with variable to initialize.
    Room classRoom(capacity, name, roomNum);

    do{
        // Tell the user the capacity of the room in the class and ask how many students they want to sign up.
        cout << "\n+ There are " << classRoom.getCapacity() - classRoom.getSignedUp() << " available seats to sign students up in class " << classRoom.getClassName() << endl;
        do{
            cout << "How many students do you want to sign up? ";
            cin >> students;
        }while (students <= 0);

        // If possible sing students to the class, if not, tell user that it is not possible.
        if (students <= classRoom.getCapacity() - classRoom.getSignedUp()){
            classRoom.singStudents(students);
        }
        else{
            cout << "Not enough seats available. \n";
        }

        // If there are still available seats ask the user if they want to sign up more.
        // If there are no more seats, end tell the user and end program.
        if(classRoom.getSignedUp() < classRoom.getCapacity()){
            cout << "\n+ Do you want to add more ? (y/n) ";
            cin >> cOption;
        }
        else{
            cout << "\n The class is full already.\n";
            cOption = 'n';
        }

    } while (tolower(cOption) != 'n');

    return 0;
}
