//Тестировалось на Arduino IDE 1.0.1
// добавляем библиотеку для работы с сервоприводами
#include <Servo.h> 
// для дальнейшей работы назовем 9 пин как servoPin
#define servoPin 9
// 544 это эталонная длина импульса при котором сервопривод должен принять положение 0°
#define servoMinImp 544 
// 2400 это эталонная длина импульса при котором сервопривод должен принять положение 180°
#define servoMaxImp 2400
Servo myServo;

const int trigPin = 11;
const int echoPin = 10;

void setup()
{
  myServo.attach(servoPin, servoMinImp, servoMaxImp);
// устанавливаем пин как вывод управления сервоприводом,
// а также для работы сервопривода непосредственно в диапазоне углов от 0 до 180° задаем мин и макс значения импульсов.
// импульсы с большей или меньшей длиной восприниматься не будут.
// для сервоприводов даже одной партии значения длин импульсов могут отличаться, может быть даже и 584-2440.
// поэкспериментируйте и найдите идеальные длины импульсов конкретно для вашего сервопривода.

  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}
void loop()
{
  // устанавливаем качалку сервопривода в положение 0°(т.к.импульс равен 544мкс)
  int tempServoImp = servoMinImp;
  while(tempServoImp < servoMaxImp){
    myServo.writeMicroseconds(tempServoImp);
    delay(100);
    showDistance();
    tempServoImp += 11;
  }
}

long microsecondsToCentimeters(long microseconds)
{
  // The speed of sound is 340 m/s or 29 microseconds per centimeter.
  // The ping travels out and back, so to find the distance of the
  // object we take half of the distance travelled.
  return microseconds / 29 / 2;
}

void showDistance() {
  long duration, inches, cm;
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  cm = microsecondsToCentimeters(duration);
  
  Serial.print(cm);
  Serial.println("cm");
}
