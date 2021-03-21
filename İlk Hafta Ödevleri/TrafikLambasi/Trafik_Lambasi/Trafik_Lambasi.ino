int kirmizi = 2 , mavi  = 3, yesil = 4;
void setup()
{
  for(int Pin = 2; Pin < 5; Pin++)
  {
    pinMode(Pin , OUTPUT);
  }
}

void loop()
{
  for(int Pin = 2; Pin < 5; Pin++)
  {
     digitalWrite(kirmizi , HIGH);
    delay(10000);

    digitalWrite(mavi , HIGH);
    delay(12000);
    
    digitalWrite(kirmizi , LOW);
    digitalWrite(mavi , LOW);
    
    digitalWrite(yesil , HIGH);
    delay(5000);
    digitalWrite(yesil , LOW);
  }
}
