void setup()
{
  for(int Pinler = 2; Pinler < 7; Pinler++)
  {
      pinMode(Pinler , OUTPUT);
  }
}

void loop()
{
  for(int Pin = 2; Pin < 7; Pin++)
  {
    digitalWrite(Pin , HIGH);
    delay(500);
    digitalWrite(Pin , LOW);
  }
  
  for(int Pin = 6; Pin >= 2; Pin--)
  {
    digitalWrite(Pin , HIGH);
    delay(500);
    digitalWrite(Pin , LOW);
  }
}
