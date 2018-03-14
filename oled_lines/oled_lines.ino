#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define OLED_RESET 4
Adafruit_SSD1306 display(OLED_RESET);

#define NUMFLAKES 10
#define XPOS 0
#define YPOS 1
#define DELTAY 2

int x0, y0, x1, y1, color = 1;

//int x0 = random(display.width());
//int y0 = random(display.height());

void setup()   {                
  Serial.begin(9600);


  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.clearDisplay();

//  // draw a single pixel
//  display.drawPixel(10, 10, WHITE);
//  // Show the display buffer on the hardware.
//  // NOTE: You _must_ call display after making any drawing commands
//  // to make them visible on the display hardware!
//  display.display();
//  delay(2000);
//  display.clearDisplay();
//
//  // draw many lines
//  testdrawline();
//  display.display();
//  delay(2000);
//  display.clearDisplay(); 
}


void loop() {
  x0 = random(display.width());
  y0 = random(display.height());
  x1 = random(display.width());
  y1 = random(display.height());
  
  display.drawLine(x0, y0, x1, y1, color);
  display.display();
//  x0 = x1;
//  y0 = y1;
  color = !color;
}
   
void testdrawline() {  
  for (int16_t i=0; i<display.width(); i+=4) {
    display.drawLine(0, 0, i, display.height()-1, WHITE);
    display.display();
    delay(1);
  }
  for (int16_t i=0; i<display.height(); i+=4) {
    display.drawLine(0, 0, display.width()-1, i, WHITE);
    display.display();
    delay(1);
  }
  delay(250);
  
  display.clearDisplay();
  for (int16_t i=0; i<display.width(); i+=4) {
    display.drawLine(0, display.height()-1, i, 0, WHITE);
    display.display();
    delay(1);
  }
  for (int16_t i=display.height()-1; i>=0; i-=4) {
    display.drawLine(0, display.height()-1, display.width()-1, i, WHITE);
    display.display();
    delay(1);
  }
  delay(250);
  
  display.clearDisplay();
  for (int16_t i=display.width()-1; i>=0; i-=4) {
    display.drawLine(display.width()-1, display.height()-1, i, 0, WHITE);
    display.display();
    delay(1);
  }
  for (int16_t i=display.height()-1; i>=0; i-=4) {
    display.drawLine(display.width()-1, display.height()-1, 0, i, WHITE);
    display.display();
    delay(1);
  }
  delay(250);

  display.clearDisplay();
  for (int16_t i=0; i<display.height(); i+=4) {
    display.drawLine(display.width()-1, 0, 0, i, WHITE);
    display.display();
    delay(1);
  }
  for (int16_t i=0; i<display.width(); i+=4) {
    display.drawLine(display.width()-1, 0, i, display.height()-1, WHITE); 
    display.display();
    delay(1);
  }
  delay(250);
}
