void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

int power(int base, int pow){
  if(pow == 1)
    return base;
  else if(pow == 0)
    return 1;
  else
    return base*power(base, pow - 1);
}
  
void loop(){
  // put your main code here, to run repeatedly:
  for(int i = 970; i < 1000; i++){
    for(int j = 0; j < 4; j++){
      Serial.println((i % power(10, j + 1))/power(10, j));
    }
    Serial.println("-----------");
    delay(1000);
  }
}
