#include "nRF24L01.h"
#include "RF24.h"

const uint64_t pipe = 0xf0f1f2f3f4ll;

RF24 radio(9, 53);

int command[2], motorSpeed = 5000,
lookup[8] = { B01000, B01100, B00100, B00110, B00010, B00011, B00001, B01001 },
a[4] = { 30, 31, 32, 33 },
b[4] = { 34, 35, 36, 37 };



void setup() 
{
	for (size_t i = 30; i < 38; i++)
		pinMode(i, OUTPUT);

	Serial.begin(9600);

	radio.begin();
	delay(2);
	radio.setChannel(11);
	radio.setDataRate(RF24_1MBPS);
	radio.setPALevel(RF24_PA_HIGH);
	radio.openReadingPipe(1, pipe);
	radio.startListening();
}

void loop()
{
	while (radio.available() == 0);

	radio.read(&command, sizeof(command));
	int leftTrack = command[0], rightTrack = command[1];
  Serial.print(leftTrack);
  Serial.println(rightTrack);
	if (rightTrack == leftTrack && rightTrack == 0)
	{
		return;
	}
	else
	{
		for (int i = 0; i < 8; i++)
		{
			if (leftTrack == 0 || rightTrack == 0)
			{
				if (rightTrack == 0)
				{
					leftTrack == 1 ? setSingle(i, a) : setSingle(7 - i, a);
				}
				else
				{
					rightTrack == 1 ? setSingle(i, b) : setSingle(7 - i, b);
				}
			}
			else
			{
				if (rightTrack == leftTrack)
				{
					leftTrack == 1 ? setSync(i) : setSync(7 - i);
				}
				else
				{
					leftTrack == 2 ? setAsync(i, b, a) : setAsync(i, a, b);
				}
			}
			delayMicroseconds(motorSpeed);
		}
	}
}

void setSync(int out)
{
	for (int i = 0; i < 4; i++) {
		digitalWrite(a[i], bitRead(lookup[out], i));
		digitalWrite(b[i], bitRead(lookup[out], i));
	}
}

void setAsync(int out, int *first, int *second)
{
	for (int i = 0; i < 4; i++) {
		digitalWrite(first[i], bitRead(lookup[out], i));
		digitalWrite(second[i], bitRead(lookup[7 - out], i));
	}
}

void setSingle(int out, int *first)
{
	for (int i = 0; i < 4; i++) {
		digitalWrite(first[i], bitRead(lookup[out], i));
	}
}


