long int last_time = 0, new_time, interval = 1000, n = 20, res = 1;
bool state = false;
void setup() {
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
//  new_time = millis();
//  if ( new_time - last_time >= interval) {
//    last_time = new_time;
//    Serial.println("hello");
//    state = !state;
//    digitalWrite(LED_BUILTIN, state);
//  }
  int last_time = micros();
  for(int j = 1; j <= n; j++) {
    int start = micros(); 
    for(int i = j; i > 0; i--) {
      res *= i;
    }
    int finish = micros();
    Serial.println(res);
    Serial.print("time: ");
    Serial.println(finish - start);
    res = 1;
  }
  delay(5000);
}
