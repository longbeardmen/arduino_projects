#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

const uint64_t pipe = 0xF0F1F2F3F4LL;
 
RF24 radio(9, 10);
LiquidCrystal_I2C lcd(0x3f,16,2);
void setup()
{
  lcd.init();                     
  lcd.backlight();// Включаем подсветку дисплея

  
  Serial.begin(9600);

  radio.begin();
  delay(2);
  radio.setChannel(11);
  radio.setDataRate(RF24_1MBPS);
  radio.setPALevel(RF24_PA_HIGH);   
  radio.openWritingPipe(pipe);
  digitalWrite(A3, HIGH);
  digitalWrite(A2, HIGH);
  lcd.init();
  lcd.backlight();
} 


void loop()   
{
	int leftTrack = analogRead(2),
		rightTrack = analogRead(3),
		firstPart = analizeAnalogIn(leftTrack),
		secondPart = analizeAnalogIn(rightTrack),
		command[2] = {firstPart, secondPart};
   Serial.print(firstPart);
   Serial.println(secondPart);
  lcd.setCursor(0, 0);
  lcd.print(firstPart );
  lcd.setCursor(0, 1);
  lcd.print(secondPart );
	radio.write(&command, sizeof(command));
}

int analizeAnalogIn(int arg)
{
	if (arg < 600 && arg > 400)
	{
		return 1;
	}
	else if (arg < 400)
	{
		return 2;
	}
	else
	{
		return 0;
	}
}

