#include <PID_v1.h>
#include<Wire.h>
#include <Servo.h>

#define MPU_addr 0x68
#define servoMinImp 544
#define servoMaxImp 2400
#define signalPin 9

//int16_t error, tempServoImp;
double error = 0, tempServoImp = 0, setpoint = 0, kp = 10, ki = 0 , kd = 0;             // modify for optimal performance
//double input = 0, output = 0, setpoint = 0;

PID myPID(&error, &tempServoImp, &setpoint, kp, ki, kd, REVERSE);  // if motor will only run at full speed try 'REVERSE' instead of 'DIRECT'

Servo myservo;

void setup(){
  Serial.begin(9600);
//  tempServoImp = servoMinImp;
  myservo.attach(signalPin, servoMinImp, servoMaxImp);
  myservo.writeMicroseconds(servoMinImp);

  myPID.SetMode(AUTOMATIC);
  myPID.SetSampleTime(100);
  myPID.SetOutputLimits(servoMinImp, servoMaxImp);
  
  Wire.begin();
  Wire.beginTransmission(MPU_addr);
  Wire.write(0x6B);  // PWR_MGMT_1 register
  Wire.write(0);     // set to zero (wakes up the MPU-6050)
  Wire.endTransmission(true);
}

void loop(){
  Wire.beginTransmission(MPU_addr);
  Wire.write(0x3B);  // starting with register 0x3B (ACCEL_XOUT_H)  
  Wire.requestFrom(MPU_addr,2,true);  // request just 2 registers (14 - full)
  error = Wire.read()<<8|Wire.read();  // 0x43 (GYRO_XOUT_H) & 0x44 (GYRO_XOUT_L)
  Wire.endTransmission(true);
  myPID.Compute();                                    // calculate new output
  Serial.println(error);
  myservo.writeMicroseconds(tempServoImp);
//  if(error > 0){
//    myservo.writeMicroseconds(tempServoImp += 1);
//  }else{
//    myservo.writeMicroseconds(tempServoImp -= 1);
//  }
}

//int scale_1(int error) {
//  int delta = abs(error)/100;
////  Serial.print("delta: ");Serial.println(delta);
//  
//  if(delta == 0) {
//    return 1;
//  } else {
//    return delta/2;
//  }
//}
//
//int scale_2(int error) {
//  int abs_error = abs(error);
//  
//  if(abs_error <= 800) {
//    return 1;
//  } else if(abs_error > 800 && abs_error <= 3200) {
//    return 4;
//  } else if(abs_error > 3200 && abs_error <= 6400) {
//    return 8;
//  } else if(abs_error > 6400 && abs_error <= 12800) {
//    return 16;
//  } else if(abs_error > 12800) {
//    return 32;
//  }
//}

