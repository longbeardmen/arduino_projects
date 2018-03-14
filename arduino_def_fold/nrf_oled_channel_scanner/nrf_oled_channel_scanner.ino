#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include "nRF24L01.h"
#include "RF24.h"
#include "printf.h"

#define OLED_RESET 4
Adafruit_SSD1306 display(OLED_RESET);

#define NUMFLAKES 10
#define XPOS 0
#define YPOS 1
#define DELTAY 2

RF24 radio(9,10);
const uint8_t num_channels = 128;
uint8_t values[num_channels];

int x0, y0, x1, y1, color = 1;

//int x0 = random(display.width());
//int y0 = random(display.height());

void setup()   {                
  Serial.begin(57600);
  printf_begin();
  printf("\n\rRF24/examples/scanner/\n\r");
  radio.begin();
  radio.setAutoAck(false);

  // Get into standby mode
  radio.startListening();
  radio.stopListening();

  // Print out header, high then low digit
  int i = 0;
  while ( i < num_channels )
  {
    printf("%x",i>>4);
    ++i;
  }
  printf("\n\r");
  i = 0;
  while ( i < num_channels )
  {
    printf("%x",i&0xf);
    ++i;
  }
  printf("\n\r");

  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.clearDisplay();
}

const int num_reps = 100;

//void loop() {
//  x0 = random(display.width());
//  y0 = random(display.height());
//  x1 = random(display.width());
//  y1 = random(display.height());
//  
//  display.drawLine(x0, y0, x1, y1, 1);
//  display.display();
//  
//  delay(1);
//  
////  x0 = x1;
////  y0 = y1;
//}
void loop(void)
{
  // Clear measurement values
  memset(values,0,sizeof(values));

  // Scan all channels num_reps times
  int rep_counter = num_reps;
  while (rep_counter--)
  {
    int i = num_channels;
    while (i--)
    {
      // Select this channel
      radio.setChannel(i);

      // Listen for a little
      radio.startListening();
      //delayMicroseconds(128);
      radio.stopListening();

      // Did we get a carrier?
      if ( radio.testCarrier() )
        ++values[i];
    }
  }

  // Print out channel measurements, clamped to a single hex digit
  int i = 0;
  display.clearDisplay();
  while ( i < num_channels )
  {
    printf("%x",min(0xf,values[i]&0xf));
    display.drawLine(i, display.height(), i, display.height() - 4*min(0xf,values[i]&0xf), 1);
    ++i;
  }
  printf("\n\r");
  display.display();
}



 
