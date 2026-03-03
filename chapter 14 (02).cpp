#include <iostream>
#include <string>
using namespace std;

// Outer Class
class House {
public:
    // 1. NESTED CLASS (Defined entirely inside House)
    class Room {
    private:
        string roomName;
        int size;
    public:
        Room(string name, int s); 
        void showRoom();
    };

private:
    string address;
    Room myRoom; // Creating an object of the nested class

public:
    House(string addr, string rName, int rSize);
    void showHouse();
};

// --- Definitions Outside the Classes ---
House::Room::Room(string name, int s) : roomName(name), size(s) { 
    // Initialization list used above
}

void House::Room::showRoom() {
    cout << "Room: " << roomName << ", Size: " << size << " sq meters" << endl;
}

// 3. Defining the Outer Class methods
// Initialization list sets up the address AND builds the nested myRoom object
House::House(string addr, string rName, int rSize) : address(addr), myRoom(rName, rSize) {
    // Body is empty because initialization list did the work
}

void House::showHouse() {
    cout << "\nHouse Address: " << address << endl;
    myRoom.showRoom(); // Calling the inner class method
}

// --- Main Program ---

int main() {
    string inputAddress, inputRoom;
    int inputSize;

    // User Input
    cout << "Enter house address (one word): ";
    cin >> inputAddress;
    cout << "Enter room name (one word): ";
    cin >> inputRoom;
    cout << "Enter room size (in sq meters): ";
    cin >> inputSize;

    // Build the house (which automatically builds the room inside it)
    House myHouse(inputAddress, inputRoom, inputSize);
    myHouse.showHouse();

    return 0;
}