/*
   lowPins for 14, 1, 2, 5, 7, 8 pins of inidcator
   highPins for  12(A), 13(B), 6(C), 3(D), 9(E), 10(F), 11(G), 4(DP)

   + A +
   F   B
   + G +
   E   C
   + D + DP

*/
enum section {
      a = 1<<2,
      b = 1<<3,
      c = 1<<4,
      d = 1<<5,
      e = 1<<6,
      f = 1<<7,
      g = 1<<8,
      dp = 1<<9
    };

int i, j,
    lowPins[]= {43, 41, 39, 37, 35, 33},
    highPins[] = {2, 3, 4, 5, 6, 7, 8, 9},
    digits[] = {
      a|b|c|d|e|f,
      b|c,
      a|b|d|e|g,
      a|b|c|d|g,
      b|c|f|g,
      a|c|d|f|g,
      a|c|d|e|f|g,
      a|b|c,
      a|b|c|d|e|f|g,
      a|b|c|d|f|g
    };

void getDigit(int x, const char c) {
  for (int i = 0; i < 10; i++) {
    if (digits[x] & 1<<i) {
      digitalWrite(i, c);
    }
  }
}

int day[] = {0,0,0,0,0,0};

void setup (){
  for(int high : highPins){
    pinMode(high, OUTPUT);
  }
  
  for(int low : lowPins){
    pinMode(low, OUTPUT);
    digitalWrite(low, HIGH);
  }
}

void incDigit() {

  day[5]++;
  bool dop = false;

  for (int i = 5; i >= 0; i--) {
    if (dop) {
      day[i]++;
    }
    dop = false;
    
    if (day[i] == 10) {
      day[i] = 0;
      dop = true;
    }
  }
}

void loop (){
  static int time = 0;
  for(i = 0; i < 6; i++)
  {
    digitalWrite(lowPins[i], LOW);
      
      getDigit(day[i], HIGH); 
      delay(4);//kastyl'
      getDigit(day[i], LOW);

      time++;
      if (time >= 15) {
        incDigit();
        time = 0;
      }
    
    digitalWrite(lowPins[i], HIGH);
  }
}
