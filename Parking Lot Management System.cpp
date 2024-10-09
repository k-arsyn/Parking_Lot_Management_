#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Class representing a parking area
class ParkingArea {
public:
    vector<string> colour_of_the_car; // Stores the color of parked cars
    vector<string> reg_no;            // Stores the registration numbers of cars
    vector<string> slot_no;           // Stores the slot numbers for parked cars

    static int m; // Tracks the current slot number
    static int c; // Tracks the total number of cars parked

public:
    // Function to park a car with registration number and color
    void park(string r, string color) {
        c++; // Increment the car count
        reg_no.push_back(r);
        colour_of_the_car.push_back(color);
        slot_no.push_back(to_string(m + 1)); // Assign next available slot

        cout << "Allocated slot is: " << slot_no[m] << endl;
        m++; // Increment the slot number
    }

    // Function to unpark a car based on registration number, color, and slot
    void unpark(string r, string colour, string slot) {
        bool flag = false;
        int match_index = -1;

        // Search for the car with the given registration number
        for (int i = 0; i < c; i++) {
            if (reg_no[i] == r) {
                flag = true;
                match_index = i;
                break;
            }
        }

        // If car is found, proceed with unpark
        if (flag) {
            cout << "Car found in the parking area." << endl;
            reg_no.erase(reg_no.begin() + match_index);
            colour_of_the_car.erase(colour_of_the_car.begin() + match_index);
            slot_no.erase(slot_no.begin() + match_index);
            c--; // Decrease car count
            cout << "Slot " << slot << " is now free." << endl;
        } else {
            cout << "Car not found." << endl;
        }
    }

    // Function to find a car based on its parking slot number
    void findParkingBySlot(string slot) {
        bool flag = false;
        for (int i = 0; i < c; i++) {
            if (slot_no[i] == slot) {
                flag = true;
                cout << "Car found in slot: " << slot << endl;
                return;
            }
        }
        if (!flag) {
            cout << "Car not found in the specified slot." << endl;
        }
    }

    // Function to find a car based on its color
    void findParkingByColour(string colour) {
        bool flag = false;
        for (int i = 0; i < c; i++) {
            if (colour_of_the_car[i] == colour) {
                flag = true;
                cout << "Car with color " << colour << " found." << endl;
                return;
            }
        }
        if (!flag) {
            cout << "No car with the specified color found." << endl;
        }
    }

    // Function to find a car based on its registration number
    void findParkingByRegno(string r) {
        bool flag = false;
        for (int i = 0; i < c; i++) {
            if (reg_no[i] == r) {
                flag = true;
                cout << "Car with registration number " << r << " found." << endl;
                return;
            }
        }
        if (!flag) {
            cout << "No car with the specified registration number found." << endl;
        }
    }

    // Function to get details of a car based on its registration number
    void getCarDetails(string registration_no) {
        for (int i = 0; i < c; i++) {
            if (reg_no[i] == registration_no) {
                cout << "Car details:" << endl;
                cout << "Color: " << colour_of_the_car[i] << endl;
                cout << "Registration No: " << reg_no[i] << endl;
                cout << "Slot No: " << slot_no[i] << endl;
                return;
            }
        }
        cout << "Car not found." << endl;
    }

    // Function to print all parked cars and their details
    void printAllParking() {
        if (c == 0) {
            cout << "No cars in the parking area." << endl;
            return;
        }
        for (int i = 0; i < c; i++) {
            cout << "Parking Slot " << i + 1 << ":" << endl;
            cout << "Color: " << colour_of_the_car[i] << endl;
            cout << "Registration No: " << reg_no[i] << endl;
            cout << "Slot No: " << slot_no[i] << endl;
            cout << endl;
        }
    }
};

// Instructions for using the parking management system
void instructions() {
    cout << "Parking Area Management System" << endl;
    cout << "Available Commands:" << endl;
    cout << "- park <reg_no> <colour> --> Park a car." << endl;
    cout << "- unpark <reg_no> <colour> <slot> --> Unpark a car." << endl;
    cout << "- find_parking_slot <slot> --> Find a car by slot number." << endl;
    cout << "- find_car <colour> --> Find a car by its color." << endl;
    cout << "- find_car_number <reg_no> --> Find a car by its registration number." << endl;
    cout << "- get_car_details <reg_no> --> Get car details by registration number." << endl;
    cout << "- show_all --> Display details of all parked cars." << endl;
    cout << "- exit --> Exit the system." << endl;
}

// Initialize static members
int ParkingArea::c = 0;
int ParkingArea::m = 0;

int main() {
    ParkingArea parking_lot;
    string command;

    // Display instructions
    instructions();

    // Command loop
    while (true) {
        cout << "Enter the command: ";
        cin >> command;

        if (command == "park") {
            string reg_no, colour;
            cin >> reg_no >> colour;
            parking_lot.park(reg_no, colour);
        } 
        else if (command == "unpark") {
            string reg_no, colour, slot;
            cin >> reg_no >> colour >> slot;
            parking_lot.unpark(reg_no, colour, slot);
        } 
        else if (command == "find_parking_slot") {
            string slot;
            cin >> slot;
            parking_lot.findParkingBySlot(slot);
        } 
        else if (command == "find_car") {
            string colour;
            cin >> colour;
            parking_lot.findParkingByColour(colour);
        } 
        else if (command == "find_car_number") {
            string reg_no;
            cin >> reg_no;
            parking_lot.findParkingByRegno(reg_no);
        } 
        else if (command == "get_car_details") {
            string reg_no;
            cin >> reg_no;
            parking_lot.getCarDetails(reg_no);
        } 
        else if (command == "show_all") {
            parking_lot.printAllParking();
        } 
        else if (command == "exit") {
            break;
        } 
        else {
            cout << "Invalid Command." << endl;
        }
    }

    return 0;
}
