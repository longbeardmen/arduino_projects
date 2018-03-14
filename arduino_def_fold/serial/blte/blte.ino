char ans;
void setup() {
  Serial.begin(115200);
  Serial.println(Serial.read());
  Serial.println("###");
}

void loop() {
  Serial.write("AT+BAUD4");
  ans = Serial.read();
  Serial.println();
  Serial.println(ans);
  delay(1000);
  Serial.write("AT");
  Serial.println();
  ans = Serial.read();
  Serial.println(ans);
  delay(1000);
  Serial.write("AT");
  Serial.println();
  ans = Serial.read();
  Serial.println(ans);
  delay(1000);
}
