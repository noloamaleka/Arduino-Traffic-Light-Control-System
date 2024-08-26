# Arduino-Traffic-Light-Control-and-Collision-Avoidance-Project

## Project Overview
This project simulates a traffic light control system with collision avoidance for an Arduino-controlled car. The car responds to traffic light signals sent via an RF module and adjusts its movement accordingly. The car acts as a receiver while the Traffic Light controller acts as a transmitter. This facilitates client to server communication bewteen the two arduinos.

## Directory Structure
- `src/`: Contains the main Arduino `.ino` files.
  - `Traffic_Controller.ino`: Code for the traffic light control.
  - `Car_Traffic.ino`: Code for the car's movement and obstacle avoidance.

## Setup Instructions
1. Clone this repository or download the ZIP file.
2. Open the `.ino` files in the Arduino IDE.
3. Upload the code to the respective Arduino boards.
   - The `Traffic_Controller.ino` should be uploaded to the traffic light controller arduino board.
   - The `Car_Traffic.ino` should be uploaded to the car arduino uno board.

## Dependencies
- The project requires the `RadioHead` library. You can install it via the Arduino IDE Library Manager.

## Collaboration
- Please ensure you pull the latest changes before making any modifications.
- Commit your changes with clear messages.

## Further Development
- The Collision avoidance logic can be expanded or modified.
- The traffic light states and corresponding car actions can be adjusted for different scenarios.

