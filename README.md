
# Car Rental System

## Overview

The Car Rental System is a command-line C++ application that allows users to manage a car rental business. It includes features for adding and removing cars, renting and returning cars, and displaying available and rented cars. The system uses JSON files for data storage and supports basic validation for phone numbers and dates.

## Features

- **Add a Car**: Add new cars to the inventory with details like name, car number, model, and rent price.
- **Remove a Car**: Remove a car from the inventory using its car number.
- **Rent a Car**: Rent a car by providing renter details, car number, and rental period.
- **Return a Car**: Return a rented car, making it available for future rentals.
- **Show Available Cars**: Display a list of all available cars with their details.
- **Show Rented Cars**: Display a list of all rented cars along with renter details, rental periods, and rent prices.

## Installation

To get started with the Car Rental System, follow these steps:

1. **Clone the Repository**

   ```bash
   git clone https://github.com/gprashant22github/CAR-RENTAL-SYSTEM.git
   ```

2. **Navigate to the Project Directory**

   ```bash
   cd car-rental-system
   ```

3. **Install Dependencies**

   The project requires the [JSON for Modern C++](https://github.com/nlohmann/json) library. Download the `json.hpp` file and place it in the `json` directory.

4. **Compile the Code**

   Use a C++ compiler to compile the `main.cpp` file. You can use `g++` or any other C++ compiler:

   ```bash
    g++ main.cpp jsoncpp.cpp -o CarRentalSystem
   ```

## Usage

To run the Car Rental System, execute the compiled binary:

```bash
./CarRentalSystem
```

Follow the on-screen menu to navigate through the different options.

### Menu Options

1. **Add Car**: Add a new car to the inventory.
2. **Remove Car**: Remove a car from the inventory.
3. **Rent Car**: Rent a car to a customer.
4. **Return Car**: Return a rented car to the inventory.
5. **Show Available Cars**: Display all available cars.
6. **Show Rented Cars**: Display all rented cars and rental details.
7. **Exit**: Exit the application.

## JSON Files

The application uses two JSON files for data storage:

- `cars.json`: Stores information about available cars.
- `rents.json`: Stores information about rented cars and rental details.

Example of `cars.json` file:

```json
[
    {
        "name": "Toyota Camry",
        "carNumber": "abc123",
        "model": "2020",
        "rentPrice": "50"
    },
    {
        "name": "Honda Accord",
        "carNumber": "xyz789",
        "model": "2021",
        "rentPrice": "60"
    }
]
```

Example of `rents.json` file:

```json
[
    {
        "renter": {
            "name": "John Doe",
            "phone": "1234567890",
            "address": "123 Elm Street"
        },
        "car": {
            "carNumber": "abc123",
            "name": "Toyota Camry",
            "model": "2020",
            "rentPrice": "50"
        },
        "rentStartDate": "01-01-2024",
        "rentEndDate": "10-01-2024"
    }
]
```

## Contributing

Contributions are welcome! If you have suggestions or improvements, please fork the repository and create a pull request.

## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.

## Acknowledgments

- The [JSON for Modern C++](https://github.com/nlohmann/json) library for JSON parsing.
- [GitHub](https://github.com) for providing a platform for version control and collaboration.

---


