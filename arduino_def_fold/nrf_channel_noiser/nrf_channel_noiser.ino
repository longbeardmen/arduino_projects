#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h> // https://github.com/maniacbug/RF24
   
const uint64_t pipe = 0xF0F1F2F3F4LL; // индитификатор передачи, "труба"
 
RF24 radio(9, 10); // CE, CSN

int k = 100, c = 60;

void setup(){
  Serial.begin(9600);

  radio.begin();
  delay(2);
  radio.setChannel(c); // канал (0-127)
    
      // скорость, RF24_250KBPS, RF24_1MBPS или RF24_2MBPS
      // RF24_250KBPS на nRF24L01 (без +) неработает.
      // меньше скорость, выше чувствительность приемника.
  radio.setDataRate(RF24_1MBPS); 
   
      // мощьность передатчика, RF24_PA_MIN=-18dBm, RF24_PA_LOW=-12dBm, RF24_PA_MED=-6dBM,
  radio.setPALevel(RF24_PA_HIGH);   

  radio.openWritingPipe(pipe); // открываем трубу на передачу.
} 


void loop()   
{
  while(k-->0){
    radio.setChannel(c); // канал (0-127)
      
        // скорость, RF24_250KBPS, RF24_1MBPS или RF24_2MBPS
        // RF24_250KBPS на nRF24L01 (без +) неработает.
        // меньше скорость, выше чувствительность приемника.
    radio.setDataRate(RF24_1MBPS); 
     
        // мощьность передатчика, RF24_PA_MIN=-18dBm, RF24_PA_LOW=-12dBm, RF24_PA_MED=-6dBM,
    radio.setPALevel(RF24_PA_HIGH);   
  
    radio.openWritingPipe(pipe); // открываем трубу на передачу.
  
    int data = 0xFF; // читаем значение
    
    radio.write(&data, sizeof(data)); // отправляем данные и указываем сколько байт пакет
    
    Serial.println(c);
  }

  k = 50;
  
  if(c < 128)
    c+=10;
  else
    c = 60;
    
    
}

