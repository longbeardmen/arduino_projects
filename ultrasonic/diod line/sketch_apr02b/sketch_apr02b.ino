#define trigPin 33
#define echoPin 35

int n = 10, leds[9] = {53, 51, 49, 47, 45, 43, 41, 39, 37}, ledsCount, cmMin = 6;
long duration, cm;

long microsecondsToCentimeters(long microseconds)
{
  // The speed of sound is 340 m/s or 29 microseconds per centimeter.
  // The ping travels out and back, so to find the distance of the
  // object we take half of the distance travelled.
  return microseconds / 29 / 2;
}

void setup() {
  Serial.begin (9600);

  for (int l : leds)
    pinMode(l, OUTPUT);

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(2);
  digitalWrite(trigPin, LOW);
  
  duration = pulseIn(echoPin, HIGH);
  cm = microsecondsToCentimeters(duration);
  ledsCount = round(cmMin*9/cm);
  //  Serial.print(cm);
  //  Serial.print("cm");
  //  Serial.println();
  Serial.print(ledsCount);
  Serial.println("led");

  for (int i = 0; i < ledsCount; i++) {
    digitalWrite(leds[i], HIGH);
    delayMicroseconds(600);
    digitalWrite(leds[i], LOW);
  }
}
