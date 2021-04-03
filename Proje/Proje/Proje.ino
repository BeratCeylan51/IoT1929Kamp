#define BLYNK_PRINT Serial


#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char auth[] = "tfemUL1yZEl5vsay13tS1nnkGkl_QLLd";
char ssid[] = "Iphone";
char pass[] = "BeratCeylan";

#define ldr A0
WidgetLCD lcd(V6);


BLYNK_WRITE(V0)

{

  int pinValue = param.asInt(); // assigning incoming value from pin V1 to a variable

  analogWrite(D1,pinValue);

  Blynk.virtualWrite(V1, pinValue);

  Serial.print("V0 Slider value is: ");

  Serial.println(pinValue);

}


void setup()
{
  
  Serial.begin(9600);

  Blynk.begin(auth, ssid, pass);

}

void loop()
{
  Blynk.run();

  int deger = analogRead(ldr);

  if(deger > 5)
  {
    lcd.print(0,0, "Işık Açık!!!");
    lcd.print(1,0, "Işığı Kapatınız.");
  }
  else
  {
    lcd.clear();
  }
}
