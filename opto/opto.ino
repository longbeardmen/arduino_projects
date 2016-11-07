int sda = 5;
int scl = 6;

int sda_read, i=0;
int delay_time=50;

// the setup function runs once when you press reset or power the board
void setup() {
  
  Serial.begin(9600);
  
  pinMode(scl, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  
  pinMode(sda, OUTPUT);

  digitalWrite(sda, HIGH);  //
  delay(delay_time);        //
  digitalWrite(scl, HIGH);  //                
  delay(delay_time);        //
  digitalWrite(sda, LOW);   // Start
  delay(delay_time);        //
  digitalWrite(scl, LOW);   // 
  delay(delay_time);        //
  
  /************** DEVICE ADDRESS STARTS HERE ***************/
  
  digitalWrite(sda, HIGH);  //
  delay(delay_time);        //
  digitalWrite(scl, HIGH);  //  
  delay(delay_time);        //   1   MSB
  digitalWrite(scl, LOW);   //
  delay(delay_time);        //
  
  digitalWrite(sda, LOW);   //
  delay(delay_time);        //
  digitalWrite(scl, HIGH);  //  
  delay(delay_time);        //   2 
  digitalWrite(scl, LOW);   //
  delay(delay_time);        // 
  
  digitalWrite(sda, HIGH);  // 
  delay(delay_time);        // 
  digitalWrite(scl, HIGH);  //  
  delay(delay_time);        //   3 
  digitalWrite(scl, LOW);   //
  delay(delay_time);        //
  
  digitalWrite(sda, LOW);   //
  delay(delay_time);        //
  digitalWrite(scl, HIGH);  //  
  delay(delay_time);        //   4 
  digitalWrite(scl, LOW);   //
  delay(delay_time);        //
  
  digitalWrite(scl, HIGH);  //  
  delay(delay_time);        //   5 
  digitalWrite(scl, LOW);   //
  delay(delay_time);        //

  digitalWrite(scl, HIGH);  //  
  delay(delay_time);        //   6 
  digitalWrite(scl, LOW);   //
  delay(delay_time);        // 
  
  digitalWrite(scl, HIGH);  //  
  delay(delay_time);        //   7
  digitalWrite(scl, LOW);   //
  delay(delay_time);        //
  
  digitalWrite(scl, HIGH);  //  
  delay(delay_time);        //   8   LSB
  digitalWrite(scl, LOW);   //
  delay(delay_time);        // 

  /************** DEVICE ADDRESS ENDS HERE ***************/

  digitalWrite(scl, HIGH);         //  
  delay(delay_time);               //
  pinMode(sda, INPUT);             //
  Serial.print(digitalRead(sda));  //   ACKNOWLEDGEMENT
  delay(delay_time);               //
  digitalWrite(scl, LOW);          //
  delay(delay_time);               //

  /************** WORD ADDRESS STARTS HERE ***************/
  
  pinMode(sda, OUTPUT);     //
  
  digitalWrite(sda, LOW);   //  
  delay(delay_time);        //
  digitalWrite(scl, HIGH);  //  
  delay(delay_time);        //   1   MSB
  digitalWrite(scl, LOW);   //
  delay(delay_time);        //
  
  digitalWrite(scl, HIGH);  //  
  delay(delay_time);        //   2 
  digitalWrite(scl, LOW);   //
  delay(delay_time);        //
  
  digitalWrite(scl, HIGH);  //  
  delay(delay_time);        //   3 
  digitalWrite(scl, LOW);   //
  delay(delay_time);        //
  
  digitalWrite(scl, HIGH);  //  
  delay(delay_time);        //   4 
  digitalWrite(scl, LOW);   //
  delay(delay_time);        //
  
  digitalWrite(scl, HIGH);  //  
  delay(delay_time);        //   5 
  digitalWrite(scl, LOW);   //
  delay(delay_time);        // 

  digitalWrite(scl, HIGH);  //  
  delay(delay_time);        //   6 
  digitalWrite(scl, LOW);   //
  delay(delay_time);        // 

  digitalWrite(sda, HIGH);  //  
  delay(delay_time);        //
  digitalWrite(scl, HIGH);  //  
  delay(delay_time);        //   7
  digitalWrite(scl, LOW);   //
  delay(delay_time);        //
  
  digitalWrite(scl, HIGH);  //  
  delay(delay_time);        //   8   LSB
  digitalWrite(scl, LOW);   //
  delay(delay_time);        //
  
  /************** DEVICE ADDRESS ENDS HERE ***************/
  
  digitalWrite(sda, LOW);            //
  delay(delay_time);                 //
  digitalWrite(scl, HIGH);           //  
  delay(delay_time);                 //  
  pinMode(sda, INPUT);               //
  Serial.print(digitalRead(sda));    //   ACKNOWLEDGEMENT
  delay(delay_time);                 //   
  digitalWrite(scl, LOW);            //
  delay(delay_time);                 //

  /************** DATA STARTS HERE ***************/
  
  pinMode(sda, OUTPUT);
  digitalWrite(sda, HIGH);  //
  delay(delay_time);        //
  digitalWrite(scl, HIGH);  //  
  delay(delay_time);        //   1   MSB
  digitalWrite(scl, LOW);   //
  delay(delay_time);        // 
  
  digitalWrite(sda, LOW);   //
  delay(delay_time);        //
  digitalWrite(scl, HIGH);  //  
  delay(delay_time);        //   2
  digitalWrite(scl, LOW);   //
  delay(delay_time);        //
  
  digitalWrite(sda, HIGH);  //
  delay(delay_time);        //
  digitalWrite(scl, HIGH);  //  
  delay(delay_time);        //   3
  digitalWrite(scl, LOW);   //  
  delay(delay_time);        //

  digitalWrite(sda, LOW);   //
  delay(delay_time);        //
  digitalWrite(scl, HIGH);  //  
  delay(delay_time);        //   4
  digitalWrite(scl, LOW);   //  
  delay(delay_time);        //
  
  digitalWrite(sda, HIGH);  //
  delay(delay_time);        //
  digitalWrite(scl, HIGH);  //  
  delay(delay_time);        //   5
  digitalWrite(scl, LOW);   //  
  delay(delay_time);        //
 
  digitalWrite(sda, LOW);   //
  delay(delay_time);        //
  digitalWrite(scl, HIGH);  //  
  delay(delay_time);        //   6
  digitalWrite(scl, LOW);   //
  delay(delay_time);        // 

  digitalWrite(sda, HIGH);  //
  delay(delay_time);        //
  digitalWrite(scl, HIGH);  //  
  delay(delay_time);        //   7
  digitalWrite(scl, LOW);   //
  delay(delay_time);        //

  digitalWrite(sda, LOW);   //
  delay(delay_time);        // 
  digitalWrite(scl, HIGH);  //  
  delay(delay_time);        //   8   LSB
  digitalWrite(scl, LOW);   //  
  delay(delay_time);        //
  
  /************** DATA ENDS HERE ***************/

  digitalWrite(sda, LOW);            //
  delay(delay_time);                 // 
  digitalWrite(scl, HIGH);           //  
  delay(delay_time);                 //  
  pinMode(sda, INPUT);               //
  Serial.print(digitalRead(sda));    //   ACKNOWLEDGEMENT
  delay(delay_time);                 //   
  digitalWrite(scl, LOW);            //
  delay(delay_time);                 //
  
  pinMode(sda, OUTPUT);  
  digitalWrite(sda, LOW);   //
  delay(delay_time);        //
  digitalWrite(scl, HIGH);  //  
  delay(delay_time);        //   STOP
  digitalWrite(sda, HIGH);  //   
  delay(delay_time);        //

  delay(3000);
}
