#include <Adafruit_VL6180X.h>
#include <Wire.h>



Adafruit_VL6180X vl = Adafruit_VL6180X();
//Adafruit_VL6180X v2 = Adafruit_VL6180X();

byte laser1SHDNPin = 2;
byte laser2SHDNPin = 3;


void setup() {
  Serial.begin(9600);
 //pinMode(laser1SHDNPin, OUTPUT);
 //pinMode(laser2SHDNPin, OUTPUT);
 Serial.println("1");
 Wire.begin();
 //digitalWrite(laser1SHDNPin, LOW);
 
 delay(1000);
 //digitalWrite(laser1SHDNPin, HIGH);
 //digitalWrite(laser2SHDNPin, LOW);
 Serial.println("2");
  // wait for serial port to open on native usb devices
  while (!Serial) {
    delay(1);
  }
  
  Serial.println("Adafruit VL6180x test!");
  if (! vl.begin()) {
    Serial.println("Failed to find sensor1");
    while (1);
  }
  //if (! v2.begin(0x82)) {
  //  Serial.println("Failed to find sensor2");
   // while (1);
 // }  
  Serial.println("Sensor found!");
}

void loop() {
  float lux = vl.readLux(VL6180X_ALS_GAIN_5);
  Serial.print("IM INSIDE");
  Serial.print("Lux: "); Serial.println(lux);
  
  uint8_t range = vl.readRange();
  uint8_t status = vl.readRangeStatus();

  if (status == VL6180X_ERROR_NONE) {
    Serial.print("Range: "); Serial.println(range);
  }

  // Some error occurred, print it out!
  
  if  ((status >= VL6180X_ERROR_SYSERR_1) && (status <= VL6180X_ERROR_SYSERR_5)) {
    Serial.println("System error");
  }
  else if (status == VL6180X_ERROR_ECEFAIL) {
    Serial.println("ECE failure");
  }
  else if (status == VL6180X_ERROR_NOCONVERGE) {
    Serial.println("No convergence");
  }
  else if (status == VL6180X_ERROR_RANGEIGNORE) {
    Serial.println("Ignoring range");
  }
  else if (status == VL6180X_ERROR_SNR) {
    Serial.println("Signal/Noise error");
  }
  else if (status == VL6180X_ERROR_RAWUFLOW) {
    Serial.println("Raw reading underflow");
  }
  else if (status == VL6180X_ERROR_RAWOFLOW) {
    Serial.println("Raw reading overflow");
  }
  else if (status == VL6180X_ERROR_RANGEUFLOW) {
    Serial.println("Range reading underflow");
  }
  else if (status == VL6180X_ERROR_RANGEOFLOW) {
    Serial.println("Range reading overflow");
  }
  delay(50);
}

