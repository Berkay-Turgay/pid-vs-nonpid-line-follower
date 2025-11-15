
# Line Follower Robot - PID vs Non-PID
This repository contains the firmware for a line follower robot demonstrating two control methods: PID (Proportional, Integral, Derivative) and Non-PID (simple threshold-based).

## Features
- Non-PID line following (threshold-based)
- PID line following for smoother and faster control
- Adjustable Kp and Kd constants in PID software
- Sensor reading and motor correction logic

## Hardware Used
- Infrared line sensors (QTR-8RC) and holder
- DC motors (micro reduction)
- Motor driver (L298P Shield)
- Microcontroller (Arduino Uno) and proto shield
- Mini Sumo Robot Body with Tracks

## How to Use
1. Open Arduino IDE
2. Open either "Line_Follower_PID.ino" or "Line_Follower_NonPID.ino"
3. Upload to your microcontroller
4. Connect the sensors and motors as shown in the wiring diagram
5. This robot has only 6 pair IR sensor!!!

## YouTube Video
Full video and calibration process  is available here:  
https://youtu.be/0R3Sow6XPbE

## License
This project is licensed under the MIT License.

## Contributions
Feel free to open issues or submit pull requests for improvements.
