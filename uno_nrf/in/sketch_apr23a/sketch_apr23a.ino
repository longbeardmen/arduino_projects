#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h> // https://github.com/maniacbug/RF24

const uint64_t pipe = 0xf0f1f2f3f4ll; // индитификатор передачи, "труба"

RF24 radio(9, 53); // ce, csn
  
void setup(){
  serial.begin(9600);
  
  radio.begin();  
  delay(2);
  radio.setchannel(9); // канал (0-127)
  
      // скорость, rf24_250kbps, rf24_1mbps или rf24_2mbps
      // rf24_250kbps на nrf24l01 (без +) неработает.
      // меньше скорость, выше чувствительность приемника.
  radio.setdatarate(rf24_1mbps);     
  
      // мощьность передатчика rf24_pa_min=-18dbm, rf24_pa_low=-12dbm, rf24_pa_med=-6dbm,
  radio.setpalevel(rf24_pa_high);   
    
  radio.openreadingpipe(1,pipe); // открываем первую трубу с индитификатором "pipe"
  radio.startlistening(); // включаем приемник, начинаем слушать трубу
}
 
//  radio.stoplistening(); // останавливает приём (нужно перед началом передачи) 


void loop()   
{  
  int data; 
  
  if (radio.available()){ // проверяем не пришло ли чего в буфер.
    radio.read(&data, sizeof(data)); // читаем данные, указываем сколько байт читать
    
    serial.print("data: ");
    serial.println(data); 
  } 
}
