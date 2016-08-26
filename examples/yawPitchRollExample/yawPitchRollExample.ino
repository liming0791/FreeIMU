#include <Wire.h>
#include <FreeSixIMU.h>

FreeSixIMU imu;


void setup() {
  
  imu.init();
  
  Serial.begin(19200);
}

void loop() {
  
  float angles[3];
  float q[4];
    
  //imu.getYawPitchRoll(angles);  
  //imu.getQ(q);
  imu.getEuler(angles);

  Serial.print(-angles[0]);   //yaw
  Serial.print(",\t");
  Serial.print(-angles[1]);  //pitch
  Serial.print(",\t");
  Serial.println(-angles[2]);  //roll


  // Serial.print(q[0]);   
  // Serial.print(",\t");
  // Serial.print(q[1]);  
  // Serial.print(",\t");
  // Serial.print(q[2]); 
  // Serial.print(",\t");
  // Serial.println(q[3]);  

}
