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
    printaccelerometer();
    printOrientation();
    Serial.println(); 
  }
}

void printaccelerometer()
{ 
  Serial.print("x: ");
  Serial.print(accelerometer.cx, 3);
  Serial.print("\t");
  Serial.print("y: ");
  Serial.print(accelerometer.cy, 3);
  Serial.print("\t");
    Serial.print("z: ");
  Serial.print(accelerometer.cz, 3);
  Serial.print("\t");
}

void printOrientation()
{
  //byte pl = accelerometer.readPL();
//  int acc;  
  if(accelerometer.cy <= 0.150 && accelerometer.cy >= -0.150 && accelerometer.cx <= 0.150 && accelerometer.cx >= -0.150){
//      Serial.print("Flat");
//      acc = 1;
      Serial.write("F");
//      Serial.print(acc);
 
   
  }
   else if(accelerometer.cy < -0.150){
//      Serial.print("Left");
//       acc = 2;
       Serial.write("L");
//             Serial.print(acc);

   }
   else if(accelerometer.cy > 0.150){
//      Serial.print("Right");
//       acc = 3;
       Serial.write("R");
//             Serial.print(acc);

   }
    else if(accelerometer.cx > 0.150){
//      Serial.print("backward");
//       acc = 4;
       Serial.write("D");
//             Serial.print(acc);

   }
 else if(accelerometer.cx < 0.150){
//      Serial.print("foward");
//       acc = 5;
       Serial.write("U");
//             Serial.print(acc);

   }


}
