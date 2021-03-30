
#include<Servo.h>

Servo servo1;
Servo servo2;

const byte potPin1 = A1;
const byte potPin2 = A2;

int potDeger1;
int potDeger2;

void setup() {

  Serial.begin(9600);
  servo1.attach(5);
  servo2.attach(6);

}

void loop() {

  potDeger1 = analogRead(potPin1);
  potDeger1 = map(potDeger1 , 0 , 1023 , 0 , 90);
  servo1.write(potDeger1);
  delay(15);

  potDeger2 = analogRead(potPin2);
  potDeger2 = map(potDeger2 , 0 , 1023 , 0 , 180);
  servo2.write(potDeger2);
  delay(15);
}
