#include<Servo.h>
Servo motor;
void setup()
{
  motor.attach(3);
}

void loop()
{
  for(int start = 0; start <= 180; start += 15)
  {
    motor.write(start);
    delay(1000);
  }
  
  for(int finish = 180; finish > 0; finish -= 30)
  {
    motor.write(finish);
    delay(1000);
  }
}
