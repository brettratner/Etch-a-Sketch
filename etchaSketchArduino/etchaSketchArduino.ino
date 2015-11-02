#include <Wire.h> 
#include <SFE_MMA8452Q.h>

MMA8452Q accelerometer;
void setup() {
  Serial.begin(9600);
  accelerometer.init(SCALE_8G, ODR_100);
}
void loop() {
  int sensorValue = analogRead(A0);
  sensorValue = sensorValue/17;
  Serial.println(sensorValue);
  if (accelerometer.available())
  {
    accelerometer.read();
    //printaccelerometer();
    printOrientation();
    Serial.println(); 
  }
}
// This will print out the x,y, and z axis information for the accelerometer. 
void printaccelerometer()
{ 
  Serial.print("x: ");
  Serial.print(accelerometer.cx, 3);
  Serial.print("\t");
  Serial.print("y: ");
  Serial.print(accelerometer.cy, 3);
  Serial.print("\t");
    Serial.print("y: ");
  Serial.print(accelerometer.cz, 3);
  Serial.print("\t");
}
void printOrientation()
{
if(accelerometer.cy <= 0.150 && accelerometer.cy >= -0.150 && accelerometer.cx
                    <= 0.150 && accelerometer.cx >= -0.150){
//      Serial.print("Flat");
      Serial.write("F");
}
  else if(accelerometer.cx < -0.150 && !(accelerometer.cy > 0.150 || accelerometer.cy < -0.150)){
//      Serial.print("foward");
       Serial.write("U");
  }
  
  else if(accelerometer.cx < -0.150 && accelerometer.cy > 0.150){
//      Serial.print("fowardRight");
       Serial.write("T");
  }
  
  else if(accelerometer.cy > 0.150 && !(accelerometer.cx < -0.150 || accelerometer.cx > 0.150)){
//      Serial.print("Right");
       Serial.write("R");
  }
  
  else if(accelerometer.cx < -0.150 && accelerometer.cy < -0.150){
//      Serial.print("UpLeft");
       Serial.write("Q");
  }
  
  else if(accelerometer.cy < -0.150 && !(accelerometer.cx < -0.150 || accelerometer.cx > 0.150)){
//      Serial.print("Left");
       Serial.write("L");
  }
  
  else if(accelerometer.cx > 0.150 && accelerometer.cy < -0.150){
//      Serial.print("backwardLeft");
       Serial.write("Z");
  }
    else if(accelerometer.cx > 0.150 && !(accelerometer.cy > 0.150 || accelerometer.cy < -0.150)){
//      Serial.print("backward");
       Serial.write("D");
   }
    else if(accelerometer.cx > 0.150 && accelerometer.cy > 0.150){
//      Serial.print("backwardRight");
       Serial.write("C");
   }
 
}



