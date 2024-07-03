#include <iostream>
#include <limits>   // for std::numeric_limits
#include <string>
#include <fstream>
#include "json/json.h"
#include <algorithm> // for std::transform
#include <cctype>    // for std::tolower
#include <vector>
#include <regex>     // for regular expressions
#include <iomanip>   // for std::setw and std::left

using namespace std;

struct Renter {
    string name;
    string phone;
    string address;
};

Json::Value getCarRecords() {
    Json::Value carRecords;
    ifstream carFile("cars.json", ifstream::binary);
    if (carFile.is_open()) {
        carFile >> carRecords;
        carFile.close();
    }
    return carRecords;
}

Json::Value getRentRecords() {
    Json::Value rentRecords;
    ifstream rentFile("rents.json", ifstream::binary);
    if (rentFile.is_open()) {
        rentFile >> rentRecords;
        rentFile.close();
    }
    return rentRecords;
}

void setCarRecords(Json::Value carRecords) {
    ofstream carFile("cars.json", ofstream::binary);
    if (carFile.is_open()) {
        carFile << carRecords;
        carFile.close();
    }
}

void setRentRecords(Json::Value rentRecords) {
    ofstream rentFile("rents.json", ofstream::binary);
    if (rentFile.is_open()) {
        rentFile << rentRecords;
        rentFile.close();
    }
}

// Utility function to convert a string to lowercase
string toLowercase(string str) {
    transform(str.begin(), str.end(), str.begin(), ::tolower);
    return str;
}

// Function to validate phone number format
bool isValidPhoneNumber(const string& phoneNumber) {
    // Regex pattern for a basic phone number format (10 digits)
    regex pattern(R"(\d{10})");
    return regex_match(phoneNumber, pattern);
}

// Function to validate date format (dd-mm-yyyy)
bool isValidDateFormat(const string& date) {
    // Regex pattern for dd-mm-yyyy format
    regex pattern(R"(\d{2}-\d{2}-\d{4})");
    return regex_match(date, pattern);
}

void addCar() {
    Json::Value carRecords = getCarRecords();

    Json::Value newCar;
    string name, carNumber, model, rentPrice;

    cout << "Enter Car Name: ";
    getline(cin, name);
    cout << "Enter Car Number: ";
    getline(cin, carNumber);
    cout << "Enter Car Model: ";
    getline(cin, model);
    cout << "Enter Rent Price (per day): ";
    getline(cin, rentPrice);

    // Convert inputs to lowercase for case insensitivity
    name = toLowercase(name);
    carNumber = toLowercase(carNumber);
    model = toLowercase(model);

    // Check if car with same number already exists
    for (const auto& car : carRecords) {
        if (toLowercase(car["carNumber"].asString()) == carNumber) {
            cout << "Car with this number already exists." << endl;
            return;
        }
    }

    newCar["name"] = name;
    newCar["carNumber"] = carNumber;
    newCar["model"] = model;
    newCar["rentPrice"] = rentPrice;

    carRecords.append(newCar);
    setCarRecords(carRecords);

    cout << "Car added successfully!" << endl;
}

void removeCar() {
    string carNumber;
    cout << "Enter Car Number to remove: ";
    getline(cin, carNumber);

    carNumber = toLowercase(carNumber);

    Json::Value carRecords = getCarRecords();
    int numOfCars = carRecords.size();

    for (int i = 0; i < numOfCars; i++) {
        if (toLowercase(carRecords[i]["carNumber"].asString()) == carNumber) {
            carRecords.removeIndex(i, nullptr);
            setCarRecords(carRecords);
            cout << "Car removed successfully!" << endl;
            return;
        }
    }

    cout << "Car not found in inventory." << endl;
}

void addRentRecord() {
    string carNumber, rentStartDate, rentEndDate;
    Renter r;

    Json::Value carRecords = getCarRecords();
    bool carExists = false;
    Json::Value carToRent;

    cout << endl << "--- Provide Rent Details ---" << endl;
    cout << "Car Number: ";
    getline(cin, carNumber);

    carNumber = toLowercase(carNumber);

    // Verify the car exists in the inventory
    for (int i = 0; i < carRecords.size(); i++) {
        if (toLowercase(carRecords[i]["carNumber"].asString()) == carNumber) {
            carExists = true;
            carToRent = carRecords[i];
            carRecords.removeIndex(i, nullptr);
            break;
        }
    }

    if (!carExists) {
        cout << "Car not found in inventory." << endl;
        return;
    }

    Json::Value rentRecords = getRentRecords();
    int numOfRents = rentRecords.size();

    cout << "Renter's Name: ";
    getline(cin, r.name);
    
    // Validate phone number
    do {
        cout << "Renter's Phone (10 digits): ";
        getline(cin, r.phone);
    } while (!isValidPhoneNumber(r.phone));

    cout << "Renter's Address: ";
    getline(cin, r.address);

    // Validate dates in dd-mm-yyyy format
    do {
        cout << "Rent Start Date (dd-mm-yyyy): ";
        getline(cin, rentStartDate);
    } while (!isValidDateFormat(rentStartDate));

    do {
        cout << "Rent End Date (dd-mm-yyyy): ";
        getline(cin, rentEndDate);
    } while (!isValidDateFormat(rentEndDate));

    Json::Value record;
    record["renter"]["name"] = r.name;
    record["renter"]["phone"] = r.phone;
    record["renter"]["address"] = r.address;
    record["car"]["carNumber"] = carToRent["carNumber"].asString();
    record["car"]["name"] = carToRent["name"].asString();
    record["car"]["model"] = carToRent["model"].asString();
    record["car"]["rentPrice"] = carToRent["rentPrice"].asString();
    record["rentStartDate"] = rentStartDate;
    record["rentEndDate"] = rentEndDate;

    rentRecords.append(record);
    setRentRecords(rentRecords);
    setCarRecords(carRecords);

    cout << endl << r.name << " rented a car. " << endl;
    cout << "Car Name: " << carToRent["name"].asString() << endl;
    cout << "Car Number: " << carToRent["carNumber"].asString() << endl;
}

