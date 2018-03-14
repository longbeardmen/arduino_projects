int k = 3500, i = 0;;
void setup() {
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  digitalWrite(9, 1);
  delayMicroseconds(k);
  digitalWrite(10, 0);
  delayMicroseconds(k);
  digitalWrite(11, 0);
  delayMicroseconds(k);
  digitalWrite(9, 1);
  delayMicroseconds(k);
  digitalWrite(10, 1);
  delayMicroseconds(k);
  digitalWrite(11, 0);
  delayMicroseconds(k);
  
  digitalWrite(9, 0);
  delayMicroseconds(k);
  digitalWrite(10, 1);
  delayMicroseconds(k);
  digitalWrite(11, 0);
  delayMicroseconds(k);
  digitalWrite(9, 0);
  delayMicroseconds(k);
  digitalWrite(10, 1);
  delayMicroseconds(k);
  digitalWrite(11, 1);
  delayMicroseconds(k);
  
  digitalWrite(9, 0);
  delayMicroseconds(k);
  digitalWrite(10, 0);
  delayMicroseconds(k);
  digitalWrite(11, 1);
  delayMicroseconds(k);
  digitalWrite(9, 1);
  delayMicroseconds(k);
  digitalWrite(10, 0);
  delayMicroseconds(k);
  digitalWrite(11, 1);
  delayMicroseconds(k);
  
  i++;

  if(k >= 1500 && i == 1 ){
    i = 0;
    k-=10;
    Serial.println(k);
  } else if( k < 1500 && k >= 500 && i == 2){
    i = 0;
    k-=5;
    Serial.println(k);
  } else if( k < 500 && k >= 400 && i == 4){
    i = 0;
    k--;
    Serial.println(k);
  } else {
  }
  
//  for(int i = 0; i < 360; i++){
//    analogWrite(9, sin(radians(i))/1.0*256);
//    analogWrite(10, sin(radians(i+120))/1.0*256);
//    analogWrite(11, sin(radians(i+240))/1.0*256);
//    delayMicroseconds(k);
//  }
}
