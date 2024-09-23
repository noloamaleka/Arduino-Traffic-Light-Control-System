# Arduino-Traffic-Light-Control-and-Collision-Avoidance-Project

## Project Overview
This project simulates a traffic light control system with collision avoidance for an Arduino-controlled car. The car listens for signals and responds to traffic light signals sent via an ESP32 module and responds accordingly. The car acts as a receiver while the Traffic Light controller acts as a transmitter. This facilitates client to server communication bewteen the two ESP32 Boards.

## Directory Structure
- `src/`: Contains the main Arduino `.ino` files.
  - `Traffic_Controller.ino`: Code for the traffic light control.
  - `Car_Traffic.ino`: Code for the car's movement and obstacle avoidance.

## Setup Instructions
1. Clone this repository or download the ZIP file.
2. Open the `.ino` files in the Arduino IDE.
3. Upload the code to the respective Arduino boards.
   - The `Traffic_Controller.ino` should be uploaded to the traffic light controller ESP32 board.
   - The `Car_Traffic.ino` should be uploaded to the car ESP32 board.

## Dependencies
- The project requires the `ESP32` library by Espressif. You can install it via the Arduino IDE Library and Boards Manager.
- Select COM5 as the port to ensure the board connection is established.

## Collaboration
- Please ensure you pull the latest changes before making any modifications.
- Commit your changes with clear messages.

## Further Development
- The Collision avoidance logic can be expanded or modified.
- The traffic light states and corresponding car actions can be adjusted for different scenarios.