void showCars() {
    cout << "--- List of Cars ---" << endl;

    Json::Value list = getCarRecords();
    int len = list.size();

    cout << left << setw(4) << "No." << " | "
         << setw(15) << "Car Name" << " | "
         << setw(10) << "Car No." << " | "
         << setw(12) << "Model" << " | "
         << setw(15) << "Rent Price (per day)" << endl;
    cout << "------------------------------------------------------------" << endl;

    for (int i = 0; i < len; i++) {
        cout << left << setw(4) << i + 1 << " | "
             << setw(15) << list[i]["name"].asString() << " | "
             << setw(10) << list[i]["carNumber"].asString() << " | "
             << setw(12) << list[i]["model"].asString() << " | "
             << setw(15) << "$" + list[i]["rentPrice"].asString() << endl;
    }
}

void showRents() {
    cout << "--- List of Rents ---" << endl;

    Json::Value list = getRentRecords();
    int len = list.size();

    cout << left << setw(4) << "No." << " | "
         << setw(15) << "Renter Name" << " | "
         << setw(15) << "Car Name" << " | "
         << setw(10) << "Car No." << " | "
         << setw(12) << "Rent Price" << " | "
         << setw(15) << "Rent Start Date" << " | "
         << setw(15) << "Rent End Date" << endl;
    cout << "----------------------------------------------------------------------------------" << endl;

    for (int i = 0; i < len; i++) {
        cout << left << setw(4) << i + 1 << " | "
             << setw(15) << list[i]["renter"]["name"].asString() << " | "
             << setw(15) << list[i]["car"]["name"].asString() << " | "
             << setw(10) << list[i]["car"]["carNumber"].asString() << " | "
             << setw(12) << "$" + list[i]["car"]["rentPrice"].asString() << " | "
             << setw(15) << list[i]["rentStartDate"].asString() << " | "
             << setw(15) << list[i]["rentEndDate"].asString() << endl;
    }
}

void returnCar() {
    Json::Value rentRecords = getRentRecords();
    int numOfRents = rentRecords.size();

    if (numOfRents == 0) {
        cout << "No cars are currently rented." << endl;
        return;
    }

    string carNumber;
    cout << "Enter Car Number to return: ";
    getline(cin, carNumber);

    carNumber = toLowercase(carNumber);

    for (int i = 0; i < numOfRents; i++) {
        if (toLowercase(rentRecords[i]["car"]["carNumber"].asString()) == carNumber) {
            Json::Value returnedCar = rentRecords[i]["car"];

            // Add returned car back to carRecords
            Json::Value carRecords = getCarRecords();
            carRecords.append(returnedCar);

            // Remove from rentRecords
            rentRecords.removeIndex(i, nullptr);

            // Save changes
            setCarRecords(carRecords);
            setRentRecords(rentRecords);

            cout << "Car returned successfully!" << endl;
            return;
        }
    }

    cout << "Car not found in rented records." << endl;
}

int main() {
    int choice;

    while (true) {
        cout << endl;
        cout << "Car Rental System" << endl;
        cout << "-----------------" << endl;
        cout << "1. Add Car" << endl;
        cout << "2. Remove Car" << endl;
        cout << "3. Rent Car" << endl;
        cout << "4. Return Car" << endl;
        cout << "5. Show Available Cars" << endl;
        cout << "6. Show Rented Cars" << endl;
        cout << "7. Exit" << endl;
        cout << "Enter your choice: ";

        // Input validation to handle non-integer inputs
        while (!(cin >> choice)) {
            cout << "Invalid input. Please enter a number: ";
            cin.clear(); // Clear error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
        }
        cin.ignore(); // Clear newline character from the input buffer

        switch (choice) {
            case 1:
                addCar();
                break;
            case 2:
                removeCar();
                break;
            case 3:
                addRentRecord();
                break;
            case 4:
                returnCar();
                break;
            case 5:
                showCars();
                break;
            case 6:
                showRents();
                break;
            case 7:
                cout << "Exiting program..." << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
