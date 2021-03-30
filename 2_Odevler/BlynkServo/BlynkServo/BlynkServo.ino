#define BLYNK_PRINT Serial
#include <Servo.h>

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>



Servo servo; 
char auth[] = "token";

char ssid[] = "Wifi bağlantı adı";
char pass[] = "sıfre";

void setup()
{
  // Debug console
  Serial.begin(9600);

  Blynk.begin(auth, ssid, pass);
  servo.attach(15);
}

void loop()
{
  Blynk.run();
}
BLYNK_WRITE(V1)
{
  servo.write(param.asInt());
  
}
