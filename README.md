# Parking Area Management System

## Overview

This C++ program simulates a Parking Area Management System. The system allows users to park, unpark, and search for cars based on various criteria such as registration number, parking slot, or car color. Users can also display details of all parked cars. The program continuously accepts user input until the exit command is entered.

## Features

- **Park a Car**: Park a car by providing its registration number and color. The system automatically assigns the next available slot.
- **Unpark a Car**: Unpark a car by providing its registration number, color, and slot number.
- **Find a Car by Slot Number**: Search for a car parked in a specific slot.
- **Find a Car by Color**: Search for cars based on their color.
- **Find a Car by Registration Number**: Search for a car using its registration number.
- **Get Car Details**: Display details of a car, including its registration number, color, and parking slot.
- **Display All Parked Cars**: List all cars currently parked in the parking area, along with their details.
- **Exit the System**: Exit the program.

## Requirements

- C++ Compiler (e.g., g++)

## How to Run

1. **Compile the program**:
   ```
   g++ parking_system.cpp -o parking_system
   ```

2. **Run the program**:
   ```
   ./parking_system
   ```

3. **Follow the prompts** to use the system.

## Available Commands

- `park <reg_no> <colour>`: Park a car with the specified registration number and color. For example:
  ```
  park ABC123 red
  ```
  
- `unpark <reg_no> <colour> <slot>`: Unpark a car with the given registration number, color, and parking slot. For example:
  ```
  unpark ABC123 red 1
  ```

- `find_parking_slot <slot>`: Find a car parked in the specified slot. For example:
  ```
  find_parking_slot 1
  ```

- `find_car <colour>`: Find a car with the specified color. For example:
  ```
  find_car red
  ```

- `find_car_number <reg_no>`: Find a car using its registration number. For example:
  ```
  find_car_number ABC123
  ```

- `get_car_details <reg_no>`: Display the details of a car using its registration number. For example:
  ```
  get_car_details ABC123
  ```

- `show_all`: Display all parked cars and their details.
  
- `exit`: Exit the system.

## Example Usage

1. **Park a car**:
   ```
   Enter the command: park ABC123 red
   Allocated slot is: 1
   ```

2. **Find a car by slot**:
   ```
   Enter the command: find_parking_slot 1
   Car found in slot: 1
   ```

3. **Unpark a car**:
   ```
   Enter the command: unpark ABC123 red 1
   Car found in the parking area.
   Slot 1 is now free.
   ```

4. **Exit**:
   ```
   Enter the command: exit
   ```

## File Structure

- **parking_system.cpp**: The main C++ file containing the implementation of the Parking Area Management System.

## Notes

- The parking slots are allocated sequentially starting from slot 1.
- The system handles basic error cases like trying to unpark a non-existent car or searching for a car that isn't parked.
