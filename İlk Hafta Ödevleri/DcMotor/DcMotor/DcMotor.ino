const int DC = 3;
const int pot = A0;
int motor;
int led = 4;


void setup()
{
  pinMode(DC, OUTPUT);
  pinMode(led, OUTPUT);
  Serial.begin(9600);
}



void loop()
{
   motor = analogRead(pot);
    motor = map(motor, 0,1023,0,255);
    analogWrite(DC, motor);
    int hiz = map(motor,0,255, 0,5555);
    
  if (hiz > 3000)
  {
  digitalWrite(led, HIGH);
  }
  else{
  digitalWrite(led, LOW);
  } 
  
  Serial.print("Motor Hizi : ");
  Serial.println(hiz);
  Serial.println("d/dk");
  
  
  
}
