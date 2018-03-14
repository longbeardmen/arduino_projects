
#define C4 53
#define Db4 51
#define D4  49
#define Eb4 47
#define E4  45
#define F4  43
#define Gb4 41
#define G4  39
#define Ab4 37
#define A4  35
#define Bb4 33
#define B4  31

int sum, temp[12] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, octave[12] = {C4, Db4, D4, Eb4, E4, F4, Gb4, G4, Ab4, A4, Bb4, B4};
float freqs[12] = {261.63, 277.18, 293.66, 311.13, 329.63, 349.23, 369.99, 392.0, 415.3, 440.0, 466.16, 493.88};

void setup() {
  for(int i = 0; i < 12; i++) {
    pinMode(octave[i], OUTPUT);
    digitalWrite(octave[i], 0);
  }
}

void loop() {
  sum = 0;
  
  for(int i = 0; i < 12; i++) {
    temp[i] = digitalRead(octave[i]);
    sum += temp[i];
  }

  if(sum ==0) {
      noTone(8);
  }
    
  for(int i = 0; i < 12; i++) {
    if(temp[i]) {
      tone(8, freqs[i]);
    }  
  }
}
