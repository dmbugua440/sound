#include <Servo.h>

Servo servo1;
Servo servo2;
Servo servo3;

const int soundSensorPin = A0;
int soundThreshold = 270; 
int soundValue = 0;

void setup() {
  Serial.begin(9600);
  servo1.attach(9);
  servo2.attach(10); 
  servo3.attach(11);
  servo1.write(0);
  servo2.write(0);
  servo3.write(0);
}

void loop() {
  soundValue = analogRead(soundSensorPin);
  Serial.println(soundValue); 

  if (soundValue > soundThreshold) {
    int choice = detectNumber();
    
    if (choice == 1) {
      Serial.println("Opening Door 1");
      servo1.write(90);  
      delay(2000);      
      servo1.write(0);  
      }
    else if (choice == 2) {
      Serial.println("Opening Door 2");
      servo2.write(90);
      delay(2000);
      servo2.write(0);
    }
    else if (choice == 3) {
      Serial.println("Opening Door 3");
      servo3.write(90);
      delay(2000);
      servo3.write(0);
    }
  }
}

int detectNumber() {
  delay(100); 
  int val = analogRead(soundSensorPin);
  if (val > soundThreshold + 5) return 1;
  else if (val > soundThreshold + 2) return 2;
  else return 3; 
}
