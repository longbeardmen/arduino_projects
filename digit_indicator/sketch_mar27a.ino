/*
   lowPins for 14, 1, 2, 5, 7, 8 pins of inidcator
   highPins for  12(A), 13(B), 6(C), 3(D), 9(E), 10(F), 11(G), 4(DP)

   + A +
   F   B
   + G +
   E   C
   + D + DP

*/

#define A   2
#define B   3
#define C   4
#define D   5
#define E   6
#define F   7
#define G   8
#define DP  9

int i, n = 6, ledDelay = 100, highPins[] = {A, B, C, D, E, F, G, DP}, lowPins[]= {43, 41, 39, 37, 35, 33};

void setup ()
{
  for(int high : highPins)
  {
    pinMode(high, OUTPUT);
  }
  
  for(int low : lowPins)
  {
    pinMode(low, OUTPUT);
    digitalWrite(low, HIGH);
  }
}

void loop ()
{
  for(int i = 0; i < 6; i++)
  {
    digitalWrite(lowPins[i], LOW);
    for(int j = 0; j < 8; j++)
    {
      digitalWrite(highPins[j], HIGH);
      delay(200);
      digitalWrite(highPins[j], LOW);
      delay(200);
    }
    digitalWrite(lowPins[i], HIGH);
  }
}

