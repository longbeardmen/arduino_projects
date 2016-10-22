char temp[] = {};
int incomingByte, ledPin = 12, len = 0, result = 0, c = 0;
void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  if(Serial.available() > 4 && Serial.available() < 6){
    
    for(int i = 0; i < 6; i++){
      temp[i] = Serial.read();
    }

    show(5, temp);
    
//    for(int i = 0; i < 6; i++){
//      incomingByte = temp[i];
//      result += check(len, incomingByte);
//      
//    }
//    Serial.write(result);
//    if(result > 0){
//      int j = 0;
//      while(j <= result){
//        digitalWrite(ledPin, LOW);
//        delay(100);
//        digitalWrite(ledPin, HIGH);
//        delay(100);
//        j++;
//      }
//    }
  }
  digitalWrite(ledPin, HIGH);
  delay(100);
  digitalWrite(ledPin, LOW);
  delay(100);
  digitalWrite(ledPin, HIGH);
  delay(100);
}

void show(int a, char *b){
  for(int i = 0; i < a - 1; i++){
    Serial.print(b[i]);
  }
  Serial.println(b[a - 1]);
}

int check(int len, char incomingByte){
  if(len < 1 && incomingByte == 'R'){
    temp[0] = incomingByte;
    len++;
    c = 1;
  }else if(temp[len - 1] == 'R' && incomingByte == 'O'){
    temp[len] = incomingByte;
    len++;
    c = 1;
  }else if(temp[len - 1] == 'O' && incomingByte == 'M'){
    temp[len] = incomingByte;
    len++;
    c = 1;
  }else if(temp[len - 1] == 'M' && incomingByte == 'A'){
    temp[len] = incomingByte;
    len++;
    c = 1;
  }else if(temp[len - 1] == 'A' && incomingByte == 'N'){
    temp[len] = incomingByte;
    len++;
    c = 1;
  }
  return c;
  c = 0;
}
