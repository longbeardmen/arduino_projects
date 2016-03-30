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

int i, j,
    lowPins[]= {43, 41, 39, 37, 35, 33},
    highPins[] = {A, B, C, D, E, F, G, DP},
    zero[] = {A, B, C, D, E, F, DP},
    one[] = {B, C},
    two[] = {A, B, D, E, G},
    three[] = {A, B, C, D, G},
    four[] = {B, C, F, G},
    five[] = {A, C, D, F, G},
    six[] = {A, C, D, E, F, G, DP},
    seven[] = {A, B, C},
    eight[] = {A, B, C, D, E, F, G},
    nine[] {A, B, C, D,F, G, DP};

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

void power(int digit, const char constant)
{
  switch(digit)
      {
        case 0:
          for(int segment : zero)
          {
            digitalWrite(segment, constant);
          }
          break;
        case 1:
          for(int segment : one)
          {
            digitalWrite(segment, constant);
          }
          break;
        case 2:
          for(int segment : two)
          {
            digitalWrite(segment, constant);
          }
          break;
        case 3:
          for(int segment : three)
          {
            digitalWrite(segment, constant);
          }
          break;
        case 4:
          for(int segment : four)
          {
            digitalWrite(segment, constant);
          }
          break;
        case 5:
          for(int segment : five)
          {
            digitalWrite(segment, constant);
          }
          break;
        case 6:
          for(int segment : six)
          {
            digitalWrite(segment, constant);
          }
          break;
        case 7:
          for(int segment : seven)
          {
            digitalWrite(segment, constant);
          }
          break;
        case 8:
          for(int segment : eight)
          {
            digitalWrite(segment, constant);
          }
          break;
        case 9:
          for(int segment : nine)
          {
            digitalWrite(segment, constant);
          }
          break;        
      }
}

void loop ()
{
  for(i = 0; i < 6; i++)
  {
    digitalWrite(lowPins[i], LOW);
    for(j = 0; j < 10; j++)
    {
      power(j, HIGH);    
      delay(100);
      power(j, LOW);
      delay(100);
    }
    digitalWrite(lowPins[i], HIGH);
  }
}
