#include <SPI.h>

uint8_t csnPin = 10;
uint8_t cePin = 9;
uint8_t channel = 90 ;
uint8_t addLength = 5;
char * address = "00001";
uint8_t payload;
uint8_t PTX;



void setup()
{
  Serial.begin(9600);
  Serial.println( "Starting wireless..." );

  //initialisation code
  pinMode(cePin, OUTPUT);
  pinMode(csnPin, OUTPUT);
  ceLow();
  csnHi();
  SPI.begin();
  SPI.setDataMode(SPI_MODE0);
  SPI.setClockDivider(SPI_2XCLOCK_MASK);
  setRaddress((byte *)address);
  payload = sizeof(unsigned long);
  config();

  byte rfsetup = 0;
  //
  //
  //
  //CHANGE 0x05 to any Register you want to Read
  readregister(0x05, &rfsetup, sizeof(rfsetup));
  //
  //
  //
  //


  Serial.print( "rf_setup = " );
  Serial.println( rfsetup, BIN );

  Serial.println( "Wireless initialized!" );

  Serial.println(payload, BIN);//Output from register
  Serial.println(payload, DEC);//Same as above but in different formats
  Serial.println(payload, HEX);


}

void loop()
{

}
//reads an array of bytes from the given start position in the registers
void readregister(uint8_t reg, uint8_t * value, uint8_t len)
{
  csnLow();
  spisend(0x00 | ( 0x1F & reg));
  transfersync(value, value, len);
  csnHi();
}

void transfersync(uint8_t *dataout, uint8_t *datain, uint8_t len)
{
  uint8_t i;
  for (i = 0; i < len; i++)
  {
    datain[i] = spisend(dataout[i]);
  }

}


void config()
{
  configregister(0x05, channel); //Set the RF channel to 90
  configregister(0x11, payload);
  configregister(0x12, payload);

  poweruprx();//to do
  flushrx(); // to do

}

void flushrx()
{
  csnLow();
  spisend(0xE2);
  csnHi();
}

void poweruprx()
{
  PTX = 0;
  ceLow();
  configregister(0x00, 0x07 | ((1 << 0x01) | (0 << 0)));
  ceHi();
  configregister(0x07, (1 << 0x05) | (1 << 0x04)) ;
}


void configregister(uint8_t reg, uint8_t value)
{
  csnLow();
  spisend(0x20 | (0x1F & reg));
  spisend(value);
  csnHi();
}



void setRaddress(uint8_t * adr)
{
  ceLow();
  writeRegister(0x0B, adr, addLength);
  ceHi();
}

void writeRegister(uint8_t reg, uint8_t * value, uint8_t len)
{
  csnLow();
  spisend(0x20 | (0x1F & 0x0B));
  transmitsync(value, len);
  csnHi();
}

//Need to see if this works
uint8_t spisend(uint8_t data)
{
  return SPI.transfer(data);
}

void transmitsync(uint8_t *dataout, uint8_t len)
{
  uint8_t i;
  for (i = 0; i < len; i++)
  {
    spisend(dataout[i]);
  }
}


//Functions to control the chip select pins
void ceHi() {
  digitalWrite(cePin, HIGH);
}

void ceLow() {
  digitalWrite(cePin, LOW);
}

void csnHi() {
  digitalWrite(csnPin, HIGH);
}

void csnLow() {
  digitalWrite(csnPin, LOW);
}
