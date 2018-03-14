#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h> // https://github.com/maniacbug/RF24

const uint64_t pipe = 0xF0F1F2F3F4LL; // индитификатор передачи, "труба"

RF24 radio(9, 10); // ce, csn
  
void setup(){
  Serial.begin(9600);
  
  radio.begin();  
  delay(2);
  radio.setChannel(127); // канал (0-127)
  
      // скорость, rf24_250kbps, rf24_1mbps или rf24_2mbps
      // rf24_250kbps на nrf24l01 (без +) неработает.
      // меньше скорость, выше чувствительность приемника.
  radio.setDataRate(RF24_1MBPS);     
  
      // мощьность передатчика rf24_pa_min=-18dbm, rf24_pa_low=-12dbm, rf24_pa_med=-6dbm,
  radio.setPALevel(RF24_PA_HIGH);   
    
  radio.openReadingPipe(1,pipe); // открываем первую трубу с индитификатором "pipe"
  radio.startListening(); // включаем приемник, начинаем слушать трубу
}
 
//  radio.stoplistening(); // останавливает приём (нужно перед началом передачи) 


void loop()   
{  
  int data; 
  
  if (radio.available()){ // проверяем не пришло ли чего в буфер.
    radio.read(&data, sizeof(data)); // читаем данные, указываем сколько байт читать
    
    Serial.print("data: ");
    Serial.println(data); 
  } 
}
