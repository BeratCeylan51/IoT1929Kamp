#include <dht11.h>

dht11 DHT;

int dhtPin = 2;

void setup() 
{
  Serial.begin(9600);
}

void loop() 
{
  int okunanDeger = DHT.read(dhtPin);

  Serial.print("Nem Oranı : ");
  Serial.println((float)DHT.humidity , 2);

  Serial.print("Sıcaklık (Celcius) : ");
  Serial.println(DHT.temperature , 2);

  Serial.print("Sıcaklık (Kelvin) : ");
  Serial.println(DHT.kelvin() , 2);

  Serial.print("Sıcaklık (Fahrenheit) : ");
  Serial.println(DHT.fahrenheit() , 2);

  delay(2000);
}
