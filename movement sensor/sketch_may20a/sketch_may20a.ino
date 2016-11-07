//Тестировалось на Arduino IDE 1.0.1
#define pirPin 2
#define ledPin 13

void setup()
{
  Serial.begin(9600);
  pinMode(pirPin, INPUT);
  pinMode(ledPin,OUTPUT);
}

void loop()
{
  int pirVal = digitalRead(pirPin);

  //Если обнаружили движение
  if(pirVal == HIGH)
  {
    digitalWrite(ledPin, HIGH);
    Serial.print("Motion detected");
    delay(2000);
  }
  else
  {
    Serial.print("No motion");
    digitalWrite(ledPin,LOW);
  }
}
