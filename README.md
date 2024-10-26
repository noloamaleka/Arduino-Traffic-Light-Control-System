# Arduino-Smart-Traffic-Light-System

## Project Overview
This project simulates a traffic light control system for an Arduino-controlled car. The car listens for signals and responds to traffic light signals sent via an ESP32 module which then sends the signals to the Ardunio car and responds accordingly. The system facilitates client to server communication bewteen the two ESP32 Boards and an Arduino programmed car.

The simulated system with more features such as obstacle avoidance can be viewed on: https://simulated-system.vercel.app/

## Directory Structure
- `src/`: Contains the main Arduino `.ino` files.
  - `Trasmitter.ino`: Code for the traffic light control.
  - `Receiver.ino`: Code for the car's movement based on reciveed signals

## Setup Instructions
1. Clone this repository or download the ZIP file.
2. Open the `.ino` files in the Arduino IDE.
3. Upload the code to the respective Arduino boards.
   - The `Transmitter.ino` should be uploaded to the traffic light controller ESP32 board.
   - The `Receiver.ino` should be uploaded to the reciever ESP32 board.

## Dependencies
- The project requires the `ESP32` library by Espressif. You can install it via the Arduino IDE Library and Boards Manager.
- Select COM5 as the port to ensure the board connection is established.

## Collaboration
- Please ensure you pull the latest changes before making any modifications.
- Commit your changes with clear messages.

## Further Development
- The System can be expanded to include obstacle avoidance logic which can be expanded upon or modified.
- The traffic light states and corresponding car actions can be adjusted for different scenarios.

