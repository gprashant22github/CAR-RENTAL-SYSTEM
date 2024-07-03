
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
   git clone https://github.com/yourusername/car-rental-system.git
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
   g++ -o car_rental_system main.cpp
   ```

## Usage

To run the Car Rental System, execute the compiled binary:

```bash
./car_rental_system
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

## Contact

For any questions or feedback, you can reach me at [your.email@example.com](mailto:your.email@example.com).

---

Happy coding!
```

### To Do After Copying the Content

1. **Replace Placeholder Information**:
   - Replace `yourusername` with your GitHub username in the clone URL.
   - Replace `your.email@example.com` with your actual email address.

2. **Add `LICENSE` File**:
   If you are using the MIT License, add a `LICENSE` file to your repository with the following content:

   ```
   MIT License

   Copyright (c) [year] [Your Name]

   Permission is hereby granted, free of charge, to any person obtaining a copy
   of this software and associated documentation files (the "Software"), to deal
   in the Software without restriction, including without limitation the rights
   to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
   copies of the Software, and to permit persons to whom the Software is
   furnished to do so, subject to the following conditions:

   The above copyright notice and this permission notice shall be included in all
   copies or substantial portions of the Software.

   THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
   IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
   FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
   AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
   LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
   OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
   SOFTWARE.
   ```

   Replace `[year]` with the current year and `[Your Name]` with your name.

### Adding `json.hpp`

Make sure to include the `json.hpp` file from the [JSON for Modern C++](https://github.com/nlohmann/json) library in your project directory under `json/`.

With this `README.md`, you should be well-prepared to share your project on GitHub!
