# ArduinoAutonomousCar
Source code for Mandark 
(Autonomous Car using Arduino Mega, Ultrasonic Sensor, VL6180X Laser Sensors, Arduino Motor Shield, DC Motors, Adafruit Library)

This program is an attempt to successfully navigate a maze autonomously. By implementing dynamic path finding algorithms and peripheral devices and programmatically allowing all the systems to communicate the system was capable of rudimentarily navigating a maze. This system was developed using the current version of the Arduino IDE 1.6.4.

Include the provided Adafruit_VL6180X library in the Arduino library.
Include the provided TimedAction and multiVL6180x files to the Arduino sketchbook.

Embedded Device: Arduino Mega 2560

Peripherals: 1x Ultrasonic sensor, 2x VL6180 Time of flight sensors, 1x Arduino Motor Shield, 2x DC Motors
 
Misc: 1x breadboard, Male-to-male wires, Male-to-Female wires, Female-to-female wires.

Motors should be wired to the motor shield.

VL6180 Sensors should be ran in series with the I2C bus, with the right facing sensor GPIO shutdown pin connected to digital pin 3, and the left facing GPIO shutdown pin connected to digital pin 2.

The ultrasonic sensor should have the trig pin plugged into  digital pin 5, and the echo plugged into pin 4.
