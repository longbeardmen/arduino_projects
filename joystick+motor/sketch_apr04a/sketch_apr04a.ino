int yPin = A1, speed = 0, buttonPin = 4, buttonState = 0, startPin = 2, speedPin = 3, temp = 0;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  pinMode(yPin, INPUT);
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(speedPin, OUTPUT);
  pinMode(startPin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
    
    buttonState = digitalRead(buttonPin);
    delay(200);
    Serial.print("buttonState ");
    Serial.println(buttonState);
    
    if (buttonState == 0) {
      if(temp == 0){
        temp = 1;
      }else{
        temp = 0;
      }
    }
    
    Serial.print("temp ");
    Serial.println(temp);
    
    if(temp == 0){
      digitalWrite(startPin, LOW);
    }else{
      digitalWrite(startPin, HIGH);
      speed = analogRead(yPin);
      Serial.println(speed);
      analogWrite(speedPin, speed);
    }
}
