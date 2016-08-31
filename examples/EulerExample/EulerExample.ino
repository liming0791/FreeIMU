#include <Wire.h>
#include <FreeSixIMU.h>

FreeSixIMU imu;

void setup() {
  imu.init();
  Serial.begin(115200);
}

void loop() {
  
  float angles[3];
  //float q[4];
    
  //imu.getYawPitchRoll(angles);  
  //imu.getQ(q);
  imu.getEuler(angles);

  float y = -angles[0]/180*PI;
  float p = -angles[1]/180*PI;
  float r = -angles[2]/180*PI;

  float sy = sin(y), cy = cos(y),
        sp = sin(p), cp = cos(p),
        sr = sin(r), cr = cos(r);

  float m00=cp*cy,          m01=cp*sy,          m02=-sp,
        m10=sr*sp*cy-cr*sy, m11=sr*sp*sy+cr*cy, m12=sr*cp,
        m20=cr*sp*cy+sr*sy, m21=cr*sp*sy-sr*cy, m22=cr*cp;

  Serial.print(m00);
  Serial.print(" ");
  Serial.print(m10);
  Serial.print(" ");
  Serial.print(m20);
  Serial.print(" ");
  Serial.print(m01);
  Serial.print(" ");
  Serial.print(m11);
  Serial.print(" ");
  Serial.print(m21);
  Serial.print(" ");
  Serial.print(m02);
  Serial.print(" ");
  Serial.print(m12);
  Serial.print(" ");
  Serial.println(m22);
  
  //Serial.print(-angles[0]);   //yaw
  //Serial.print(",\t");
  //Serial.print(-angles[1]);  //pitch
  //Serial.print(",\t");
  //Serial.println(-angles[2]);  //roll


  // Serial.print(q[0]);   
  // Serial.print(",\t");
  // Serial.print(q[1]);  
  // Serial.print(",\t");
  // Serial.print(q[2]); 
  // Serial.print(",\t");
  // Serial.println(q[3]);  

}
