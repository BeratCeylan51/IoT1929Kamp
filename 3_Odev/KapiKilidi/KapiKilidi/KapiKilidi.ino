
#define SS_PIN D2
#define RST_PIN  D1

int yesilLed = D4;
int kirmiziLed = D3;

#include <SPI.h>
#include <MFRC522.h>

MFRC522 mfrc522(SS_PIN, RST_PIN);   
int statuss = 0;
int out = 0;

void setup() 
{
  pinMode(yesilLed, OUTPUT);
  pinMode(kirmiziLed, OUTPUT);
  
  Serial.begin(9600);   
  SPI.begin();      
  mfrc522.PCD_Init();   
}

void loop() 
{
  
  if ( ! mfrc522.PICC_IsNewCardPresent()) 
  {
    return;
  }
  
  if ( ! mfrc522.PICC_ReadCardSerial()) 
  {
    return;
  }
  
  Serial.println();
  Serial.print(" UID etiketi :");
  String content= "";
  byte letter;
  for (byte i = 0; i < mfrc522.uid.size; i++) 
  {
     Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
     Serial.print(mfrc522.uid.uidByte[i], HEX);
     content.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " "));
     content.concat(String(mfrc522.uid.uidByte[i], HEX));
  }
  content.toUpperCase();
  Serial.println();
  if (content.substring(1) == "F9 15 F0 A3")
  {
    Serial.println(" Giris Basarili ! ");
    Serial.println(" Hos Geldiniz, Sn. Berat CEYLAN. İyi günler dileriz. ");
     digitalWrite(yesilLed, HIGH);
      delay(100);
    digitalWrite(yesilLed, LOW);
    delay(100);
    Serial.println(" Eglencenize bakin :) ");
    Serial.println();
    statuss = 1;
   
  }
  
  else   {
    Serial.println(" Kart Tanimlanmadi ! ");
    Serial.println(" Giris Basarisiz. ");
    digitalWrite(kirmiziLed, HIGH);
      delay(100);
    digitalWrite(kirmiziLed, LOW);
      delay(100);
  }
} 
