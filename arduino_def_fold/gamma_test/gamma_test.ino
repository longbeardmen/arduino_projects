// DURATION OF THE NOTES 
#define BPM 144    //  you can change this value changing all the others
#define H 2*Q //half 2/4
#define Q 60000/BPM //quarter 1/4 
#define E Q/2   //eighth 1/8
#define S Q/4 // sixteenth 1/16
#define W 4*Q // whole 4/4

void setup() {     
  pinMode(8, OUTPUT);
  Serial.begin(9600);
}


void loop() {
  //tone(pin, note, duration)
  for(int i = 0; i < 1000; i++) {
    Serial.println(i);
    tone(8,i,0);
  }
  for(int i = 1000; i > 0; i--) {
    Serial.println(i);
    tone(8,i,0);
  }
}
