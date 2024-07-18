# Proximity Control with Arduino

This Arduino sketch controls LEDs based on readings from proximity sensors.

## Components Used

- 3 LEDs connected to pins A3, A4, and A5
- 3 proximity sensors connected to pins A0, A1, and A2

## Functionality

- **Setup**: Initializes pins and serial communication.
- **Loop**: Continuously reads sensor values, prints them to Serial Monitor, and controls LEDs based on proximity readings.
- **Control Logic**:
  - All sensors below a threshold (`threshold = 700`) turn on all LEDs.
  - Specific combinations of sensor values turn on specific LEDs.
  - If no conditions are met, all LEDs are turned off.

## Installation

To use this sketch:
1. Connect your Arduino board with LEDs and proximity sensors as specified.
2. Upload `proximity_control.ino` to your Arduino.
3. Open Serial Monitor to view sensor readings.

Feel free to modify `threshold` or adjust pin assignments as needed.


