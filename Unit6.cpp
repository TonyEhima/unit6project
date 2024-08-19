#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Hotel {
public:
    void addRoom();
    void removeRoom();
    void displayRooms();
    void displayMenu();
    bool processChoice(int choice);

private:
    struct Room {
        int roomNumber;
        string roomType;
    };

    vector<Room> rooms; // Vector to store room details
};

int main() {
    Hotel hotel;
    int choice;

    while (true) {
        hotel.displayMenu();
        cout << "Enter your choice (0 to quit): ";
        cin >> choice;

        if (!hotel.processChoice(choice)) {
            break;
        }
    }

    return 0;
}

// Function to add a room to the system
void Hotel::addRoom() {
    Room newRoom;
    cout << "Enter room number: ";
    cin >> newRoom.roomNumber;
    cout << "Enter room type (Single/Double/Suite): ";
    cin >> newRoom.roomType;

    rooms.push_back(newRoom);
    cout << "Room added successfully!" << endl;
}

// Function to remove a room from the system
void Hotel::removeRoom() {
    int roomNumber;
    cout << "Enter the room number to remove: ";
    cin >> roomNumber;

    for (auto it = rooms.begin(); it != rooms.end(); ++it) {
        if (it->roomNumber == roomNumber) {
            rooms.erase(it);
            cout << "Room removed successfully!" << endl;
            return;
        }
    }
    cout << "Room not found!" << endl;
}

// Function to display all rooms in the system
void Hotel::displayRooms() {
    if (rooms.empty()) {
        cout << "No rooms available." << endl;
    } else {
        cout << "\n--- List of Rooms ---" << endl;
        for (const auto& room : rooms) {
            cout << "Room Number: " << room.roomNumber << ", Type: " << room.roomType << endl;
        }
    }
}

// Function to display the menu
void Hotel::displayMenu() {
    cout << "\n--- Hotel Management System ---" << endl;
    cout << "1. Add Room" << endl;
    cout << "2. Remove Room" << endl;
    cout << "3. Display All Rooms" << endl;
    cout << "0. Exit" << endl;
}

// Function to process the user's choice
bool Hotel::processChoice(int choice) {
    switch (choice) {
        case 1:
            addRoom();
            break;
        case 2:
            removeRoom();
            break;
        case 3:
            displayRooms();
            break;
        case 0:
            cout << "Exiting program..." << endl;
            return false;
        default:
            cout << "Invalid choice. Please try again." << endl;
    }
    return true;
}
